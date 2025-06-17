#include <iostream>
using namespace std;

class Hi
{
public:
    string sayHello(string name)
    {
        return "Hello " + name;
    }
};

int main()
{
    string (Hi::*f)(string) = &Hi::sayHello;

    Hi h;
    cout << (h.*f)("ehsan");  
}
