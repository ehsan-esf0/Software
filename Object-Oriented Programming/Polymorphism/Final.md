# 🔒 The `final` Keyword in C++

### Purpose:

`final` prevents further inheritance or overriding.

### Uses:

* **Final Class**: Prevents other classes from inheriting it.

```cpp
class Base final {
    // No class can inherit Base
};

// Error: cannot derive from final class
class Derived : public Base {};
```

* **Final Virtual Function**: Prevents further overriding in derived classes.

```cpp
class Base {
public:
    virtual void foo() {}
};

class Derived : public Base {
public:
    void foo() final override {}  // Cannot be overridden further
};

class MoreDerived : public Derived {
public:
    void foo() override {}  // Error: foo() is final in Derived
};
```

### Summary:

* Use `final` on a class to **stop inheritance**.
* Use `final` on a virtual method to **stop further overrides** in derived classes.

