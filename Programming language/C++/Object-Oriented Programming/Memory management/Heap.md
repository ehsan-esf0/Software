### What is **Heap Memory**?

Heap memory is a section of RAM used during **runtime** for **dynamic memory allocation**. It allows programmers to allocate and deallocate memory **manually**, unlike the stack which is managed automatically.

---

### ✅ Simple Definition:

Heap is a memory region from which memory can be **allocated dynamically** at runtime and must be **freed manually** by the programmer.

---

### 🆚 Stack vs. Heap:

| Feature           | Stack                                 | Heap                        |
| ----------------- | ------------------------------------- | --------------------------- |
| Memory management | Automatic                             | Manual                      |
| Access speed      | Fast                                  | Slower                      |
| Lifetime of data  | Short (until the function/block ends) | Long (until manually freed) |
| Allocation type   | LIFO (Last In, First Out)             | Random and flexible         |
| Common issues     | Stack overflow                        | Memory leak                 |

---

### 📌 Heap Usage:

* Creating arrays or structures of unknown or variable size at runtime.
* Sharing data between functions or classes.
* Storing data that needs to outlive a single function call.

---

### 🎯 Example in C++:

```cpp
int* p = new int; // allocate on the heap
*p = 42;

delete p; // free the memory
```

For arrays:

```cpp
int* arr = new int[5]; // heap allocation

arr[0] = 10;

delete[] arr; // free the array
```

---

### ⚠️ Important Notes:

* Forgetting to `delete` → causes **memory leak**.
* Calling `delete` twice → may cause crash (**double free**).
* Use smart pointers (`std::unique_ptr`, `std::shared_ptr`) in modern C++ to avoid manual memory management.

---

### 📦 Stack vs. Heap: Examples

| Structure / Example             | Stored In                                | Explanation                                  |
| ------------------------------- | ---------------------------------------- | -------------------------------------------- |
| `int x = 5;`                    | **Stack**                                | Local variable                               |
| `int arr[10];`                  | **Stack**                                | Fixed-size array                             |
| `int* p = new int;`             | **Heap**                                 | Dynamically allocated memory                 |
| `int* arr = new int[100];`      | **Heap**                                 | Dynamically allocated array                  |
| `std::string s = "hi";`         | **Stack (object)** + **Heap (data)**     | Object on stack, content in heap             |
| `std::vector<int> v(100);`      | **Stack (object)** + **Heap (elements)** | Vector itself on stack, elements on heap     |
| Global variable                 | **Data Segment**                         | Not on stack or heap                         |
| `static int x;` inside function | **Data Segment**                         | Allocated only once, kept throughout program |

---

### 💡 Example: Combination of Stack and Heap

```cpp
void foo() {
    std::vector<int> v(10); // vector on Stack, elements on Heap
}
```

