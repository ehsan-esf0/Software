# 🔒 Encapsulation in Python

---

## ✅ What is Encapsulation?

**Encapsulation** is one of the **four pillars** of Object-Oriented Programming (OOP), along with Inheritance, Polymorphism, and Abstraction.

> **Definition:**
> Encapsulation is the concept of **hiding internal data** and behavior of an object and only **exposing a controlled interface** to the outside world.

In simpler terms:

> **"You protect the inner workings of your object and only allow others to interact with it in safe, predefined ways."**

---

## 💡 Why is Encapsulation Important?

* ✅ Protects data from unauthorized access and modification
* ✅ Makes code more modular and maintainable
* ✅ Prevents accidental interference
* ✅ Allows validation and control over changes

---

## 🧱 How is Encapsulation Implemented in Python?

Python does not have **true private access modifiers** (like `private` in C++ or Java), but it uses a **naming convention** to simulate access control.

| Syntax       | Access Level              | Description                                          |
| ------------ | ------------------------- | ---------------------------------------------------- |
| `public`     | No underscore             | Accessible from anywhere                             |
| `_protected` | Single underscore `_var`  | Meant for internal use only (by convention)          |
| `__private`  | Double underscore `__var` | Name mangling makes it harder to access from outside |

---

## ✅ Public Members (Default)

```python
class Person:
    def __init__(self, name):
        self.name = name  # public attribute

    def greet(self):
        print(f"Hello, my name is {self.name}")

p = Person("Alice")
print(p.name)      # ✅ Accessible
p.greet()          # ✅ Accessible
```

---

## ✅ Protected Members (Convention: `_var`)

```python
class Animal:
    def __init__(self):
        self._species = "Unknown"  # protected by convention

a = Animal()
print(a._species)   # ⚠️ Still accessible, but _suggested_ to be internal use only
```

> ❗ It’s a **convention**, not a real restriction.

---

## ✅ Private Members (Name Mangling: `__var`)

```python
class BankAccount:
    def __init__(self, balance):
        self.__balance = balance  # private attribute

    def get_balance(self):
        return self.__balance

    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount

acc = BankAccount(1000)
print(acc.get_balance())   # ✅ OK
# print(acc.__balance)     ❌ Error: AttributeError

# But it's still technically accessible:
print(acc._BankAccount__balance)  # ⚠️ Not recommended, but possible
```

> 🔒 `__var` triggers **name mangling**: it becomes `_ClassName__var` internally.

---

## 🔧 Encapsulation with Getters and Setters

Encapsulation often includes **getters and setters** to control access to private data.

```python
class Student:
    def __init__(self, age):
        self.__age = age

    def get_age(self):
        return self.__age

    def set_age(self, new_age):
        if 0 < new_age < 150:
            self.__age = new_age
        else:
            print("Invalid age!")

s = Student(20)
print(s.get_age())     # 20
s.set_age(30)
print(s.get_age())     # 30
s.set_age(-5)          # Invalid age!
```

---

## ✅ Pythonic Way: Using `@property`

Python provides a clean and elegant way to use **encapsulation** with `@property`.

```python
class Circle:
    def __init__(self, radius):
        self.__radius = radius

    @property
    def radius(self):
        return self.__radius

    @radius.setter
    def radius(self, value):
        if value > 0:
            self.__radius = value
        else:
            raise ValueError("Radius must be positive")

c = Circle(5)
print(c.radius)      # 5
c.radius = 10        # Uses setter
print(c.radius)      # 10
# c.radius = -3      # ❌ Raises error
```

---

## 🧠 Summary

| Feature                 | Public                                  | Protected               | Private                    |
| ----------------------- | --------------------------------------- | ----------------------- | -------------------------- |
| Syntax                  | `name`                                  | `_name`                 | `__name`                   |
| Access from outside?    | ✅ Yes                                   | ✅ Yes (not recommended) | ❌ No (but hackable)        |
| Purpose                 | Free access                             | Internal use            | Encapsulated/private logic |
| Pythonic encapsulation? | Use `@property` for getter/setter logic |                         |                            |

---

## 🚀 When to Use Encapsulation?

* To **protect critical data** (e.g., passwords, bank balance)
* To **control how and when** data is changed
* To **hide complexity** from the user of a class
