## 🎓 **Lesson 4: Decorators with Arguments in Python**

*(Enhancing decorators using `*args`, `**kwargs`, and external parameters)*

---

### ✅ Part 1: Decorating Functions That Take Arguments

If your target function takes arguments, your `wrapper` function must be able to accept any number of arguments.

#### 📌 Example 1: A decorator that supports arguments in the wrapped function

```python
def my_decorator(func):
    def wrapper(*args, **kwargs):
        print("Before function call")
        result = func(*args, **kwargs)
        print("After function call")
        return result
    return wrapper

@my_decorator
def greet(name):
    print(f"Hello, {name}!")

greet("Ehsan")
```

> 🧠 `*args` and `**kwargs` make the wrapper flexible for any kind of function.

---

### ✅ Part 2: Decorators That **Take Their Own Arguments**

In this case, we add **one extra layer**:

> A function that returns a decorator!

#### 📌 Example 2: A decorator with a custom message parameter

```python
def custom_decorator(message):
    def actual_decorator(func):
        def wrapper(*args, **kwargs):
            print(f"[{message}] Before")
            result = func(*args, **kwargs)
            print(f"[{message}] After")
            return result
        return wrapper
    return actual_decorator

@custom_decorator("LOG")
def say_hi(name):
    print(f"Hi, {name}!")

say_hi("Sara")
```

🔍 **How it works:**

1. `custom_decorator("LOG")` runs and returns `actual_decorator`
2. `actual_decorator` takes your function and wraps it in `wrapper`
3. `wrapper` adds behavior before and after the original function

---

### ✅ Part 3: Using `functools.wraps` (To Preserve Original Function Metadata)

By default, decorators overwrite function metadata (like `__name__`, `__doc__`).
To **preserve the original function’s identity**, use `functools.wraps`.

#### 📌 Example 3: Using `functools.wraps`

```python
import functools

def my_decorator(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        print("Running decorated function")
        return func(*args, **kwargs)
    return wrapper

@my_decorator
def greet(name):
    """Greets a person by name"""
    print(f"Hello, {name}!")

print(greet.__name__)  # Output: greet
print(greet.__doc__)   # Output: Greets a person by name
```

---

### ✅ Key Takeaways

| Topic                  | Description                                               |
| ---------------------- | --------------------------------------------------------- |
| `*args`, `**kwargs`    | Used in wrappers to handle any input                      |
| Decorators with params | Use 3 layers: outer function → actual decorator → wrapper |
| `functools.wraps`      | Keeps original function’s metadata intact                 |
