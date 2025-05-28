# 🔹 `static_cast` in C++

## ✅ Purpose:
Used for **conversions between compatible types**, such as:
- Numeric conversions (int to float)
- Pointer up/down-casting (base/derived)
- Enum to int, and vice versa

## 🧠 Safety:
Safe **only** if the types are logically convertible.

## 🧪 Example:
```cpp
int i = 42;
double d = static_cast<double>(i);  // int to double

class Base {};
class Derived : public Base {};

Base* b = new Derived;
Derived* d2 = static_cast<Derived*>(b);  // Safe only if 'b' actually points to Derived
```

## 🔍 Notes:
- No runtime type checking.
- Prefer over C-style cast when types are compatible.