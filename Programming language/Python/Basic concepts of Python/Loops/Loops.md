## 🔁 Loops in Python

**Loops** are used to **repeat a block of code** multiple times, either for a fixed number of iterations or while a condition holds true.

Python supports two primary types of loops:

1. `for` loop
2. `while` loop

---

## ✅ 1. `for` Loop

Used for **iterating over sequences** like lists, tuples, strings, dictionaries, or ranges.

### 📌 Basic Example:

```python
fruits = ["apple", "banana", "cherry"]

for fruit in fruits:
    print(fruit)
```

---

### ✅ Using `range()` with `for` loop:

```python
for i in range(5):  # 0 to 4
    print(i)
```

```python
for i in range(1, 6):  # 1 to 5
    print(i)
```

```python
for i in range(10, 0, -2):  # Countdown by 2
    print(i)
```

---

### ✅ Nested `for` Loop:

```python
for i in range(3):
    for j in range(2):
        print(f"i = {i}, j = {j}")
```

---

## ✅ 2. `while` Loop

Executes a block of code **as long as the condition is `True`**.

### 📌 Example:

```python
i = 0

while i < 5:
    print(i)
    i += 1
```

---

## 🔄 Loop Control Statements

### ✅ `break`:

**Exits the loop immediately.**

```python
for i in range(10):
    if i == 5:
        break
    print(i)
```

---

### ✅ `continue`:

**Skips the current iteration** and continues with the next one.

```python
for i in range(5):
    if i == 2:
        continue
    print(i)
```

---

### ✅ `else` with loops:

The `else` block runs **only if the loop finishes without hitting a `break`**.

```python
for i in range(5):
    print(i)
else:
    print("Loop finished normally")
```

---

## ✅ `for` vs `while` Comparison

| Feature               | `for` loop                         | `while` loop                    |
| --------------------- | ---------------------------------- | ------------------------------- |
| Main use              | Iterating over a sequence or range | Repeating while condition holds |
| Iteration control     | Predefined                         | Needs manual update             |
| Risk of infinite loop | Low                                | Higher if condition not handled |

---

## 🎯 Practical Example:

```python
password = ""

while password != "1234":
    password = input("Enter password: ")

print("Access granted!")
```

