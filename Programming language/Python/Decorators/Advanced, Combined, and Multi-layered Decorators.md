## 🎓 **Lesson 6: Advanced, Combined, and Multi-layered Decorators**

*(Stacking decorators, conditional logic, framework usage, and generic patterns)*

---

### ✅ Part 1: Using Multiple Decorators on One Function

Python lets you apply **multiple decorators** to a single function — they are **stacked**.

#### 📌 Example 1: Stacked decorators

```python
def bold(func):
    def wrapper(*args, **kwargs):
        return f"<b>{func(*args, **kwargs)}</b>"
    return wrapper

def italic(func):
    def wrapper(*args, **kwargs):
        return f"<i>{func(*args, **kwargs)}</i>"
    return wrapper

@bold
@italic
def get_text():
    return "Hello"

print(get_text())  # Output: <b><i>Hello</i></b>
```

> 🔍 Decorators are applied from **bottom to top**. First `italic`, then `bold`.

---

### ✅ Part 2: Conditional Decorators (Dynamic Behavior)

You can write decorators that behave **differently based on conditions or parameters**.

#### 📌 Example 2: Conditional logging decorator

```python
def conditional_log(enabled):
    def decorator(func):
        def wrapper(*args, **kwargs):
            if enabled:
                print(f"[LOG] Calling {func.__name__}")
            return func(*args, **kwargs)
        return wrapper
    return decorator

@conditional_log(True)
def run():
    print("Running...")

run()
```

---

### ✅ Part 3: Generic, Reusable Decorators

Using `*args`, `**kwargs`, and `functools.wraps`, you can write decorators that work on **any type of function**.

#### 📌 Example 3: Timing decorator

```python
import time
from functools import wraps

def timing(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print(f"{func.__name__} took {end - start:.4f} seconds")
        return result
    return wrapper

@timing
def slow_function():
    time.sleep(1)
    return "Done"

print(slow_function())
```

---

### ✅ Part 4: Decorators in Frameworks (Flask, Django, etc.)

Decorators are heavily used in popular Python web frameworks like Flask and Django.

#### 📌 Example 4: Decorator in Flask

```python
from flask import Flask

app = Flask(__name__)

@app.route("/")
def home():
    return "Hello, Flask!"
```

> `@app.route("/")` is a decorator that **registers the function** as a handler for the root URL `/`.

---

### ✅ Full Summary

| Feature               | Purpose                                |
| --------------------- | -------------------------------------- |
| Multiple decorators   | Stack multiple behaviors on a function |
| Conditional logic     | Enable/disable behaviors dynamically   |
| Generic wrappers      | Work with any function signature       |
| Framework integration | Core part of tools like Flask/Django   |

