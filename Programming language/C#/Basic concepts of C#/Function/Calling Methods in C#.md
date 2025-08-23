# 📌 2. Calling Methods in C\#

### ✅ What does “calling a method” mean?

When you **define** a method, it does nothing until you **call (invoke)** it.
Calling a method means writing its **name** followed by parentheses `()` — and if it has inputs, passing the arguments inside.

---

## 📌 Different ways to call methods

### 1. **Calling a method with no input and no return value**

```csharp
using System;

class Program
{
    static void PrintMessage()
    {
        Console.WriteLine("Welcome to C#!");
    }

    static void Main()
    {
        PrintMessage(); // method call
    }
}
```

🔹 `PrintMessage()` takes no input and returns nothing (`void`).

---

### 2. **Calling a method with input parameters**

```csharp
using System;

class Program
{
    static void Greet(string name)
    {
        Console.WriteLine("Hello, " + name + "!");
    }

    static void Main()
    {
        Greet("Ali");   // input → "Ali"
        Greet("Sara");  // input → "Sara"
    }
}
```

🔹 `Greet` takes a **string parameter** and prints a message.

---

### 3. **Calling a method with a return value**

```csharp
using System;

class Program
{
    static int Square(int number)
    {
        return number * number;
    }

    static void Main()
    {
        int result = Square(6); // store returned value
        Console.WriteLine("6² = " + result);
    }
}
```

🔹 `Square(int number)` returns an `int` value that we save in `result`.

---

### 4. **Calling multiple methods in one program**

```csharp
using System;

class Program
{
    static void PrintLine()
    {
        Console.WriteLine("----------");
    }

    static int Add(int a, int b)
    {
        return a + b;
    }

    static void Main()
    {
        PrintLine(); // first call
        Console.WriteLine("Sum = " + Add(5, 7)); // second call
        PrintLine(); // third call
    }
}
```

🔹 Here we define and call **different methods** (`PrintLine` and `Add`).

---

### ⚡ Key Notes:

* You can call a method **multiple times**.
* You can pass **different arguments** each time.
* If the method has a return value, you can store it in a variable or use it directly.
