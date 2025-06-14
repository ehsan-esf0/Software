#include <iostream>
#include <initializer_list>

void printAll(std::initializer_list<int> values) {
    for (int v : values)
        std::cout << v << " ";
    std::cout << std::endl;
}

int sum(std::initializer_list<int> values) {
    int sum = 0;
    for (int v : values)
        sum += v;
    return sum;
}

int main() {
    printAll({1, 2, 3, 4, 5});
    std::cout << sum({1, 2, 3, 4, 5}) << std::endl;
}
