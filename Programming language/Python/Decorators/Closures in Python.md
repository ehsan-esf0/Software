## 🎓 **Lesson 2: Closures in Python**

---

### ✅ Part 1: What Is a Closure?

A **closure** happens when an **inner function** remembers and has access to variables from its **outer (enclosing) function**, **even after the outer function has finished executing**.

> 🔥 In other words: the inner function “remembers” its surrounding context.

---

### ✅ Part 2: Why Are Closures Important?

Closures allow you to create **custom functions with their own state**, without using classes — which is **essential for decorators**.

---

### ✅ Part 3: Basic Structure of a Closure

#### 📌 Example 1: Simple closure

```python
def outer():
    x = "Python"
    def inner():
        print(f"I love {x}")
    return inner

my_func = outer()
my_func()  # Output: I love Python
```

🔍 **Explanation:**

* When `outer()` runs, it defines `x = "Python"`.
* The inner function `inner()` uses `x`.
* Even after `outer()` has finished, `my_func()` can still access `x` — that’s a closure.

---

### ✅ Part 4: Closures with Dynamic Values

#### 📌 Example 2: Creating customized functions using closures

```python
def power(n):
    def calc(x):
        return x ** n
    return calc

square = power(2)
cube = power(3)

print(square(5))  # Output: 25
print(cube(2))    # Output: 8
```

> `square` and `cube` are two different functions that each remember their own `n`.

---

### ✅ Part 5: Inspecting Closures

You can check if a function is a closure by looking at its `.__closure__` attribute:

```python
print(square.__closure__)
print(square.__closure__[0].cell_contents)  # Output: 2
```

---

### ✅ Common Uses of Closures

| Use Case                   | Description                          |
| -------------------------- | ------------------------------------ |
| Retaining state            | Without using classes                |
| Custom function generators | Like decorators with internal config |
| Data hiding                | Encapsulation of variables           |

---

### ✅ Key Takeaways

* A **closure** is a function that captures and remembers variables from its outer scope.
* Closures are foundational for writing decorators, where a function needs to retain extra information.
* Examples like `power`, `calc`, and `inner` demonstrate how closures preserve state and customize behavior.
