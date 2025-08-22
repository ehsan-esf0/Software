# 📌 Data Types in C\#

In C#, every variable and object must have a type.
Types are mainly divided into the following categories:

---

## 🔹 1. **Value Types**

* Store the actual value directly (in the **Stack**).
* Copying creates a completely separate copy.

### Examples:

* **Integer types** → `byte, sbyte, short, ushort, int, uint, long, ulong`
* **Floating-point types** → `float, double, decimal`
* **Other basics** → `bool`, `char`
* **Structures** (`struct`) → e.g., `DateTime`, `TimeSpan`
* **Enumerations** (`enum`)

---

## 🔹 2. **Reference Types**

* Store a **reference (address)** to the object in the **Heap**.
* If two variables reference the same object → changes affect both.

### Examples:

* `class`
* `string`
* `array` (`int[]`, `string[]`, …)
* `object` (base of all types)
* `interface`
* `delegate`

---

## 🔹 3. **Nullable Types**

* Value types cannot normally hold `null`.
* With `?`, they can:

  ```csharp
  int? x = null;
  ```

---

## 🔹 4. **Pointer Types**

* Only available in **unsafe** context.
* Work like C/C++ pointers (store the actual memory address).
* Rarely used in everyday C#.

---

## 🔹 5. **Special Types**

* `var` → type is inferred at **compile time** from the value.
* `dynamic` → type is determined at **runtime**.
* `object` → the ultimate base type for everything.

---

## ✅ Quick Summary Table

| Category           | Examples                        | Storage    | Key Behavior        |
| ------------------ | ------------------------------- | ---------- | ------------------- |
| **Value Type**     | `int, bool, char, struct, enum` | Stack      | Independent copy    |
| **Reference Type** | `class, string, array, object`  | Heap       | Shared reference    |
| **Nullable**       | `int?, bool?`                   | Stack      | Can hold `null`     |
| **Pointer**        | `int* p` (unsafe)               | Heap/Stack | Real memory address |
| **Special**        | `var, dynamic, object`          | -          | Flexible typing     |

