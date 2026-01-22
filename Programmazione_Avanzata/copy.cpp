// SHALLOW & DEEP COPY
#include <iostream>

using namespace std;


int main() {
    A a;        // A::A()
    A a2(a);    // A::A(const A&)
    a = a2;     // A& A::operator(cosnt A& a)
                // They both do a SHALLOW COPY because "a" uses the same instance as "a2"
                // So we redefine the copy constructor and =operator

    int num = 10; // LVALUE = RVALUE
                  
    // int &x = 5; // DOES NOT COMPILE
    const int &y = 6; // COMPILES
    int &&j = 7; // ?
    
    cout << &j << endl;

// --- MOVE --- //
    // T&& move(T&& arg); Returns an rvalue reference to arg.

    int n1 = 13;
    int n2 = move(++n1); // WITH ++n1, n2 = 14, WITH n1++, n2 = 13   
    n2++;
    
    cout << n1 << endl;
    cout << n2 << endl; 

    return 0;
}
// NEXT: copy.cpp
