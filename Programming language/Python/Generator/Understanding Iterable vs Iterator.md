## 🧠 Lesson 1: Understanding Iterable vs Iterator in Python

### 🎯 Objective:

By the end of this lesson, you’ll understand:

* What **iterables** and **iterators** are
* How `for` loops work under the hood
* How to use `iter()` and `next()`
* What `StopIteration` means
* The difference between a list and an iterator in terms of memory and behavior

---

## 🔹 1. What is an Iterable?

An **iterable** is any Python object that can return its elements one at a time.

📌 Common iterable types in Python:

```python
list, tuple, string, dict, set, file
```

✅ Example:

```python
for char in "python":
    print(char)
```

This works because `"python"` is an **iterable**.

---

## 🔹 2. What is an Iterator?

An **iterator** is an object that:

* Implements a method `__next__()` to return the next item
* Implements `__iter__()` which returns the iterator itself

Think of it like a cursor that moves through the iterable.

---

## ✅ Example: Iterable vs Iterator

```python
numbers = [1, 2, 3]   # This is an iterable
it = iter(numbers)    # This is an iterator

print(next(it))  # 1
print(next(it))  # 2
print(next(it))  # 3
print(next(it))  # Error: StopIteration
```

> 🔎 `numbers` is iterable, not an iterator. `iter(numbers)` creates an iterator from it.

---

## 🔍 What happens inside a `for` loop?

This:

```python
for x in [1, 2, 3]:
    print(x)
```

Internally behaves like this:

```python
it = iter([1, 2, 3])
while True:
    try:
        x = next(it)
        print(x)
    except StopIteration:
        break
```

---

## 🔸 3. The `iter()` and `next()` functions

| Function    | Purpose                               |
| ----------- | ------------------------------------- |
| `iter(obj)` | Creates an iterator from an iterable  |
| `next(it)`  | Returns the next item in the iterator |

🛑 If no more items are left, `next()` raises a `StopIteration` exception.

---

## 🧪 Examples:

### ✅ Example 1: Iterating over a string manually

```python
word = "hello"
it = iter(word)

print(next(it))  # h
print(next(it))  # e
print(next(it))  # l
```

---

### ✅ Example 2: Dictionary items

```python
d = {"a": 1, "b": 2}
it = iter(d.items())

print(next(it))  # ('a', 1)
print(next(it))  # ('b', 2)
```

---

### ✅ Example 3: StopIteration

```python
lst = [42]
it = iter(lst)

print(next(it))  # 42
print(next(it))  # StopIteration error
```

---

## 🔎 How to check if something is Iterable or Iterator

Use `collections.abc`:

```python
from collections.abc import Iterable, Iterator

print(isinstance([1, 2, 3], Iterable))  # True
print(isinstance([1, 2, 3], Iterator))  # False

it = iter([1, 2, 3])
print(isinstance(it, Iterator))        # True
```

---

## 💡 Key Points:

* Every **iterator** is also an **iterable** (i.e. `it.__iter__() == it`)
* Not every iterable is an iterator (lists, strings, etc.)
* `for` loop hides the complexity of calling `next()` and catching `StopIteration`