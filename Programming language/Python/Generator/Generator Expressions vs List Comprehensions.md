# 🧠 **Lesson 5: Generator Expressions vs List Comprehensions in Python**

### 🎯 What you’ll learn:

* What a **generator expression** is and how to write one
* The difference between **generator expressions** and **list comprehensions**
* When to use each one (memory, performance, readability)
* Practical examples and comparisons

---

## 🔹 1. What is a Generator Expression?

A **generator expression** is a **compact syntax** to create a generator — similar to a list comprehension, but it uses **round brackets `()`** instead of square brackets `[]`.

✅ **Syntax:**

```python
(expression for item in iterable if condition)
```

---

### ✅ Example 1: Square numbers using generator expression

```python
gen = (x*x for x in range(5))
print(next(gen))  # 0
print(next(gen))  # 1
```

### ✅ Same with list comprehension:

```python
lst = [x*x for x in range(5)]
print(lst)  # [0, 1, 4, 9, 16]
```

> 📌 List comprehension creates and stores **all elements in memory**,
> but generator expression **produces them one by one** (lazy evaluation).

---

## 🔸 2. Key Differences: Generator Expression vs List Comprehension

| Feature                | List Comprehension       | Generator Expression        |
| ---------------------- | ------------------------ | --------------------------- |
| Syntax                 | `[ ... ]`                | `( ... )`                   |
| Returns                | List                     | Generator object (iterator) |
| Memory usage           | Loads everything at once | Loads one item at a time    |
| Speed (for small data) | Faster                   | Slower (slightly)           |
| Suitable for           | Small to medium data     | Large data / streaming      |

---

### ✅ Example 2: Compare memory usage

```python
import sys

lst = [x for x in range(1000000)]
gen = (x for x in range(1000000))

print("List:", sys.getsizeof(lst))  # Large
print("Generator:", sys.getsizeof(gen))  # Very small
```

---

## ✅ Example 3: Filter even numbers

```python
evens = (x for x in range(10) if x % 2 == 0)
for n in evens:
    print(n)
```

**Output:**

```
0
2
4
6
8
```

---

## ✅ Example 4: Using with `sum()` and `any()` directly

```python
# Sum of squares using generator
total = sum(x*x for x in range(100))
print(total)

# Check if any number is divisible by 7
check = any(x % 7 == 0 for x in range(10, 20))
print(check)  # True
```

---

## 🧠 When should you use each?

### Use **list comprehension** when:

* You need to **reuse the result multiple times**
* The data is **small or moderate in size**

### Use **generator expression** when:

* You only need to iterate **once**
* The data is **large**, or performance/memory matters
* You're passing data to a function like `sum()`, `max()`, `any()`, etc.

