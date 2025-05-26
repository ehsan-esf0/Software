#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
using namespace std;

int main()
{
    auto x = 5;       // int
    auto y = 3.14;    // double
    auto z = "Hello"; // const char*

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl;

    vector<int> vec = {1, 2, 3, 4};

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }

    int x1 = 42;
    auto y1 = x1;      // y: int
    auto &z1 = x1;     // z: int&
    const auto w = x1; // w: const int

    std::vector<std::string> names = {"Ali", "Sara", "Reza"};

    for (auto &name : names)
    {
        std::cout << name << std::endl;
    }
}

auto sum(int a, int b)
{
    return a + b;
}

auto func() -> int { return 42; }