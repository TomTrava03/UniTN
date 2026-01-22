// REDEFINING OPERATORS
class A {
    int i;
    public:
        A(int _i) {
            i = _i;
        }
        A operator+(const A&); // operator= can ONLY be redefined like this
                               
        
};

A A::operator+(const A& _a) { // method
    return A(i + _a.i);
}

A& A::operator++();     // prefix : ++i
A A::operator++(int);   // postfix : i++


class B {
    int i;
    public:
        B(int _i) {
            i = _i;
        }
        friend B operator+(const B&, const B&); // FRIEND : NOT a definition, but lets the function access PRIVATE varibles/methods, like "i"
}
 
B operator+(const B& _x, const B& _y) { // function
    return B(_x.i + _y.i);
}

int main() {
    A a1(1), a2(2);
    a1 = 2 + a2; // ERROR
    
    B b1(1), b2(2);
    b2 = 2 + b2; // COMPILES THX TO 2 -> A(2)
}
