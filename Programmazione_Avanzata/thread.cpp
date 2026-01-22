#include <thread>
#include <atomic>
#include <mutex>

using namespace std;

// DATA RACE
static int shared = 0;
void f1() {
    num -= 1;
} 
void f2() {
    num += 1; 
}

// Use of ATOMIC
static atomic<int> shared_atomic(0);
void f1_a() {
    shared_atomic += 1;
}
void f2_a() {
    shared_atomic -= 1;
}

// Define MUTEX
mutex mtx;

void f1_mtx() {
    mtx.lock();
    shared += 1;
    mtx.unlock();
}
void f2_mtx() {
    mtx.lock();
    condivisa -= 1;
    mtx.unlock();
}

void ft() {
    const lock_guard(mutex) lock(mtx);
    shared ++;
    // mtx gets realeased when lock gets out of scope (function ends)
}

int main() {
    thread t1(f1, 1);
    thread t2(f2, 1);
    
    t1.join();
    t2.join();

    // --- DATA RACE SOLUTIONS --- //
    // 1. ATOMIC: make operation atomic on a certain variable 
    thread t1_a(f1_a);
    thread t2_a(f2_a);

    t1_a.join();
    t2_a.join();

    // 2. MUTEX: define critical sections as exclusive pieces of code using mutexes
    thread t1_mtx(f1_mtx);
    thread t2_mtx(f2_mtx);

    thread t3_lock_guard_mtx(ft);

    t1_mtx.join();
    t2_mtx.join();
    t3_lock_guard_mtx.join();
}
