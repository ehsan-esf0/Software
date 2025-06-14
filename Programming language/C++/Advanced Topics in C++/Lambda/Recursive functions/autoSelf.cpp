#include <iostream>

int main() {
    auto factorial = [](auto self, int n) -> int {
        if (n <= 1) return 1;
        return n * self(self, n - 1);
    };

    std::cout << "factorial(5) = " << factorial(factorial, 5) << "\n";
}
