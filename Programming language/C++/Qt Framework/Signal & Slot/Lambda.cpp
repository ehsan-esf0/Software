#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;

    auto func = [ &a, &b ]( int x )->int {
        cout << "func" << endl;
        cout << a << " " << b << endl;
        a = 100;
        b = 200;

        return a + b + x;
    };

    cout << func(100) << endl;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

  
}