// 1.  ############################################################################################# 

// O(n^2)
// divide-and-conquer method for multiplying large numbers
bool karatsuba(bool X[], bool Y[], int len) {
    if(n == 1) {
        return X[0] * Y[0];
    } else {
        bool a[len/2], b[len/2]; // DIVIDE Y into a and b
        bool c[len/2], d[len/2]; // DIVIDE X into c and d

        bool *A1 = karatsuba(a, b, len/2);
        bool *A3 = karatsuba(b, d, len/2);
        bool *m = karatsuba(Y, X, len/2);
        bool *A2 = m - A1 - A3;
    
        return A1 * pow(2, n) + A2 * pow(2, n/2) + A3;
    }
}

// O(n^2)
void selection_sort(int A[], int n) {
    for(int i = 0; i < n-2; i++) {
        int min = min(A, i, n-1);
        A[i], A[min] = A[min], A[i]; // swap A[i] with A[min]
    }
}
int min(int A[], int start, int end) { // return min index
    int min = start;
    for(int j = start+1; j < end; j++) {
        if(A[j] < A[min]) { // found new min
            min = j;
        }
    }
}

void insert_sort(int A[], int n) {
    for(int i = 0; i < n-1; i++) {
        int temp = A[i];
        int j = i;
        while(j > 0 && A[j-1] > temp) {
            A[j] = A[j-1];
            j = j - 1; 
        }
        A[j] = temp;
    }
}

// 2.  #############################################################################################

// O(n)
int max_sum(int A[], int n) {
    int maxSoFar = 0;
    int maxHere = 0;
    for(int i = 0; i < n; i++) {
        maxHere = max(maxHere+A[i], 0);
        maxSoFar = max(maxSoFar, maxHere);
    }
    return maxSoFar;
}

// 3.  #############################################################################################



// 4.  #############################################################################################

void increment(int A[], int k) {
    int i = 0;
    while(i < k && A[i]==1) {
        
    }
}
// 6.  #############################################################################################
// TREEs

struct Tree {
    int value;
    Tree *left;
    Tree *right;
} t;

void DFS(Tree *t) { // Depth-First Search
    if(t != NULL) {
        printf("%d", t->value); // PRE-ORDER: root -> left -> right
        
        DFS(t->left);
        printf("%d", t->value); // IN-ORDER: left -> root -> right

        DEF(t->right);
        printf("%d", t->value); // POST-ORDER: left -> right -> root
    }
}

int count_nodes(Tree *t) {
    if(t == NULL) {
        return 0;
    }
    int Cl = count_nodes(t->left);
    int Cr = count_nodes(t->right);
    return Cl + Cr + 1;
}

void BFS(Tree *t) {
    Queue Q = Queue();
    Q->enqueue(t);
    while(!Q.is_empty()) {
        Tree *u = Q->dequeue();
        printf("%d", u->value); // visit tree by levels
        u = u->leftmost_child();
        while(u != NULL) {
            Q->enqueue(u);
            u = u->right;
        }
    }
}

// 17. #############################################################################################



// 23. #############################################################################################

// O(n+k)
void counting_sort(int A[], int n, int k) {
    int B[k]; // counts every time a num from 1 to k is in A
    for(int i = 0; i < k; i++) {
        B[i] = 0;
    }
    for(int j = 1; j < n; j++) {
        B[A[j]] = B[A[j]] + 1;
    }
    j = 1;
    for(int i =  1; i < k; i++) {
        while(B[i] > 0) {
            A[j] = i;
            j = j + 1;
            B[i] = B[i] - 1;
        }
    }
}
