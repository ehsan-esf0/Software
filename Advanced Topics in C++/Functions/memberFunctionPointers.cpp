#include <iostream>
using namespace std;

class Calculator {
public:
    int multiply(int a, int b) {
        return a * b;
    }

    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    int divide(int a, int b) {
        return a / b;
    }
};

void operate(int x, int y, int (Calculator::*func)(int, int), Calculator& obj) {
    cout << "Result: " << (obj.*func)(x, y) << endl;
}

int main() {
    Calculator calc;
    operate(2, 3, &Calculator::multiply, calc);
    operate(2, 3, &Calculator::add, calc);
    operate(2, 3, &Calculator::subtract, calc);
    operate(2, 3, &Calculator::divide, calc);
    return 0;
}
