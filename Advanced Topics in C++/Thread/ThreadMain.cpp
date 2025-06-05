#include <iostream>
#include <thread>

using namespace std;

void say_hello() {
    cout << "Hello from thread!\n";
}
void say_hello2() {
    cout << "Hello from thread 2!\n";
}
void say_hello3() {
    cout << "Hello from thread 3!\n";
}
void say_hello4() {
    cout << "Hello from thread 4!\n";
}

int main() {
    thread t(say_hello);
    thread t2(say_hello2); 
    thread t3(say_hello3); 
    thread t4(say_hello4); 
    t.join(); 
    t2.join(); 
    t3.join();                 
    t4.join(); 
    cout << "Hello from main!\n";
    return 0;
}
