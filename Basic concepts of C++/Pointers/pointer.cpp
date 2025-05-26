#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;


    int *number = new int();
    *number = 10;
    cout << *number << endl;

    int *numbers = new int[3];
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    cout << numbers[0] << endl;
    cout << numbers[1] << endl;
    cout << numbers[2] << endl;
}
