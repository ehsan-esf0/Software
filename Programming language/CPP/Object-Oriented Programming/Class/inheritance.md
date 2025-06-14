# 🧬 C++ Inheritance

## 📌 What is Inheritance?

Inheritance is a core concept in Object-Oriented Programming (OOP) that allows a class (called the **derived class**) to acquire properties and behaviors (members) from another class (called the **base class**).

```cpp
class Base {
public:
    void greet() {
        std::cout << "Hello from Base!" << std::endl;
    }
};

class Derived : public Base {
    // Inherits greet()
};
```

---

## 🔷 Types of Inheritance Access

In C++, you can inherit with three different access specifiers:

| Inheritance Type | Public members become | Protected members become | Private members |
|------------------|------------------------|---------------------------|-----------------|
| `public`         | public                 | protected                 | inaccessible    |
| `protected`      | protected              | protected                 | inaccessible    |
| `private`        | private                | private                   | inaccessible    |

### Example:

```cpp
class Base {
public: int a;
protected: int b;
private: int c;
};

class Derived : public Base {
    // a → public, b → protected, c → inaccessible
};
```

---

## 🔹 Constructor and Destructor Behavior

- Base class constructor is called **before** derived constructor.
- Destructors are called **in reverse order**.

```cpp
class Base {
public:
    Base() { std::cout << "Base constructor\n"; }
    ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor\n"; }
    ~Derived() { std::cout << "Derived destructor\n"; }
};
```

---

## 🔸 Types of Inheritance Structures

1. **Single Inheritance**

```cpp
class A { };
class B : public A { };
```

2. **Multiple Inheritance**

```cpp
class A { };
class B { };
class C : public A, public B { };
```

3. **Multilevel Inheritance**

```cpp
class A { };
class B : public A { };
class C : public B { };
```

4. **Hierarchical Inheritance**

```cpp
class A { };
class B : public A { };
class C : public A { };
```

5. **Hybrid Inheritance**

Combination of any of the above.

---

## ⚠️ Diamond Problem in Multiple Inheritance

```cpp
class A { };
class B : public A { };
class C : public A { };
class D : public B, public C { }; // Ambiguity: 2 copies of A
```

### ✅ Solution: Virtual Inheritance

```cpp
class A { };
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { }; // Only one A
```

---

## 🎯 Virtual Functions and Polymorphism

```cpp
class Base {
public:
    virtual void speak() { std::cout << "Base\n"; }
};

class Derived : public Base {
public:
    void speak() override { std::cout << "Derived\n"; }
};

void makeSpeak(Base* obj) {
    obj->speak(); // Runtime dispatch
}
```

- `virtual` allows **runtime polymorphism**
- Always use `virtual` destructors in base classes!

```cpp
class Base {
public:
    virtual ~Base() {} // important!
};
```

---

## 🛡️ Using `override` and `final`

```cpp
class Base {
public:
    virtual void talk() const = 0;
};

class Derived : public Base {
public:
    void talk() const override final { }
};
```

- `override` ensures you're overriding a virtual function
- `final` prevents further overriding

---

## 🔐 Summary of Access in Derived Classes

| Member Type   | Access in Base | Public Inheritance | Protected Inheritance | Private Inheritance |
|---------------|----------------|---------------------|------------------------|----------------------|
| `public`      | public         | public              | protected              | private              |
| `protected`   | protected      | protected           | protected              | private              |
| `private`     | private        | inaccessible        | inaccessible           | inaccessible         |
