# ✅ What is List Comprehension?

**List Comprehension** is a **concise**, **elegant**, and **Pythonic** way to create lists from iterables such as `range()`, `lists`, `strings`, etc.

Instead of writing a loop and using `append()`, you can use one **expression** to build a list.

---

## 🔹 Basic Syntax

```python
[expression for item in iterable]
```

🔸 This is equivalent to:

```python
result = []
for item in iterable:
    result.append(expression)
```

### 🔸 Example:

```python
squares = [x**2 for x in range(5)]   # [0, 1, 4, 9, 16]
```

---

## 🔹 With Condition (if)

```python
[expression for item in iterable if condition]
```

### 🔸 Example:

```python
evens = [x for x in range(10) if x % 2 == 0]   # [0, 2, 4, 6, 8]
```

---

## 🔹 With if-else (Ternary Operator)

You can include `if-else` in the expression part:

```python
[true_value if condition else false_value for item in iterable]
```

### 🔸 Example:

```python
labels = ['even' if x % 2 == 0 else 'odd' for x in range(5)]
# ['even', 'odd', 'even', 'odd', 'even']
```

⚠️ Note: You **cannot** use both `if-else` and filtering `if` at the same time **after** the `for` — only in the expression.

---

## 🔹 Nested List Comprehension

Used when you're working with **2D lists**, matrices, or generating combinations.

### 🔸 Flatten a 2D list:

```python
matrix = [[1, 2], [3, 4], [5, 6]]
flattened = [elem for row in matrix for elem in row]  # [1, 2, 3, 4, 5, 6]
```

### 🔸 Multiplication table:

```python
table = [[i * j for j in range(1, 6)] for i in range(1, 6)]
```

---

## 🔹 With Multiple Conditions

```python
[x for x in range(20) if x % 2 == 0 if x > 10]
# [12, 14, 16, 18]
```

You can chain multiple `if` conditions.

---

## 🔹 With Functions

List comprehensions can call functions:

```python
def square(x):
    return x * x

results = [square(x) for x in range(5)]   # [0, 1, 4, 9, 16]
```

---

## 🔹 Working with Strings

```python
chars = [c.upper() for c in 'python']     # ['P', 'Y', 'T', 'H', 'O', 'N']
vowels = [c for c in 'alphabet' if c in 'aeiou']
```

---

## 🔹 Cartesian Product (like nested loops)

```python
colors = ['red', 'green']
items = ['hat', 'shirt']

pairs = [(color, item) for color in colors for item in items]
# [('red', 'hat'), ('red', 'shirt'), ('green', 'hat'), ('green', 'shirt')]
```

---

## 🔹 Practical Use Cases

| Task            | Example                                      |
| --------------- | -------------------------------------------- |
| Filtering       | `[x for x in nums if x > 10]`                |
| Transformation  | `[x**2 for x in nums]`                       |
| Flattening      | `[elem for sub in nested for elem in sub]`   |
| Combining       | `[a + b for a, b in zip(list1, list2)]`      |
| Removing spaces | `[word.strip() for word in line.split(',')]` |

---

## 🔹 List Comprehension vs Regular Loop

### 🔸 Regular Loop

```python
result = []
for i in range(10):
    if i % 2 == 0:
        result.append(i)
```

### 🔸 List Comprehension

```python
result = [i for i in range(10) if i % 2 == 0]
```

✅ List comprehension is **shorter**, **more readable**, and often **faster**.

---

## 🔹 Performance Consideration

List comprehensions are **usually faster** than using a loop with `append()`.

You can benchmark it with the `timeit` module:

```python
import timeit
timeit.timeit('[x**2 for x in range(1000)]')
```

---

## 🔹 Comprehensions for Other Types

* **Set Comprehension**: `{x for x in range(10)}`
* **Dict Comprehension**: `{x: x**2 for x in range(5)}`
* **Generator Expression**: `(x for x in range(5))`

---

## ✅ Summary

| Feature          | Supported?                  |
| ---------------- | --------------------------- |
| If filtering     | ✅                           |
| If-else in expr  | ✅                           |
| Nested loops     | ✅                           |
| Function calls   | ✅                           |
| Multiple filters | ✅                           |
| Complex logic    | ❌ (better use regular loop) |

