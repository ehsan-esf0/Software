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

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
printNumber(T value) {
    std::cout << "Integer: " << value << std::endl;
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
printNumber(T value) {
    std::cout << "Float: " << value << std::endl;
}

void print() {
    std::cout << "(end)" << std::endl;
}

template<typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    print(args...);
}

template<typename... Args>
void countArgs(Args... args) {
    std::cout << "Number of arguments: " << sizeof...(args) << std::endl;
}


int main()
{
    myclass<int , double> a(10 , 6.242);
    myclass<double , string> b(10.5 , "number");
    a.display();
    b.display();

    printNumber(10);
    printNumber(10.5);

    print(1, 2, 3, 4, 5);

    countArgs(1, 2, 3, 4, 5);

    return 0;
}
