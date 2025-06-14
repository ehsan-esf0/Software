#include <iostream>
#include <string>
using namespace std;

union value
{
    char c;
    int i;
    float f;
    char str[50];
};

int main()
{
    value v;
    v.c = 'm';
    cout << v.c << endl;
    v.i = 123;
    cout << v.i << endl;
    v.f = 123.456;
    cout << v.f << endl;
    v.str[0] = 'm';
    v.str[1] = 'a';
    v.str[2] = 'n';
    v.str[3] = '\0';
    cout << v.str << endl;
    return 0;
}