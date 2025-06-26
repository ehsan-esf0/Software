## 🔹 1. What is a List?

A **list** is a built-in data structure in Python used to store an **ordered, mutable** collection of items. It can contain elements of **different data types**:

```python
my_list = [1, 2, 3, 4, 5]
mixed_list = [1, "hello", 3.14, True]
```

---

## 🔹 2. Accessing List Elements

You can access list elements using **indexes**:

```python
my_list = [10, 20, 30, 40]

print(my_list[0])     # 10
print(my_list[-1])    # 40 (last element)
```

---

## 🔹 3. List Slicing

```python
my_list = [10, 20, 30, 40, 50]

print(my_list[1:4])    # [20, 30, 40]
print(my_list[:3])     # [10, 20, 30]
print(my_list[::2])    # [10, 30, 50]
```

---

## 🔹 4. Modifying List Elements

```python
my_list[0] = 100
print(my_list)   # [100, 20, 30, 40, 50]
```

---

## 🔹 5. Adding Elements

```python
my_list.append(60)           # Add at the end
my_list.insert(2, 25)        # Insert at index 2
my_list.extend([70, 80])     # Add multiple elements
```

---

## 🔹 6. Removing Elements

```python
my_list.remove(25)     # Remove by value
del my_list[1]         # Remove by index
last = my_list.pop()   # Remove last element and return it
```

---

## 🔹 7. Useful List Functions and Methods

| Method / Function  | Description                     |
| ------------------ | ------------------------------- |
| `len(lst)`         | Length of list                  |
| `lst.append(x)`    | Add item to end                 |
| `lst.extend(lst2)` | Add multiple items              |
| `lst.insert(i, x)` | Insert at index                 |
| `lst.remove(x)`    | Remove first occurrence of x    |
| `lst.pop(i)`       | Remove and return item at index |
| `lst.index(x)`     | Find index of first x           |
| `lst.count(x)`     | Count occurrences of x          |
| `lst.sort()`       | Sort the list                   |
| `lst.reverse()`    | Reverse the list                |
| `lst.copy()`       | Return shallow copy             |
| `lst.clear()`      | Remove all elements             |

---

## 🔹 8. Looping Through Lists

```python
for item in my_list:
    print(item)

# Or with index
for i in range(len(my_list)):
    print(i, my_list[i])
```

---

## 🔹 9. Nested Lists

```python
matrix = [[1, 2], [3, 4], [5, 6]]

print(matrix[1])     # [3, 4]
print(matrix[1][0])  # 3
```

---

## 🔹 10. List Comprehension

A powerful way to build lists:

```python
squares = [x**2 for x in range(5)]  # [0, 1, 4, 9, 16]

# With condition
evens = [x for x in range(10) if x % 2 == 0]
```

---

## 🔹 11. Copying Lists

```python
a = [1, 2, 3]
b = a         # Reference to same list
c = a.copy()  # Creates a new list

# Other ways
d = a[:]
e = list(a)
```

---

## 🔹 12. Comparing Lists

```python
[1, 2, 3] == [1, 2, 3]   # True
[1, 2] < [1, 2, 3]       # True
```

---

## 🔹 13. Membership Test

```python
3 in [1, 2, 3]       # True
5 not in [1, 2, 3]   # True
```

---

## 🔹 14. Mutability of Lists

Lists are **mutable**, which means they can be changed:

```python
a = [1, 2, 3]
a[0] = 100
print(a)   # [100, 2, 3]
```

---

## 🔹 15. Converting to a List

```python
list("hello")       # ['h', 'e', 'l', 'l', 'o']
list(range(5))      # [0, 1, 2, 3, 4]
```

---

## 🔹 16. Comparison with Other Data Structures

| Type  | Mutable | Ordered       | Allows Duplicates   |
| ----- | ------- | ------------- | ------------------- |
| List  | ✅       | ✅             | ✅                   |
| Tuple | ❌       | ✅             | ✅                   |
| Set   | ✅       | ❌             | ❌                   |
| Dict  | ✅       | ✅ (since 3.7) | Keys must be unique |

