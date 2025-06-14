# 🎯 Function Overloading in C++

Function Overloading allows **multiple functions with the same name** to be defined, as long as they differ in **parameter types or number of parameters**.

---

## 🌟 Key Rules

✅ You **can overload** a function if:

- Parameter **types** are different  
- Parameter **count** is different  
- Parameter **order** is different

❌ You **cannot overload** based only on:

- Return type

---

## 📌 Syntax Example

```cpp
#include <iostream>
using namespace std;

void print(int x) {
    cout << "Integer: " << x << endl;
}

void print(double x) {
    cout << "Double: " << x << endl;
}

void print(string s) {
    cout << "String: " << s << endl;
}

int main() {
    print(10);        // Integer
    print(3.14);      // Double
    print("Hello");   // String
}
```

---

## ⚠️ Invalid Overloading

```cpp
int func(int x);
double func(int x); // ❌ ERROR: Only return type differs
```

⛔ **Compiler Error:** Function redefinition

---

## ✅ Valid Overloading Patterns

| Function 1             | Function 2               | Valid? | Reason                          |
|------------------------|--------------------------|--------|----------------------------------|
| `void func(int)`       | `void func(double)`      | ✅     | Different parameter type        |
| `void func(int)`       | `void func(int, int)`    | ✅     | Different number of parameters  |
| `int func(int, float)` | `int func(float, int)`   | ✅     | Different parameter order       |
| `int func(int)`        | `double func(int)`       | ❌     | ❗ Only return type differs      |

---

## 🛠 Constructor Overloading

You can overload constructors too:

```cpp
class Point {
public:
    Point() { x = 0; y = 0; }
    Point(int a, int b) { x = a; y = b; }

private:
    int x, y;
};
```

---

## 🧠 Summary

| Feature        | Overloading | Overriding  |
|----------------|-------------|-------------|
| Inheritance    | ❌ Not needed | ✅ Required |
| Same function name | ✅ Yes | ✅ Yes       |
| Same parameters | ❌ No | ✅ Yes         |
| Return type only | ❌ Not allowed | ❌ Not allowed |
| Polymorphism   | ✅ Compile-time | ✅ Runtime |
| `virtual` needed | ❌ No | ✅ Yes        |
