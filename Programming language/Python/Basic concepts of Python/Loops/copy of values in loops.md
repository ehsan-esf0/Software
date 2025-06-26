## Do we get a copy of values in loops in Python?

### ✅ Short answer:

Yes! In most cases (like lists, tuples, strings), when you iterate over a structure with a `for` loop, the loop variable gets **a copy of the element’s value**, **not the original element itself.**

---

### 🔍 More details: Value or Reference?

In Python, everything is an object. Whether you get a copy or reference depends on the **data type**:

#### 1. Immutable types (`int`, `float`, `str`, `tuple`):

The loop variable gets a **copy of the original value**. Changing the loop variable does **not** affect the original data.

```python
nums = [1, 2, 3]

for n in nums:
    n += 10

print(nums)  # Output: [1, 2, 3] ← no change
```

Here, since `int` is immutable and `n` is just a copy, modifying `n` does not affect the list.

---

#### 2. Mutable types (`list`, `dict`, `set`, custom objects):

The loop variable points to the **same object reference**, not a copy. So modifying the object via the loop variable **does affect** the original data.

```python
lists = [[1], [2], [3]]

for item in lists:
    item.append(100)

print(lists)
# Output: [[1, 100], [2, 100], [3, 100]]
```

Here, `item` references the inner lists directly, so appending modifies the original lists.

---

### ⚠️ Important note:

If you modify the loop variable directly (like `n += 10`) on immutable types, it does NOT change the original. For mutable objects, modifying the object *inside* the loop does change the original.

---

### Summary:

| Data type      | Loop variable gets  | Original data changes? |
| -------------- | ------------------- | ---------------------- |
| `int`, `str`   | Copy of the value   | ❌ No                   |
| `list`, `dict` | Reference to object | ✅ Yes                  |

---

---

## How to avoid copying and modify list elements directly?

If you want to modify elements of a simple list (e.g., list of integers) inside a loop **without creating copies**, you need to modify the list elements *directly* because integers are immutable in Python.

---

### 1. Using indices to modify list elements:

```python
nums = [1, 2, 3, 4, 5]

for i in range(len(nums)):
    nums[i] += 10

print(nums)
# Output: [11, 12, 13, 14, 15]
```

Here, you directly modify the elements by their index, so changes affect the original list.

---

### 2. Using `enumerate()` to get index and value:

```python
nums = [1, 2, 3, 4, 5]

for i, n in enumerate(nums):
    nums[i] = n + 10

print(nums)
# Output: [11, 12, 13, 14, 15]
```

---

### 3. If you have mutable objects inside the list, you can modify them directly:

```python
lists = [[1], [2], [3]]

for item in lists:
    item.append(100)

print(lists)
# Output: [[1, 100], [2, 100], [3, 100]]
```

---

### Key point:

* Immutable types (`int`, `str`, `tuple`) require index-based assignment for permanent modification.
* Mutable objects (like lists) can be changed directly through the loop variable.
