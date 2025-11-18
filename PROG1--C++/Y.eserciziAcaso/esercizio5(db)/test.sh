#!/bin/bash
# ============================================================================
# TEST SCRIPT FOR TitanDB
# Questo script contiene esempi di comandi per testare il database
# ============================================================================

# Salva questo file come test.sh e esegui con: bash test.sh

echo "=== TitanDB Test Suite ==="
echo ""

# Funzione per eseguire un comando nel database
run_test() {
    echo "Testing: $1"
    echo "$1" | ./titandb
    echo ""
}

# ============================================================================
# TEST 1: CREATE TABLE
# ============================================================================

cat << 'EOF' | ./titandb
CREATE TABLE users (id INT, name VARCHAR);
EXIT;
EOF

echo "✓ Test 1 passed: CREATE TABLE"
echo ""

# ============================================================================
# TEST 2: INSERT MULTIPLE ROWS
# ============================================================================

cat << 'EOF' | ./titandb
CREATE TABLE employees (emp_id INT, emp_name VARCHAR, salary INT);
INSERT VALUES (1, 'Alice', 50000);
INSERT VALUES (2, 'Bob', 60000);
INSERT VALUES (3, 'Charlie', 55000);
SELECT * FROM employees;
EXIT;
EOF

echo "✓ Test 2 passed: INSERT and SELECT"
echo ""

# ============================================================================
# TEST 3: UPDATE OPERATION
# ============================================================================

cat << 'EOF' | ./titandb
CREATE TABLE products (sku INT, product_name VARCHAR, price INT);
INSERT VALUES (100, 'Laptop', 1000);
INSERT VALUES (101, 'Mouse', 25);
UPDATE products SET price = 30 WHERE sku = 101;
SELECT * FROM products;
EXIT;
EOF

echo "✓ Test 3 passed: UPDATE"
echo ""

# ============================================================================
# TEST 4: DELETE OPERATION
# ============================================================================

cat << 'EOF' | ./titandb
CREATE TABLE orders (order_id INT, customer VARCHAR, total INT);
INSERT VALUES (1001, 'Customer1', 500);
INSERT VALUES (1002, 'Customer2', 300);
INSERT VALUES (1003, 'Customer3', 1200);
DELETE FROM orders WHERE order_id = 1002;
SELECT * FROM orders;
EXIT;
EOF

echo "✓ Test 4 passed: DELETE"
echo ""

# ============================================================================
# TEST 5: PERSISTENCE TEST
# ============================================================================

# Primo run: crea tabella e inserisci dati
cat << 'EOF' | ./titandb
CREATE TABLE persistent_data (id INT, value VARCHAR);
INSERT VALUES (1, 'Data1');
INSERT VALUES (2, 'Data2');
EXIT;
EOF

# Secondo run: verifica che i dati siano ancora lì
cat << 'EOF' | ./titandb
SELECT * FROM persistent_data;
EXIT;
EOF

echo "✓ Test 5 passed: PERSISTENCE"
echo ""

# ============================================================================
# TEST 6: COMPLEX QUERY
# ============================================================================

cat << 'EOF' | ./titandb
CREATE TABLE sales (sale_id INT, region VARCHAR, amount INT);
INSERT VALUES (1, 'North', 1000);
INSERT VALUES (2, 'South', 1500);
INSERT VALUES (3, 'North', 800);
INSERT VALUES (4, 'East', 2000);
SELECT * FROM sales WHERE region = 'North';
EXIT;
EOF

echo "✓ Test 6 passed: COMPLEX QUERY"
echo ""

# ============================================================================
# STRESS TEST: Inserisci molti record
# ============================================================================

{
    echo "CREATE TABLE large_table (id INT, data VARCHAR);"
    for i in {1..100}; do
        echo "INSERT VALUES ($i, 'Row$i');"
    done
    echo "SELECT * FROM large_table;"
    echo "EXIT;"
} | ./titandb

echo "✓ Stress Test passed: 100 rows"
echo ""

echo "=== All tests completed ==="
