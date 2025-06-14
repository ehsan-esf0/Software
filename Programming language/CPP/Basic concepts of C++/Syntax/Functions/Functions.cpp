#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <optional>
using namespace std;

void plus1( int a )
{
    a += 1;
}

void plus2( int &x )
{
    x += 1;
} 

void plus3( int *x )
{
    *x += 1;
} 

struct Point {
    int x, y;
};

Point getOrigin() {
    return {0, 0};
}


int add(int a, int b) {
    return a + b;
}

int& getElement(vector<int>& arr, int index) {
    return arr[index];
}

int* createInt() {
    int* ptr = new int(10);
    return ptr;
}

template<typename T>
T identity(T value) {
    return value;
}

optional<int> find(int id) {
    if (id == 1) return 42;
    return nullopt;
}

variant<int, string> getResult(bool asString) {
    if (asString) return string("hello");
    return 42;
}


int main()
{
    int x = 0;
    plus1(x);
    cout << x << endl;
    plus2(x);
    cout << x << endl;
    plus3(&x);
    cout << x << endl;

    int a = 10, b = 20;
    cout << add(a, b) << endl;

}