## 🧱 Defining **Attributes** in Python

Attributes are usually defined inside the `__init__` method of a class and belong to each instance (object) of the class.

```python
class Person:
    def __init__(self, name, age):
        self.name = name      # Attribute: name
        self.age = age        # Attribute: age
```

* `self.name` and `self.age` are **instance attributes**.
* `self` refers to the current object.

---

## ⚙️ Defining **Methods** in Python

Methods are functions defined inside a class and typically operate on the object's data:

```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def greet(self):  # Method to greet
        print(f"Hello, my name is {self.name} and I am {self.age} years old.")
```

Usage:

```python
p = Person("Ali", 25)
p.greet()  # Output: Hello, my name is Ali and I am 25 years old.
```

---

## ✅ Attributes can also be added outside the class

```python
p.job = "Engineer"  # Adding a new attribute dynamically
print(p.job)
```

However, it's better practice to define all necessary attributes within the class.

---

## 📦 Types of Attributes

1. **Instance Attributes** – Unique to each object, defined in `__init__`.
2. **Class Attributes** – Shared across all instances.

```python
class Person:
    species = "Human"  # Class attribute

    def __init__(self, name):
        self.name = name  # Instance attribute
```

---

## 🧪 Full Example:

```python
class Car:
    wheels = 4  # Class attribute

    def __init__(self, brand, model):
        self.brand = brand      # Instance attribute
        self.model = model

    def drive(self):
        print(f"{self.brand} {self.model} is driving.")
```

```python
c1 = Car("Toyota", "Corolla")
c1.drive()         # Output: Toyota Corolla is driving.
print(c1.wheels)   # Output: 4
```
