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

