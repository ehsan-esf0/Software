# 🧩 **Lesson 1: Introduction to Python Modules**

---

## 🎯 **Goal of This Lesson:**

* Understand what a **module** is in Python
* Learn how to **import** and use modules in different ways
* Create your **first custom module**
* Explore **built-in standard modules** in Python

---

## 📘 1. What is a Module?

A **module** in Python is a **`.py` file** that contains Python code — usually **functions, classes, or variables** — which can be reused in other programs using the `import` statement.

---

## ✅ 2. Why Use Modules?

| Benefit              | Description                                    |
| -------------------- | ---------------------------------------------- |
| Better organization  | Keep code clean and structured across files    |
| Reusability          | Use the same logic across multiple projects    |
| Improved readability | Each module does one task — easier to maintain |

---

## 🧪 3. Creating Your First Module

Create a file named `math_utils.py`:

```python
# math_utils.py
def add(x, y):
    return x + y

def subtract(x, y):
    return x - y

PI = 3.14159
```

---

## 📥 4. Different Ways to Import a Module

Assuming `math_utils.py` is in the same directory as your main script.

### ✅ Method 1: Full import

```python
import math_utils

print(math_utils.add(5, 2))     # 7
print(math_utils.PI)            # 3.14159
```

---

### ✅ Method 2: Import specific item

```python
from math_utils import add

print(add(4, 6))  # 10
```

---

### ✅ Method 3: Import with alias

```python
import math_utils as mu

print(mu.subtract(10, 3))  # 7
```

---

### ⚠️ Method 4: Import everything (not recommended)

```python
from math_utils import *

print(add(2, 2))  # 4
```

> ❗ This can cause naming conflicts and make the code harder to read.

---

## 📚 5. Using Python’s Standard Library Modules

Python has many built-in modules you can use right away.

### Example:

```python
import math

print(math.sqrt(16))     # 4.0
print(math.factorial(5)) # 120
```

---

## 🧠 6. The `__name__ == "__main__"` Trick

Inside every Python file, there’s a special variable: `__name__`.

```python
# my_module.py
def greet():
    print("Hello!")

if __name__ == "__main__":
    greet()
```

* If the file is run **directly**, `greet()` will be called.
* If the file is **imported as a module**, it will not execute `greet()`.

---

## 🧾 Lesson 1 Summary

| Topic             | Explanation                                                     |
| ----------------- | --------------------------------------------------------------- |
| Module            | A `.py` file with code that can be imported elsewhere           |
| Importing Modules | Use `import`, `from`, `as`, or `*`                              |
| Direct Execution  | Use `__name__ == "__main__"` to run only when executed directly |
| Standard Modules  | Built-in modules like `math`, `os`, `random`                    |