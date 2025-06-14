#include <cstdarg>
#include <iostream>

void printAll(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int val = va_arg(args, int);
        std::cout << val << " ";
    }
    va_end(args);
    std::cout << std::endl;
}

int main() {
    printAll(4, 10, 20, 30, 40);
}
