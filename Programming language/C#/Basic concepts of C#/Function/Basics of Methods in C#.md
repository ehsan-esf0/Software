# 📌 1. Basics of Methods in C\#

### ✅ What is a Method?

A **method** is a block of code that performs a specific task.
You can **call** it multiple times without rewriting the same code.

---

### 📝 General Syntax of a Method:

```csharp
[AccessModifier] [ReturnType] MethodName([parameters])
{
    // method body
}
```

---

### 📌 Parts of a Method:

1. **AccessModifier (optional):**
   Defines the visibility of the method (`public`, `private`, etc.).

2. **ReturnType:**
   The type of value the method returns. If it returns nothing, use `void`.

3. **MethodName:**
   The name of the method (PascalCase is recommended in C#).

4. **Parameters (optional):**
   Input values for the method (can be none, one, or many).

5. **Body:**
   The block of code that runs when the method is called.

---

### 📌 Example 1: Method with **no input and no return value**

```csharp
using System;

class Program
{
    static void SayHello()
    {
        Console.WriteLine("Hello, World!");
    }

    static void Main()
    {
        SayHello(); // Calling the method
    }
}
```

🔹 `SayHello()` → no input, no return (`void`).

---

### 📌 Example 2: Method with **return value**

```csharp
using System;

class Program
{
    static int Sum()
    {
        int a = 5;
        int b = 10;
        return a + b; // returning the result
    }

    static void Main()
    {
        int result = Sum();
        Console.WriteLine("Result = " + result);
    }
}
```

🔹 `Sum()` → returns an `int` value.

---

### 📌 Example 3: Method with **parameters and return value**

```csharp
using System;

class Program
{
    static int Multiply(int x, int y)
    {
        return x * y;
    }

    static void Main()
    {
        int result = Multiply(3, 4); // passing arguments
        Console.WriteLine("3 × 4 = " + result);
    }
}
```

🔹 `Multiply(int x, int y)` → takes **two inputs** and returns their product.

