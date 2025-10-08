#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

bool isIsogram(const std::string& str) {
    std::unordered_set<char> seen;
    for (char c : str) {
        char lower = std::tolower(static_cast<unsigned char>(c));
        if (seen.count(lower)) {
            return false;
        }
        seen.insert(lower);
    }
    return true;
}

int main() {
    std::string test1 = "Dermatoglyphics";
    std::string test2 = "aba";
    std::string test3 = "moOse";
    std::string test4 = "";

    std::cout << std::boolalpha;
    std::cout << "\"" << test1 << "\" --> " << isIsogram(test1) << std::endl;
    std::cout << "\"" << test2 << "\" --> " << isIsogram(test2) << std::endl;
    std::cout << "\"" << test3 << "\" --> " << isIsogram(test3) << std::endl;
    std::cout << "\"" << test4 << "\" --> " << isIsogram(test4) << std::endl;

    return 0;
}