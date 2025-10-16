#include <iostream>
using namespace std;

void strcpy(char*  src, char* dest);
bool strcmp(char* src, char* dest);
#define N 255

char s1[N] = {'A','b','b','a','s','s','o',' ','l','e',' ','g','u','a','r','d','i','e','\0'};
char s2[N];

int main(){



    strcpy(s1, s2);  

    cout << "s2 dopo la copia: " << s2 << endl;

    if(strcmp(s1, s2))
        cout << "Confronto s1 e s3 sono uguali" <<endl;
    else 
        cout << "Confronto s1 e s3 sono diverse" <<endl;


    return 0;
}

void strcpy(char* src, char* dest){
    int i = 0;
    while (src[i] != '\0') {   
        dest[i] = src[i];      
        i++;
    }
    dest[i] = '\0';

}

bool strcmp(char* src, char* dest){

    int i = 0;
    while (src[i] != '\0' && dest[i] != '\0') {
        if (src[i] != dest[i]) 
            return false;
        i++;
    }
    
    return src[i] == dest[i];

}