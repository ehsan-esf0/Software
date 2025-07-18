# 🧠 Complete List of Operator Overloading Methods in Python

## 🔹 1. Arithmetic Operators

| Operator | Method         | Example                             |
| -------- | -------------- | ----------------------------------- |
| `+`      | `__add__`      | `a + b`                             |
| `-`      | `__sub__`      | `a - b`                             |
| `*`      | `__mul__`      | `a * b`                             |
| `/`      | `__truediv__`  | `a / b`                             |
| `//`     | `__floordiv__` | `a // b`                            |
| `%`      | `__mod__`      | `a % b`                             |
| `**`     | `__pow__`      | `a ** b`                            |
| `@`      | `__matmul__`   | `a @ b`     (matrix multiplication) |

---

## 🔹 2. In-Place Arithmetic Operators (like `+=`, `-=`, etc.)

| Operator | Method          | Example   |
| -------- | --------------- | --------- |
| `+=`     | `__iadd__`      | `a += b`  |
| `-=`     | `__isub__`      | `a -= b`  |
| `*=`     | `__imul__`      | `a *= b`  |
| `/=`     | `__itruediv__`  | `a /= b`  |
| `//=`    | `__ifloordiv__` | `a //= b` |
| `%=`     | `__imod__`      | `a %= b`  |
| `**=`    | `__ipow__`      | `a **= b` |
| `@=`     | `__imatmul__`   | `a @= b`  |

---

## 🔹 3. Comparison Operators

| Operator | Method   | Example  |
| -------- | -------- | -------- |
| `==`     | `__eq__` | `a == b` |
| `!=`     | `__ne__` | `a != b` |
| `>`      | `__gt__` | `a > b`  |
| `<`      | `__lt__` | `a < b`  |
| `>=`     | `__ge__` | `a >= b` |
| `<=`     | `__le__` | `a <= b` |

---

## 🔹 4. Unary Operators

| Operator | Method       | Example  |
| -------- | ------------ | -------- |
| `-a`     | `__neg__`    | `-a`     |
| `+a`     | `__pos__`    | `+a`     |
| `~a`     | `__invert__` | `~a`     |
| `abs(a)` | `__abs__`    | `abs(a)` |

---

## 🔹 5. Bitwise Operators

| Operator | Method       | Example  |     |     |
| -------- | ------------ | -------- | --- | --- |
| `&`      | `__and__`    | `a & b`  |     |     |
| \`       | \`           | `__or__` | \`a | b\` |
| `^`      | `__xor__`    | `a ^ b`  |     |     |
| `<<`     | `__lshift__` | `a << b` |     |     |
| `>>`     | `__rshift__` | `a >> b` |     |     |

### ✔ In-place versions:

| Operator | Method        |           |
| -------- | ------------- | --------- |
| `&=`     | `__iand__`    |           |
| \`       | =\`           | `__ior__` |
| `^=`     | `__ixor__`    |           |
| `<<=`    | `__ilshift__` |           |
| `>>=`    | `__irshift__` |           |

---

## 🔹 6. Type Conversion Methods

| Function     | Method        |
| ------------ | ------------- |
| `int(x)`     | `__int__`     |
| `float(x)`   | `__float__`   |
| `complex(x)` | `__complex__` |
| `bool(x)`    | `__bool__`    |
| `str(x)`     | `__str__`     |
| `repr(x)`    | `__repr__`    |
| `bytes(x)`   | `__bytes__`   |

---

## 🔹 7. Object Access and Container Behavior

| Action                       | Method         |
| ---------------------------- | -------------- |
| Indexing (`obj[i]`)          | `__getitem__`  |
| Setting item (`obj[i] = x`)  | `__setitem__`  |
| Deleting item (`del obj[i]`) | `__delitem__`  |
| Iteration                    | `__iter__`     |
| Getting next item            | `__next__`     |
| Length                       | `__len__`      |
| Containment (`x in obj`)     | `__contains__` |

---

## 🔹 8. Callable & Context Manager

| Feature                     | Method                  |
| --------------------------- | ----------------------- |
| Callable object (`obj()`)   | `__call__`              |
| Context management (`with`) | `__enter__`, `__exit__` |

---

## 🔹 9. Attribute Access

| Action                  | Method             |
| ----------------------- | ------------------ |
| Get attribute           | `__getattr__`      |
| Set attribute           | `__setattr__`      |
| Delete attribute        | `__delattr__`      |
| Get any attribute       | `__getattribute__` |
| List attributes (`dir`) | `__dir__`          |

---

## 🧪 Example: Overloading `+`

```python
class Vector:
    def __init__(self, x, y):
        self.x, self.y = x, y

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __repr__(self):
        return f"Vector({self.x}, {self.y})"

v1 = Vector(1, 2)
v2 = Vector(3, 4)

print(v1 + v2)  # Output: Vector(4, 6)
```