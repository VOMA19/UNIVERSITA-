
#include <iostream>
using namespace std;
//parentesizazzione perfetta in un array controllare se i caratteri parentesi sono corretti () --> ok (() --> non ok
bool controllo(char parentesi[]);
int main(){

    char parentesi[] = {'(','(',')',')',')','(','\0'};
    bool corr = controllo(parentesi);

    if(corr)
        cout << "la parentesizzazione è perfetta" <<endl;
    else
        cout << "la parentesizzazione non è perfetta" <<endl;

    return 0;
}

bool controllo(char parentesi[]){
    int cont = 0;
    int contGraffe = 0;
    int contQuad = 0;

    for (int i = 0; parentesi[i] != '\0'; i++){

        if (parentesi[i] == '(') {
            cont++;  

        }else if(parentesi[i] == ')'){
            cont--;  
            if (cont < 0) 
                return false;

        }else if(parentesi[i] == '{'){
            contGraffe ++;
        }else if (parentesi[i] == '}'){
            
            contGraffe --;
            if (contGraffe < 0) {
                
                return false;
            }
        }else if(parentesi[i] == '['){
            contQuad ++;
        }else if (parentesi[i] == ']'){
            contQuad --;
            if (contQuad < 0) {
                
                return false;
            }
        }
    }

    if(cont == 0 && contGraffe == 0 && contQuad == 0){
        return true;
    }else {
        return false;
    }

}