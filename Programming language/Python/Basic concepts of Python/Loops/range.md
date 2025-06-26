## 🔷 `range()` Function in Python

The `range()` function is used to generate a sequence of integers. It's **most commonly used with `for` loops** to iterate a specific number of times.

---

## ✅ Syntax

```python
range(stop)
range(start, stop)
range(start, stop, step)
```

* **`start`**: (Optional) The beginning value of the sequence (default is `0`)
* **`stop`**: The end of the range **(exclusive)**
* **`step`**: (Optional) The difference between each number (default is `1`)

---

## ✅ Simple Examples

### 🔹 Only `stop`:

```python
for i in range(5):
    print(i)
# Output: 0 1 2 3 4
```

### 🔹 With `start` and `stop`:

```python
for i in range(2, 6):
    print(i)
# Output: 2 3 4 5
```

### 🔹 With `step`:

```python
for i in range(0, 10, 2):
    print(i)
# Output: 0 2 4 6 8
```

---

## ✅ Countdown (Negative Step)

```python
for i in range(10, 0, -1):
    print(i)
# Output: 10 9 8 7 6 5 4 3 2 1
```

---

## ✅ Using `range()` Outside of Loops

You can convert a `range` to a list, tuple, etc.:

```python
r = range(3, 8)
print(list(r))  # Output: [3, 4, 5, 6, 7]
```

---

## ✅ Key Properties

| Property         | Value                                 |
| ---------------- | ------------------------------------- |
| Type             | `range` object (not a list)           |
| Memory efficient | ✅ Yes, it doesn’t store all numbers   |
| Iterable         | ✅ Yes (used in loops, comprehensions) |

---

## ⚠️ Important Notes

* `stop` is **not included** in the output. (`range(0, 5)` gives `0` to `4`)
* If `step` is negative, `start` must be greater than `stop`, or nothing will be generated.
* `range()` only works with **integers**. It does **not support floats**.

---

## ✅ Practical Example

```python
even_numbers = []

for i in range(2, 21, 2):
    even_numbers.append(i)

print(even_numbers)
# Output: [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
```

---