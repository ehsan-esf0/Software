# C++ Operator Overloading

---

## 🧠 What is Operator Overloading?
Operator overloading lets you redefine the meaning of operators (`+`, `-`, `[]`, etc.) for user-defined types.

---

## 🔹 Syntax Overview
```cpp
ReturnType operatorOP(const Type& other) {
    // logic
}
```

---

## ⚙️ Common Overloaded Operators

### 1. Arithmetic Operators: `+`, `-`, `*`, `/`, `%`
```cpp
Point operator+(const Point& p) {
    return Point(x + p.x, y + p.y);
}
```

### 2. Compound Assignment: `+=`, `-=`, `*=`, `/=`, `%=` 
```cpp
Point& operator+=(const Point& p) {
    x += p.x;
    y += p.y;
    return *this;
}
```

### 3. Unary Operators: `-`, `++`, `--`, `!`
```cpp
Point operator-() const {
    return Point(-x, -y);
}
```

### 4. Comparison Operators: `==`, `!=`, `<`, `>`, `<=`, `>=`
```cpp
bool operator==(const Point& p) const {
    return x == p.x && y == p.y;
}
```

### 5. Subscript `[]`
```cpp
double& operator[](int index);
double operator[](int index) const;
```

### 6. Function Call `()`
```cpp
void operator()(int a);
```

### 7. Arrow Operator `->`
```cpp
T* operator->();
```

### 8. Dereference `*`
```cpp
T& operator*();
```

### 9. Address-of `&`
```cpp
SomeClass* operator&();
```

### 10. Stream Insertion/Extraction: `<<`, `>>`
```cpp
friend ostream& operator<<(ostream&, const Class&);
friend istream& operator>>(istream&, Class&);
```

### 11. Logical Operators: `!`, `&&`, `||`
```cpp
bool operator!() const;
```

### 12. Assignment `=`
```cpp
Class& operator=(const Class&);
```

### 13. Comma `,`
```cpp
Class operator,(const Class&);
```

### 14. Type Conversion
```cpp
operator int() const;
```

---

## 🧩 Tips
- Avoid overusing to maintain readability.
- Always return references for compound assignment.
- Provide `const` versions for operators like `[]`, `()`.
- Be consistent with behavior.

```cpp
#include <iostream>
using namespace std;

class Matrix {
private:
    int** data;
    int rows, cols;

    class Row {
    private:
        int* rowData;
    public:
        Row(int* rowData) : rowData(rowData) {}

        int& operator[](int col) {
            return rowData[col];
        }
    };

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new int[cols]{};
    }

    Row operator[](int row) {
        return Row(data[row]);
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }
};

int main() {
    Matrix mat(3, 3);

    mat[1][2] = 42;   // operator[][]

    cout << "mat[1][2] = " << mat[1][2] << endl;

    return 0;
}

```
---

```cpp
class Matrix {
private:
    int** data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[r];
        for (int i = 0; i < r; ++i)
            data[i] = new int[c]{};
    }

    int* operator[](int i) {
        return data[i];
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }
};

Matrix m(3, 4);
m[1][2] = 99;
cout << m[1][2];


```
---

## ✅ Two Common Ways to Overload `operator[]`

### 🟦 1. Returning a value:

```cpp
int operator[](int i) {
    return data[i];
}
```

### 🟩 2. Returning a pointer:

```cpp
int* operator[](int i) {
    return data[i];
}
```

---

## 🧠 What's the Practical Difference?

### ✅ 1. **Returning a value (`int`)**

* You return a **copy** of the data at index `i`.
* You **cannot modify** the original element through the return value.
* It's read-only.

🔹 Example:

```cpp
MyClass obj;
int x = obj[2];     // OK: you get a copy
obj[2] = 5;         // ❌ Error: cannot assign to a temporary int
```

---

### ✅ 2. **Returning a pointer (`int*`)**

* You return a **pointer to the element**.
* You can **read and write** the original data.
* You can do `obj[i][j]` if `operator[]` returns a pointer to a row.

🔹 Example:

```cpp
MyClass obj;
*obj[2] = 42;       // ✅ Modify the actual element
obj[2][3] = 10;     // ✅ If data is a 2D array, this works
```

---

## 📌 Summary Table

| Return Type | Meaning             | Usage        | Writable? |
| ----------- | ------------------- | ------------ | --------- |
| `int`       | Returns a copy      | Read-only    | ❌ No      |
| `int*`      | Returns a pointer   | Read & write | ✅ Yes     |
| `int&`      | Returns a reference | Read & write | ✅ Yes     |

---

## 🔁 Bonus: Returning a reference

```cpp
int& operator[](int i) {
    return data[i];
}
```

* Lets you modify the original data without returning a pointer.

* You can write:

  ```cpp
  obj[5] = 100;
  ```

* But you **cannot** do `obj[i][j]` unless you return a pointer to a row.

---

## ✅ Final Thoughts

* `int` → Copy of data (read-only).
* `int*` → Pointer to data (can be read/written; supports 2D access).
* `int&` → Reference to data (read/write access without pointer syntax).

---

## ✅ Background: Arrays and Pointers in C++

Let’s say you have a 2D array:

```cpp
int matrix[10][20];
```

In this case:

* `matrix` is a pointer to the first row → type: `int (*)[20]`
* `matrix[i]` is the `i`-th row → type: `int[20]`
* When you write:

  ```cpp
  matrix[i][j]
  ```

  It’s equivalent to:

  ```cpp
  *(*(matrix + i) + j)
  ```

Breakdown:

1. `matrix + i` → pointer to row `i`
2. `*(matrix + i)` → row `i` (decays to `int*`)
3. `*(... + j)` → element at column `j` in row `i`

---

## ✅ Why can we use `[][]` if `operator[]` returns a pointer?

Let’s suppose you have a class with a 2D array:

```cpp
int data[10][20];

int* operator[](int i) {
    return data[i];
}
```

Here’s what happens:

* `data[i]` is an array of 20 `int`s → `int[20]`
* When returned as `int*`, the array **decays** to a pointer to the first element of the row

So:

```cpp
obj[i]      // returns int* (pointer to the start of row i)
obj[i][j]   // equals *(obj[i] + j) → element in row i, column j
```

✅ This works just like using a regular 2D array.

---

## 🧠 Summary Table

| `operator[]` Return Type | Meaning          | Can Use `[][]`? | Why?                          |
| ------------------------ | ---------------- | --------------- | ----------------------------- |
| `int`                    | Value (copy)     | ❌ No            | Just a number, can't index it |
| `int&`                   | Reference to int | ❌ No            | Still a single value          |
| `int*`                   | Pointer to int   | ✅ Yes           | You can index a pointer       |

---

## 🔚 Real Example:

```cpp
class Matrix {
    int data[10][20];
public:
    int* operator[](int i) {
        return data[i];  // int[20] decays to int*
    }
};
```

Usage:

```cpp
Matrix m;
m[3][5] = 42;  // ✅ m[3] returns int*, then [5] gives element
```

---
