# 📦 **Lesson 3: Introduction to Python Packages**

---

## 🎯 **Objectives:**

* Understand what a **package** is in Python
* Learn the **folder structure** of packages
* Create your **own package**
* Import from **packages and subpackages**
* Understand the role of `__init__.py`

---

## 🧩 1. What is a Package?

A **package** is a **directory** that contains multiple modules or other packages, and **must include** a file named `__init__.py`.

> Package = Folder + `__init__.py`

---

## 📁 2. Package Structure Example

```
my_package/
│
├── __init__.py
├── math_utils.py
├── string_utils.py
└── geometry/
    ├── __init__.py
    └── shapes.py
```

---

## 🛠 3. Creating a Custom Package

### Step 1: Create the folder

```
mkdir my_package
```

### Step 2: Add files

#### `my_package/math_utils.py`

```python
def add(x, y):
    return x + y
```

#### `my_package/__init__.py`

```python
from .math_utils import add
```

---

## 📥 4. Importing from a Package

```python
from my_package import add

print(add(2, 3))  # 5
```

Or:

```python
import my_package.math_utils as mu

print(mu.add(1, 1))  # 2
```

---

## 📂 5. Creating a Subpackage

### `my_package/geometry/shapes.py`

```python
class Rectangle:
    def __init__(self, w, h):
        self.w = w
        self.h = h

    def area(self):
        return self.w * self.h
```

### `my_package/geometry/__init__.py`

```python
from .shapes import Rectangle
```

### Usage:

```python
from my_package.geometry import Rectangle

r = Rectangle(4, 5)
print(r.area())  # 20
```

---

## 🧠 6. Role of `__init__.py`

* Makes Python recognize the folder as a package
* Can include imports and default exports
* Can be empty or contain logic

> Without it, Python may not recognize the folder as a package in older versions.

---

## ✅ Lesson 3 Summary

| Topic             | Description                                    |
| ----------------- | ---------------------------------------------- |
| Package           | A folder with Python modules and `__init__.py` |
| Subpackage        | A subfolder that’s also a package              |
| `__init__.py`     | Initializes the package and controls imports   |
| Modular structure | Helps organize large projects                  |

