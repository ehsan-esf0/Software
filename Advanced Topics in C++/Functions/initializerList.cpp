#include <iostream>
#include <initializer_list>

void printAll(std::initializer_list<int> values) {
    for (int v : values)
        std::cout << v << " ";
    std::cout << std::endl;
}

int main() {
    printAll({1, 2, 3, 4, 5});
}
