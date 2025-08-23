# 📌 6. Scope and Lifetime of Variables in C\#

### ✅ Scope

**Scope** refers to the *region of the code* where a variable or method is accessible.

* **Local Variables:** Accessible only inside the method or block where they are declared.
* **Class-level / Global Variables (Fields):** Accessible throughout the class (or object).

---

### ✅ Lifetime

**Lifetime** means *how long a variable exists in memory*.

* Local variables → Exist only while the method is executing.
* Fields (class-level variables) → Exist as long as the object (or program for `static`) exists.

---

## 📌 Examples

### 1. **Local variable**

```csharp
static void Test()
{
    int x = 10; // local variable
    Console.WriteLine(x);
}
```

🔹 `x` only exists inside `Test()`. Outside of it, it’s not accessible.

---

### 2. **Class-level variable (Field)**

```csharp
class Program
{
    static int counter = 0; // class-level variable

    static void Increase()
    {
        counter++;
        Console.WriteLine("Counter = " + counter);
    }

    static void Main()
    {
        Increase();
        Increase();
    }
}
```

🔹 `counter` persists between method calls because it’s declared at the class level.

---

### 3. **Local vs Global (Shadowing)**

```csharp
class Program
{
    static int number = 50; // global (field)

    static void Show()
    {
        int number = 10; // local variable shadows the global one
        Console.WriteLine(number); 
    }

    static void Main()
    {
        Show();                 // prints 10 (local)
        Console.WriteLine(number); // prints 50 (global)
    }
}
```

🔹 A local variable can **shadow** a global one if they share the same name.

---

### 4. **Block scope**

```csharp
static void Main()
{
    int a = 5;
    {
        int b = 10;
        Console.WriteLine(a + b); // both accessible here
    }
    // Console.WriteLine(b); ❌ Error (b is out of scope)
}
```

---

### ⚡ Key Notes

* Local variables → Exist only within their method or block.
* Class-level variables (fields) → Exist as long as the class/object lives.
* If two variables have the same name, the **local one takes priority** (shadowing).

