# 📌 Expression-bodied Methods in C\#

### ✅ Definition

Introduced in **C# 6**, an **expression-bodied method** allows you to write short methods in a **single line** using the `=>` (lambda arrow) operator, instead of a full block `{ }`.

---

## 📌 General Syntax

```csharp
ReturnType MethodName(parameters) => expression;
```

* **ReturnType** → type of the value returned (or `void` if none)
* **expression** → a single expression (not a block of code)

---

## 📌 Examples

### 1. Simple calculation method

```csharp
static int Square(int x) => x * x;

static void Main()
{
    Console.WriteLine(Square(5)); // 25
}
```

---

### 2. Void method

```csharp
static void PrintMessage(string msg) => Console.WriteLine(msg);

static void Main()
{
    PrintMessage("Hello, World!");
}
```

---

### 3. Expression-bodied Property

```csharp
class Person
{
    public string FirstName { get; set; }
    public string LastName { get; set; }

    // Expression-bodied property
    public string FullName => $"{FirstName} {LastName}";
}

class Program
{
    static void Main()
    {
        Person p = new Person { FirstName = "Ali", LastName = "Rezaei" };
        Console.WriteLine(p.FullName); // Ali Rezaei
    }
}
```

---

### 4. Expression-bodied Constructor & Destructor (C# 7+)

```csharp
class Car
{
    private string model;

    // Expression-bodied constructor
    public Car(string model) => this.model = model;

    // Expression-bodied destructor
    ~Car() => Console.WriteLine("Car object destroyed");
}
```

---

### 5. Recursive Expression-bodied Method

```csharp
static int Factorial(int n) => (n <= 1) ? 1 : n * Factorial(n - 1);

static void Main()
{
    Console.WriteLine(Factorial(5)); // 120
}
```

---

## ⚡ Key Notes

* Best for **short, single-expression methods**.
* Improves **readability and conciseness**.
* If the method body needs multiple statements, use the regular `{ }` form instead.
