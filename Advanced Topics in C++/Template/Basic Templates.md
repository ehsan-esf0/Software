# Basic Templates in C++

## 🔹 Function Templates

### 💡 Syntax:

```cpp
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

### 🧪 Example:

```cpp
#include <iostream>
using namespace std;

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << max(3, 7) << endl;          // Output: 7 (int)
    cout << max(4.5, 2.1) << endl;      // Output: 4.5 (double)
    cout << max('a', 'z') << endl;      // Output: z (char)
}
```

---

## 🔹 Class Templates

### 💡 Syntax:

```cpp
template<typename T>
class Box {
private:
    T value;
public:
    void set(T v) { value = v; }
    T get() { return value; }
};
```

### 🧪 Example:

```cpp
int main() {
    Box<int> intBox;
    intBox.set(42);
    cout << intBox.get() << endl;     // Output: 42

    Box<string> strBox;
    strBox.set("Hello");
    cout << strBox.get() << endl;     // Output: Hello
}
```

---

## 🔹 Multiple Template Parameters

```cpp
template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
};
```

---


