// TEMPLATE - <T>
// EXPRESSION ARE PROCESSED AT COMPILE TIME
using namespace std;

// EXAMPLES
template <class T1, class T2>
T1 max(T1 a, T2 b) {
    if(a > b) return a;
    else return b;
}

template <unsigned int n>
struct factorial {
    enum {
        value = n*factorial<n-1>::value;
    };
};

template <>
struct factorial<0> {
    enum {
        value = 1;
    };
};

// STRUCTURE: IF
template <bool condition, class Then, class Else> // DECLARATION
struct IF { // DEFAULT -> TRUE
    typedef Then RET;
}

template <class Then, class Else> // SPECIALIZATION (WITHOUT CONDITION, FORCED TO FALSE)
                                  // THE SPEC. CANNOT HAVE MORE TEMPLATE PARAMETERS THAN THE 
                                  // DECLARATION
struct IF<false, Then, Else> { // FALSE
    typedef Else RET;
}

// FUNCTIONs 
template <int n, template<int> class F>
struct Accumulate {
    enum {
        RET = Accumulate<n-1, F>::RET + F<n>::RET; // RECURSION
    };
};

template <template<int> class F>
struct Accumulate<0, F> { // BASE CASE (n==0)
    enum {
        RET = F<0>::RET;
    };
};

template <int n>
struct Square {
    enum {
        RET = n*n;
    };
};

int main() {
    vector<bool> vb; // space efficient
    
    cout << max(int(2), double(3.14)) << endl;
    cout << factorial<7>::value << endl;

    IF<sizeof(int) < sizeof(long), long, int>::RET i;

    // FOR EACH n CALLS Square (n^2)
    // RET = 12
    // n = 3 -> RET = acc(2, Square) : Square(3) -> 3 + 9
    // n = 2 -> RET = acc(1, Square) : Square(2) -> 1 + 2
    // n = 1 -> RET = acc(0, Square) : Square(1) -> 0 + 1
    // n = 0 -> RET = Square(0) -> 0
    cout << Accumulate<3, Square>::RET << endl; 
}
