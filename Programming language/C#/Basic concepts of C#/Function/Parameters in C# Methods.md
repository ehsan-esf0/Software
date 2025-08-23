# 📌 3. Parameters in C# Methods

### ✅ What are parameters?

Parameters are **inputs** that you can pass into a method so it can work with them.
They are defined inside the parentheses `()` after the method name.

---

## 📌 Types of Parameters in C\#

### 1. **Regular Parameters (By Value – default)**

* The value is **copied** and passed into the method.
* Changing it inside the method does **not** affect the original variable.

```csharp
using System;

class Program
{
    static void ChangeValue(int x)
    {
        x = 100;
        Console.WriteLine("Inside method: " + x);
    }

    static void Main()
    {
        int a = 10;
        ChangeValue(a);
        Console.WriteLine("Outside method: " + a);
    }
}
```

**Output:**

```
Inside method: 100
Outside method: 10
```

---

### 2. **Default Parameters**

* You can assign a default value to a parameter.
* If no value is passed, the default is used.

```csharp
static void Greet(string name = "Guest")
{
    Console.WriteLine("Hello, " + name);
}

static void Main()
{
    Greet();        // Hello, Guest
    Greet("Sara");  // Hello, Sara
}
```

---

### 3. **Optional Parameters**

* Similar to defaults, but you can skip some arguments when calling.

```csharp
static void ShowInfo(string name, int age = 18)
{
    Console.WriteLine($"{name}, {age} years old");
}

static void Main()
{
    ShowInfo("Ali");        // Ali, 18 years old
    ShowInfo("Sara", 25);   // Sara, 25 years old
}
```

---

### 4. **Named Arguments**

* You can pass arguments by explicitly naming them.
* Order doesn’t matter when using names.

```csharp
static void Display(string firstName, string lastName)
{
    Console.WriteLine($"{firstName} {lastName}");
}

static void Main()
{
    Display(firstName: "Ali", lastName: "Rezaei");
    Display(lastName: "Ahmadi", firstName: "Sara"); // order reversed
}
```

---

### 5. **`ref` Parameters**

* Passed by **reference**, not by value.
* Changes inside the method affect the original variable.

```csharp
static void Increase(ref int number)
{
    number += 10;
}

static void Main()
{
    int a = 5;
    Increase(ref a);
    Console.WriteLine(a); // 15
}
```

---

### 6. **`out` Parameters**

* Also passed by reference.
* The variable **must be assigned** inside the method before being used.

```csharp
static void GetValues(out int x, out int y)
{
    x = 5;
    y = 10;
}

static void Main()
{
    int a, b;
    GetValues(out a, out b);
    Console.WriteLine($"a={a}, b={b}"); // a=5, b=10
}
```

---

### 7. **`params` (Variable Number of Arguments)**

* Allows you to pass an arbitrary number of values as an array.

```csharp
static int Sum(params int[] numbers)
{
    int total = 0;
    foreach (int n in numbers)
        total += n;
    return total;
}

static void Main()
{
    Console.WriteLine(Sum(1, 2, 3));        // 6
    Console.WriteLine(Sum(10, 20, 30, 40)); // 100
}
```
