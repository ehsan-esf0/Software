# 📚 Operators in C\#

Operators in C# are special symbols that perform operations on operands (variables, constants, values).
They are grouped into categories:

---

## 1) Arithmetic Operators

`+  -  *  /  %`

```csharp
int a = 7, b = 3;
Console.WriteLine(a + b); // 10
Console.WriteLine(a - b); // 4
Console.WriteLine(a * b); // 21
Console.WriteLine(a / b); // 2   ← integer division
Console.WriteLine(a % b); // 1
```

**Notes:**

* Integer division truncates the result. For decimals, cast one operand to `double`/`decimal`.
* `decimal` is more precise than `double` for financial calculations.
* Divide-by-zero: integers → exception, floating-point → `Infinity`/`NaN`.

---

## 2) Unary Operators

`+  -  !  ~  ++  --  *  &  await  sizeof  typeof  checked/unchecked  null-forgiving (!)`

```csharp
int x = 5;
Console.WriteLine(+x);   // 5
Console.WriteLine(-x);   // -5
bool f = false;
Console.WriteLine(!f);   // true
int y = 1; Console.WriteLine(++y); // 2 (pre-increment)
int z = 1; Console.WriteLine(z++); // 1 (post-increment, then z=2)
```

**Notes:**

* `~` flips bits.
* `await` is an operator in async methods.
* `sizeof(T)` works in unsafe contexts or with built-in types.
* Null-forgiving `!` tells compiler “not null” (no runtime effect).
* In `unsafe` code: `*` (dereference), `&` (address-of).

---

## 3) Assignment & Compound Assignment

`=  +=  -=  *=  /=  %=  &=  |=  ^=  <<=  >>=  >>>=  ??=`

```csharp
int a = 10;
a += 5;   // 15
a <<= 1;  // 30
string? s = null;
s ??= "default"; // assign only if null
```

---

## 4) Relational / Comparison Operators

`==  !=  <  >  <=  >=`

```csharp
Console.WriteLine(3 == 3); // true
Console.WriteLine(3 != 4); // true
Console.WriteLine(2 < 5);  // true
```

**Notes:**

* For reference types, `==` checks reference equality by default (same address).
* Classes can overload `==`. For example, `string` checks content equality.

---

## 5) Logical Operators

`&&  ||  !`

```csharp
bool a = true, b = false;
Console.WriteLine(a && b); // false
Console.WriteLine(a || b); // true
```

**Notes:**

* `&&` and `||` are **short-circuit** operators (second operand not evaluated if result is determined).

---

## 6) Bitwise & Shift Operators

`&  |  ^  ~  <<  >>  >>>`

```csharp
int m = 0b_0101, n = 0b_0011;
Console.WriteLine(m & n); // 1
Console.WriteLine(m | n); // 7
Console.WriteLine(m ^ n); // 6
Console.WriteLine(~m);    // bitwise NOT
Console.WriteLine(m << 1);// 10
Console.WriteLine(m >> 1);// 2
```

**Notes:**

* `>>>` (unsigned right shift) introduced in C# 11.

---

## 7) Conditional (Ternary) Operator

`condition ? whenTrue : whenFalse`

```csharp
int age = 20;
string label = age >= 18 ? "Adult" : "Minor";
```

---

## 8) Null-coalescing & Null-conditional

* **Null-coalescing:** `??`, `??=`
* **Null-conditional:** `?.`, `?[]`

```csharp
string? name = null;
string display = name ?? "Unknown";

Person? p = GetPerson();
Console.WriteLine(p?.Address?.City); // safe navigation
int? len = p?.Tags?["fav"]?.Length;
```

---

## 9) Type & Pattern Operators

`is  as  (T)cast  switch-patterns`

```csharp
object obj = 42;

if (obj is int i && i > 10) { /*...*/ }

string? s = obj as string; // null if cast fails
int k = (int)obj;          // throws exception if invalid
```

Pattern matching with `switch`:

```csharp
object v = 15;
string desc = v switch
{
    int i when i < 0 => "negative int",
    int i            => $"int {i}",
    string str       => $"string len={str.Length}",
    _                => "other"
};
```

---

## 10) Index & Range Operators

`^  ..`

```csharp
int[] arr = {10,20,30,40,50};
int last = arr[^1];      // 50
int[] slice = arr[1..4]; // {20,30,40}
```

---

## 11) Object & Metadata Operators

* `new`, `with`, `nameof`, `typeof`, `default`

```csharp
var p = new Person { Name = "Ali" };
var p2 = p with { Name = "Sara" }; // record clone
Console.WriteLine(nameof(Person.Name)); // "Name"
Type t = typeof(List<int>);
int zero = default;        // 0
```

---

## 12) Invocation, Indexer & Lambda

```csharp
int Sum(int x, int y) => x + y;
var list = new List<int> {1,2,3};
Console.WriteLine(list[0]); // 1
Func<int,int,int> add = (a,b) => a + b;
```

---

## 13) String Operators

* `+` concatenation
* String interpolation `$"Hello {name}"`
* Verbatim strings `@"C:\path\file.txt"`

---

## 14) Unsafe Operators

`*  &  ->  stackalloc`

```csharp
unsafe
{
    int n = 42;
    int* p = &n;
    Console.WriteLine(*p); // 42
    int* buffer = stackalloc int[10];
}
```

---

## 15) Checked / Unchecked

```csharp
checked
{
    int a = int.MaxValue;
    // a + 1 → OverflowException
}
```

---

## 16) Operator Overloading

You can overload operators in `struct`/`class`.

```csharp
public readonly struct Meter
{
    public double Value { get; }
    public Meter(double v) => Value = v;
    public static Meter operator +(Meter a, Meter b) => new(a.Value + b.Value);
    public static bool operator ==(Meter a, Meter b) => a.Value == b.Value;
    public static bool operator !=(Meter a, Meter b) => !(a == b);
    public override bool Equals(object? o) => o is Meter m && m.Value == Value;
    public override int GetHashCode() => Value.GetHashCode();
}
```

---

## 17) Precedence & Associativity (simplified order)

1. Parentheses `()`, index `[]`, calls, `?.`, `^`, `..`
2. Unary `+ - ! ~ ++ -- (T)`
3. `* / %`
4. `+ -`
5. Shifts `<< >> >>>`
6. Relational `< <= > >= is as`
7. Equality `== !=`
8. Bitwise `& ^ |`
9. Logical `&& ||`
10. Null-coalescing `??`
11. Ternary `?:`
12. Assignment `= += -= … ??=`

👉 Always use parentheses for clarity.

---

## ⚠️ Common Pitfalls

* `5 / 2 == 2` → integer division.
* `==` on reference types = reference equality unless overloaded.
* Use `&&`/`||` for short-circuit to avoid `NullReferenceException`.
* Use `decimal` for money, not `double`.
* Boxing/unboxing happens when casting value types to `object`.
* Overflow silently wraps unless in `checked` block.
* `?.` + `??` = safest way to handle `null`.
