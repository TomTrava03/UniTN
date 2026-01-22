#include <iostream>

using namespace std;

int main() {
    try {
        // ...
        throw error("error");
    } catch (error e) {
        cout << e.what() << endl;
    } catch(...) { // ANY TYPE of EXCEPTIONS
        cout << "Something went wrong!" << endl;
    }

    /*COMMON COMPILE-TIME ERRORS
     *  MISSING SEMICOLON/SYNTAX
     *  UNDECLARED VARIABLES
     *  MISMATCHED TYPES
     */
    /*COMMON RUN-TIME ERRORS
     *  DIVIDE BY ZERO
     *  ARRAY OUT OF BOUNDS
     *  DANGLING POINTER
     */

    return 0;
}
