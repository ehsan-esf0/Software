#  Variadic Templates

Templates that accept a variable number of arguments.

### 🔹 Syntax:

```cpp
template<typename T, typename... Args>
void func(T first, Args... rest);
```

---

## 🧪 Example 1: Recursive Printing

```cpp
void print() {
    std::cout << "(end)" << std::endl;
}

template<typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    print(args...);
}

int main() {
    print(1, "hello", 3.14, 'A');
}
```

---

## 🧪 Example 2: Counting Arguments

```cpp
template<typename... Args>
void countArgs(Args... args) {
    std::cout << "Number of arguments: " << sizeof...(args) << std::endl;
}
```

---

## 🧪 Example 3: Variadic Template Class

```cpp
template<typename... Args>
class MyTuple;

template<typename T, typename... Rest>
class MyTuple<T, Rest...> {
public:
    T value;
    MyTuple<Rest...> rest;

    MyTuple(T v, Rest... r) : value(v), rest(r...) {}
};

template<>
class MyTuple<> {};  // base case
```

---

