# 🧠 **Lesson 4: Advanced Generators and the `yield from` Keyword**

### 🎯 What you’ll learn:

* How to build more complex and elegant generators
* How to use **loops inside generators**
* How and when to use the **`yield from`** keyword
* Several useful and professional examples

---

## 🔹 1. Using loops inside generators

You can use nested loops in a generator to yield deeply nested or structured data.

---

### ✅ Example: Yielding all characters from a list of words

```python
def letters_in_words(words):
    for word in words:
        for char in word:
            yield char
```

```python
for ch in letters_in_words(["hi", "bye"]):
    print(ch)
```

**Output:**

```
h
i
b
y
e
```

---

## 🔸 2. What is `yield from`?

The **`yield from`** statement is used to **delegate part of a generator’s operations to another iterable or sub-generator**.

It makes your code **shorter and more readable**, especially when chaining generators or flattening nested structures.

---

### ✅ Simple example: Yielding from multiple iterables

```python
def multi_list_gen():
    yield from [1, 2, 3]
    yield from (4, 5)
    yield from range(6, 8)
```

```python
for x in multi_list_gen():
    print(x)
```

**Output:**

```
1
2
3
4
5
6
7
```

---

### ✅ Example: Flattening a list of lists

```python
def flatten(nested):
    for sublist in nested:
        yield from sublist
```

```python
for item in flatten([[1, 2], [3, 4, 5]]):
    print(item)
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

### ✅ Advanced Example: Recursively walking a tree structure

```python
def walk_tree(tree):
    for node in tree:
        if isinstance(node, list):
            yield from walk_tree(node)
        else:
            yield node
```

```python
data = [1, [2, [3, 4], 5], 6]
for val in walk_tree(data):
    print(val)
```

**Output:**

```
1
2
3
4
5
6
```
