#include <iostream>
using namespace std;

template <typename T , typename U >
class myclass
{
public:
    T x;
    U y;
    myclass(T a , U b)
    {
        x = a;
        y = b;
    }
    void display()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
};

template <typename T>
class myclass<T , string>
{
public:
    T x;
    string y;
    myclass(T a , string b)
    {
        x = a;
        y = b;
    }
    void display()
    {
        cout << "x = " << x << endl;
        cout << "string = " << y << endl;
    }
};

int main()
{
    myclass<int , double> a(10 , 6.242);
    myclass<double , string> b(10.5 , "number");
    a.display();
    b.display();
    return 0;
}
