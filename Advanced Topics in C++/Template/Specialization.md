# Specialization

## 🔸 Full Specialization

```cpp
template<typename T>
class Printer {
public:
    void print(T value) {
        std::cout << "Value: " << value << std::endl;
    }
};

// Specialization for char*
template<>
class Printer<char*> {
public:
    void print(char* value) {
        std::cout << "String: " << value << std::endl;
    }
};
```

---

## 🔸 Partial Specialization

```cpp
template<typename T1, typename T2>
class Pair {
public:
    void print() {
        std::cout << "Generic Pair" << std::endl;
    }
};

template<typename T1>
class Pair<T1, int> {
public:
    void print() {
        std::cout << "Pair with int as second" << std::endl;
    }
};
```