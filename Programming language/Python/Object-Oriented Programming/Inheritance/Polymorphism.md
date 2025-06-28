## What is Polymorphism?

**Polymorphism** means "many forms." In programming, it refers to the ability of different classes to be treated through the same interface, usually by having methods with the same name but possibly different behaviors.

In Python, polymorphism allows you to use the same method name in different classes and have each class implement it differently.

---

## Example of Polymorphism with Classes

```python
class Dog:
    def speak(self):
        print("Woof!")

class Cat:
    def speak(self):
        print("Meow!")

def animal_sound(animal):
    animal.speak()  # Calls the speak method of whatever object is passed in

dog = Dog()
cat = Cat()

animal_sound(dog)  # Output: Woof!
animal_sound(cat)  # Output: Meow!
```

Here, `animal_sound` function can work with any object that has a `speak` method — that’s polymorphism.

---

## Polymorphism with Inheritance

When child classes override a parent method, calling that method on a parent reference to a child object invokes the child's version:

```python
class Animal:
    def speak(self):
        print("Animal speaks")

class Dog(Animal):
    def speak(self):
        print("Woof!")

class Cat(Animal):
    def speak(self):
        print("Meow!")

def make_animal_speak(animal: Animal):
    animal.speak()

d = Dog()
c = Cat()

make_animal_speak(d)  # Output: Woof!
make_animal_speak(c)  # Output: Meow!
```

---

## Summary

* Polymorphism lets you call the same method on different objects and get different behaviors.
* It makes your code more flexible and extensible.
* In Python, duck typing (“if it walks like a duck and quacks like a duck, it’s a duck”) means any object with the expected method will work, regardless of its class.

