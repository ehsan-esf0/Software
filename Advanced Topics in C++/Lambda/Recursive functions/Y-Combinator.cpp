#include <iostream>
#include <utility>

template<typename F>
class YCombinator {
    F f;
public:
    explicit YCombinator(F&& func) : f(std::forward<F>(func)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return f(*this, std::forward<Args>(args)...);
    }
};

auto factorial = YCombinator([](auto& self, int n) -> int {
    if (n <= 1) return 1;
    return n * self(n - 1);
});

int main() {
    std::cout << factorial(5) << std::endl;
    return 0;
}