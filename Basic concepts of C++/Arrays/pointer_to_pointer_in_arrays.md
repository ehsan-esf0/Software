# 🧑‍💻 Pointer to Pointer (`int**`) in C++

---

## What is a Pointer to Pointer? 🔗🔗

A **pointer to pointer** is a variable that stores the address of another pointer.

```cpp
int x = 10;
int* p = &x;      // p points to int
int** pp = &p;    // pp points to pointer p
```

- `x` is an integer  
- `p` holds the address of `x`  
- `pp` holds the address of `p`  

---

## Pointer to Pointer in 2D Arrays 🗂️

When dealing with dynamic 2D arrays, `int**` is often used.

```cpp
int rows = 3;
int cols = 4;

int** matrix = new int*[rows];    // Array of int pointers (rows)

for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];    // Each row is an array of ints (cols)
}
```

- `matrix` is a pointer to pointer to int (`int**`)  
- `matrix[i]` is a pointer to the `i`th row  
- `matrix[i][j]` accesses the element at row `i`, column `j`

---

## Example: Dynamic 2D Array Using Pointer to Pointer 💡

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 4;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Initialize elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }

    // Print elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
```

---

## Static vs Dynamic 2D Arrays 🆚

| Array Type          | Memory Layout                   | Access Method        |
|---------------------|--------------------------------|---------------------|
| `int matrix[3][4];` | Continuous block of 12 ints     | `matrix[i][j]`      |
| `int** matrix;`     | Array of pointers, rows separate | `matrix[i][j]`      |

---

## Important Notes ⚠️

- **Memory is not contiguous in `int**` arrays** — each row is separately allocated in memory.  
- **You must `delete[]` each allocated array** to avoid memory leaks.  
- **Modern C++ encourages using `std::vector<std::vector<int>>`** for safety and ease of use.

---

## Quick Pointer to Pointer Access Demo 🎯

```cpp
int x = 5;
int* p = &x;
int** pp = &p;

cout << **pp << endl;  // Outputs: 5
```

- `*pp` gives the pointer `p`  
- `**pp` gives the value of `x`

---

## Summary 📝

- Pointer to pointer holds the address of another pointer  
- Used commonly in dynamic 2D arrays with `int**`  
- Requires careful memory management (`new` and `delete`)  
- Prefer safer containers like `std::vector` in modern C++
