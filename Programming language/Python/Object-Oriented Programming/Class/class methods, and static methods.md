## 🔹 1. Instance Methods

### ✅ Definition:

These are the most common type of methods in a class. They operate on an **instance (object)** of the class and can access or modify the object’s attributes.

### ✅ Key point:

They always have `self` as the **first parameter**, which refers to the **instance** calling the method.

### ✅ Example:

```python
class MyClass:
    def instance_method(self, x):
        print(f"This is an instance method. x = {x}, self = {self}")
```

### ✅ Usage:

```python
obj = MyClass()
obj.instance_method(10)
```

### ✅ Features:

* Can access and modify instance variables
* Can call other instance methods
* Can indirectly access class-level data using `self.__class__`

---

## 🔹 2. Class Methods

### ✅ Definition:

These methods operate on the **class itself**, not on instances. The first parameter is always `cls`, which refers to the **class**.

### ✅ Decorator:

You must use `@classmethod`.

### ✅ Example:

```python
class MyClass:
    class_variable = 42

    @classmethod
    def class_method(cls, value):
        print(f"This is a class method. cls = {cls}, value = {value}")
        print(f"Accessing class variable: {cls.class_variable}")
```

### ✅ Usage:

```python
MyClass.class_method(100)  # Called on class
obj = MyClass()
obj.class_method(100)      # Can also be called on instance
```

### ✅ Common Use Cases:

* Accessing or modifying **class-level data**
* Creating **factory methods**

### ✅ Factory Method Example:

```python
class Person:
    def __init__(self, name):
        self.name = name

    @classmethod
    def from_string(cls, name_str):
        return cls(name_str)

p = Person.from_string("Alice")
print(p.name)  # Alice
```

---

## 🔹 3. Static Methods

### ✅ Definition:

Static methods are **independent functions** placed inside a class for **organizational purposes**. They don’t take `self` or `cls` as the first parameter.

### ✅ Decorator:

You must use `@staticmethod`.

### ✅ Example:

```python
class Math:
    @staticmethod
    def add(x, y):
        return x + y
```

### ✅ Usage:

```python
print(Math.add(3, 4))  # 7
```

### ✅ Features:

* Do **not** access instance or class data
* Useful for **utility/helper functions**
* Can be used without creating an object

### ✅ Example:

```python
class Temperature:
    @staticmethod
    def celsius_to_fahrenheit(c):
        return c * 9/5 + 32

print(Temperature.celsius_to_fahrenheit(25))  # 77.0
```

---

## 🔍 Comparison Table

| Feature          | Instance Method          | Class Method                | Static Method            |
| ---------------- | ------------------------ | --------------------------- | ------------------------ |
| First parameter  | `self` (instance)        | `cls` (class)               | None                     |
| Access instance? | ✅ Yes                    | ❌ No                        | ❌ No                     |
| Access class?    | ✅ (via `self.__class__`) | ✅ Yes                       | ❌ No                     |
| Use decorator?   | ❌ No                     | ✅ `@classmethod`            | ✅ `@staticmethod`        |
| Use cases        | Instance-specific logic  | Class-wide logic, factories | Helper/utility functions |

---

## 🧠 Important Notes

1. Use `@classmethod` when your method needs to access or modify **class-level data**.
2. Use `@staticmethod` when your method does **not depend on instance or class data**.
3. You can call all types of methods from both **instances and the class**, but it's more readable and logical to follow standard usage.
4. Misusing them can lead to confusing and hard-to-maintain code.

---

## ✅ Full Practical Example

```python
class Book:
    tax_rate = 0.1  # class attribute

    def __init__(self, price):
        self.price = price

    def final_price(self):
        return self.price * (1 + Book.tax_rate)

    @classmethod
    def change_tax(cls, new_tax):
        cls.tax_rate = new_tax

    @staticmethod
    def is_valid_price(price):
        return price > 0

book = Book(100)
print(book.final_price())  # 110.0

Book.change_tax(0.2)
print(book.final_price())  # 120.0

print(Book.is_valid_price(50))  # True
print(Book.is_valid_price(-10)) # False
```
