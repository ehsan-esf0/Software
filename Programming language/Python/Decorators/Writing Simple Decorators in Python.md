## 🎓 **Lesson 3: Writing Simple Decorators in Python**

*(Your first hands-on step into the world of decorators)*

---

### ✅ Part 1: What Is a Decorator?

A **decorator** in Python is a function that:

* **Takes another function as input**
* And **returns a new function**, usually adding some behavior **before or after** the original function runs.

> 🔥 This allows you to **enhance or modify a function’s behavior without changing its code** — very powerful!

---

### ✅ Part 2: Writing a Basic Decorator

#### 📌 Basic structure:

```python
def my_decorator(func):
    def wrapper():
        print("Before the function runs")
        func()
        print("After the function runs")
    return wrapper
```

Now let’s apply this decorator to another function:

```python
def say_hello():
    print("Hello!")

decorated = my_decorator(say_hello)
decorated()
```

#### 📤 Output:

```
Before the function runs  
Hello!  
After the function runs
```

---

### ✅ Part 3: Using the `@` Symbol (Syntactic Sugar)

Python allows a cleaner way to apply a decorator:

```python
@my_decorator
def say_hi():
    print("Hi!")

say_hi()
```

> 🔍 This is exactly the same as: `say_hi = my_decorator(say_hi)`

---

### ✅ Part 4: Decorating a Function That Takes Arguments

We need to use `*args` and `**kwargs` to handle any number of arguments:

```python
def my_decorator(func):
    def wrapper(*args, **kwargs):
        print("Before the function")
        result = func(*args, **kwargs)
        print("After the function")
        return result
    return wrapper

@my_decorator
def greet(name):
    print(f"Hello, {name}!")

greet("Ehsan")
```

---

### ✅ Part 5: Common Uses of Decorators

| Use Case       | Description                           |
| -------------- | ------------------------------------- |
| Logging        | Track function calls, arguments, etc. |
| Access control | Check permissions before execution    |
| Caching        | Store results for reuse               |
| Timing         | Measure execution time                |

---

### ✅ Part 6: Reusable Decorators

You can use a single decorator across many functions:

```python
@my_decorator
def add(a, b):
    print(f"Result: {a + b}")

add(2, 3)
```

---

### ✅ Key Points Recap:

* `@decorator_name` means the function is being passed to a decorator.
* Always use `*args` and `**kwargs` in your wrapper to keep it flexible.
* Decorators don’t modify the original function — they **wrap** it and **add extra behavior**.

