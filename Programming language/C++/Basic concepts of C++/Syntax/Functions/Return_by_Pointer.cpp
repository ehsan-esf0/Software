#include <iostream>
#include <string>
#include <vector>
using namespace std;

int *createInt()
{
    int *ptr = new int(10);
    return ptr;
}

// int* badPointer() {
//     int x = 5;
//     return &x;  // ❌
// }

int *plus1(int x, int y)
{
    int *ptr = new int(x + y);
    return ptr;
}

int *plus2(int x)
{
    int *ptr = new int(x);
    *ptr = x + 1;
    return ptr;
}

int main()
{
    int *p = createInt();
    cout << *p << endl;
    delete p;

    int *p1 = plus1(10, 20);
    cout << *p1 << endl;
    delete p1;

    int x = 1;
    int *p2 = plus2(x);
    cout << x << endl;
    cout << *p2 << endl;
    delete p2;
    return 0;
}
