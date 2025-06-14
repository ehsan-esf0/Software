#include <iostream>
#include <functional>

int main() {
    std::function<int(int)> factorial = [&](int n) -> int {
        if (n <= 1) return 1;
        return n * factorial(n - 1); 
    };

    std::cout << "factorial(5) = " << factorial(5) << "\n"; // خروجی: 120
}
