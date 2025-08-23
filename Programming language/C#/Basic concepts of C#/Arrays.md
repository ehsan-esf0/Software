# 🔹 What is an Array?

* An **array** is a collection of elements of the **same type**.
* The size is **fixed** once created.
* Arrays are **reference types** (allocated on the heap).

```csharp
int[] numbers = new int[5]; // an array of 5 integers
```

---

# 🔹 Ways to Create Arrays

### 1. With size, then assign values

```csharp
int[] arr = new int[3];
arr[0] = 10;
arr[1] = 20;
arr[2] = 30;
```

### 2. With initialization

```csharp
int[] arr = { 10, 20, 30 };
```

### 3. Multi-dimensional array

```csharp
int[,] matrix = new int[2, 3];
int[,] matrix2 = { {1, 2, 3}, {4, 5, 6} };
```

### 4. Jagged array (array of arrays)

```csharp
int[][] jagged = new int[2][];
jagged[0] = new int[] { 1, 2, 3 };
jagged[1] = new int[] { 4, 5 };
```

---

# 🔹 Array Properties

```csharp
int[] nums = { 5, 10, 15 };

Console.WriteLine(nums.Length);   // 3
Console.WriteLine(nums[0]);       // 5
nums[1] = 20;                     // modify element
```

---

# 🔹 Iterating Arrays

### Using `for`

```csharp
for (int i = 0; i < nums.Length; i++)
    Console.WriteLine(nums[i]);
```

### Using `foreach`

```csharp
foreach (int n in nums)
    Console.WriteLine(n);
```

---

# 🔹 Useful Methods (`System.Array`)

```csharp
int[] arr = { 30, 10, 20 };

// Sort
Array.Sort(arr);           // 10, 20, 30

// Reverse
Array.Reverse(arr);        // 30, 20, 10

// Find index
int index = Array.IndexOf(arr, 20); // 1

// Copy
int[] copy = new int[arr.Length];
Array.Copy(arr, copy, arr.Length);
```

---

# 🔹 Multi-Dimensional Arrays

Like a matrix:

```csharp
int[,] matrix = new int[2, 3]
{
    { 1, 2, 3 },
    { 4, 5, 6 }
};

Console.WriteLine(matrix[1, 2]); // 6
```

---

# 🔹 Jagged Arrays (arrays of arrays)

Each row can have a different size:

```csharp
int[][] jagged = new int[3][];
jagged[0] = new int[] { 1, 2 };
jagged[1] = new int[] { 3, 4, 5 };
jagged[2] = new int[] { 6 };

Console.WriteLine(jagged[1][2]); // 5
```

---

# 🔹 Arrays vs Lists

| Feature | Array                                  | List<T>                           |
| ------- | -------------------------------------- | --------------------------------- |
| Size    | Fixed                                  | Dynamic                           |
| Speed   | Slightly faster                        | Slightly slower (resize overhead) |
| Methods | Limited (`Sort`, `Copy`, `Reverse`, …) | Rich (`Add`, `Remove`, `Find`, …) |

📌 If size is fixed → use `Array`
📌 If size is dynamic → use `List<T>`

---

# 🔹 Important Notes

* Arrays in C# are **always reference types**, even if they hold value types.
* Indexing is **zero-based**.
* Can hold **nullable types**:

```csharp
int?[] arr = { 1, null, 3 };
```

---

# 📝 Summary

* Arrays store **same-type elements** with fixed size.
* Types: one-dimensional, multi-dimensional, jagged.
* Useful methods: `Sort`, `Reverse`, `IndexOf`, `Copy`.
* For dynamic collections, prefer `List<T>`.
