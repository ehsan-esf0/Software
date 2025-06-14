#include <iostream>
using namespace std;

void increment(int& x) {
    x++;
}

void increment2(int* x) {
    (*x)++;
}

int main()
{
    int a = 10;
    int &b = a; // reference variable
    cout << a << endl;
    cout << b << endl;

    cout << "Address of a: " << &a << endl;
    cout << "Address of b: " << &b << endl;

    bool check = ( &a == &b ); 
    cout << "Check: " << check << endl;

    a += 10;
    cout << a << endl;
    cout << b << endl;

    int x = 10;
    increment(x);
    increment2(&x);
    cout << x << endl;

    return 0;
}