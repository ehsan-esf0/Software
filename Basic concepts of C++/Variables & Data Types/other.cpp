#include <iostream>
#include <variant>
#include <optional>
using namespace std;

constexpr int square(int x)
{
    return x * x;
}

int main()
{
    // constexpr

    int arr[square(5)];

    // variant
    variant<int, float> data;

    data = 10;    // int
    data = 3.14f; // now float

    std::visit([](auto val)
               { std::cout << val << "\n"; }, data);

    std::optional<int> maybeAge;
    
    // optional

    maybeAge = 25;

    if (maybeAge.has_value())
    {
        std::cout << "Age: " << maybeAge.value();
    }
    else
    {
        std::cout << "No age available.";
    }
}