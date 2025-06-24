# 🐍 **Data Types in Python**

---

## 📌 1. **Numbers**

### 🔹 `int` — Integer

Whole numbers (no decimals).
Example: `10`, `-3`, `0`

```python
x = 5
print(type(x))  # <class 'int'>
```

---

### 🔹 `float` — Floating Point

Decimal numbers.
Example: `3.14`, `-0.5`, `2.0`

```python
y = 3.14
print(type(y))  # <class 'float'>
```

---

### 🔹 `complex` — Complex Numbers

Numbers with real and imaginary parts.
Example: `2 + 3j`

```python
z = 2 + 3j
print(type(z))  # <class 'complex'>
```

---

## 📌 2. **Strings** → `str`

A sequence of characters inside `''` or `""`.
Example: `"Hello"`, `'Python'`

```python
s = "Hello"
print(type(s))  # <class 'str'>
```

---

## 📌 3. **Booleans** → `bool`

Represents either `True` or `False`.

```python
is_valid = True
print(type(is_valid))  # <class 'bool'>
```

---

## 📌 4. **Lists** → `list`

A **mutable** (changeable) ordered collection of items.

```python
numbers = [1, 2, 3, 4]
print(type(numbers))  # <class 'list'>
```

---

## 📌 5. **Tuples** → `tuple`

An **immutable** (unchangeable) ordered collection.

```python
coordinates = (10, 20)
print(type(coordinates))  # <class 'tuple'>
```

---

## 📌 6. **Sets** → `set`

An **unordered collection** of **unique** items.

```python
unique_nums = {1, 2, 3, 2}
print(type(unique_nums))  # <class 'set'>
```

---

## 📌 7. **Dictionaries** → `dict`

A collection of **key-value** pairs.

```python
person = {"name": "Ali", "age": 25}
print(type(person))  # <class 'dict'>
```

---

## 📌 8. **None Type** → `NoneType`

Represents the absence of a value.

```python
nothing = None
print(type(nothing))  # <class 'NoneType'>
```

---

## ✅ Summary Table

| Data Type   | Python Type | Example            |
| ----------- | ----------- | ------------------ |
| Integer     | `int`       | `5`, `-2`          |
| Float       | `float`     | `3.14`, `-0.1`     |
| Complex     | `complex`   | `1 + 2j`           |
| String      | `str`       | `"hello"`, `'abc'` |
| Boolean     | `bool`      | `True`, `False`    |
| List        | `list`      | `[1, 2, 3]`        |
| Tuple       | `tuple`     | `(1, 2)`           |
| Set         | `set`       | `{1, 2, 3}`        |
| Dictionary  | `dict`      | `{"a": 1}`         |
| None (null) | `NoneType`  | `None`             |

