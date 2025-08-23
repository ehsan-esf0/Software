# 🔹 1) `for` loop — classic counter-based

* Best when you know the number of iterations or need an index.

```csharp
for (int i = 0; i < 5; i++)
{
    Console.WriteLine(i);
}
```

### Notes

* Reverse iteration:

```csharp
for (int i = items.Count - 1; i >= 0; i--) { /* ... */ }
```

* Multiple variables:

```csharp
for (int i = 0, j = 10; i < j; i++, j--) { /* ... */ }
```

---

# 🔹 2) `foreach` loop — simple collection iteration

* Clean and safe for iterating over `IEnumerable`/`IEnumerable<T>`.

```csharp
var nums = new List<int> { 10, 20, 30 };
foreach (var n in nums)
{
    Console.WriteLine(n);
}
```

⚠️ You cannot modify the collection (add/remove) during a `foreach`.
If you need the index:

```csharp
foreach (var (value, index) in nums.Select((v, i) => (v, i)))
{
    Console.WriteLine($"{index}: {value}");
}
```

---

# 🔹 3) `while` loop — condition checked first

* Used when the number of iterations is unknown, but condition must be checked before each run.

```csharp
int i = 0;
while (i < 3)
{
    Console.WriteLine(i);
    i++;
}
```

---

# 🔹 4) `do ... while` loop — executes at least once

* Condition checked **after** execution.

```csharp
int x = 0;
do
{
    Console.WriteLine(x);
    x++;
} while (x < 1);
```

---

# 🔹 5) `await foreach` — asynchronous iteration (C# 8+)

* For streaming or gradually available data (`IAsyncEnumerable<T>`).

```csharp
await foreach (var line in ReadLinesAsync("data.txt"))
{
    Console.WriteLine(line);
}

async IAsyncEnumerable<string> ReadLinesAsync(string path)
{
    using var reader = new StreamReader(path);
    while (!reader.EndOfStream)
        yield return await reader.ReadLineAsync();
}
```

---

# 🔹 6) Loop control: `break` / `continue`

```csharp
for (int i = 0; i < 10; i++)
{
    if (i == 3) continue;  // skip iteration
    if (i == 7) break;     // exit loop
    Console.WriteLine(i);
}
```

---

# 🔹 7) Nested loops

```csharp
for (int r = 0; r < 3; r++)
{
    for (int c = 0; c < 2; c++)
        Console.Write($"({r},{c}) ");
    Console.WriteLine();
}
```

---

# 🔹 8) Iterator with `yield return`

* Create custom enumerables without building temporary collections.

```csharp
static IEnumerable<int> RangeStep(int start, int end, int step)
{
    for (int i = start; i <= end; i += step)
        yield return i;
}

foreach (var n in RangeStep(2, 10, 2))
    Console.WriteLine(n); // 2, 4, 6, 8, 10
```

---

# 🔹 9) LINQ instead of manual loops

Sometimes cleaner:

```csharp
var top3Names = people
    .Where(p => p.Age >= 18)
    .OrderByDescending(p => p.Score)
    .Select(p => p.Name)
    .Take(3)
    .ToList();
```

---

# 🔹 10) Parallel loops (CPU-bound tasks)

```csharp
Parallel.For(0, 100, i =>
{
    Work(i); // Ensure thread safety!
});
```

---

# 🔹 11) Common pitfalls

* **Off-by-one** errors (`<` vs. `<=`).
* **Changing collection in foreach** → InvalidOperationException.
* **Closures in loops**: capture the variable in a local copy.

```csharp
var actions = new List<Action>();
for (int i = 0; i < 3; i++)
{
    int copy = i;
    actions.Add(() => Console.WriteLine(copy));
}
actions.ForEach(a => a()); // 0, 1, 2
```

---

# 🔹 12) Full demo program (all loops)

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

class Program
{
    static async IAsyncEnumerable<int> NumbersAsync()
    {
        for (int i = 1; i <= 3; i++)
        {
            await Task.Delay(50);
            yield return i;
        }
    }

    static IEnumerable<int> EvensUpTo(int n)
    {
        for (int i = 2; i <= n; i += 2)
            yield return i;
    }

    static async Task Main()
    {
        // for
        for (int i = 0; i < 3; i++) Console.Write($"for:{i} ");
        Console.WriteLine();

        // foreach
        foreach (var e in EvensUpTo(6)) Console.Write($"foreach:{e} ");
        Console.WriteLine();

        // while
        int w = 0;
        while (w < 2) { Console.Write($"while:{w} "); w++; }
        Console.WriteLine();

        // do-while
        int d = 0;
        do { Console.Write($"do:{d} "); d++; } while (d < 1);
        Console.WriteLine();

        // await foreach
        await foreach (var n in NumbersAsync())
            Console.Write($"async:{n} ");
        Console.WriteLine();

        // break / continue
        for (int i = 0; i < 5; i++)
        {
            if (i == 1) continue;
            if (i == 3) break;
            Console.Write($"bc:{i} ");
        }
        Console.WriteLine();
    }
}
```

---

# 📝 Quick Comparison Table

| Loop type       | Main use case          | Pros                 | Cons                        |
| --------------- | ---------------------- | -------------------- | --------------------------- |
| `for`           | Indexed, fixed count   | Flexible             | Off-by-one mistakes         |
| `foreach`       | Iterate collections    | Very readable        | Cannot modify collection    |
| `while`         | Condition-driven       | Simple               | Risk of infinite loop       |
| `do-while`      | Must run at least once | Good for menus/input | Executes once even if false |
| `await foreach` | Async streams          | Non-blocking         | Needs `IAsyncEnumerable<T>` |
| `Parallel.For`  | CPU-bound parallelism  | Faster on multicore  | Thread safety required      |

