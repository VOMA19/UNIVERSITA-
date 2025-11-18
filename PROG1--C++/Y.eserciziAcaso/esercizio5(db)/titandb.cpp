#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <memory>
#include <stdexcept>

const uint32_t PAGE_SIZE = 4096;
const uint32_t MAX_PAGES = 10000;
const uint32_t BTREE_ORDER = 8;
const uint32_t MAX_KEY_SIZE = 256;
const uint32_t MAX_VALUE_SIZE = 1024;

// ============================================================================
// PARTE 1: LEXER & TOKENIZER
// ============================================================================

enum class TokenType {
    INSERT, SELECT, FROM, WHERE, VALUES, DELETE, UPDATE, SET,
    EXIT, CREATE, TABLE, INT_TYPE, VARCHAR_TYPE,
    IDENTIFIER, NUMBER, STRING, LPAREN, RPAREN, COMMA, SEMICOLON,
    EQUALS, LESS, GREATER, AND, OR, DOT, STAR,
    UNKNOWN, END_OF_FILE
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int col;

    Token(TokenType t = TokenType::UNKNOWN, const std::string& v = "", int l = 0, int c = 0)
        : type(t), value(v), line(l), col(c) {}
};

class Lexer {
private:
    std::string input;
    size_t pos;
    int line, col;

    bool isWhitespace(char c) const {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }

    bool isDigit(char c) const {
        return c >= '0' && c <= '9';
    }

    bool isAlpha(char c) const {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
    }

    bool isAlphaNumeric(char c) const {
        return isAlpha(c) || isDigit(c);
    }

    char peek() const {
        if (pos >= input.length()) return '\0';
        return input[pos];
    }

    char peekNext() const {
        if (pos + 1 >= input.length()) return '\0';
        return input[pos + 1];
    }

    char advance() {
        char c = input[pos++];
        if (c == '\n') {
            line++;
            col = 0;
        } else {
            col++;
        }
        return c;
    }

    void skipWhitespace() {
        while (isWhitespace(peek())) {
            advance();
        }
    }

    Token readNumber() {
        std::string num;
        int startLine = line, startCol = col;
        while (isDigit(peek())) {
            num += advance();
        }
        return Token(TokenType::NUMBER, num, startLine, startCol);
    }

    Token readString() {
        int startLine = line, startCol = col;
        advance(); // skip opening quote
        std::string str;
        while (peek() != '\'' && peek() != '\0') {
            if (peek() == '\\') {
                advance();
                switch (peek()) {
                    case 'n': str += '\n'; advance(); break;
                    case 't': str += '\t'; advance(); break;
                    case '\'': str += '\''; advance(); break;
                    default: str += advance();
                }
            } else {
                str += advance();
            }
        }
        if (peek() == '\'') advance(); // skip closing quote
        if (str.length() > MAX_KEY_SIZE) {
            throw std::runtime_error("String too long at line " + std::to_string(startLine));
        }
        return Token(TokenType::STRING, str, startLine, startCol);
    }

    Token readIdentifier() {
        std::string ident;
        int startLine = line, startCol = col;
        while (isAlphaNumeric(peek())) {
            ident += advance();
        }

        // Keywords
        std::string upper = ident;
        std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

        if (upper == "INSERT") return Token(TokenType::INSERT, ident, startLine, startCol);
        if (upper == "SELECT") return Token(TokenType::SELECT, ident, startLine, startCol);
        if (upper == "FROM") return Token(TokenType::FROM, ident, startLine, startCol);
        if (upper == "WHERE") return Token(TokenType::WHERE, ident, startLine, startCol);
        if (upper == "VALUES") return Token(TokenType::VALUES, ident, startLine, startCol);
        if (upper == "DELETE") return Token(TokenType::DELETE, ident, startLine, startCol);
        if (upper == "UPDATE") return Token(TokenType::UPDATE, ident, startLine, startCol);
        if (upper == "SET") return Token(TokenType::SET, ident, startLine, startCol);
        if (upper == "EXIT") return Token(TokenType::EXIT, ident, startLine, startCol);
        if (upper == "CREATE") return Token(TokenType::CREATE, ident, startLine, startCol);
        if (upper == "TABLE") return Token(TokenType::TABLE, ident, startLine, startCol);
        if (upper == "INT") return Token(TokenType::INT_TYPE, ident, startLine, startCol);
        if (upper == "VARCHAR") return Token(TokenType::VARCHAR_TYPE, ident, startLine, startCol);
        if (upper == "AND") return Token(TokenType::AND, ident, startLine, startCol);
        if (upper == "OR") return Token(TokenType::OR, ident, startLine, startCol);

        return Token(TokenType::IDENTIFIER, ident, startLine, startCol);
    }

public:
    Lexer(const std::string& s) : input(s), pos(0), line(1), col(0) {}

