# C++ Conditionals (if / else / switch)

## 🟢 Basic `if` Statement

```cpp
int x = 10;
if (x > 0) {
    std::cout << "Positive";
}
```

* Executes block **only if** the condition is true.

## 🟡 `if / else`

```cpp
if (x > 0) {
    std::cout << "Positive";
} else {
    std::cout << "Zero or Negative";
}
```

* Two-way branching.

## 🟠 `if / else if / else`

```cpp
if (x > 0) {
    std::cout << "Positive";
} else if (x == 0) {
    std::cout << "Zero";
} else {
    std::cout << "Negative";
}
```

* Multi-branching logic.

## 🔵 Nested `if`

```cpp
if (x > 0) {
    if (x < 100) {
        std::cout << "Positive and less than 100";
    }
}
```

## 🟣 Logical Operators

```cpp
if (x > 0 && x < 100) {
    std::cout << "In range";
}
if (x <= 0 || x >= 100) {
    std::cout << "Out of range";
}
if (!(x == 5)) {
    std::cout << "Not 5";
}
```

## 🔴 Ternary Operator `?:`

```cpp
std::string result = (x > 0) ? "Positive" : "Non-positive";
```

## ⚪ `switch` Statement

```cpp
int day = 2;
switch(day) {
    case 1:
        std::cout << "Monday";
        break;
    case 2:
        std::cout << "Tuesday";
        break;
    default:
        std::cout << "Other Day";
}
```

* Good for **integer-based** multi-branching.

## 🔥 Advanced Tips

* Use `{}` even for single-line `if` blocks for clarity.
* Avoid using `=` instead of `==` by mistake.
* Use `constexpr if` in templates (C++17):

```cpp
template<typename T>
void printType(T val) {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "Integral";
    } else {
        std::cout << "Not Integral";
    }
}
```
