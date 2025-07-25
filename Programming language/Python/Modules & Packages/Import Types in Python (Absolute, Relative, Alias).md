# 🔄 **Lesson 4: Import Types in Python (Absolute, Relative, Alias)**

---

## 🎯 **Objectives:**

* Understand **absolute vs relative imports**
* Use **aliasing** to simplify code
* Handle **import errors and `sys.path` issues**
* Learn where and when to use each import style

---

## 🧭 1. **Absolute Import**

Importing using the **full path** from the top of your project or package.

### Example Project Structure:

```
project/
├── main.py
└── my_package/
    ├── __init__.py
    └── tools.py
```

### Code:

```python
from my_package import tools
# or
from my_package.tools import my_function
```

✅ Clear, preferred in large projects
✅ Works in any context

---

## 🔁 2. **Relative Import**

Importing based on the **current file's location**.

| Syntax | Example                        | Meaning           |
| ------ | ------------------------------ | ----------------- |
| `.`    | `from . import tools`          | same folder       |
| `..`   | `from ..utils import helper`   | go one folder up  |
| `...`  | `from ...core.base import run` | go two folders up |

### In `my_package/__init__.py`:

```python
from .tools import my_function
```

---

### ⚠️ Notes on Relative Import

* Only works inside **packages** (folders with `__init__.py`)
* **Does NOT work** in directly executed scripts
* Great for **internal imports within a package**

---

## 🧰 3. **Using Aliases (`as`)**

Used to simplify long or conflicting names.

```python
import numpy as np
import pandas as pd
from my_package.tools import my_function as mf

mf()
```

✅ Clean, short, and widely used in professional codebases

---

## 🧠 4. **How Python Finds Modules — `sys.path`**

Python looks in all paths listed in `sys.path` to find modules.

```python
import sys
print(sys.path)
```

### Manually adding a path:

```python
sys.path.append('/path/to/my/custom_modules')
```

> Useful in Jupyter, custom scripts, or large repo structures

---

## 🧨 5. **Common Import Errors**

| Error                                      | Reason                                          |
| ------------------------------------------ | ----------------------------------------------- |
| `ModuleNotFoundError`                      | Wrong path or file doesn't exist                |
| `ImportError`                              | The thing you're trying to import doesn't exist |
| `ValueError: attempted relative import...` | Used relative import in non-package script      |

---

## ✅ Summary

| Import Type | Use Case                 | Advantage                   |
| ----------- | ------------------------ | --------------------------- |
| Absolute    | Top-level access         | Clean and universal         |
| Relative    | Internal package imports | Keeps structure modular     |
| Alias       | Short, clear naming      | Improves readability        |
| `sys.path`  | Manual path control      | Fixes complex import issues |
