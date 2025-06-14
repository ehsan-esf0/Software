#include <iostream>
#include <string>
using namespace std;

int main()
{
    char str[] = "Hello";
    cout << str << endl;
    cout << str[0] << endl;
    cout << *(str + 0) << endl;

    string s = "Hello";
    s += " World";
    cout << s << endl;

    std::string s2 = "Hello";
    const char *cstr = s2.c_str();
    
}