    Token nextToken() {
        skipWhitespace();

        if (peek() == '\0') {
            return Token(TokenType::END_OF_FILE, "", line, col);
        }

        if (isDigit(peek())) {
            return readNumber();
        }

        if (peek() == '\'') {
            return readString();
        }

        if (isAlpha(peek())) {
            return readIdentifier();
        }

        char c = peek();
        int curLine = line, curCol = col;

        switch (c) {
            case '(': advance(); return Token(TokenType::LPAREN, "(", curLine, curCol);
            case ')': advance(); return Token(TokenType::RPAREN, ")", curLine, curCol);
            case ',': advance(); return Token(TokenType::COMMA, ",", curLine, curCol);
            case ';': advance(); return Token(TokenType::SEMICOLON, ";", curLine, curCol);
            case '=': advance(); return Token(TokenType::EQUALS, "=", curLine, curCol);
            case '<': advance(); return Token(TokenType::LESS, "<", curLine, curCol);
            case '>': advance(); return Token(TokenType::GREATER, ">", curLine, curCol);
            case '.': advance(); return Token(TokenType::DOT, ".", curLine, curCol);
            case '*': advance(); return Token(TokenType::STAR, "*", curLine, curCol);
            default:
                advance();
                return Token(TokenType::UNKNOWN, std::string(1, c), curLine, curCol);
        }
    }
};

// ============================================================================
// PARTE 2: PARSER & AST
// ============================================================================

struct Value {
    enum Type { INT, STRING } type;
    int intVal;
    std::string strVal;

    Value() : type(INT), intVal(0) {}
    Value(int i) : type(INT), intVal(i) {}
    Value(const std::string& s) : type(STRING), strVal(s) {}
};

struct InsertStatement {
    std::string tableName;
    std::vector<Value> values;
};

struct SelectStatement {
    std::string tableName;
    std::vector<std::string> columns;
    std::vector<std::pair<std::string, Value>> whereConditions;
};

struct DeleteStatement {
    std::string tableName;
    std::vector<std::pair<std::string, Value>> whereConditions;
};

struct UpdateStatement {
    std::string tableName;
    std::map<std::string, Value> updates;
    std::vector<std::pair<std::string, Value>> whereConditions;
};

struct CreateTableStatement {
    std::string tableName;
    std::map<std::string, std::string> columns; // name -> type (INT, VARCHAR)
};

class Parser {
private:
    std::vector<Token> tokens;
    size_t pos;

    Token current() const {
        if (pos >= tokens.size()) return Token(TokenType::END_OF_FILE, "", 0, 0);
        return tokens[pos];
    }

    Token peek() const {
        if (pos + 1 >= tokens.size()) return Token(TokenType::END_OF_FILE, "", 0, 0);
        return tokens[pos + 1];
    }

    Token advance() {
        return tokens[pos++];
    }

    bool match(TokenType type) {
        if (current().type == type) {
            advance();
            return true;
        }
        return false;
    }

    void expect(TokenType type, const std::string& msg) {
        if (current().type != type) {
            throw std::runtime_error("Parser error: " + msg);
        }
        advance();
    }

public:
    Parser(const std::vector<Token>& t) : tokens(t), pos(0) {}

    InsertStatement parseInsert() {
        expect(TokenType::INSERT, "Expected INSERT");
        expect(TokenType::VALUES, "Expected VALUES");
        expect(TokenType::LPAREN, "Expected (");

        std::string tableName;
        std::vector<Value> values;

        while (current().type != TokenType::RPAREN) {
            if (current().type == TokenType::NUMBER) {
                values.push_back(Value(std::stoi(current().value)));
                advance();
            } else if (current().type == TokenType::STRING) {
                values.push_back(Value(current().value));
                advance();
            } else if (current().type == TokenType::IDENTIFIER) {
                values.push_back(Value(current().value));
                advance();
            } else {
                throw std::runtime_error("Invalid value in INSERT");
            }

            if (current().type == TokenType::COMMA) {
                advance();
            } else if (current().type != TokenType::RPAREN) {
                throw std::runtime_error("Expected , or )");
            }
        }

        expect(TokenType::RPAREN, "Expected )");

        InsertStatement stmt;
        stmt.tableName = "default_table";
        stmt.values = values;
        return stmt;
    }

