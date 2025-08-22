## 🔹 1. What Are Conditionals in C#?

Conditionals allow us to **control the flow of the program**.
They decide which part of the code should run depending on whether a condition is **true** or **false**.

* `true` → the condition is satisfied.
* `false` → the condition is not satisfied.

---

## 🔹 2. Conditional Statements in C\#

### ✅ `if`

Executes a block if the condition is true:

```csharp
int age = 20;

if (age >= 18)
{
    Console.WriteLine("You are an adult.");
}
```

---

### ✅ `if – else`

Executes one block if true, otherwise another block:

```csharp
int age = 15;

if (age >= 18)
{
    Console.WriteLine("Adult");
}
else
{
    Console.WriteLine("Not Adult");
}
```

---

### ✅ `if – else if – else`

Checks multiple conditions in order:

```csharp
int score = 75;

if (score >= 90)
{
    Console.WriteLine("Grade: A");
}
else if (score >= 70)
{
    Console.WriteLine("Grade: B");
}
else if (score >= 50)
{
    Console.WriteLine("Grade: C");
}
else
{
    Console.WriteLine("Grade: F");
}
```

---

### ✅ Nested `if`

An `if` inside another `if`:

```csharp
int age = 25;
bool hasID = true;

if (age >= 18)
{
    if (hasID)
    {
        Console.WriteLine("You can enter.");
    }
    else
    {
        Console.WriteLine("You need an ID.");
    }
}
```

---

### ✅ Ternary Operator `?:`

A shorthand form of `if–else`:

```csharp
int age = 20;
string result = (age >= 18) ? "Adult" : "Not Adult";
Console.WriteLine(result);
```

---

### ✅ `switch – case`

For checking multiple fixed values:

```csharp
int day = 3;

switch (day)
{
    case 1:
        Console.WriteLine("Monday");
        break;
    case 2:
        Console.WriteLine("Tuesday");
        break;
    case 3:
        Console.WriteLine("Wednesday");
        break;
    default:
        Console.WriteLine("Invalid day");
        break;
}
```

---

### ✅ Pattern Matching in `switch` (C# 7+)

A more powerful version of `switch`:

```csharp
object obj = 42;

switch (obj)
{
    case int n when n > 0:
        Console.WriteLine("Positive integer");
        break;
    case int n when n < 0:
        Console.WriteLine("Negative integer");
        break;
    case string s:
        Console.WriteLine($"String with length {s.Length}");
        break;
    default:
        Console.WriteLine("Other type");
        break;
}
```

---

## 🔹 3. Comparison Operators

Used inside conditions:

* `==` → equal to
* `!=` → not equal to
* `>` → greater than
* `<` → less than
* `>=` → greater than or equal to
* `<=` → less than or equal to

Example:

```csharp
int a = 10, b = 20;

if (a != b)
{
    Console.WriteLine("a is not equal to b");
}
```

---

## 🔹 4. Logical Operators

Combine multiple conditions:

* `&&` → AND (all must be true)
* `||` → OR (at least one must be true)
* `!` → NOT (reverses the result)

Example:

```csharp
int age = 22;
bool hasTicket = true;

if (age >= 18 && hasTicket)
{
    Console.WriteLine("You can enter.");
}
```

---

## 🔹 5. Key Notes

1. Conditions must return a **Boolean (true/false)**.
2. Unlike C++ or JavaScript, you **cannot use numbers instead of Boolean** in C#.
   Example: `if (1)` is invalid in C#.
3. Ternary operator `?:` is useful for short conditions.
4. Use `switch` when you have multiple fixed cases.
