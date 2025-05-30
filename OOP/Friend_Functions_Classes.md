# C++ `friend` Functions and Classes

---

## 👥 What is a `friend`?
A `friend` function or class has special permission to access private and protected members of another class.

---

## ✅ Friend Function
### 📌 Declared inside a class but defined outside.
```cpp
class MyClass {
private:
    int secret = 42;
    friend void showSecret(MyClass); // Declaration
};

void showSecret(MyClass obj) {
    cout << obj.secret; // ✅ Allowed
}
```

---

## ✅ Friend Class
### 📌 One class grants another full access.
```cpp
class A {
private:
    int secret = 123;
    friend class B; // Class B is a friend
};

class B {
public:
    void reveal(A a) {
        cout << a.secret; // ✅ Allowed
    }
};
```

---

## 🚫 Not Inherited
- Friendship is not inherited.
- A derived class doesn’t inherit the friendship of the base class.

---

## ❓ Why Use `friend`?
- For operator overloading (especially `<<`, `>>`)
- When external functions need access to internal state (e.g., helpers, loggers)
- When another class needs full access

---

## 📋 friend + operator overloading
```cpp
class Complex {
private:
    double real, imag;
    friend ostream& operator<<(ostream& os, const Complex& c);
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << "+" << c.imag << "i";
    return os;
}
```

---

## 🧩 Notes
- Friend functions are **not** member functions.
- They **don’t** have a `this` pointer.
- Can access all members (public, protected, private).
- Must be declared inside the class they want to access.
