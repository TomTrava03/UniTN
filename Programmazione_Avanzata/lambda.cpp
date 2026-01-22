int main() {
    // LAMBDA
    // [capture] (parameters) { code };
    auto msg = []() {
        cout << "HELLO WORLD!" << endl;
    };
    msg(); // HELLO WORLD!\n

    auto add = [](int a, int b) {
        return a + b;
    };
    cout << add(1, 2) << endl; // 3
                               
    // With capture([]) we can access outside defined variables
    int num;
    auto print = [num]() {
        cout << num;
    }
}
