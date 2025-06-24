## 🔹 Root Cause: **Pass-by-Value (Copy)**

In a **range-based `for` loop**, by default, **each element is copied into the loop variable**. That means you're modifying a copy — not the original element in the container.

### 🔸 Example:

```cpp
std::vector<int> nums = {1, 2, 3, 4};

for (int x : nums) {
    x += 10;  // Only the copy 'x' is changed
}

for (int x : nums) {
    std::cout << x << " ";  // Output: 1 2 3 4
}
```

> Why? Because `x` is just a **copy** of each element, not a reference.

---

## 🔹 Solution: Use a Reference (`&`)

If you want to **modify the actual element** in the container, use a reference:

```cpp
for (int& x : nums) {
    x += 10;  // 'x' now refers to the original element
}

for (int x : nums) {
    std::cout << x << " ";  // Output: 11 12 13 14
}
```

---

## 🔹 How Does `range-based for` Work Internally?

The range-based `for` loop is essentially **syntactic sugar** for using iterators. For example:

```cpp
for (int x : nums)
```

is roughly equivalent to:

```cpp
for (auto it = nums.begin(); it != nums.end(); ++it) {
    int x = *it;  // Copy
}
```

And if you use reference:

```cpp
for (int& x : nums)
```

it’s similar to:

```cpp
for (auto it = nums.begin(); it != nums.end(); ++it) {
    int& x = *it;  // Reference to original
}
```

---

## 🔹 What If You Only Want to Read the Data?

If you want to read the data safely and efficiently without making unnecessary copies:

```cpp
for (const int& x : nums) {
    std::cout << x << '\n';  // Read-only reference
}
```

---

## ✅ Summary Table

| Loop Type                  | Behavior                                 |
| -------------------------- | ---------------------------------------- |
| `for (int x : vec)`        | Pass-by-value → copy → no change         |
| `for (int& x : vec)`       | Pass-by-reference → modifies original    |
| `for (const int& x : vec)` | Read-only reference → safe and efficient |