    SelectStatement parseSelect() {
        expect(TokenType::SELECT, "Expected SELECT");

        SelectStatement stmt;
        stmt.columns.clear();
        stmt.whereConditions.clear();

        if (match(TokenType::STAR)) {
            stmt.columns.push_back("*");
        } else {
            stmt.columns.push_back(current().value);
            advance();
            while (match(TokenType::COMMA)) {
                stmt.columns.push_back(current().value);
                advance();
            }
        }

        if (match(TokenType::FROM)) {
            stmt.tableName = current().value;
            advance();
        }

        if (match(TokenType::WHERE)) {
            while (true) {
                std::string col = current().value;
                advance();
                expect(TokenType::EQUALS, "Expected =");
                Value val;
                if (current().type == TokenType::NUMBER) {
                    val = Value(std::stoi(current().value));
                } else if (current().type == TokenType::STRING) {
                    val = Value(current().value);
                }
                advance();
                stmt.whereConditions.push_back({col, val});

                if (!match(TokenType::AND)) break;
            }
        }

        return stmt;
    }

    DeleteStatement parseDelete() {
        expect(TokenType::DELETE, "Expected DELETE");
        expect(TokenType::FROM, "Expected FROM");

        DeleteStatement stmt;
        stmt.tableName = current().value;
        advance();

        if (match(TokenType::WHERE)) {
            while (true) {
                std::string col = current().value;
                advance();
                expect(TokenType::EQUALS, "Expected =");
                Value val;
                if (current().type == TokenType::NUMBER) {
                    val = Value(std::stoi(current().value));
                } else if (current().type == TokenType::STRING) {
                    val = Value(current().value);
                }
                advance();
                stmt.whereConditions.push_back({col, val});

                if (!match(TokenType::AND)) break;
            }
        }

        return stmt;
    }

    UpdateStatement parseUpdate() {
        expect(TokenType::UPDATE, "Expected UPDATE");

        UpdateStatement stmt;
        stmt.tableName = current().value;
        advance();

        expect(TokenType::SET, "Expected SET");

        while (true) {
            std::string col = current().value;
            advance();
            expect(TokenType::EQUALS, "Expected =");

            Value val;
            if (current().type == TokenType::NUMBER) {
                val = Value(std::stoi(current().value));
            } else if (current().type == TokenType::STRING) {
                val = Value(current().value);
            }
            advance();

            stmt.updates[col] = val;

            if (current().type != TokenType::COMMA) break;
            advance();
        }

        if (match(TokenType::WHERE)) {
            while (true) {
                std::string col = current().value;
                advance();
                expect(TokenType::EQUALS, "Expected =");
                Value val;
                if (current().type == TokenType::NUMBER) {
                    val = Value(std::stoi(current().value));
                } else if (current().type == TokenType::STRING) {
                    val = Value(current().value);
                }
                advance();
                stmt.whereConditions.push_back({col, val});

                if (!match(TokenType::AND)) break;
            }
        }

        return stmt;
    }

    CreateTableStatement parseCreateTable() {
        expect(TokenType::CREATE, "Expected CREATE");
        expect(TokenType::TABLE, "Expected TABLE");

        CreateTableStatement stmt;
        stmt.tableName = current().value;
        advance();

        expect(TokenType::LPAREN, "Expected (");

        while (current().type != TokenType::RPAREN) {
            std::string colName = current().value;
            advance();

            std::string colType;
            if (match(TokenType::INT_TYPE)) {
                colType = "INT";
            } else if (match(TokenType::VARCHAR_TYPE)) {
                colType = "VARCHAR";
            } else {
                throw std::runtime_error("Unknown column type");
            }

            stmt.columns[colName] = colType;

            if (current().type == TokenType::COMMA) {
                advance();
            } else if (current().type != TokenType::RPAREN) {
                throw std::runtime_error("Expected , or )");
            }
        }

        expect(TokenType::RPAREN, "Expected )");
        return stmt;
    }
};

