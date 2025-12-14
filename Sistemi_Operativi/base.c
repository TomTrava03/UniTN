// BASE
#include <stdio.h>
#include <stdlib.h>
// ADD-ONs
#include <string.h>


struct Car {} car1;  // aggregazione di diverse Variabili
typedf struct Books {} bookType;
union Result {} res1: // usare per unire piu Tipi

enum State {
    Undef = 9,
    Working = 1,
    Failed = 8
};

int func(int arg) {
    return arg * 2;
}

void main() {
    // DATA TYPEs
    bookType book1; // typedef
    enum State s = Undef;

    // PUNTATORI
    int num = 1;
    int *pNum = &num; // & indica l indirizzo di memoria della variabile
    int val = *(pNum): // = num, VALORE puntato da pNum
    // P. a FUNZIONI
    int (*pFunc) (int); // return_type (*puntatoreAFunzione) (arg_type, ...);
    pFunc = &func; // the & is optional 
    int res = pFunc(5); // 10
    
    // CONVERSIONI
    char *stringF = "3.14";
    float varF = atof(stringF); // 3,14
    char *stringI = "1";
    int varI = atoi(stringI); // 1
    int sscanf(stringI, "%d", &varI); // MIGLIORE di atoi()
    
    // ARRAY
    int arr[4] = {2, 0, 2, 5};
    char str1[4] = {'c', 'i', 'a', 'o'};
    // STRINGHE --string.h--
    char *str2 = "stringa";
} 

