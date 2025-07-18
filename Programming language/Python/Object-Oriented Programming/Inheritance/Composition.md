## ✅ What is Composition?

**Composition** is an object-oriented programming principle where one class **contains** an object of another class as an attribute. This is often referred to as a **"has-a" relationship**.

> Rather than saying "Class A is a type of Class B" (which is inheritance), we say "Class A has a Class B".

---

## 🔹 Simple Example:

```python
class Engine:
    def start(self):
        print("Engine started")

class Car:
    def __init__(self):
        self.engine = Engine()  # Composition: Car has an Engine

    def start(self):
        self.engine.start()
        print("Car is moving")

# Usage
my_car = Car()
my_car.start()
```

### Output:

```
Engine started  
Car is moving
```

---

## 🔸 Composition vs Inheritance

| Feature           | Inheritance                     | Composition                        |
| ----------------- | ------------------------------- | ---------------------------------- |
| Relationship Type | "is-a" (e.g., Dog is an Animal) | "has-a" (e.g., Car has an Engine)  |
| Flexibility       | Less flexible                   | More flexible                      |
| Reusability       | Limited by hierarchy            | Highly reusable                    |
| Runtime changes   | Hard                            | Easy (swap components dynamically) |

---

## 🔹 Why Use Composition?

* ✅ **Better modularity** – code is cleaner and more independent
* ✅ **More flexible** – components can be replaced easily
* ✅ **Avoids tight coupling** – promotes loosely coupled systems
* ✅ **Testable** – classes are easier to test in isolation

---

## 🔸 More Complex Example:

```python
class Battery:
    def get_status(self):
        return "Battery full"

class Screen:
    def turn_on(self):
        return "Screen is on"

class Smartphone:
    def __init__(self):
        self.battery = Battery()
        self.screen = Screen()

    def power_on(self):
        print(self.battery.get_status())
        print(self.screen.turn_on())

# Usage
phone = Smartphone()
phone.power_on()
```
