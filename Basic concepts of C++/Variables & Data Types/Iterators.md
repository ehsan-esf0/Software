# 📘 C++ Iterators – Complete Guide

---

## 🔍 What is an Iterator?

An **iterator** is an object (like a pointer) used to traverse containers such as `vector`, `list`, `map`, etc.

✅ It points to elements in a container and allows:

* Accessing elements (`*it`)
* Moving between elements (`++it`, `--it`)
* Comparing positions (`it == other`)

---

## 🧠 Analogy

Think of an iterator as your **finger pointing at items in a list**.
You can:

* Look at the item (`*finger`)
* Move to the next one (`++finger`)
* Stop at the end (`finger == end()`)

---

## 🧰 Common STL Containers with Iterators

| Container Type       | Header File       |
| -------------------- | ----------------- |
| `std::vector`        | `<vector>`        |
| `std::list`          | `<list>`          |
| `std::deque`         | `<deque>`         |
| `std::set` / `map`   | `<set>`, `<map>`  |
| `std::unordered_map` | `<unordered_map>` |
| `std::array`         | `<array>`         |

---

## ✍️ Basic Syntax

```cpp
std::vector<int> vec = {1, 2, 3};

std::vector<int>::iterator it = vec.begin();

std::cout << *it; // prints 1
```

💡 With `auto` (modern and simpler):

```cpp
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}
```

---

## 🔧 Important Iterator Methods

| Method     | Description                            |
| ---------- | -------------------------------------- |
| `begin()`  | Returns iterator to first element      |
| `end()`    | Returns iterator past the last element |
| `rbegin()` | Reverse begin (last element)           |
| `rend()`   | Reverse end (before first element)     |

---

## 🛠️ Key Operations

| Operation       | Meaning                       |
| --------------- | ----------------------------- |
| `*it`           | Access current element        |
| `it++` / `++it` | Move to next element          |
| `it--`          | Move to previous (if allowed) |
| `it == it2`     | Compare iterator positions    |

---

## 🧪 Example: Iterating Through a Vector

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {10, 20, 30};

    for (auto it = nums.begin(); it != nums.end(); ++it) {
        std::cout << *it << " ";
    }
}
```

---

## 🎯 Modern C++: Range-Based For Loop (uses iterators under the hood)

```cpp
for (int x : nums) {
    std::cout << x << " ";
}
```

OR, for modifying elements:

```cpp
for (int& x : nums) {
    x *= 2;
}
```

---

## 🔄 Iterator Types

| Iterator Type    | Description                  |
| ---------------- | ---------------------------- |
| Input Iterator   | Read-only, forward movement  |
| Output Iterator  | Write-only, forward movement |
| Forward Iterator | Read/write, single-pass      |
| Bidirectional    | Can go `++` and `--`         |
| Random Access    | Full pointer-like operations |

🔸 `vector` → random access
🔸 `list` → bidirectional
🔸 `map` → bidirectional
🔸 `forward_list` → forward only

---

## 💥 Iterator vs Pointer

| Feature        | Iterator              | Pointer |
| -------------- | --------------------- | ------- |
| High-level     | ✅                     | ❌       |
| Safe           | ✅                     | ❌       |
| Works with STL | ✅                     | ✅       |
| Arithmetic     | Partial               | Full    |
| Object-like    | ✅ (can be customized) | ❌       |

---

## 🧵 Custom Iterator (Advanced)

In user-defined classes, you can create your own iterator by implementing `begin()`, `end()`, `operator*`, `operator++`, etc.

---

## ✅ Summary

* Iterators behave like smart pointers to container elements.
* Always use `begin()` and `end()` to control iteration.
* Use `*it` to get the value, and `++it` to move forward.
* Safer and more flexible than raw pointers.
* Use `auto` and range-based loops for cleaner code!

---