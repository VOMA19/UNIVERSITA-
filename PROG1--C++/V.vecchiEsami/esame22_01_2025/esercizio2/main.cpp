#include <iostream>
#include <cstring>

struct Key {
    int size;
    char *data;
};

const char data[][10] = {
    "0abc",
    "1def",
    "2ghi",
    "3jkl",
    "4mno",
    "5pqrs",
    "6tuv",
    "7wxyz",
    "8 .,@*=+-",
    "9"
};

// Inserire qui sotto la dichiarazione della funzione decode 
void decode(const char* str, int size, Key keyboard[]);
// Inserire qui sopra la dichiarazione della funzione decode 


int main(int argc, char **argv){

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <string to decode>" << std::endl;
        return 1;
    }
    int size = strlen(argv[1]);
    for (int i = 0; i < size; i++)
    {
        if (argv[1][i] != ' ' && (argv[1][i] < '0' || argv[1][i] > '9')) {
            std::cerr << "Invalid character: " << argv[1][i] << std::endl;
            return 1;
        }
    }
    
    Key keyboard[10];
    // Populate the keyboard array
    for (int i = 0; i < 10; i++) {
        keyboard[i].size = strlen(data[i]);
        keyboard[i].data = new char[keyboard[i].size];
        strncpy(keyboard[i].data, data[i], keyboard[i].size);
    }

    std::cout << "Decoding string: \"" << argv[1] << "\"" << std::endl;
    std::cout << "Decoded string: \"";
    decode(argv[1], size, keyboard);
    std::cout << "\"" << std::endl;

    // Deallocate the memory
    for (int i = 0; i < 10; i++) {
        delete[] keyboard[i].data;
    }
}

// Inserire qui sotto la definizione della funzione decode
void decode(const char* str, int size, Key keyboard[]) {
    for (int index = 0; index < size; ) {
        if (str[index] == ' ') {
            std::cout << ' ';
            index++;
        } else {
            int digit = str[index] - '0';
            int count = 1;
            
            while (index + count < size && str[index + count] == str[index]) {
                count++;
            }
            
            if (count <= keyboard[digit].size) {
                std::cout << keyboard[digit].data[count - 1];
            }
            
            index += count;
        }
    }
}
// Inserire qui sopra la definizione della funzione decode
