#include <iostream>
#include <functional>
using namespace std;

// template<typename T>
// void operate(T x, T y, function<T(T, T)> func)
// {
//     cout << "Result: " << func(x, y) << endl;
// }

// int add(int a, int b)
// {
//     return a + b;
// }

// int main()
// {
//     operate<int>(5, 6, add); 
//     operate<int>(5, 6, [](int a, int b) { return a * b; });
//     return 0;
// }


void operate(int x, int y, function<int(int, int)> func)
{
    cout << "Result: " << func(x, y) << endl;
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    operate(5, 6, add); 
    operate(5, 6, [](int a, int b) { return a * b; });
    return 0;
}
