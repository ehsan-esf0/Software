# 📌 Lambda Expressions in C\#

### ✅ Definition

* A **lambda expression** is an **anonymous function** (a function without a name).
* It can contain expressions or statements and is often used to create **inline methods**.
* The symbol **`=>`** is called the **lambda operator**, and it means *“goes to”*.

---

## 📌 General Syntax

```csharp
(parameters) => expression
```

For multiple statements:

```csharp
(parameters) =>
{
    // statements
    return value;
}
```

---

## 📌 Examples

### 1. Single-line lambda

```csharp
Func<int, int> square = x => x * x;

Console.WriteLine(square(5)); // 25
```

🔹 Here, `x => x * x` defines a function that takes an integer and returns its square.

---

### 2. Multi-line lambda

```csharp
Func<int, int, int> add = (a, b) =>
{
    int result = a + b;
    return result;
};

Console.WriteLine(add(3, 4)); // 7
```

🔹 Multi-line lambdas must use `{ }` and `return`.

---

### 3. Using **Action** (no return value)

```csharp
Action<string> greet = name => Console.WriteLine("Hello, " + name);

greet("Sara"); // Hello, Sara
```

---

### 4. No parameters

```csharp
Action sayHi = () => Console.WriteLine("Hi there!");

sayHi(); // Hi there!
```

---

### 5. With LINQ

Lambdas are heavily used in **LINQ** queries:

```csharp
int[] numbers = { 1, 2, 3, 4, 5, 6 };

var evenNumbers = numbers.Where(n => n % 2 == 0);

foreach (var num in evenNumbers)
    Console.WriteLine(num); // 2, 4, 6
```

---

### 6. With List methods

```csharp
List<string> names = new List<string> { "Ali", "Sara", "Reza" };

names.ForEach(n => Console.WriteLine("Name: " + n));
```

---

## 📌 Key Notes

* Lambdas were introduced in **C# 3.0**, replacing older **anonymous methods**.
* They improve **readability and conciseness**.
* Commonly used with:

  * **Func<T>** → methods that return a value
  * **Action<T>** → methods that return nothing (`void`)
  * **Predicate<T>** → methods that return a `bool`

---

✅ Summary:

* **`Func<int, int>`** → takes an `int`, returns an `int`.
* **`Action<string>`** → takes a `string`, returns nothing.
* **`Predicate<int>`** → takes an `int`, returns `bool`.
