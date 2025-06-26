# 📘 Python Dictionaries 

## 🔹 1. What is a Dictionary?

A **dictionary** in Python is an **unordered**, **mutable**, and **indexed** collection used to store data in **key-value** pairs.

### ✅ Syntax:

```python
my_dict = {
    "name": "Alice",
    "age": 25,
    "is_student": True
}
```

---

## 🔹 2. Dictionary Characteristics

| Property                         | Supported |
| -------------------------------- | --------- |
| Key-Value Pairs                  | ✅         |
| Mutable                          | ✅         |
| Ordered (since Python 3.7+)      | ✅         |
| Keys must be unique and hashable | ✅         |
| Values can be of any type        | ✅         |

---

## 🔹 3. Creating Dictionaries

### 🔸 With `{}`:

```python
person = {"name": "Bob", "age": 30}
```

### 🔸 With `dict()`:

```python
person = dict(name="Bob", age=30)
```

### 🔸 From list of tuples:

```python
pairs = [("a", 1), ("b", 2)]
d = dict(pairs)
```

---

## 🔹 4. Accessing Items

```python
print(person["name"])     # "Bob"
```

### 🔸 With `.get()` (returns `None` if key is missing):

```python
person.get("age")         # 30
person.get("city")        # None
```

---

## 🔹 5. Modifying Dictionaries

### 🔸 Add or update:

```python
person["city"] = "Tehran"
```

### 🔸 Remove:

```python
del person["age"]          # removes key "age"
value = person.pop("name") # returns and removes
```

---

## 🔹 6. Dictionary Methods

| Method           | Description                           |
| ---------------- | ------------------------------------- |
| `.get(key)`      | Get value, return `None` if not exist |
| `.keys()`        | Returns all keys                      |
| `.values()`      | Returns all values                    |
| `.items()`       | Returns list of (key, value) tuples   |
| `.pop(key)`      | Removes and returns value of key      |
| `.popitem()`     | Removes and returns **last** item     |
| `.update(other)` | Adds or updates from another dict     |
| `.clear()`       | Removes all items                     |
| `.copy()`        | Shallow copy of the dictionary        |

---

## 🔹 7. Looping Through Dictionaries

### 🔸 Keys only:

```python
for k in my_dict:
    print(k)
```

### 🔸 Keys and values:

```python
for key, value in my_dict.items():
    print(f"{key} => {value}")
```

---

## 🔹 8. Checking for Key Existence

```python
if "name" in person:
    print("Found")
```

---

## 🔹 9. Nested Dictionaries

```python
students = {
    "ali": {"age": 20, "major": "CS"},
    "reza": {"age": 22, "major": "EE"}
}
```

Access:

```python
print(students["ali"]["major"])   # CS
```

---

## 🔹 10. Dictionary Comprehension

### 🔸 Basic:

```python
squares = {x: x**2 for x in range(5)}
# {0: 0, 1: 1, 2: 4, 3: 9, 4: 16}
```

### 🔸 With condition:

```python
evens = {x: x for x in range(10) if x % 2 == 0}
```

---

## 🔹 11. Keys Must Be Immutable (Hashable)

Valid key types:

* string, number, tuple, boolean

Invalid key:

```python
# {"list": [1,2]} is OK
# {[1,2]: "list"} ❌ → Error: unhashable type: 'list'
```

---

## 🔹 12. Merging Dictionaries

### 🔸 Python 3.9+:

```python
d1 = {"a": 1}
d2 = {"b": 2}
merged = d1 | d2
```

### 🔸 Python < 3.9:

```python
merged = {**d1, **d2}
```

---

## 🔹 13. Copying Dictionaries

### Shallow copy:

```python
copy1 = my_dict.copy()
copy2 = dict(my_dict)
```

### Deep copy (for nested structures):

```python
import copy
deep_copy = copy.deepcopy(my_dict)
```

---

## 🔹 14. Using Tuples as Dictionary Keys

```python
locations = {
    (35.7, 51.4): "Tehran",
    (48.8, 2.3): "Paris"
}
```

---

## 🔹 15. Dictionary Use Cases

| Use Case                    | Example                                     |
| --------------------------- | ------------------------------------------- |
| Counting items              | Use with `collections.Counter`              |
| Storing configuration       | `config = {"debug": True, "theme": "dark"}` |
| Fast lookup tables          | `data[id] = person`                         |
| Representing JSON-like data | Nested dictionaries                         |

---

## 🔹 16. Dictionary vs List (Quick Comparison)

| Feature     | List          | Dictionary    |
| ----------- | ------------- | ------------- |
| Indexed by  | Position      | Key           |
| Fast lookup | ❌ (slow)      | ✅ (very fast) |
| Ordered     | ✅ (since 3.7) | ✅             |
| Use case    | Sequences     | Mappings      |

---

## ✅ Summary Table

| Operation     | Syntax                        |      |
| ------------- | ----------------------------- | ---- |
| Create        | `my_dict = {"a": 1}`          |      |
| Access        | `my_dict["a"]`                |      |
| Modify/Add    | `my_dict["b"] = 2`            |      |
| Delete        | `del my_dict["a"]`            |      |
| Get safely    | `my_dict.get("x", "default")` |      |
| Iterate       | `for k, v in d.items()`       |      |
| Check key     | `"a" in my_dict`              |      |
| Merge (3.9+)  | \`d1                          | d2\` |
| Comprehension | `{k: v for k, v in list}`     |      |

---

## 🧠 Pro Tips

* Use `.get()` instead of direct access to **avoid errors**.
* Use dictionary comprehension for **cleaner logic**.
* Use `defaultdict` or `Counter` from `collections` for more advanced use.
* Use JSON-compatible structures (dicts) for **data exchange** (e.g., API, file).

