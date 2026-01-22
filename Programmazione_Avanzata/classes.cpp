// SUPERCLASS a.h
#ifndef CLASS_A
#define CLASS_A

#include <string>;

#include <iostream>
using namespace std;

class A {
    int i; // private
    public:
        A(); // definition
        explicit A(int _i);
        A(const A& _a);
        A& operator=(const A& _a);
        virtual ~A();
        int get_i() const;

        // Redefining operators
        // Method
        ostream& operator=(ostream &os, const A& a) {
            return os;
        }
        // Function
        friend A operator+(const A&);
};


#endif

// SUBCLASS b.h
#ifndef CLASS_B
#define CLASS_B

#include <iostream>
using namespace std;

class B: public A { // inheritance
    string s; // private
    public: 
        B();
        B(int _i, string _s);
        ~();
        string get_s();
};
#endif

//a.cpp
#include "a.h"
A::A() { // declaration
    i = 0;
}
A::A(int _i) {
    i = _i;
}
A::A(const A& _a) {
    i = _a.i; // can access "i" directly because A == typeof(_a)
}
int A::get_i() const {
    return i;
}
A& A::operator+() {
    
}

// PURELY VIRTUAL CLASS
// Has at least 1 purely virtual method
class V {
    virtual int method()=0; // =0 !IMPORTANT
};

int main() {
    return 0;
}

