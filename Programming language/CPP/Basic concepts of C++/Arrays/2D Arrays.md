#Traversal Techniques for 2D Arrays in C++

---

### 📊 Introduction

2D arrays (two-dimensional arrays) are essential in many applications, such as matrices, games (like Tic-Tac-Toe), and image processing. Traversing them efficiently and correctly is crucial. This document covers the traversal techniques for both **static** and **dynamic** 2D arrays in **C++**.

---

### 📁 Static 2D Array Traversal

Static arrays are declared with fixed size known at compile time.

```cpp
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

#### 🔄 Row-wise Traversal

```cpp
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

#### 🔄 Column-wise Traversal

```cpp
for (int j = 0; j < 3; ++j) {
    for (int i = 0; i < 3; ++i) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

#### 🔄 Diagonal Traversal

**Main diagonal:** `i == j`

```cpp
for (int i = 0; i < 3; ++i) {
    cout << matrix[i][i] << " ";
}
```

**Anti-diagonal:** `i + j == n - 1`

```cpp
for (int i = 0; i < 3; ++i) {
    cout << matrix[i][2 - i] << " ";
}
```

---

### 📁 Dynamic 2D Array Traversal

Dynamic arrays are allocated at runtime using pointers.

```cpp
int** matrix = new int*[3];
for (int i = 0; i < 3; ++i)
    matrix[i] = new int[3];
```

#### 🔄 Row-wise Traversal

```cpp
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

#### 🔄 Column-wise Traversal

```cpp
for (int j = 0; j < 3; ++j) {
    for (int i = 0; i < 3; ++i) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

#### ⚠️ Warning: Avoid Flat Traversal with Pointers

```cpp
int* ptr = matrix[0];
for (int i = 0; i < 9; ++i) {
    cout << *(ptr + i) << " "; // Unsafe if rows are not contiguous!
}
```

---

### 📅 Summary Table

| Method       | Static Array | Dynamic Array | Safe to Use |
| ------------ | ------------ | ------------- | ----------- |
| Row-wise     | Yes          | Yes           | ✅ Yes       |
| Column-wise  | Yes          | Yes           | ✅ Yes       |
| Diagonal     | Yes          | Yes           | ✅ Yes       |
| Flat (ptr+i) | ❌ No         | ❌ No          | ❌ No        |

---

