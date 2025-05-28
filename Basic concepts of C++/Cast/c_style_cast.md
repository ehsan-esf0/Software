# 🔹 C-style Cast in C++

## ❌ Discouraged in modern C++

## 🧠 Purpose:
Performs a cast using the old C-style syntax:
```cpp
int x = (int)3.14;
```

## 🧪 Equivalent to:
Tries:
1. `const_cast`
2. `static_cast`
3. `reinterpret_cast`

## 🧪 Example:
```cpp
float pi = 3.14f;
int i = (int)pi;  // Works, but prefer static_cast
```

## ⚠️ Warning:
- No safety.
- Unclear which cast is being used.
- Avoid in favor of C++-style casts.