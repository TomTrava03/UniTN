// STL: Standard Template Library
#include <cstdlib>

#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b; // DESCENDING
}

int main() {
// --- LIST --- // 
    list<int> l(10); // then elements 

    l.push_front(1);
    l.push_back(1);

    l.pop_front();
    l.pop_back();

    int front = l.front();  // PEEK FRONT
    int back = l.back();    // PEEK BACK
    // ITERATE
    for(int el : l) {
        cout << el;
    }

    list<int>::iterator it;
    for(it = l.begin(); it != l.end(); it++) {
        cout << *it;
    }
// --- GENERAL FUNCTIONS ---
    // IOTA - <algorithm>
    // Initialize the structure using incremental(+1) num from STARTING VALUE 
    iota(l, l+10, 10); // (FIRST POSITION, LAST POSITION, STARTING VALUE) 
                       
    // TRANSFORM



// --- SET --- //
    set<int> s;
    multiset<int> ms; // ORDERED SET and DUPLICATE VALUES ACCEPTED

    s.insert(1);
    if(s.contains(1)) { 
        cout << "CONTAINS!";
    }
    cout << s.empty(); // is empty ?
    cout << s.size();

// --- MAP --- //
    map<int, int> m;
    multimap<int> mm;

    list<multiset<int>> lms;
    list<multimap<int>> lmm;

// --- BITSET --- //
    bitset<64> bs; // array of bits (physical bits)
    
    string s = "01010100101011110010101";
    b = bitset<64>(s);

    bs.flip(); // flip bits

// --- ALGORITHM --- //
    // using a "function template" 
    vector<int> v = {5, 2, 9, 1, 3};

    sort(v.begin(), v.end());
    sort(v.begin(), v.end(), compare);

    reverse(v.begin(), v.end());

    int el = 2;
    auto it = find(v.begin(), v.end(), el);
    if(it != v.end()) cout << "Found" << endl;

    // USING LAMBDAS
    sort(v.begin(), v.end(),
        [](int a, int b) {
            return a < b; // ASCENDING 
        } 
    );
}

