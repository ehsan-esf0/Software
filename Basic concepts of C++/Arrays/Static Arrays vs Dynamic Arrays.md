# Static Arrays vs Dynamic Arrays and Pointer Access in C++

### 1. Static Array (`int arr[10]`)

* Allocated **on the stack**.
* Size fixed at compile-time.
* Automatically deallocated when out of scope.
* Access elements using `arr[i]` or pointer arithmetic.
* The name `arr` **decays** to a pointer to the first element in most expressions.

**Example:**

```cpp
int arr[10];
arr[0] = 5;          // Access element 0
int* p = arr;        // arr decays to pointer to first element
p[1] = 10;           // Equivalent to arr[1]
```

---

### 2. Dynamic Array (`int* ptr = new int[10];`)

* Allocated **on the heap**.
* Size determined at runtime.
* Must be manually deallocated with `delete[]`.
* Access elements similarly with `ptr[i]` or pointer arithmetic.

**Example:**

```cpp
int* ptr = new int[10];
ptr[0] = 5;
ptr[1] = 10;
// ... use the array ...
delete[] ptr;   // Must free memory manually
```

---

### 3. Why does `[]` operator work on pointers?

`ptr[i]` is equivalent to:

```cpp
*(ptr + i)
```

Meaning: advance the pointer by `i` elements and dereference it.

---

### 4. Similarities & Differences

| Feature           | Static Array (`int arr[10]`)               | Dynamic Array (`int* ptr = new int[10]`) |
| ----------------- | ------------------------------------------ | ---------------------------------------- |
| Memory Location   | Stack                                      | Heap                                     |
| Size              | Fixed at compile-time                      | Dynamic (runtime)                        |
| Memory Management | Automatic (scope-based)                    | Manual (`delete[]`)                      |
| `[]` Usage        | Same as pointer arithmetic                 | Same as pointer arithmetic               |
| Decay to Pointer  | `arr` converts to pointer to first element | `ptr` already a pointer                  |

---

### 5. Summary

* **From access perspective**, both behave similarly with `[]`.
* **From memory management perspective**, they differ significantly.
* Use static arrays for fixed small sizes and automatic lifetime.
* Use dynamic arrays for runtime-sized data requiring manual control.

