## 🟦 Part 1: **Comparison Operators**

### ✅ Purpose:

Used to **compare two values** (numbers, strings, lists, etc.). They always return either `True` or `False`.

| Operator | Meaning               | Example  | Result |
| -------- | --------------------- | -------- | ------ |
| `==`     | Equal to              | `3 == 3` | `True` |
| `!=`     | Not equal to          | `3 != 4` | `True` |
| `>`      | Greater than          | `5 > 2`  | `True` |
| `<`      | Less than             | `2 < 5`  | `True` |
| `>=`     | Greater than or equal | `3 >= 3` | `True` |
| `<=`     | Less than or equal    | `2 <= 3` | `True` |

### 📌 Example:

```python
x = 10
y = 20

print(x == y)   # False
print(x != y)   # True
print(x < y)    # True
print(x >= 5)   # True
```

---

## 🟩 Part 2: **Logical Operators**

### ✅ Purpose:

Used to **combine multiple conditions**.

| Operator | Meaning                              | Example          | Result  |
| -------- | ------------------------------------ | ---------------- | ------- |
| `and`    | Logical AND (both must be `True`)    | `True and False` | `False` |
| `or`     | Logical OR (at least one is `True`)  | `True or False`  | `True`  |
| `not`    | Logical NOT (reverses boolean value) | `not True`       | `False` |

### 📌 Example:

```python
age = 25
is_student = True

print(age > 18 and is_student)   # True
print(age < 18 or is_student)    # True
print(not is_student)            # False
```

---

## 🧠 Important Difference: `and`, `or` vs `&`, `|`

\| Purpose       | Use `and`/`or` | Use `&`/`|`     |
\|---------------|----------------|-------------|
\| Booleans      | ✅ Yes         | ❌ No        |
\| Bitwise ops   | ❌ No          | ✅ Yes       |

### Example:

```python
# Logical
x = True
y = False
print(x and y)  # False

# Bitwise
a = 5      # 0b0101
b = 3      # 0b0011
print(a & b)  # 1 => 0b0001
```

---

## 🧪 Combined Example:

```python
x = 10
y = 20

if x < y and y < 30:
    print("x is less than y and y is less than 30")
```

---

## ✅ Quick Summary Table:

| Category   | Operators                        | Description                   |
| ---------- | -------------------------------- | ----------------------------- |
| Comparison | `==`, `!=`, `>`, `<`, `>=`, `<=` | Compare values                |
| Logical    | `and`, `or`, `not`               | Combine conditions (booleans) |

