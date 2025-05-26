# 🔧 C++ Functions - Complete Guide

## 🟢 Basics: Function Declaration & Definition

```cpp
int add(int a, int b) {
    return a + b;
}
```

* `int` → return type
* `add` → function name
* `a`, `b` → parameters

## 🟡 Calling a Function

```cpp
int result = add(5, 3);
```

## 🟠 Void Function (no return value)

```cpp
void sayHello() {
    std::cout << "Hello!";
}
```

## 🔵 Default Arguments

```cpp
void greet(std::string name = "Guest") {
    std::cout << "Hello, " << name;
}
```

## 🟣 Function Overloading

```cpp
int square(int x) {
    return x * x;
}
double square(double x) {
    return x * x;
}
```

* Same name, different parameters

## 🔴 Recursive Functions

```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

## ⚪ Pass by Reference

```cpp
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

## 🟤 Inline Functions

```cpp
inline int cube(int x) {
    return x * x * x;
}
```

## 🔶 Function Pointer

```cpp
int multiply(int a, int b) {
    return a * b;
}
int (*funcPtr)(int, int) = multiply;
std::cout << funcPtr(2, 3);  // Outputs 6
```

## 🟩 Lambda Function (C++11+)

```cpp
auto square = [](int x) { return x * x; };
std::cout << square(5);
```

## 🟫 Template Function

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

## 🔷 Constexpr Function (C++11+)

```cpp
constexpr int square(int x) {
    return x * x;
}
int arr[square(3)]; // valid
```

## 🔳 Variadic Function (C-style)

```cpp
#include <cstdarg>
int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    int total = 0;
    for (int i = 0; i < count; ++i) {
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}
```

## 🔻 Advanced: std::function

```cpp
#include <functional>
std::function<int(int)> doubleIt = [](int x) { return x * 2; };
```

## 💡 Best Practices

* Use `const` reference for large objects
* Keep functions short and single-purpose
* Prefer templates over function overloading when appropriate
