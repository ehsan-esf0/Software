# 📌 8. Static vs Instance Methods in C\#

### ✅ 1. Instance Methods (Object-bound)

* You must **create an object** of the class before calling them.
* They can access both **instance fields** and **instance properties** of that object.

```csharp
class Person
{
    public string Name;

    public void SayHello()
    {
        Console.WriteLine("Hello, my name is " + Name);
    }
}

class Program
{
    static void Main()
    {
        Person p = new Person();
        p.Name = "Ali";
        p.SayHello(); // requires an object
    }
}
```

🔹 `SayHello` is an **instance method** because it’s called on an object (`p`).

---

### ✅ 2. Static Methods (Class-bound)

* Belong to the **class**, not to an object.
* Can be called **without creating an instance**.
* Can only access **static fields and properties** of the class.

```csharp
class MathHelper
{
    public static int Square(int x)
    {
        return x * x;
    }
}

class Program
{
    static void Main()
    {
        int result = MathHelper.Square(5); // no object needed
        Console.WriteLine(result);
    }
}
```

🔹 `Square` is a **static method** because it’s called directly on the class.

---

### ✅ Key Differences

| Feature            | Instance Method                             | Static Method                  |
| ------------------ | ------------------------------------------- | ------------------------------ |
| Belongs to         | Object (instance)                           | Class                          |
| Access to fields   | Can access both instance and static members | Can only access static members |
| How to call        | `object.Method()`                           | `Class.Method()`               |
| Requires an object | ✅ Yes                                       | ❌ No                           |

---

### ⚡ Important Notes

* **Utility/helper methods** are often `static` (e.g., `Math.Sqrt`).
* **Behavior that depends on an object’s state** is usually implemented as instance methods.

---
