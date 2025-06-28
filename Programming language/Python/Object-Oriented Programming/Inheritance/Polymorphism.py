class Animal:
    def __init__(self, name):
        self.name = name
        
class Dog(Animal):
    def speak(self):
        print("Woof!")
        
class Cat(Animal):
    def speak(self):
        print("Meoow!")
        
dog = Dog("Buddy")
cat = Cat("Whiskers")

class Sheep:
    def __init__(self, name):
        self.name = name
        
    def speak(self):
        print("baba!")
        
sheep = Sheep("Noly")
        
for o in [dog , cat , sheep]:
    o.speak()
