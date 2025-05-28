# 🧠 Understanding Arrays vs Pointers in C++  
## With Focus on `int[]`, `int*`, `char[]`, and `char*`

---

## 📌 Basics: Similar Syntax, Different Semantics

In C++, arrays and pointers often look similar in syntax, but behave differently in memory and mutability.

### `int[]` vs `int*`

```cpp
int arr[] = {1, 2, 3};   // Real array (allocated on stack)
int* ptr = arr;          // Pointer to the first element
````

✅ Both point to the same memory on the **stack**
✅ Both are **modifiable**

```cpp
arr[0] = 10;  // ✅
ptr[1] = 20;  // ✅
```

---

## 🔥 Special Case: String Literals

Unlike integers, **C++ supports string literals** like `"abc"` stored in **read-only memory**.

### `char[]` vs `char*`

```cpp
char str1[] = "abc";     // Array copy of literal → Stack
char* str2 = "abc";      // Pointer to string literal → Read-only memory
```

| Type     | Memory Location   | Mutable? | Notes                            |
| -------- | ----------------- | -------- | -------------------------------- |
| `char[]` | Stack             | ✅ Yes    | You own the memory               |
| `char*`  | Read-only segment | ❌ No     | Changing it = Undefined Behavior |

```cpp
str1[0] = 'A'; // ✅ Allowed
str2[0] = 'A'; // ❌ May crash or behave unexpectedly
```

---

## ❓ Why is `char*` read-only?

String literals like `"abc"` are placed in **read-only memory** by the compiler.
Modifying them is **undefined behavior**, which is why using `const char*` is preferred:

```cpp
const char* msg = "hello";  // Safe: You can't modify the literal accidentally
```

---

## 🧩 Summary Table

| Syntax       | Memory Location     | Modifiable | Literal? | Notes                     |
| ------------ | ------------------- | ---------- | -------- | ------------------------- |
| `int arr[]`  | Stack               | ✅ Yes      | ❌ No     | Fully mutable             |
| `int* ptr`   | Points to something | ✅ Maybe    | ❌ No     | Depends on pointed memory |
| `char arr[]` | Stack               | ✅ Yes      | ✅ Yes    | Copies the literal        |
| `char* str`  | Read-only segment   | ❌ No       | ✅ Yes    | Dangerous if modified     |
