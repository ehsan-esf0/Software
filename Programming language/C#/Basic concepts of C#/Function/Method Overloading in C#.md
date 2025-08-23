# 📌 5. Method Overloading in C\#

### ✅ Definition

**Overloading** means defining **multiple methods with the same name** but with **different parameter lists**.
This allows us to perform a similar task in different ways, depending on the input.

---

## 📌 Rules for Overloading

1. The **number** of parameters must be different **OR**
2. The **types** of parameters must be different **OR**
3. The **order** of parameter types must be different.

⚠️ Changing **only the return type** is **not enough** for overloading.

---

## 📌 Examples

### 1. Different number of parameters

```csharp
static int Add(int a, int b)
{
    return a + b;
}

static int Add(int a, int b, int c)
{
    return a + b + c;
}

static void Main()
{
    Console.WriteLine(Add(3, 5));      // calls first Add
    Console.WriteLine(Add(3, 5, 7));   // calls second Add
}
```

---

### 2. Different parameter types

```csharp
static int Multiply(int a, int b)
{
    return a * b;
}

static double Multiply(double a, double b)
{
    return a * b;
}

static void Main()
{
    Console.WriteLine(Multiply(2, 3));       // int version
    Console.WriteLine(Multiply(2.5, 3.2));   // double version
}
```

---

### 3. Different parameter order

```csharp
static void Print(string name, int age)
{
    Console.WriteLine($"{name}, {age} years old");
}

static void Print(int age, string name)
{
    Console.WriteLine($"{name}, {age} years old (different order)");
}

static void Main()
{
    Print("Ali", 25);  
    Print(30, "Sara"); 
}
```

---

### ⚡ Key Notes

* Overloading improves **readability and flexibility** of code.
* It’s heavily used in the .NET Framework and libraries.
  👉 Example: `Console.WriteLine()` has many overloaded versions (string, int, double, object, etc.).

