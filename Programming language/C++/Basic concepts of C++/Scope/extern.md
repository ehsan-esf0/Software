## 🧩 Using extern for Global Variables Across Multiple Files

### ✅ Scenario:

You want to define a global variable in one file and use it in another file. To do this properly, you need to use the `extern` keyword.

---

### 📄 Example

#### 📁 file1.cpp

```cpp
int myGlobal = 42;  // This is the actual definition
```

#### 📁 file2.cpp

```cpp
extern int myGlobal;  // This is a declaration

int main() {
    myGlobal += 10;
    return 0;
}
```

#### ✅ Compilation:

You must compile both files together so the linker can resolve references:

```bash
g++ file1.cpp file2.cpp -o myProgram
```

---

### ⚠️ Important Rules

| Rule                      | Explanation                                                           |
| ------------------------- | --------------------------------------------------------------------- |
| ✅ Only one **definition** | You can define the variable (with storage) in only one file.          |
| ✅ Use `extern` in others  | In all other files, you must **declare** the variable using `extern`. |
| ✅ Link all files          | All relevant files must be included at link time.                     |

---

### ❌ Common Mistake

If you forget `extern` and accidentally **redefine** the variable in another file like this:

```cpp
// file2.cpp
int myGlobal;  // ❌ This creates a second definition!
```

You'll get a **linker error**: `multiple definition of 'myGlobal'`.

---

### 🔹 What about functions?

Function declarations **do not need `extern`**, because by default they have **external linkage**.

These two are equivalent:

```cpp
void foo();           // ✅ Standard function declaration
extern void foo();    // ✅ Also valid, but redundant
```

---

### ✅ Summary

| Item            | Needs `extern`? | Reason                                     |
| --------------- | --------------- | ------------------------------------------ |
| Global variable | ✅ Yes           | Otherwise it becomes a definition          |
| Function        | ❌ No            | Functions have external linkage by default |

