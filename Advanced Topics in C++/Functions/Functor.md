## 📘 Functors 

### 📌 What is a Functor?

A **functor**, or **function object**, is an object that can be called like a function. This is done by **overloading the `operator()`** in a class.

---

### ✅ Basic Definition

```cpp
class MyFunctor {
public:
    void operator()() {
        std::cout << "Hello from functor!" << std::endl;
    }
};
```

**Usage:**

```cpp
int main() {
    MyFunctor functor;
    functor();  // acts like a function call
    return 0;
}
```

---

### 🎯 Why Use Functors?

| Advantage             | Explanation                                                        |
| --------------------- | ------------------------------------------------------------------ |
| **Encapsulation**     | You can store state (data) inside the functor object.              |
| **Performance**       | In some cases, functors are faster than regular function pointers. |
| **STL Compatibility** | Many STL algorithms accept functors as callable objects.           |
| **Reusability**       | Functors can be reused and passed around like regular objects.     |

---

### 📘 Functor with Parameters and State

```cpp
class Multiplier {
    int factor;
public:
    Multiplier(int f) : factor(f) {}

    int operator()(int x) {
        return x * factor;
    }
};

int main() {
    Multiplier times3(3);
    std::cout << times3(10);  // Output: 30
    return 0;
}
```

---

### ⚙️ Functor in STL Algorithms

#### Example: `std::for_each`

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Printer {
public:
    void operator()(int x) const {
        std::cout << x << " ";
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::for_each(nums.begin(), nums.end(), Printer()); // Output: 1 2 3 4
    return 0;
}
```

---

### 🆚 Functor vs Function Pointer vs Lambda

| Feature              | Functor        | Function Pointer | Lambda                 |
| -------------------- | -------------- | ---------------- | ---------------------- |
| Has internal state   | ✅ Yes          | ❌ No             | ✅ Yes (if captured)    |
| Reusable object      | ✅ Yes          | ❌ No             | ⚠️ Depends             |
| Readability          | ⚠️ Medium      | ❌ Low            | ✅ High                 |
| C++11 required       | ❌ No           | ❌ No             | ✅ Yes                  |
| Custom logic storage | ✅ Encapsulated | ❌                | ⚠️ Captured by context |

---

### 🔁 Functor with Templates

```cpp
template<typename T>
class Adder {
    T value;
public:
    Adder(T v) : value(v) {}

    T operator()(T x) {
        return x + value;
    }
};

int main() {
    Adder<int> add10(10);
    std::cout << add10(5);  // Output: 15
    return 0;
}
```

---

### 🔒 Const Functor

```cpp
class ConstPrinter {
public:
    void operator()(int x) const {
        std::cout << "Value: " << x << std::endl;
    }
};
```

---

### 📚 Summary

* A **functor** is any object that implements `operator()`.
* You can store **state** inside a functor, unlike a normal function.
* Functors are highly useful in **STL algorithms**.
* With C++11 and later, **lambdas** provide a simpler alternative, but functors still remain powerful and flexible.

---
