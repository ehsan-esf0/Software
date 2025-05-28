# 🔹 `dynamic_cast` in C++

## ✅ Purpose:
Used for **safe downcasting** in polymorphic class hierarchies.

## 🧠 Requirements:
- Base class must have **at least one virtual function**.
- Uses **RTTI** for runtime type checking.

## 🧪 Example:
```cpp
class Base { public: virtual ~Base() {} };
class Derived : public Base {};

Base* b = new Derived;
Derived* d = dynamic_cast<Derived*>(b);  // OK

Base* b2 = new Base;
Derived* d2 = dynamic_cast<Derived*>(b2);  // Returns nullptr (safe failure)
```

## 🔍 Notes:
- Returns `nullptr` if cast fails.
- Safer but slower than static_cast.