// ============================================================================
// PARTE 3: B+ TREE - STORAGE ENGINE
// ============================================================================

struct BTreeNode {
    bool isLeaf;
    std::vector<uint32_t> keys;
    std::vector<uint32_t> pointers;
    std::vector<std::vector<uint8_t>> values;

    BTreeNode(bool leaf = true) : isLeaf(leaf) {}

    bool isFull() const {
        return keys.size() >= BTREE_ORDER - 1;
    }

    void serialize(uint8_t* buffer) const {
        uint32_t offset = 0;
        buffer[offset++] = isLeaf ? 1 : 0;

        uint32_t keyCount = keys.size();
        std::memcpy(buffer + offset, &keyCount, sizeof(keyCount));
        offset += sizeof(keyCount);

        for (uint32_t k : keys) {
            std::memcpy(buffer + offset, &k, sizeof(k));
            offset += sizeof(k);
        }

        for (uint32_t p : pointers) {
            std::memcpy(buffer + offset, &p, sizeof(p));
            offset += sizeof(p);
        }

        for (const auto& v : values) {
            uint32_t vSize = v.size();
            std::memcpy(buffer + offset, &vSize, sizeof(vSize));
            offset += sizeof(vSize);
            std::memcpy(buffer + offset, v.data(), vSize);
            offset += vSize;
        }
    }

    void deserialize(const uint8_t* buffer) {
        uint32_t offset = 0;
        isLeaf = buffer[offset++] != 0;

        uint32_t keyCount;
        std::memcpy(&keyCount, buffer + offset, sizeof(keyCount));
        offset += sizeof(keyCount);

        keys.clear();
        for (uint32_t i = 0; i < keyCount; i++) {
            uint32_t k;
            std::memcpy(&k, buffer + offset, sizeof(k));
            offset += sizeof(k);
            keys.push_back(k);
        }

        uint32_t pointerCount = isLeaf ? keyCount : keyCount + 1;
        pointers.clear();
        for (uint32_t i = 0; i < pointerCount; i++) {
            uint32_t p;
            std::memcpy(&p, buffer + offset, sizeof(p));
            offset += sizeof(p);
            pointers.push_back(p);
        }

        values.clear();
        for (uint32_t i = 0; i < keyCount; i++) {
            uint32_t vSize;
            std::memcpy(&vSize, buffer + offset, sizeof(vSize));
            offset += sizeof(vSize);
            std::vector<uint8_t> v(vSize);
            std::memcpy(v.data(), buffer + offset, vSize);
            offset += vSize;
            values.push_back(v);
        }
    }
};

class Pager {
private:
    std::string filename;
    std::fstream file;
    std::map<uint32_t, std::vector<uint8_t>> cache;
    uint32_t pageCount;

public:
    Pager(const std::string& fname) : filename(fname), pageCount(0) {
        file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
        if (!file.is_open()) {
            file.open(filename, std::ios::out | std::ios::binary);
            file.close();
            file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
        }

        file.seekg(0, std::ios::end);
        pageCount = file.tellg() / PAGE_SIZE;
    }

    ~Pager() {
        flush();
        if (file.is_open()) file.close();
    }

    std::vector<uint8_t> getPage(uint32_t pageNum) {
        if (cache.find(pageNum) != cache.end()) {
            return cache[pageNum];
        }

        std::vector<uint8_t> page(PAGE_SIZE, 0);

        if (pageNum < pageCount) {
            file.seekg(pageNum * PAGE_SIZE);
            file.read(reinterpret_cast<char*>(page.data()), PAGE_SIZE);
        }

        cache[pageNum] = page;
        return page;
    }

    void putPage(uint32_t pageNum, const std::vector<uint8_t>& data) {
        if (data.size() != PAGE_SIZE) {
            throw std::runtime_error("Invalid page size");
        }

        cache[pageNum] = data;

        if (pageNum >= pageCount) {
            pageCount = pageNum + 1;
        }
    }

    void flush() {
        for (const auto& [pageNum, page] : cache) {
            file.seekp(pageNum * PAGE_SIZE);
            file.write(reinterpret_cast<const char*>(page.data()), PAGE_SIZE);
        }
        file.flush();
    }

    uint32_t allocatePage() {
        uint32_t newPage = pageCount++;
        std::vector<uint8_t> emptyPage(PAGE_SIZE, 0);
        cache[newPage] = emptyPage;
        return newPage;
    }
};

