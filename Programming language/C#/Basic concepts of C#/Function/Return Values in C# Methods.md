# 📌 4. Return Values in C# Methods

### ✅ Definition

A method can **return a value** after completing its work.
We use the **`return` keyword** for this purpose.

---

## 📌 Different Cases

### 1. **Method with no return value (`void`)**

* The method performs an action but doesn’t return anything.

```csharp
static void PrintMessage()
{
    Console.WriteLine("Hello!");
}
```

---

### 2. **Method with a return value**

* Replace `void` with the type of value you want to return (`int`, `string`, `bool`, etc.).
* Use the `return` keyword inside the method.

```csharp
static int Add(int a, int b)
{
    return a + b;
}

static void Main()
{
    int result = Add(3, 5);
    Console.WriteLine("Result = " + result);
}
```

---

### 3. **Returning different data types**

* Any data type can be returned.

```csharp
static string GetGreeting(string name)
{
    return "Hello, " + name;
}

static bool IsEven(int number)
{
    return number % 2 == 0;
}

static double GetPi()
{
    return 3.14159;
}
```

---

### 4. **Early return**

* You can exit a method early using `return`.

```csharp
static void CheckNumber(int number)
{
    if (number < 0)
    {
        Console.WriteLine("Negative number!");
        return; // exit method early
    }

    Console.WriteLine("Positive number!");
}
```

---

### 5. **Multiple return statements**

* A method can have multiple `return` statements depending on conditions.

```csharp
static string Grade(int score)
{
    if (score >= 90) return "A";
    if (score >= 75) return "B";
    if (score >= 50) return "C";
    return "F";
}
```

---

### ⚡ Key Notes

* A method can have **multiple return points**.
* If the return type is **not `void`**, the method **must** return a value.
* In `void` methods, you can still use `return;` to exit early.

---
