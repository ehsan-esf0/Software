# 🌟 Nested Classes

---

## 🔹 What is a Nested Class?

A **nested class** is a class that is **defined inside another class**.
It is used when one class logically belongs to another or should be tightly scoped within it.

---

### ✅ Basic Syntax:

```cpp
class Outer {
public:
    class Inner {
    public:
        void display();
    };
};
```

You define a class (`Inner`) **inside** another class (`Outer`).

---

### 📘 Example:

```cpp
#include <iostream>
using namespace std;

class Outer {
public:
    int outerData;

    class Inner {
    public:
        void show() {
            cout << "Inside Inner class\n";
        }
    };
};

int main() {
    Outer::Inner obj;
    obj.show();
    return 0;
}
```

#### 🔎 Output:

```
Inside Inner class
```

---

## ❗ Important Notes:

### 1. **Nested class does NOT automatically have access to the outer class members**

If you want to access `Outer`'s data, you need to explicitly pass a reference or pointer.

```cpp
class Outer {
    int secret = 42;

public:
    class Inner {
    public:
        void reveal(Outer& o) {
            cout << "Outer secret: " << o.secret << '\n';  // ✅ OK
        }
    };
};
```

---

### 2. **Outer class does NOT automatically have access to private members of the nested class**

Access is limited just like regular classes unless you use `friend`.

---

### 3. **Nested classes are often used in:**

* **Implementation hiding** (helper classes)
* **Iterators** (like `std::vector<int>::iterator`)
* **Organizing logic** inside big classes

---

### 🧠 Example with Realistic Use:

```cpp
class Engine {
public:
    class Piston {
    public:
        void move() {
            cout << "Piston moving!\n";
        }
    };

    void run() {
        Piston piston;
        piston.move();
    }
};
```

---

## 🧾 Summary Table

| Feature                                | Behavior                                 |
| -------------------------------------- | ---------------------------------------- |
| Nested class inside outer class        | Defined in scope of outer class          |
| Can access outer members?              | ❌ Not directly (needs reference/pointer) |
| Can outer access nested class private? | ❌ Not unless `friend` is used            |
| How to instantiate?                    | `Outer::Inner obj;`                      |

