#include <iostream>
#include <string>
using namespace std;

class MyClass {
private:
    string* data;

public:
    // ✅ Constructor معمولی
    MyClass(const string& value) {
        data = new string(value);
        cout << "Constructor called\n";
    }

    // ✅ Copy Constructor (ارجاع به lvalue)
    MyClass(const MyClass& other) {
        data = new string(*other.data);
        cout << "Copy Constructor called\n";
    }

    // ✅ Move Constructor (ارجاع به rvalue)
    MyClass(MyClass&& other) noexcept {
        data = other.data;        // انتقال مالکیت
        other.data = nullptr;     // null کردن منبع اصلی
        cout << "Move Constructor called\n";
    }

    // ✅ Destructor
    ~MyClass() {
        delete data;
        cout << "Destructor called\n";
    }

    void print() {
        if (data)
            cout << "Data: " << *data << endl;
        else
            cout << "Data is null\n";
    }
};

int main() {
    MyClass obj1("Hello");      // صدا زدن Constructor معمولی
    MyClass obj2 = obj1;        // صدا زدن Copy Constructor
    MyClass obj3 = MyClass("World");  // صدا زدن Move Constructor

    obj1.print();
    obj2.print();
    obj3.print();

    return 0;
}
