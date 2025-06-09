## Difference between `#include` and `using` 

### 1. What is `#include` and what does it do?

`#include` is a **preprocessor directive**. Before compiling, it copies the contents of the specified file into the current file.

#### Main role:

To bring in code definitions from other files (like libraries or headers) into your current program.

#### Example:

```cpp
#include <iostream> // includes the iostream library to use cout, cin, etc.
```

#### Notes:

* Use `#include <filename>` for system/library headers.
* Use `#include "filename"` for user-defined headers.

---

### 2. What is `using` and what does it do?

`using` is for **accessing members of a namespace** without needing to write the full namespace prefix each time.

#### Main role:

To simplify access to names inside a namespace.

#### Example:

```cpp
using namespace std;

int main() {
    cout << "Hello";  // no need to write std::cout
}
```

---

### Summary table:

| Feature        | `#include`                             | `using`                                |
| -------------- | -------------------------------------- | -------------------------------------- |
| Type           | Preprocessor directive                 | C++ language keyword (namespace usage) |
| When processed | Before compilation                     | During compilation                     |
| Purpose        | Insert code from another file          | Simplify usage of namespace members    |
| Common use     | Include libraries (e.g., `<iostream>`) | Use namespace (e.g., `std`)            |
| Effect on code | Copies code from the included file     | Changes how names are resolved in code |
| Example        | `#include <vector>`                    | `using namespace std;`                 |

---

## How to access a class variable inside a namespace?

Suppose we have:

```cpp
namespace MyNamespace {
    class MyClass {
    public:
        int myVar;
        MyClass(int val) : myVar(val) {}
    };
}
```

### 1. Without `using`, full namespace qualification:

```cpp
int main() {
    MyNamespace::MyClass obj(10);
    std::cout << obj.myVar << std::endl;
    return 0;
}
```

### 2. With `using namespace`:

```cpp
using namespace MyNamespace;

int main() {
    MyClass obj(10);
    std::cout << obj.myVar << std::endl;
    return 0;
}
```

### 3. Using a namespace alias:

```cpp
namespace MN = MyNamespace;

int main() {
    MN::MyClass obj(10);
    std::cout << obj.myVar << std::endl;
    return 0;
}
```

---

### Notes:

* `myVar` is a public member, so you access it directly via the object (`obj.myVar`).
* The difference is how you refer to the class: with or without the namespace prefix.


