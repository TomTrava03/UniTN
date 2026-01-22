// POINTERS
#include <iostream>

using namespace std;

double f1(int n, double d) {
    return n*d;
}

int main() {
    int num = 1;
    int *p = &num; // POINTER(*) = REFERENCE(&)VALUE(num)
    int **pp = &p; // POINTER OF POINTER

    cout << *p; // 1
    cout << **p;

    // POINTER TO FUNCTIONs
    double f2(int n, double d); // FUNCTION
    double (*pFun);
    pFun = f1; // OR &f
    pFun = f2;

    cout << (*pFun)(3, 2.0) << endl;
    return 0;
}
// NEXT: copy.cpp
