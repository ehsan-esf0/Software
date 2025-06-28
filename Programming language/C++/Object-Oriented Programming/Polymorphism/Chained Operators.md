# ✅ Chained Operators in C++

Chained operators like `obj[1][2][3]` in C++ are achievable through operator overloading — particularly `operator[]`. This technique is widely used in **fluent interfaces**, **custom DSLs**, **multi-dimensional access**, and **parser-like structures**.

---

## 🔷 What is a Chained Operator?

A *chained operator* is a pattern where you can use an operator (e.g., `[]`, `()`, `.`, etc.) multiple times in a sequence, such as:

```cpp
obj[1][2][3];
```

This is made possible by returning an object (either the same or a new one) that also supports the same operator.

---

## ✅ Two Main Strategies

### 1. Returning the Same Object: `return *this;`

* Executes all operations on a **single object**
* No new object is created
* Ideal for **fluent APIs** or **builder patterns**

```cpp
class Chain {
public:
    Chain operator[](int value) {
        std::cout << "[*this] Got: " << value << "\n";
        return *this;
    }
};
```

### 2. Returning a New Object: `return ClassName(...)`

* Each step returns a **new object with a new state**
* Enables tracking depth or hierarchy
* Ideal for **tree-like**, **nested**, or **parser** structures

```cpp
class Chain {
    int depth;
public:
    Chain(int d = 0) : depth(d) {}

    Chain operator[](int value) {
        std::cout << "[Depth " << depth << "] Got: " << value << "\n";
        return Chain(depth + 1);
    }
};
```

---

## 🔄 Comparison Table

| Feature               | `return *this;`                   | `return ClassName(...)`             |
| --------------------- | --------------------------------- | ----------------------------------- |
| Object Reused         | ✔️ Yes                            | ❌ No (new object per step)          |
| Custom state per step | ❌ Not flexible                    | ✔️ Fully customizable               |
| Suitable for          | Fluent APIs, Logger, Config Chain | DSLs, AST, Multi-level interpreters |
| Memory Usage          | Low (no new allocations)          | Depends (copies or moves involved)  |
| Flexibility in logic  | Limited                           | High                                |

---

## 🧩 Multi-Class Chained Operators

You can also chain across **multiple classes**, as long as each class returns an object (or reference) to the next class that supports `operator[]`.

### Example: Multi-class chaining

```cpp
class B;

class A {
public:
    B operator[](int x);
};

class B {
public:
    B operator[](int y) {
        std::cout << "B got: " << y << "\n";
        return *this;
    }
};

B A::operator[](int x) {
    std::cout << "A got: " << x << "\n";
    return B();
}

int main() {
    A obj;
    obj[1][2][3];  // A handles [1], B handles [2] and [3]
}
```

🧠 You can chain across **as many classes as you want**, enabling powerful DSL-style or layered behavior.

---

## 🛠 Practical Use Cases

| Use Case                           | Strategy                    |
| ---------------------------------- | --------------------------- |
| Fluent API (`config.set().do()`)   | `*this`                     |
| Matrix access (`m[1][2]`)          | Return reference to row     |
| JSON/DSL Builder (`obj["key"][0]`) | Return new wrapper          |
| Expression trees (`expr[op][arg]`) | New object per operation    |
| Logging chain (`log[INFO][msg]`)   | Either, depending on design |

---

## ✅ Summary

| Question                              | Answer                                        |
| ------------------------------------- | --------------------------------------------- |
| Can both strategies support chaining? | ✔️ Yes                                        |
| Is `return *this` better for memory?  | ✔️ Yes (no new object)                        |
| Is `return Class(...)` more flexible? | ✔️ Yes (per-step custom logic possible)       |
| Can I chain between multiple classes? | ✔️ Absolutely — as long as return types match |
