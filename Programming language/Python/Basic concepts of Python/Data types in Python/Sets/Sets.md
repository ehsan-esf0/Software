# 📘 Python Sets 

## 🔹 1. What is a Set?

A **set** in Python is an **unordered**, **mutable**, and **unindexed** collection of **unique** elements.

### ✅ Key Features:

* Elements are **unique**
* The set itself is **mutable**
* It is **unordered** (no indexing or slicing)
* Elements must be **immutable (hashable)**

---

## 🔹 2. Creating a Set

### 🔸 Basic Set:

```python
my_set = {1, 2, 3}
```

### 🔸 With `set()` constructor:

```python
s = set([1, 2, 3, 2])  # {1, 2, 3}
```

### 🔸 Empty set (⚠️ not `{}`):

```python
empty = set()  # ✅ correct
# empty = {}   # ❌ creates a dictionary
```

---

## 🔹 3. Accessing Elements

You **cannot** access set elements by index (they are unordered), but you can loop through them:

```python
for item in my_set:
    print(item)
```

---

## 🔹 4. Adding & Removing Elements

### 🔸 Add single element:

```python
my_set.add(4)
```

### 🔸 Add multiple elements:

```python
my_set.update([5, 6])
```

### 🔸 Remove element (raises error if not found):

```python
my_set.remove(2)
```

### 🔸 Discard element (no error if not found):

```python
my_set.discard(10)
```

### 🔸 Remove and return a random element:

```python
my_set.pop()
```

### 🔸 Clear all elements:

```python
my_set.clear()
```

---

## 🔹 5. Set Operations (Union, Intersection, etc.)

| Operation       | Symbol / Method                | Example           |     |                   |
| --------------- | ------------------------------ | ----------------- | --- | ----------------- |
| Union           | \`                             | `, `.union()\`    | \`a | b`or`a.union(b)\` |
| Intersection    | `&`, `.intersection()`         | `a & b`           |     |                   |
| Difference      | `-`, `.difference()`           | `a - b`           |     |                   |
| Symmetric Diff. | `^`, `.symmetric_difference()` | `a ^ b`           |     |                   |
| Subset          | `<`, `.issubset()`             | `a < b`           |     |                   |
| Superset        | `>`, `.issuperset()`           | `a > b`           |     |                   |
| Disjoint        | `.isdisjoint()`                | `a.isdisjoint(b)` |     |                   |

### 🔸 Example:

```python
a = {1, 2, 3}
b = {3, 4, 5}

print(a | b)  # {1, 2, 3, 4, 5}
print(a & b)  # {3}
print(a - b)  # {1, 2}
print(a ^ b)  # {1, 2, 4, 5}
```

---

## 🔹 6. Membership Testing

```python
if 2 in my_set:
    print("Yes")
```

---

## 🔹 7. Set Comprehension

Like list comprehension but with `{}`:

```python
squared = {x**2 for x in range(5)}  # {0, 1, 4, 9, 16}
```

---

## 🔹 8. Frozen Sets (Immutable Sets)

A `frozenset` is like a set, but **immutable**. Useful as dictionary keys or elements of other sets.

```python
fs = frozenset([1, 2, 3])
# fs.add(4)  # ❌ AttributeError
```

---

## 🔹 9. Examples of Real Use Cases

| Use Case                 | Description                        |
| ------------------------ | ---------------------------------- |
| Removing duplicates      | `list(set(my_list))`               |
| Set algebra in math/data | Intersection/union of groups       |
| Fast membership checking | `in` is faster with sets           |
| Comparing datasets       | `set1 == set2`, `set1 - set2` etc. |

---

## 🔹 10. Difference between Set & List & Dict

| Feature    | List          | Set | Dictionary          |
| ---------- | ------------- | --- | ------------------- |
| Ordered    | ✅ (since 3.7) | ❌   | ✅                   |
| Duplicates | ✅             | ❌   | Keys must be unique |
| Indexed    | ✅             | ❌   | ✅ by key            |
| Mutable    | ✅             | ✅   | ✅                   |

---

## 🔹 11. Built-in Set Methods Summary

| Method                    | Description                          |
| ------------------------- | ------------------------------------ |
| `.add(x)`                 | Add element x                        |
| `.update(iterable)`       | Add multiple elements                |
| `.remove(x)`              | Remove x (raises error if not found) |
| `.discard(x)`             | Remove x if exists (no error)        |
| `.pop()`                  | Remove and return random element     |
| `.clear()`                | Empty the set                        |
| `.union(other)`           | Return union of sets                 |
| `.intersection(other)`    | Return common elements               |
| `.difference(other)`      | Return elements in self not in other |
| `.symmetric_difference()` | Elements in either but not both      |
| `.issubset(other)`        | Whether self ⊆ other                 |
| `.issuperset(other)`      | Whether self ⊇ other                 |
| `.isdisjoint(other)`      | No common elements                   |
| `.copy()`                 | Shallow copy                         |

---

## ✅ Summary Table

| Operation              | Syntax                          |                   |
| ---------------------- | ------------------------------- | ----------------- |
| Create                 | `s = {1, 2, 3}`                 |                   |
| Add item               | `s.add(4)`                      |                   |
| Remove item            | `s.remove(2)` or `s.discard(2)` |                   |
| Set union              | \`a                             | b`or`a.union(b)\` |
| Set intersection       | `a & b` or `a.intersection(b)`  |                   |
| Set difference         | `a - b`                         |                   |
| Symmetric difference   | `a ^ b`                         |                   |
| Membership test        | `x in s`                        |                   |
| Frozen (immutable) set | `frozenset([...])`              |                   |

