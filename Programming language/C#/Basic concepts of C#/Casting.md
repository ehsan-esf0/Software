# 🔹 1. **Implicit Conversion (Casting)**

* Done automatically by the compiler.
* Safe: happens when converting from a smaller type to a larger type (e.g., `int → double`).
* No data loss.

### Example:

```csharp
using System;

class Program
{
    static void Main()
    {
        int a = 100;        // 32-bit
        double b = a;       // 64-bit, implicit conversion

        Console.WriteLine($"int: {a}");
        Console.WriteLine($"double (implicit): {b}");
    }
}
```

✅ Output:

```
int: 100
double (implicit): 100
```

---

# 🔹 2. **Explicit Conversion (Casting)**

* Performed manually by writing `(type)` before the value.
* Used when converting from a larger type to a smaller type (e.g., `double → int`).
* Possible **data loss** or truncation.

### Example:

```csharp
using System;

class Program
{
    static void Main()
    {
        double x = 9.78;
        int y = (int)x;   // explicit cast: fractional part is removed

        Console.WriteLine($"double: {x}");
        Console.WriteLine($"int (explicit): {y}");
    }
}
```

✅ Output:

```
double: 9.78
int (explicit): 9
```

---

# 🔹 3. **Using the Convert Class**

* The `Convert` class provides many helper methods like `ToInt32`, `ToDouble`, `ToString`, etc.
* Safer than manual casting.
* If conversion fails → throws an **exception**.

### Example:

```csharp
using System;

class Program
{
    static void Main()
    {
        string s = "123";
        int num = Convert.ToInt32(s);   // string → int

        double d = 12.34;
        string text = Convert.ToString(d);  // double → string

        Console.WriteLine($"Convert string to int: {num}");
        Console.WriteLine($"Convert double to string: {text}");
    }
}
```

✅ Output:

```
Convert string to int: 123
Convert double to string: 12.34
```

---

# 🔹 4. **Parse and TryParse**

* Designed for converting **strings** into numbers, booleans, etc.
* `Parse` → converts directly, throws an error if the string is invalid.
* `TryParse` → safer, returns `true/false` instead of throwing an error.

### Example:

```csharp
using System;

class Program
{
    static void Main()
    {
        // --- Parse ---
        string str1 = "456";
        int n1 = int.Parse(str1);  // string → int
        Console.WriteLine($"Parse: {n1}");

        // --- TryParse ---
        string str2 = "abc";
        bool success = int.TryParse(str2, out int n2);

        Console.WriteLine($"TryParse success: {success}");
        Console.WriteLine($"TryParse result: {n2}"); // default is 0 if failed
    }
}
```

✅ Output:

```
Parse: 456
TryParse success: False
TryParse result: 0
```

---

# 📝 Summary

| Method       | When to Use                                 | Advantages                   | Disadvantages               |
| ------------ | ------------------------------------------- | ---------------------------- | --------------------------- |
| **Implicit** | Smaller → larger type (e.g., int → double)  | Safe, automatic              | Limited use                 |
| **Explicit** | Larger → smaller type (e.g., double → int)  | Simple                       | Possible data loss          |
| **Convert**  | General conversions (string, number, bool…) | Many built-in methods, safer | Throws exception if invalid |
| **Parse**    | Convert strings to numbers/booleans         | Direct and simple            | Exception on invalid input  |
| **TryParse** | Safe string → number conversions            | No exceptions, safe          | Needs success check         |