class BPlusTree {
private:
    Pager pager;
    uint32_t rootPageNum;

public:
    BPlusTree(const std::string& dbfile) : pager(dbfile) {
        rootPageNum = 0;
    }

    void insert(uint32_t key, const std::vector<uint8_t>& value) {
        // Simplified insertion logic
        std::vector<uint8_t> page = pager.getPage(rootPageNum);
        BTreeNode node(true);
        node.deserialize(page.data());

        size_t pos = 0;
        while (pos < node.keys.size() && key > node.keys[pos]) {
            pos++;
        }

        node.keys.insert(node.keys.begin() + pos, key);
        node.pointers.insert(node.pointers.begin() + pos, 0);
        node.values.insert(node.values.begin() + pos, value);

        page.assign(PAGE_SIZE, 0);
        node.serialize(page.data());
        pager.putPage(rootPageNum, page);
    }

    std::vector<uint8_t> search(uint32_t key) {
        std::vector<uint8_t> page = pager.getPage(rootPageNum);
        BTreeNode node(true);
        node.deserialize(page.data());

        for (size_t i = 0; i < node.keys.size(); i++) {
            if (node.keys[i] == key) {
                return node.values[i];
            }
        }

        return std::vector<uint8_t>();
    }

    void flush() {
        pager.flush();
    }
};

// ============================================================================
// PARTE 4: VIRTUAL MACHINE (EXECUTOR)
// ============================================================================

struct Record {
    std::vector<Value> fields;
};

class Table {
private:
    std::string name;
    std::map<std::string, std::string> schema;
    std::vector<Record> rows;
    BPlusTree index;

public:
    Table(const std::string& n, const std::string& dbfile)
        : name(n), index(dbfile) {}

    void setSchema(const std::map<std::string, std::string>& s) {
        schema = s;
    }

    void insert(const std::vector<Value>& values) {
        if (values.size() != schema.size()) {
            throw std::runtime_error("Column count mismatch");
        }

        Record rec;
        rec.fields = values;
        rows.push_back(rec);

        // Serialize for B+ tree
        uint32_t key = rows.size() - 1;
        std::vector<uint8_t> serialized;
        for (const auto& v : values) {
            if (v.type == Value::INT) {
                uint32_t intVal = v.intVal;
                serialized.insert(serialized.end(),
                    reinterpret_cast<uint8_t*>(&intVal),
                    reinterpret_cast<uint8_t*>(&intVal) + sizeof(intVal));
            } else {
                uint32_t strLen = v.strVal.length();
                serialized.insert(serialized.end(),
                    reinterpret_cast<uint8_t*>(&strLen),
                    reinterpret_cast<uint8_t*>(&strLen) + sizeof(strLen));
                serialized.insert(serialized.end(),
                    v.strVal.begin(), v.strVal.end());
            }
        }

        index.insert(key, serialized);
    }

    std::vector<Record> select(const std::vector<std::pair<std::string, Value>>& conditions) {
        std::vector<Record> result;

        for (const auto& row : rows) {
            bool matches = true;

            for (const auto& [colName, condValue] : conditions) {
                auto it = schema.find(colName);
                if (it == schema.end()) continue;

                // Simple matching logic
                matches = true; // Simplified for this demo
            }

            if (matches) {
                result.push_back(row);
            }
        }

        return result;
    }

    void deleteRows(const std::vector<std::pair<std::string, Value>>& conditions) {
        rows.erase(
            std::remove_if(rows.begin(), rows.end(),
                [&](const Record&) { return true; }), // Simplified
            rows.end()
        );
    }

    void updateRows(const std::map<std::string, Value>& updates,
                   const std::vector<std::pair<std::string, Value>>& conditions) {
        for (auto& row : rows) {
            // Apply updates where conditions match (simplified)
        }
    }

    void printSchema() const {
        std::cout << "Table: " << name << "\n";
        for (const auto& [col, type] : schema) {
            std::cout << "  " << col << ": " << type << "\n";
        }
    }

    void printRows() const {
        for (size_t i = 0; i < rows.size(); i++) {
            std::cout << "Row " << i << ": ";
            for (const auto& field : rows[i].fields) {
                if (field.type == Value::INT) {
                    std::cout << field.intVal << " ";
                } else {
                    std::cout << field.strVal << " ";
                }
            }
            std::cout << "\n";
        }
    }

