## ✅ 1. `if` Statement

The `if` statement is used to execute a block of code **only if a certain condition is true**.

```python
x = 10

if x > 5:
    print("x is greater than 5")
```

---

## ✅ 2. `if-else` Statement

Executes one block if the condition is `True`, otherwise executes the `else` block.

```python
x = 3

if x > 5:
    print("x is greater than 5")
else:
    print("x is less than or equal to 5")
```

---

## ✅ 3. `if-elif-else` Statement

Used when you need to check **multiple conditions**. Only the **first true condition** is executed.

```python
x = 0

if x > 0:
    print("Positive")
elif x == 0:
    print("Zero")
else:
    print("Negative")
```

---

## ✅ 4. One-Line `if` / Ternary Operator

You can write a simple `if-else` in a single line:

```python
age = 18

status = "Adult" if age >= 18 else "Minor"
print(status)
```

---

## ✅ 5. Nested `if` Statements

An `if` inside another `if` — for checking more specific conditions.

```python
x = 15

if x > 10:
    if x < 20:
        print("x is between 10 and 20")
```

---

## ✅ 6. Using Logical Operators (`and`, `or`, `not`) with `if`

Combine multiple conditions in a single `if`.

```python
age = 25
is_student = True

if age > 18 and is_student:
    print("Adult student")
```

---

## ✅ 7. Range Comparison (Chained Comparisons)

Python allows concise syntax for checking ranges:

```python
x = 7

if 5 < x < 10:
    print("x is between 5 and 10")
```

---

## 🛑 Important Notes:

* Always use a colon `:` after `if`, `elif`, or `else`.
* Indentation is **required** in Python (typically 4 spaces).
* Parentheses around conditions are **optional**.

---

## 🎯 Full Example:

```python
score = 85

if score >= 90:
    print("Grade: A")
elif score >= 80:
    print("Grade: B")
elif score >= 70:
    print("Grade: C")
else:
    print("Grade: F")
```

---
