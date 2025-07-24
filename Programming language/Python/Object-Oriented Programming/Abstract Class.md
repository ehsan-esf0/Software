## 🧠 What is an Abstract Class?

An **Abstract Class** is a **template or blueprint** for other classes. It:

1. **Cannot be instantiated directly**
2. **Contains abstract methods** that **must** be implemented in any subclass

---

## ✅ When to Use It?

* When you want to **enforce a structure** across multiple classes
* When you want to **define a common interface** for subclasses

---

## 🔧 How to Create an Abstract Class in Python?

Use the built-in `abc` module:

```python
from abc import ABC, abstractmethod
```

### ✔ `ABC`: base class for all abstract classes

### ✔ `@abstractmethod`: defines a method that must be implemented

---

## 📘 Example:

```python
from abc import ABC, abstractmethod

class Animal(ABC):  # Abstract Base Class
    @abstractmethod
    def speak(self):
        pass

    def move(self):
        print("Moving...")

# ❌ This will raise an error:
# animal = Animal()

class Dog(Animal):
    def speak(self):
        print("Woof!")

class Cat(Animal):
    def speak(self):
        print("Meow!")

dog = Dog()
cat = Cat()

dog.speak()   # Woof!
cat.speak()   # Meow!
dog.move()    # Moving...
```

---

## ⚠️ Rules:

| Rule                                         | Description                                     |
| -------------------------------------------- | ----------------------------------------------- |
| Can't instantiate abstract classes           | Must inherit and implement all abstract methods |
| Abstract method                              | Use `@abstractmethod`                           |
| Can contain normal methods                   | Not all methods need to be abstract             |
| Subclass must implement all abstract methods | Otherwise, it's still abstract                  |

---

## 🆚 Abstract Class vs Interface (in other languages):

* In Java, **interface** = only method declarations
* In Python, abstract classes can have both:

  * **Abstract methods** (no implementation)
  * **Concrete methods** (with implementation)

---

## 🧱 Abstract Class with Multiple Methods

```python
class Shape(ABC):
    @abstractmethod
    def area(self): pass

    @abstractmethod
    def perimeter(self): pass
```

```python
class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def perimeter(self):
        return 2 * (self.width + self.height)
```

---

## 🧰 Abstract Class with `__init__` Constructor

```python
class Vehicle(ABC):
    def __init__(self, brand):
        self.brand = brand

    @abstractmethod
    def drive(self):
        pass
```

---

## 📌 Summary Table

| Feature                   | Description                           |
| ------------------------- | ------------------------------------- |
| Import                    | `from abc import ABC, abstractmethod` |
| Base class                | Inherit from `ABC`                    |
| Abstract method           | Use `@abstractmethod`                 |
| Direct instantiation      | ❌ Not allowed                         |
| Subclass must implement   | ✅ All abstract methods                |
| Can have concrete methods | ✅ Yes                                 |

