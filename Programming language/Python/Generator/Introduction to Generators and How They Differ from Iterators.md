# 🧠 **Lesson 3: Introduction to Generators and How They Differ from Iterators**

### 🎯 What you’ll learn:

* What **generators** are in Python
* How they **simplify** writing iterators
* How `yield` works and how it's different from `return`
* Benefits of using generators (like memory efficiency)
* Lots of practical examples

---

## 🔹 1. What is a Generator?

A **generator** is a special type of iterator that's created using a **function with the `yield` keyword** instead of a class.

It automatically:

* Keeps track of its own state
* Implements both `__iter__()` and `__next__()` behind the scenes

---

## ✅ Example 1: Simple generator that yields numbers from 1 to 5

```python
def count_to_five():
    num = 1
    while num <= 5:
        yield num
        num += 1
```

### Usage:

```python
for n in count_to_five():
    print(n)
```

**Output:**

```
1
2
3
4
5
```

> 🔎 `yield` pauses the function and resumes from that point on the next iteration.

---

## 🔸 2. `yield` vs `return`

| `return`                 | `yield`                         |
| ------------------------ | ------------------------------- |
| Ends the function        | Pauses and resumes the function |
| Returns one value        | Returns one value **at a time** |
| Used in normal functions | Used in generator functions     |

---

## ✅ Example 2: Generator vs List (Memory Comparison)

Let’s compare how a generator saves memory compared to a list:

```python
def generate_numbers():
    for i in range(1000000):
        yield i
```

```python
# This won't load all 1 million numbers into memory:
g = generate_numbers()
print(next(g))  # 0
print(next(g))  # 1
```

> ✅ Generators use **lazy evaluation** — they compute values only when needed.

---

## ✅ Example 3: Generator that yields even numbers up to n

```python
def even_numbers(n):
    for i in range(0, n + 1, 2):
        yield i
```

```python
for x in even_numbers(10):
    print(x)
```

**Output:**

```
0
2
4
6
8
10
```

---

## 🔍 How is a generator different from a class-based iterator?

| Feature        | Class-based Iterator          | Generator Function            |
| -------------- | ----------------------------- | ----------------------------- |
| Verbosity      | More boilerplate code         | Very concise                  |
| State handling | Manual (you track everything) | Automatic (Python handles it) |
| Memory usage   | Can be efficient              | Very efficient (lazy eval)    |
| Readability    | Lower (for beginners)         | Higher (easier to follow)     |

---

## ✅ Example 4: Generator that reads a file line-by-line

```python
def read_file_lines(filepath):
    with open(filepath, "r") as f:
        for line in f:
            yield line.strip()
```

This way, even large files can be read one line at a time, without loading everything into memory.

