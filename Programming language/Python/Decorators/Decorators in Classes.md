## 🎓 **Lesson 5: Decorators in Classes**

*(Using decorators inside classes — built-in, custom, and class-based ones)*

---

### ✅ Part 1: Common Built-in Method Decorators

Python provides several **built-in decorators** specifically for use in classes:

| Decorator       | Purpose                                                                    |
| --------------- | -------------------------------------------------------------------------- |
| `@staticmethod` | Defines a method with **no access to `self` or `cls`**                     |
| `@classmethod`  | Defines a method that receives the **class (`cls`) as the first argument** |
| `@property`     | Turns a method into a **read-only attribute**                              |

---

#### 📌 Example 1: `@staticmethod` and `@classmethod`

```python
class Person:
    name = "Default"

    @staticmethod
    def say_hello():
        print("Hi! I don't need self.")

    @classmethod
    def set_name(cls, new_name):
        cls.name = new_name
```

---

### ✅ Part 2: Custom Decorators for Class Methods

Just like regular functions, you can apply custom decorators to **methods** inside classes.

#### 📌 Example 2: Logging method calls

```python
def log_method(func):
    def wrapper(*args, **kwargs):
        print(f"[LOG] Calling: {func.__name__}")
        return func(*args, **kwargs)
    return wrapper

class Calculator:
    @log_method
    def add(self, a, b):
        return a + b

calc = Calculator()
print(calc.add(2, 3))  # Output: [LOG] Calling: add → 5
```

---

### ✅ Part 3: Writing a Class-Based Decorator

So far, all decorators were written as functions. You can also write decorators **as classes** — if the class defines a `__call__()` method, it acts like a function.

#### 📌 Example 3: Class as a decorator

```python
class MyDecorator:
    def __init__(self, func):
        self.func = func

    def __call__(self, *args, **kwargs):
        print("Before call")
        result = self.func(*args, **kwargs)
        print("After call")
        return result

@MyDecorator
def greet(name):
    print(f"Hello, {name}")

greet("Ehsan")
```

> 🔥 Note: The class becomes "callable" by implementing `__call__`.

---

### ✅ Part 4: Combining Decorators with Methods

You can use decorators to enforce rules on methods — for example, access control.

#### 📌 Example 4: Restricting access to a method

```python
def require_admin(func):
    def wrapper(self, *args, **kwargs):
        if not self.is_admin:
            raise PermissionError("You are not admin!")
        return func(self, *args, **kwargs)
    return wrapper

class User:
    def __init__(self, name, is_admin):
        self.name = name
        self.is_admin = is_admin

    @require_admin
    def delete_account(self):
        print("Account deleted.")

admin = User("Ali", True)
admin.delete_account()  # Works fine

guest = User("Sara", False)
# guest.delete_account()  ← Raises PermissionError
```

---

### ✅ Key Takeaways

| Topic                  | Description                                         |
| ---------------------- | --------------------------------------------------- |
| Built-in decorators    | `@staticmethod`, `@classmethod`, `@property`        |
| Decorating methods     | Same as functions, but includes `self` or `cls`     |
| Class-based decorators | Use `__call__` method to act like a function        |
| Method validation      | Use decorators to enforce rules like access control |

