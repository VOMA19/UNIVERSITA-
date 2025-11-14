#include <iostream>
#include <cstring>

struct List {
    char data;
    List *next;
};

struct Key {
    int size;
    List *data;
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
void decode(const char* str, int size, Key* keyboard);
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
    for (int i = 0; i < 10; i++)
    {
        keyboard[i].size = strlen(data[i]);
        List *tail;
        for (int j = 0; j < keyboard[i].size; j++)
        {
            if (j == 0)
            {
                keyboard[i].data = new List{data[i][j], nullptr};
                tail = keyboard[i].data;
            }
            else
            {
                tail->next = new List{data[i][j], nullptr};
                tail = tail->next;
            }
        }
    }
#if 0
    for(int i = 0; i < 10; i++) {
        List *tmp = keyboard[i].data;
        std::cout << "Keyboard " << i << ": ";
        while (tmp != nullptr) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
#endif
    std::cout << "Decoding string: \"" << argv[1] << "\"" << std::endl;
    std::cout << "Decoded string: \"";
    decode(argv[1], size, keyboard);
    std::cout << "\"" << std::endl;

    // Deallocate the memory
    for (int i = 0; i < 10; i++) {
        while(keyboard[i].data != nullptr) {
            List *tmp = keyboard[i].data;
            keyboard[i].data = keyboard[i].data->next;
            delete tmp;
        }
    }
}

// Inserire qui sotto la definizione della funzione decode
void decode(const char* str, int size, Key* keyboard) {
    for (int i = 0; i < size; i++) {
        if (str[i] == ' ') {
            continue; // Skip spaces
        }
        
        int digit = str[i] - '0';
        int count = 1;
        
        // Count consecutive occurrences of the same digit
        while (i + count < size && str[i + count] == str[i]) {
            count++;
        }
        
        // Get the character at position (count % size) in the list
        // If count % size == 0, use the last character
        int position = (count % keyboard[digit].size == 0) ? 
                    keyboard[digit].size : count % keyboard[digit].size;
        
        List* current = keyboard[digit].data;
        for (int j = 1; j < position; j++) {
            current = current->next;
        }
        
        std::cout << current->data;
        
        i += count - 1; // Skip the processed digits
    }
}
// Inserire qui sopra la definizione della funzione decode
