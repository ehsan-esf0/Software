# 🧬 Polymorphism in Python

> “One interface, multiple implementations”

---

## ✅ What is Polymorphism?

**Polymorphism** is an Object-Oriented Programming (OOP) concept that allows different classes to be treated **as if they are the same type**, through a **common interface**.

### 💡 In simple words:

> You can call the **same method** on different objects, and each will behave **according to its own class.**

---

## 📌 Why is Polymorphism useful?

| Benefit              | Description                              |
| -------------------- | ---------------------------------------- |
| ✅ Flexibility        | Works with different object types easily |
| ✅ Maintainability    | Code is cleaner and easier to extend     |
| ✅ Reusability        | Reuse the same logic on different types  |
| ✅ Fewer conditionals | Avoids using lots of `if`/`elif`/`else`  |

---

## 🎯 Types of Polymorphism in Python

| Type                         | Description                                 |
| ---------------------------- | ------------------------------------------- |
| 1. **Duck Typing**           | If it behaves like a duck, it is a duck     |
| 2. **Method Overriding**     | Subclass redefines a parent method          |
| 3. **Function Polymorphism** | Same function works on different data types |
| 4. **Operator Overloading**  | Using `+`, `*`, etc., on custom objects     |

---

## 🔸 1. Duck Typing

```python
class Dog:
    def speak(self):
        return "Woof!"

class Cat:
    def speak(self):
        return "Meow!"

def animal_sound(animal):
    print(animal.speak())

animal_sound(Dog())  # Woof!
animal_sound(Cat())  # Meow!
```

✔ Python doesn't care what the object's type is, **as long as it has the method**.

---

## 🔸 2. Method Overriding (via Inheritance)

```python
class Animal:
    def speak(self):
        return "Some sound"

class Dog(Animal):
    def speak(self):
        return "Woof!"

class Cat(Animal):
    def speak(self):
        return "Meow!"

animals = [Dog(), Cat(), Animal()]
for a in animals:
    print(a.speak())
```

✅ The `speak()` method is **overridden** in each subclass — classic polymorphism.

---

## 🔸 3. Function Polymorphism (Same function, different types)

```python
print(len("hello"))      # 5
print(len([1, 2, 3, 4])) # 4
print(len({"a": 1}))     # 1
```

✔ The `len()` function works differently depending on the type — this is polymorphism through **built-in functions**.

---

## 🔸 4. Operator Overloading

```python
class Vector:
    def __init__(self, x, y):
        self.x, self.y = x, y

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __repr__(self):
        return f"({self.x}, {self.y})"

v1 = Vector(1, 2)
v2 = Vector(3, 4)

print(v1 + v2)  # (4, 6)
```

✅ The `+` operator is **overloaded** to work with custom `Vector` objects.

---

## ✅ Real-Life Analogy

```text
You can “drive” a car, a motorcycle, or a truck.
Each vehicle class has its own implementation of `drive()`,
but the interface (method name) is the same.
```

---

## 🧠 Behind the Scenes: Polymorphism via Inheritance + Overriding

```python
class Shape:
    def area(self):
        raise NotImplementedError

class Circle(Shape):
    def area(self):
        return 3.14 * 5 * 5

class Square(Shape):
    def area(self):
        return 4 * 4

def print_area(shape: Shape):
    print(shape.area())

print_area(Circle())  # 78.5
print_area(Square())  # 16
```

---

## 🛠 Advanced Tip: Abstract Base Classes

```python
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def draw(self):
        pass

class Triangle(Shape):
    def draw(self):
        print("Drawing triangle")

# Cannot create instance of Shape: it's abstract
```

Using `ABC` (Abstract Base Class) ensures all subclasses implement required methods.

---

## ✅ Summary Table

| Concept               | Description                            | Example                             |
| --------------------- | -------------------------------------- | ----------------------------------- |
| Duck Typing           | Behavior matters more than type        | `animal.speak()`                    |
| Method Overriding     | Child replaces method from parent      | `Dog.speak()` over `Animal.speak()` |
| Function Polymorphism | Same function works on many data types | `len()`, `print()`                  |
| Operator Overloading  | Use operators on custom objects        | `v1 + v2` with `__add__`            |