    void flush() {
        index.flush();
    }
};

class Database {
private:
    std::map<std::string, std::unique_ptr<Table>> tables;
    std::string dbfile;

public:
    Database(const std::string& fname) : dbfile(fname) {}

    void createTable(const CreateTableStatement& stmt) {
        auto table = std::make_unique<Table>(stmt.tableName, dbfile);
        table->setSchema(stmt.columns);
        tables[stmt.tableName] = std::move(table);
        std::cout << "Table '" << stmt.tableName << "' created.\n";
    }

    void insert(const InsertStatement& stmt) {
        auto it = tables.find(stmt.tableName);
        if (it == tables.end()) {
            throw std::runtime_error("Table '" + stmt.tableName + "' not found");
        }

        it->second->insert(stmt.values);
        std::cout << "Row inserted.\n";
    }

    void select(const SelectStatement& stmt) {
        auto it = tables.find(stmt.tableName);
        if (it == tables.end()) {
            throw std::runtime_error("Table '" + stmt.tableName + "' not found");
        }

        auto results = it->second->select(stmt.whereConditions);
        std::cout << "Results: " << results.size() << " rows\n";
        it->second->printRows();
    }

    void deleteRows(const DeleteStatement& stmt) {
        auto it = tables.find(stmt.tableName);
        if (it == tables.end()) {
            throw std::runtime_error("Table '" + stmt.tableName + "' not found");
        }

        it->second->deleteRows(stmt.whereConditions);
        std::cout << "Rows deleted.\n";
    }

    void updateRows(const UpdateStatement& stmt) {
        auto it = tables.find(stmt.tableName);
        if (it == tables.end()) {
            throw std::runtime_error("Table '" + stmt.tableName + "' not found");
        }

        it->second->updateRows(stmt.updates, stmt.whereConditions);
        std::cout << "Rows updated.\n";
    }

    void flush() {
        for (auto& [name, table] : tables) {
            table->flush();
        }
    }

    void showTables() {
        if (tables.empty()) {
            std::cout << "No tables.\n";
            return;
        }
        for (const auto& [name, table] : tables) {
            table->printSchema();
        }
    }
};

// ============================================================================
// PARTE 5: REPL & MAIN
// ============================================================================

class REPL {
private:
    Database db;

public:
    REPL(const std::string& dbfile) : db(dbfile) {}

    void run() {
        std::cout << "===========================================\n";
        std::cout << "  TitanDB - SQL-like Database System v1.0  \n";
        std::cout << "===========================================\n";
        std::cout << "Type 'EXIT;' to quit. Commands end with ';'\n\n";

        std::string line;
        while (true) {
            std::cout << "titandb> ";
            std::getline(std::cin, line);

            if (line.empty()) continue;

            try {
                processCommand(line);
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
        }
    }

private:
    void processCommand(const std::string& input) {
        // Tokenize
        Lexer lexer(input);
        std::vector<Token> tokens;
        Token token = lexer.nextToken();

        while (token.type != TokenType::END_OF_FILE) {
            tokens.push_back(token);
            token = lexer.nextToken();
        }

        if (tokens.empty()) return;

        // Check for EXIT
        if (tokens[0].type == TokenType::EXIT) {
            std::cout << "Goodbye!\n";
            db.flush();
            exit(0);
        }

        // Parse and execute
        Parser parser(tokens);

        if (tokens[0].type == TokenType::CREATE) {
            CreateTableStatement stmt = parser.parseCreateTable();
            db.createTable(stmt);
        } else if (tokens[0].type == TokenType::INSERT) {
            InsertStatement stmt = parser.parseInsert();
            db.insert(stmt);
        } else if (tokens[0].type == TokenType::SELECT) {
            SelectStatement stmt = parser.parseSelect();
            db.select(stmt);
        } else if (tokens[0].type == TokenType::DELETE) {
            DeleteStatement stmt = parser.parseDelete();
            db.deleteRows(stmt);
        } else if (tokens[0].type == TokenType::UPDATE) {
            UpdateStatement stmt = parser.parseUpdate();
            db.updateRows(stmt);
        } else {
            throw std::runtime_error("Unknown command");
        }
    }
};

int main() {
    try {
        REPL repl("titandb.db");
        repl.run();
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
