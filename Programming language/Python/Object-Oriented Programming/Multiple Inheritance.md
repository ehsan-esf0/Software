# 🔄 Multiple Inheritance & `super()` in Python

## 🧩 What is **Multiple Inheritance**?

**Multiple inheritance** means a class can **inherit from more than one parent class**.

### ✅ Syntax:

```python
class Child(Parent1, Parent2):
    pass
```

### 📘 Example:

```python
class Father:
    def skills(self):
        print("Driving, Teaching")

class Mother:
    def skills(self):
        print("Cooking, Designing")

class Child(Father, Mother):
    pass

c = Child()
c.skills()  # Driving, Teaching → because Father is listed first
```

> Python uses the **MRO (Method Resolution Order)**: it searches methods **from left to right**.

---

## 🔁 `super()` Function

The `super()` function allows you to **call methods from a parent class** — and is extremely useful when working with **inheritance**, especially **multiple inheritance**.

### 🔹 Use cases:

* Initialize parent class (`__init__`)
* Avoid calling methods manually from each parent
* Respect MRO for better scalability

---

### 🧪 Basic Example:

```python
class Animal:
    def __init__(self):
        print("Animal created")

class Dog(Animal):
    def __init__(self):
        super().__init__()  # Call parent constructor
        print("Dog created")

d = Dog()
# Output:
# Animal created
# Dog created
```

---

## 🧬 Multiple Inheritance + `super()` (Advanced)

```python
class A:
    def show(self):
        print("A")

class B(A):
    def show(self):
        print("B")
        super().show()

class C(A):
    def show(self):
        print("C")
        super().show()

class D(B, C):
    def show(self):
        print("D")
        super().show()

d = D()
d.show()
```

### Output:

```
D
B
C
A
```

> `super()` follows the **MRO**, which for `D(B, C)` is:
> `D → B → C → A`

---

## 🧠 How to View MRO?

Use the `__mro__` attribute or `mro()` method:

```python
print(D.__mro__)
# or
print(D.mro())
```

---

## 🧠 Why Use `super()` in Multiple Inheritance?

✅ It helps:

* Prevent **duplicate calls**
* Maintain **clean call chains**
* Respect **MRO** without hardcoding parent classes

---

## 🔥 Example: Diamond Problem

```python
class A:
    def greet(self): print("Hello from A")

class B(A):
    def greet(self):
        print("Hello from B")
        super().greet()

class C(A):
    def greet(self):
        print("Hello from C")
        super().greet()

class D(B, C):
    def greet(self):
        print("Hello from D")
        super().greet()

d = D()
d.greet()
```

### Output:

```
Hello from D
Hello from B
Hello from C
Hello from A
```

---

## 📌 Summary

| Concept                       | Description                                      |
| ----------------------------- | ------------------------------------------------ |
| Multiple Inheritance          | Inherit from more than one class                 |
| Method Resolution Order (MRO) | Determines the order Python searches for methods |
| `super()`                     | Calls the next method in MRO                     |
| Diamond Problem               | Resolved in Python using MRO + `super()`         |
