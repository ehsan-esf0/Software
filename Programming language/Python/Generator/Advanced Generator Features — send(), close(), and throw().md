# 🧠 **Lesson 6: Advanced Generator Features — `send()`, `close()`, and `throw()`**

### 🎯 What you’ll learn:

* How to interact with generators **from the outside**
* How to use the `send()` method to **send values** into a generator
* How to stop a generator using `close()`
* How to raise exceptions inside a generator using `throw()`
* Practical and interactive examples

---

## 🔹 1. Generators are more than just data producers

Generators can **receive data**, **handle exceptions**, and **respond dynamically** to external inputs.

To use these advanced features, your generator must:

* Use `yield` **as an expression**, not just a statement
* Be assigned to a variable so you can call `.send()` on it

---

## ✅ Example 1: Using `send()` to inject values

```python
def greeter():
    name = yield "What's your name?"
    yield f"Hello, {name}!"
```

### Usage:

```python
g = greeter()

print(next(g))         # ➜ "What's your name?"
print(g.send("Alice")) # ➜ "Hello, Alice!"
```

> 🔎 `yield` pauses and also **receives** a value from `.send(...)` when resumed.

---

### ⚠️ Important Note:

Before the first `yield`, you must use `next()` — not `send()`.
Trying to `send()` before the generator starts will cause a `TypeError`.

---

## 🔹 2. The `close()` method

`close()` tells the generator to **stop execution** and raise a `GeneratorExit` inside it.

### ✅ Example:

```python
def simple_gen():
    try:
        yield 1
        yield 2
    except GeneratorExit:
        print("Generator was closed.")

g = simple_gen()
print(next(g))   # 1
g.close()        # ➜ "Generator was closed."
```

> 🔎 This is useful to **clean up resources** (e.g., closing files or database connections) inside a generator.

---

## 🔹 3. The `throw()` method

`throw()` lets you raise an exception **inside the generator**, right at the point where it's paused at a `yield`.

### ✅ Example:

```python
def controlled_gen():
    try:
        yield "Ready"
    except ValueError:
        yield "ValueError caught!"
```

### Usage:

```python
g = controlled_gen()
print(next(g))           # ➜ "Ready"
print(g.throw(ValueError)) # ➜ "ValueError caught!"
```

---

## 🧠 Summary Table:

| Method      | Purpose                                        |
| ----------- | ---------------------------------------------- |
| `send(val)` | Sends a value into the generator at `yield`    |
| `close()`   | Stops the generator and raises `GeneratorExit` |
| `throw(ex)` | Raises an exception inside the generator       |
