# Fold Expressions (C++17)

Compact syntax to work with variadic template parameter packs without recursion.

### 🔹 Fold Types:

| Fold Type         | Syntax                  |
| ----------------- | ----------------------- |
| Unary left fold   | `(... op args)`         |
| Unary right fold  | `(args op ...)`         |
| Binary left fold  | `(init op ... op args)` |
| Binary right fold | `(args op ... op init)` |

---

## 🧪 Example 1: Sum of All Parameters

```cpp
template<typename... Args>
auto sum(Args... args) {
    return (... + args);
}
```

---

## 🧪 Example 2: Multiplication

```cpp
template<typename... Args>
auto product(Args... args) {
    return (args * ...);
}
```

---

## 🧪 Example 3: Print All Arguments

```cpp
template<typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << '\n';
}
```

---

## 🧪 Example 4: Logical AND

```cpp
template<typename... Bools>
bool allTrue(Bools... bs) {
    return (... && bs);
}
```

---

## 🧪 Example 5: Fold with Initial Value

```cpp
template<typename... Args>
int sumWithInit(Args... args) {
    return (100 + ... + args);  // starts with 100
}
```

