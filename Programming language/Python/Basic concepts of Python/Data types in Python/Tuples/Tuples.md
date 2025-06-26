# 📌 Tuples in Python 

## 🔹 1. What is a Tuple?

A **tuple** is a built-in **immutable**, **ordered** data structure in Python used to store a **collection of items**.

### 🔸 Syntax:

```python
my_tuple = (1, 2, 3)
```

---

## 🔹 2. Key Characteristics

| Property          | Tuple |
| ----------------- | ----- |
| Ordered           | ✅     |
| Mutable           | ❌     |
| Allows Duplicates | ✅     |
| Iterable          | ✅     |

---

## 🔹 3. Creating Tuples

### 🔸 Basic tuple:

```python
t = (1, 2, 3)
```

### 🔸 With mixed data types:

```python
t = (1, "hello", 3.14, True)
```

### 🔸 Empty tuple:

```python
t = ()
```

### 🔸 Single-element tuple (with comma):

```python
t = (5,)      # Correct
t = (5)       # Not a tuple, just an int
```

---

## 🔹 4. Accessing Elements

Like lists, tuples are **indexed from 0**:

```python
t = (10, 20, 30)
print(t[0])     # 10
print(t[-1])    # 30
```

---

## 🔹 5. Tuple Slicing

```python
t = (1, 2, 3, 4, 5)

print(t[1:4])    # (2, 3, 4)
print(t[:3])     # (1, 2, 3)
```

---

## 🔹 6. Immutability

Tuples **cannot be changed** after creation:

```python
t = (1, 2, 3)
t[0] = 10        # ❌ Error: 'tuple' object does not support item assignment
```

However, if a tuple contains **mutable items** like a list, the list can be changed:

```python
t = (1, [2, 3])
t[1][0] = 99
print(t)         # (1, [99, 3])
```

---

## 🔹 7. Tuple Packing and Unpacking

### 🔸 Packing:

```python
person = ("Alice", 30, "Engineer")
```

### 🔸 Unpacking:

```python
name, age, job = person
```

### 🔸 Using `_` for unused variables:

```python
name, _, job = person
```

---

## 🔹 8. Iterating Through a Tuple

```python
t = (1, 2, 3)
for item in t:
    print(item)
```

---

## 🔹 9. Tuple Methods

Tuples have **limited methods** compared to lists.

| Method      | Description                    |
| ----------- | ------------------------------ |
| `.count(x)` | Counts occurrences of value x  |
| `.index(x)` | Returns first index of value x |

```python
t = (1, 2, 2, 3)
print(t.count(2))   # 2
print(t.index(2))   # 1
```

---

## 🔹 10. When to Use Tuples Instead of Lists?

| Use Tuples When...             | Reason                              |
| ------------------------------ | ----------------------------------- |
| Data shouldn't change          | Immutability ensures safety         |
| Used as keys in a dictionary   | Tuples are hashable, lists aren't   |
| Performance is important       | Tuples use less memory & are faster |
| You want to represent a record | Like a row in a database            |

---

## 🔹 11. Nesting Tuples

```python
nested = ((1, 2), (3, 4))
print(nested[1][0])    # 3
```

---

## 🔹 12. Tuple as Dictionary Key

```python
location = {(35.7, 51.4): "Tehran", (48.8, 2.3): "Paris"}
```

Tuples can be used as **keys in dictionaries** if they only contain immutable types.

---

## 🔹 13. Conversion Between List and Tuple

```python
lst = [1, 2, 3]
t = tuple(lst)         # Convert list → tuple

lst2 = list(t)         # Convert tuple → list
```

---

## 🔹 14. Returning Multiple Values from a Function

Functions can return multiple values as a tuple:

```python
def stats(nums):
    return min(nums), max(nums), sum(nums)

mn, mx, total = stats([1, 2, 3])
```

---

## 🔹 15. Comparing Tuples

Tuples are compared **lexicographically**:

```python
(1, 2) < (1, 3)        # True
(2, 0) > (1, 999)      # True
```

---

## ✅ Summary

| Feature          | Tuple |
| ---------------- | ----- |
| Ordered          | ✅     |
| Immutable        | ✅     |
| Iterable         | ✅     |
| Can be nested    | ✅     |
| Used as dict key | ✅     |
| Supports slicing | ✅     |

---

## 🧠 Pro Tips

* Use tuples when you want a **fixed collection of data**.
* Use tuple unpacking to make code **cleaner** and **more readable**.
* Use named tuples (from `collections`) for better **structure and readability** (if needed).

