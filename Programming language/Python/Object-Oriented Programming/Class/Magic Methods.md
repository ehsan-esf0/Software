# Important Python Magic Methods 

Python’s **magic methods** (also called **dunder methods**) are special methods with double underscores (`__method__`) that allow you to define or customize the behavior of your objects.

---

### 1. `__init__(self, ...)` — Constructor

Called when creating a new object, to initialize it.

```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

p = Person("Alice", 30)
```

---

### 2. `__str__(self)` — Informal string representation

Defines what gets printed when you do `print(obj)` or `str(obj)`.

```python
class Person:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return f"Person named {self.name}"

print(Person("Bob"))  # Output: Person named Bob
```

---

### 3. `__repr__(self)` — Official string representation

Used mainly for debugging. Should ideally return a string that could recreate the object.

```python
class Person:
    def __init__(self, name):
        self.name = name

    def __repr__(self):
        return f"Person('{self.name}')"

p = Person("Carol")
print(repr(p))  # Output: Person('Carol')
```

---

### 4. `__len__(self)` — Length of the object

Called by the built-in `len()` function.

```python
class MyList:
    def __init__(self, items):
        self.items = items

    def __len__(self):
        return len(self.items)

lst = MyList([1, 2, 3])
print(len(lst))  # Output: 3
```

---

### 5. `__getitem__(self, key)` — Indexing

Called when using `obj[key]`.

```python
class MyList:
    def __init__(self, items):
        self.items = items

    def __getitem__(self, index):
        return self.items[index]

lst = MyList([10, 20, 30])
print(lst[1])  # Output: 20
```

---

### 6. `__setitem__(self, key, value)` — Item assignment

Called when doing `obj[key] = value`.

```python
class MyList:
    def __init__(self, items):
        self.items = items

    def __setitem__(self, index, value):
        self.items[index] = value

lst = MyList([1, 2, 3])
lst[0] = 100
print(lst.items)  # Output: [100, 2, 3]
```

---

### 7. `__iter__(self)` and `__next__(self)` — Iteration

Make your object iterable (usable in loops).

```python
class CountDown:
    def __init__(self, start):
        self.current = start

    def __iter__(self):
        return self

    def __next__(self):
        if self.current <= 0:
            raise StopIteration
        else:
            self.current -= 1
            return self.current + 1

for i in CountDown(3):
    print(i)
# Output:
# 3
# 2
# 1
```

---

### 8. `__call__(self, ...)` — Callable objects

Allows your object to be called like a function.

```python
class Adder:
    def __init__(self, n):
        self.n = n

    def __call__(self, x):
        return self.n + x

add_five = Adder(5)
print(add_five(10))  # Output: 15
```

---

### 9. Comparison methods (`__eq__`, `__lt__`, `__gt__`, etc.)

Define behavior of comparison operators like `==`, `<`, `>`.

```python
class Person:
    def __init__(self, age):
        self.age = age

    def __eq__(self, other):
        return self.age == other.age

p1 = Person(30)
p2 = Person(30)
print(p1 == p2)  # Output: True
```

---

### 10. Context manager methods: `__enter__` and `__exit__`

Used in `with` statements for setup and cleanup.

```python
class ManagedFile:
    def __init__(self, filename):
        self.filename = filename

    def __enter__(self):
        self.file = open(self.filename, 'w')
        return self.file

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.file.close()

with ManagedFile('test.txt') as f:
    f.write('Hello, world!')
```

---

### 11. `__del__(self)` — Destructor

Called when the object is about to be destroyed (garbage collected).

```python
class MyClass:
    def __del__(self):
        print("Object is being deleted")

obj = MyClass()
del obj  # Output: Object is being deleted
```