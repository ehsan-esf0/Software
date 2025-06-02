### Overriding vs Hiding

* **Overriding** happens when a derived class provides its own implementation of a **virtual** function.
* If a function in the base class is **non-virtual**, and a derived class declares a function with the same name and signature, it **hides** the base function but does **not override** it.

### Example

```cpp
class Base {
public:
    void foo() {  // Non-virtual
        std::cout << "Base foo\n";
    }
    virtual void bar() {  // Virtual function
        std::cout << "Base bar\n";
    }
};

class Derived : public Base {
public:
    void foo() {  // Hides Base::foo, no overriding
        std::cout << "Derived foo\n";
    }
    void bar() override {  // Overrides Base::bar
        std::cout << "Derived bar\n";
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->foo();  // Calls Base::foo (no polymorphism)
    ptr->bar();  // Calls Derived::bar (runtime polymorphism)
    delete ptr;
}
```

### Summary:

* Virtual functions allow **dynamic dispatch** (the call is resolved at runtime).
* Non-virtual functions are resolved at compile-time, so base class version is called when using base class pointers/references.
* Overriding only applies to virtual functions.

