#include <iostream>
using namespace std;


int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int divs(int a, int b) {
    return a / b;
}

void operate(int x, int y, int (*func)(int, int)) {
    cout << "Result: " << func(x, y) << endl;
}

int main() {
    operate(3, 4, mul); 
    operate(3, 4, add); 
    operate(3, 4, sub); 
    operate(3, 4, divs); 
    return 0;
}
