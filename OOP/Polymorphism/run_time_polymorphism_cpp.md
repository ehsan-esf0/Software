# 🎭 Run-time Polymorphism in C++

---

## 1️⃣ What is Polymorphism?

- **Polymorphism** means *"many forms"*.
- Allows objects of different classes related by inheritance to be treated uniformly.
- In C++, **run-time polymorphism** is done using **virtual functions**.
- Function calls are resolved **at run-time** based on the object's actual type.

---

## 2️⃣ Requirements for Run-time Polymorphism

- 🏗️ A **base class** with at least one **virtual function**.
- 🛠️ Derived classes **override** the virtual functions.
- 🔗 Use **base class pointers or references** to point to derived objects.
- 🚮 **Virtual destructor** in base class to ensure proper cleanup.

---

## 3️⃣ Virtual Functions

- Declared with the keyword `virtual` in base class.
- Allow derived classes to provide their own implementation.
- Calls resolved through a **vtable** at run-time.

```cpp
class Base {
public:
    virtual void show() {
        std::cout << "Base show" << std::endl;
    }
    virtual ~Base() {}  // virtual destructor
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived show" << std::endl;
    }
};
```

---

## 4️⃣ Pure Virtual Functions & Abstract Classes

- Pure virtual function syntax: `virtual void draw() = 0;`
- Makes the class **abstract** — you **cannot instantiate** it.
- Forces derived classes to implement this function.

---

## 5️⃣ Example: Run-time Polymorphism in Action

```cpp
#include <iostream>

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing Shape" << std::endl;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

void render(Shape* s) {
    s->draw();  // calls correct version at run-time
}

int main() {
    Shape* shape1 = new Shape();
    Shape* shape2 = new Circle();

    render(shape1);  // Output: Drawing Shape
    render(shape2);  // Output: Drawing Circle

    delete shape1;
    delete shape2;
    return 0;
}
```

---

## 6️⃣ Important Notes & Best Practices

- 🛡️ **Base class destructor must be virtual** to avoid memory leaks.
- ✔️ Use `override` keyword in derived classes.
- ⏳ Virtual calls have a small performance cost due to vtable lookup.
- 🔄 Polymorphism works only with pointers or references to base, **not objects**.
- 🔍 Use `dynamic_cast` for safe downcasting.

---

## 7️⃣ Behind the Scenes

- Each polymorphic class has a **vtable**: table of function pointers.
- Each object stores a hidden **vptr** pointing to the vtable.
- Virtual function call → lookup in vtable → function call.

---

## 8️⃣ Summary Table

| Concept               | Description                                  |
|-----------------------|----------------------------------------------|
| 🔮 Virtual function    | Overridable function resolved at run-time    |
| 🚩 Pure virtual func   | Virtual function with `= 0`, makes class abstract |
| 🏗️ Abstract class      | Has ≥1 pure virtual function; non-instantiable |
| 📋 vtable             | Table of virtual function pointers            |
| 📌 vptr               | Hidden pointer in object to vtable            |
| ✅ Override keyword    | Enforces correct overriding                    |

---

## 9️⃣ Common Pitfalls

- ❌ Non-virtual destructor in base → undefined behavior.
- ❌ Trying polymorphism on objects instead of pointers/references.
- ❌ Forgetting `override` → silent bugs.
- ❌ Misusing `dynamic_cast`.

---

## 🔟 Additional Tips

- 💡 Define **interfaces** as abstract classes with pure virtual functions + virtual destructor.
- 🎯 Use polymorphism in design patterns: Strategy, Factory, Observer.
- ⚖️ Keep virtual functions minimal for performance.
- 🚫 Avoid calling virtual functions from constructors/destructors.

---