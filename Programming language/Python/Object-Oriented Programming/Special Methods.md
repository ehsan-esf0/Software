## 🧱 1. Constructor & Initialization Methods

### `__init__(self, ...)`

Called right after object creation to initialize attributes.

```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

p = Person("Ali", 25)
print(p.name, p.age)  # Ali 25
```

---

### `__new__(cls, ...)`

Called before `__init__`, responsible for creating the object instance (mostly used in immutable types like `int`, `str`).

```python
class MyInt(int):
    def __new__(cls, value):
        print("Creating MyInt")
        return super().__new__(cls, value)

x = MyInt(5)  # Creating MyInt
print(x + 2)  # 7
```

---

## 🎨 2. String Representation Methods

### `__str__(self)`

Defines the string representation used in `print()` or `str()`.

```python
class Book:
    def __init__(self, title): self.title = title
    def __str__(self): return f"Book: {self.title}"

b = Book("1984")
print(b)  # Book: 1984
```

---

### `__repr__(self)`

Defines the unambiguous representation (useful for debugging, `repr()`).

```python
class Book:
    def __init__(self, title): self.title = title
    def __repr__(self): return f"Book('{self.title}')"

b = Book("1984")
print(repr(b))  # Book('1984')
```

---

## ➕ 3. Arithmetic Operator Overloading

### `__add__(self, other)`

For `+` operator.

```python
class Point:
    def __init__(self, x, y): self.x, self.y = x, y
    def __add__(self, other): return Point(self.x + other.x, self.y + other.y)
    def __str__(self): return f"({self.x}, {self.y})"

p1 = Point(1, 2)
p2 = Point(3, 4)
print(p1 + p2)  # (4, 6)
```

---

### Other math methods:

| Operator | Method         | Example  |
| -------- | -------------- | -------- |
| `-`      | `__sub__`      | `a - b`  |
| `*`      | `__mul__`      | `a * b`  |
| `/`      | `__truediv__`  | `a / b`  |
| `//`     | `__floordiv__` | `a // b` |
| `%`      | `__mod__`      | `a % b`  |
| `**`     | `__pow__`      | `a ** b` |

---

## 🧮 4. Comparison Methods

| Operator | Method   | Example  |
| -------- | -------- | -------- |
| `==`     | `__eq__` | `a == b` |
| `!=`     | `__ne__` | `a != b` |
| `<`      | `__lt__` | `a < b`  |
| `<=`     | `__le__` | `a <= b` |
| `>`      | `__gt__` | `a > b`  |
| `>=`     | `__ge__` | `a >= b` |

```python
class Box:
    def __init__(self, volume): self.volume = volume
    def __lt__(self, other): return self.volume < other.volume

b1 = Box(100)
b2 = Box(200)
print(b1 < b2)  # True
```

---

## 📏 5. Type Conversion Methods

### `__int__`, `__float__`

```python
class Price:
    def __init__(self, amount): self.amount = amount
    def __int__(self): return int(self.amount)
    def __float__(self): return float(self.amount)

p = Price(9.99)
print(int(p))   # 9
print(float(p)) # 9.99
```

---

### `__bool__`

```python
class MyList:
    def __init__(self, items): self.items = items
    def __bool__(self): return len(self.items) > 0

ml = MyList([])
print(bool(ml))  # False
```

---

### `__len__`

```python
class Basket:
    def __init__(self, items): self.items = items
    def __len__(self): return len(self.items)

b = Basket(["apple", "banana"])
print(len(b))  # 2
```

---

## 📚 6. Item Access and Container Behavior

### `__getitem__`, `__setitem__`, `__delitem__`

```python
class MyDict:
    def __init__(self): self.data = {}
    def __getitem__(self, key): return self.data[key]
    def __setitem__(self, key, value): self.data[key] = value
    def __delitem__(self, key): del self.data[key]

d = MyDict()
d['x'] = 10
print(d['x'])   # 10
del d['x']
```

---

### `__contains__`

```python
class MyList:
    def __init__(self, items): self.items = items
    def __contains__(self, item): return item in self.items

ml = MyList([1, 2, 3])
print(2 in ml)  # True
```

---

## 🔁 7. Iterable and Iterator Methods

### `__iter__`, `__next__`

```python
class Count:
    def __init__(self, max): self.max = max; self.current = 0
    def __iter__(self): return self
    def __next__(self):
        if self.current >= self.max:
            raise StopIteration
        self.current += 1
        return self.current

for i in Count(3): print(i)  # 1 2 3
```

---

## ⚙️ 8. Context Managers (`with` Statement)

### `__enter__`, `__exit__`

```python
class MyResource:
    def __enter__(self): print("Opening"); return self
    def __exit__(self, exc_type, exc_val, exc_tb): print("Closing")

with MyResource():
    print("Doing work")
# Output:
# Opening
# Doing work
# Closing
```

---

## ☎️ 9. Callable Objects

### `__call__`

```python
class Greeter:
    def __call__(self, name): return f"Hello, {name}"

g = Greeter()
print(g("Ali"))  # Hello, Ali
```

---

## 🧩 10. Attribute Access

### `__getattr__`

Called when attribute doesn't exist.

```python
class Person:
    def __init__(self): self.name = "Ali"
    def __getattr__(self, name): return f"{name} not found"

p = Person()
print(p.age)  # age not found
```

---

### `__setattr__`, `__delattr__`

```python
class Person:
    def __setattr__(self, name, value):
        print(f"Setting {name} = {value}")
        self.__dict__[name] = value

p = Person()
p.name = "Ali"  # Setting name = Ali
```

---

## 📌 Summary Table

| Category              | Methods                                       |
| --------------------- | --------------------------------------------- |
| Construction          | `__init__`, `__new__`                         |
| String Representation | `__str__`, `__repr__`                         |
| Arithmetic Operators  | `__add__`, `__sub__`, `__mul__`, etc.         |
| Comparisons           | `__eq__`, `__lt__`, `__gt__`, etc.            |
| Type Conversion       | `__int__`, `__float__`, `__bool__`, `__len__` |
| Item Access           | `__getitem__`, `__setitem__`, `__contains__`  |
| Iteration             | `__iter__`, `__next__`                        |
| Context Management    | `__enter__`, `__exit__`                       |
| Callable Objects      | `__call__`                                    |
| Attribute Access      | `__getattr__`, `__setattr__`, `__delattr__`   |
