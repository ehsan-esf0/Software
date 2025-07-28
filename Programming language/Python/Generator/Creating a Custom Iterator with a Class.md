# 🧠 **Lesson 2: Creating a Custom Iterator with a Class**

### 🎯 What you’ll learn:

* How to create a **custom iterator** using a Python class
* The role of `__iter__()` and `__next__()` methods
* How to control when iteration ends using `StopIteration`
* Lots of examples: from beginner to intermediate level

---

## 🔹 1. What makes a class an iterator?

A class becomes an **iterator** if it implements:

```python
def __iter__(self):    # returns the iterator object itself
def __next__(self):    # returns the next value in the sequence
```

---

## ✅ Example 1: A simple iterator that counts from 1 to 5

```python
class CountToFive:
    def __init__(self):
        self.num = 1

    def __iter__(self):
        return self

    def __next__(self):
        if self.num <= 5:
            result = self.num
            self.num += 1
            return result
        else:
            raise StopIteration
```

### Usage:

```python
counter = CountToFive()
for n in counter:
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

---

## ✅ Example 2: Iterator for even numbers up to `n`

```python
class EvenNumbers:
    def __init__(self, max_num):
        self.max = max_num
        self.current = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.current <= self.max:
            result = self.current
            self.current += 2
            return result
        else:
            raise StopIteration
```

### Usage:

```python
for x in EvenNumbers(10):
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

## 🔍 Why does `__iter__()` return `self`?

Because Python calls `__iter__()` first to get an **iterator object**, and then it keeps calling `__next__()` on that object.

If the object itself implements both methods, then `__iter__()` just returns `self`.

---

## ⚠️ Common mistake:

If you define `__next__()` but forget `__iter__()`, your object won’t work in a `for` loop.

---

## ✅ Example 3: Fibonacci iterator (a bit more advanced)

```python
class Fibonacci:
    def __init__(self, limit):
        self.a = 0
        self.b = 1
        self.limit = limit

    def __iter__(self):
        return self

    def __next__(self):
        if self.a > self.limit:
            raise StopIteration
        result = self.a
        self.a, self.b = self.b, self.a + self.b
        return result
```

### Usage:

```python
for n in Fibonacci(50):
    print(n)
```

**Output:**

```
0
1
1
2
3
5
8
13
21
34
```
