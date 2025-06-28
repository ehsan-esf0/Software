## What is Inheritance in Python?

Inheritance allows you to create a new class (child class or subclass) that **inherits** attributes and methods from an existing class (parent class or superclass). The child class can use, extend, or override the behavior of the parent class.

---

## How to Define Inheritance in Python

To inherit from a parent class, write the parent class name inside parentheses after the child class name:

```python
class Parent:
    def __init__(self):
        print("Parent constructor")

    def say_hello(self):
        print("Hello from Parent")

class Child(Parent):
    def __init__(self):
        super().__init__()  # Call parent constructor
        print("Child constructor")

    def say_hello(self):
        print("Hello from Child")
```

---

## Example Usage

```python
c = Child()
c.say_hello()
```

Output:

```
Parent constructor
Child constructor
Hello from Child
```

---

## Important Points:

* `super()` is used to call methods of the parent class (commonly the parent constructor).
* If a method is defined in the child class with the same name as in the parent, it **overrides** the parent method.
* If a method is missing in the child, the parent’s method is used.

---

## Multiple Inheritance

Python allows a class to inherit from multiple parent classes:

```python
class A:
    def method_a(self):
        print("Method A")

class B:
    def method_b(self):
        print("Method B")

class C(A, B):
    pass

obj = C()
obj.method_a()
obj.method_b()
```

Output:

```
Method A
Method B
```

---