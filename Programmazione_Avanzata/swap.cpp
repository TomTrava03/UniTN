// OVERLOADING of SWAP method 
// Same method name. different parameters
void swap(int &f, int &s) { // 1
    int tmp = f;
    f = s;
    s = string;
}

void swap(string &f, string &s) { // 2
    string tmp = f;
    f = s;
    s = tmp;
}

// void *swap
void swap(void* &f, void* &s) { // 3
    void* tmp = f;
    f = s;
    s = f;
}

// using generics/template
template <class T>
void swap(T &f, T &s) { // 4
    T tmp = f;
    f = s;
    s = tmp;
}

int main {              
    int x, y;
    swap(x, y); // 1 OR 4
    cout << x << " " << y;

    string a, b;
    swap(a, b); // 2 OR 4
    cout << a << " " << b;
    // void* usage
    void *a;
    void *b;
    a = new string("a");
    b = new string("b");
    swap(a, b); // 3
    cout << *((string *)a) << " " << *((string *)b); // C-style casting
    cout << *(static_cast<string *>(a)) << " " << *(static_cast<string *>(b)); // static casting

    a = new int(1);
    b = new int(2);
    swap(a, b); // also 3
    cout << *((int *)a) << " " << *((int *)b); // C-style casting
    cout << *(static_cast<int *>(a)) << " " << *(static_cast<int *>(b)); // static casting
    
}

