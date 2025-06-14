#include <iostream>
using namespace std;

void doSomething(int a, int b, auto func) {
    cout << "Result: " << func(a, b) << endl;
}

int main() {
    doSomething(10, 5, [](int x, int y) { return x - y; });
    return 0;
}
