# 🔹 What is a String in C#?

* A **string** is a sequence of characters (`System.String` class).
* Immutable → once created, it **cannot be modified** (every change creates a new string).
* Literal syntax:

```csharp
string s1 = "Hello";
String s2 = "World"; // same as above
```

---

# 🔹 String Creation

```csharp
string empty = "";           // empty string
string fromCharArray = new string(new char[] { 'C', '#'});
string repeated = new string('*', 5); // ***** 
```

---

# 🔹 String Properties

```csharp
string text = "CSharp";
Console.WriteLine(text.Length);        // 6
Console.WriteLine(text[0]);            // 'C'
Console.WriteLine(text.Contains("Sharp")); // true
```

---

# 🔹 String Concatenation

```csharp
string a = "Hello";
string b = "World";

string c1 = a + " " + b;
string c2 = string.Concat(a, " ", b);
string c3 = string.Join(" ", a, b);

Console.WriteLine(c1); // Hello World
```

---

# 🔹 String Interpolation (C# 6+)

Cleaner than concatenation:

```csharp
string name = "Alice";
int age = 25;

string msg = $"My name is {name}, I am {age} years old.";
Console.WriteLine(msg);
```

---

# 🔹 Verbatim Strings (`@`)

* Keeps line breaks and ignores escape sequences:

```csharp
string path = @"C:\Users\Alice\Documents";
string multiline = @"Line1
Line2
Line3";
```

---

# 🔹 Common String Methods

```csharp
string s = "  Hello World!  ";

// Case
Console.WriteLine(s.ToUpper()); // "  HELLO WORLD!  "
Console.WriteLine(s.ToLower());

// Trim
Console.WriteLine(s.Trim());    // "Hello World!"

// Substring
Console.WriteLine(s.Substring(2, 5)); // "Hello"

// Replace
Console.WriteLine(s.Replace("World", "C#")); // "  Hello C#!  "

// Split & Join
string[] parts = s.Split(' ');
Console.WriteLine(string.Join("-", parts)); 
```

---

# 🔹 Searching

```csharp
string t = "Programming in C#";
Console.WriteLine(t.StartsWith("Pro"));   // true
Console.WriteLine(t.EndsWith("C#"));      // true
Console.WriteLine(t.IndexOf("in"));       // 11
Console.WriteLine(t.Contains("Java"));    // false
```

---

# 🔹 String Comparison

```csharp
string s1 = "Hello";
string s2 = "hello";

Console.WriteLine(s1 == s2);                          // false
Console.WriteLine(string.Equals(s1, s2, StringComparison.OrdinalIgnoreCase)); // true
```

---

# 🔹 StringBuilder (for performance)

Since strings are **immutable**, repeated concatenation creates new objects → inefficient.
`StringBuilder` (from `System.Text`) solves this.

```csharp
using System.Text;

var sb = new StringBuilder();
sb.Append("Hello");
sb.Append(" ");
sb.Append("World");
string result = sb.ToString(); // "Hello World"
```

---

# 🔹 Useful Features

1. **IsNullOrEmpty / IsNullOrWhiteSpace**

```csharp
string? s = null;
Console.WriteLine(string.IsNullOrEmpty(s));      // true
Console.WriteLine(string.IsNullOrWhiteSpace(" ")); // true
```

2. **Raw String Literals (C# 11)**

```csharp
string json = """
{
  "name": "Alice",
  "age": 25
}
""";
```

3. **Interpolation with formatting**

```csharp
double price = 1234.56;
Console.WriteLine($"Price: {price:C}"); // Price: $1,234.56
```

