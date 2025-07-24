# 🧮 **Lesson 2: Using Functions and Classes in Modules**

---

## 🎯 **Objectives:**

* Learn how to define functions and classes in modules
* Use them via import in other files
* Understand the `__name__ == "__main__"` block for testing
* Explore best practices in module design

---

## 📘 1. **Defining Functions in a Module**

### File: `calc_utils.py`

```python
def add(x, y):
    return x + y

def multiply(x, y):
    return x * y

def power(x, y):
    return x ** y
```

### Usage:

```python
# main.py
from calc_utils import add, power

print(add(2, 3))    # 5
print(power(2, 4))  # 16
```

---

## 🧱 2. **Defining a Class in a Module**

### File: `person.py`

```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def greet(self):
        print(f"Hello! I am {self.name}.")
```

### Usage:

```python
# main.py
from person import Person

p = Person("Ali", 22)
p.greet()  # Hello! I am Ali.
```

---

## ⚙️ 3. **Combining Functions and Classes in One Module**

### File: `shapes.py`

```python
PI = 3.14159

def circle_area(radius):
    return PI * radius ** 2

class Rectangle:
    def __init__(self, w, h):
        self.w = w
        self.h = h

    def area(self):
        return self.w * self.h
```

---

## 🧠 4. **Using `__name__ == "__main__"` for Testing**

```python
# shapes.py
def test():
    print(circle_area(3))  # Only runs when executed directly

if __name__ == "__main__":
    test()
```

* When run directly → it executes `test()`
* When imported → it doesn't run `test()`

---

## 🧰 5. **Good Practices for Module Design**

| Tip                                        | Why                                    |
| ------------------------------------------ | -------------------------------------- |
| Use clear, descriptive names               | e.g., `math_utils.py`, `file_tools.py` |
| Separate logic using classes and functions | Clean code, easy testing               |
| Use `_` prefix for internal functions      | e.g., `_validate_input()`              |
| Use `__name__ == "__main__"` to test       | Lightweight internal testing           |

---

## ✅ Lesson 2 Summary

| Concept                  | Explanation                                |
| ------------------------ | ------------------------------------------ |
| Function in module       | Define and reuse simple logic              |
| Class in module          | Bundle behavior and state                  |
| Mix classes/functions    | One module can have both                   |
| `__name__ == "__main__"` | Run test code only when executing directly |