# 🔁 C++ Loops Guide

## 🟢 `for` Loop

```cpp
for (int i = 0; i < 5; ++i) {
    std::cout << i << " ";
}
```

* Perfect when the number of iterations is known.

## 🟡 `while` Loop

```cpp
int i = 0;
while (i < 5) {
    std::cout << i << " ";
    ++i;
}
```

* Use when the condition is evaluated **before** the loop body.

## 🟠 `do...while` Loop

```cpp
int i = 0;
do {
    std::cout << i << " ";
    ++i;
} while (i < 5);
```

* Ensures the loop body is executed **at least once**.

## 🔵 Nested Loops

```cpp
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        std::cout << "(" << i << "," << j << ") ";
    }
}
```

## 🟣 Loop Control Statements

* `break` — exits the loop:

```cpp
for (int i = 0; i < 10; ++i) {
    if (i == 5) break;
    std::cout << i << " ";
}
```

* `continue` — skips to next iteration:

```cpp
for (int i = 0; i < 10; ++i) {
    if (i % 2 == 0) continue;
    std::cout << i << " ";
}
```

## ⚪ Range-based for (C++11+)

```cpp
std::vector<int> nums = {1, 2, 3};
for (int num : nums) {
    std::cout << num << " ";
}
```

* Great for collections like arrays, vectors, etc.

## 🔴 Infinite Loops

```cpp
while (true) {
    // endless loop until break
}
```

## 🔥 Advanced: Loop with Function or Lambda

```cpp
auto repeat = [](int times, auto func) {
    for (int i = 0; i < times; ++i) func(i);
};
repeat(3, [](int i){ std::cout << i << " "; });
```

### 💡 Tips:

* Choose `for` when iteration count is clear.
* Use `while` for logic-based loops.
* Avoid infinite loops unless absolutely needed.
