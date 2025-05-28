# Variable Scope in C++

## What is Variable Scope?

Variable scope defines the region of the program where a variable is accessible.  
Outside its scope, the variable is not recognized and cannot be used.

---

## Types of Variable Scope in C++

1. **Local Scope**  
2. **Global Scope**  
3. **Block Scope**  
4. **Class Scope**  
5. **Namespace Scope**

---

### 1. Local Scope

- Variables declared inside a function are local to that function.  
- They can only be accessed within that function.

```cpp
void foo() {
    int x = 10; // local variable
    std::cout << x << std::endl;
}

int main() {
    foo();
    // std::cout << x; // Error: x is not visible here
}
```

---

### 2. Global Scope

- Variables declared outside all functions and classes are global variables.  
- Accessible throughout the program (within the same file or via extern).

```cpp
int x = 100; // global variable

void foo() {
    std::cout << x << std::endl;
}

int main() {
    std::cout << x << std::endl;
    foo();
}
```

---

### 3. Block Scope

- Variables declared inside `{ ... }` blocks are only visible within that block.

```cpp
int main() {
    int x = 5;
    {
        int x = 10; // shadows outer x
        std::cout << x << std::endl; // 10
    }
    std::cout << x << std::endl; // 5
}
```

---

### 4. Class Scope

- Member variables and functions are scoped to the class.  
- Accessed through instances or class name (for static members).

```cpp
class MyClass {
public:
    int x;
    void printX() { std::cout << x << std::endl; }
};

int main() {
    MyClass obj;
    obj.x = 42;
    obj.printX(); // 42
}
```

---

### 5. Namespace Scope

- Variables and functions declared inside a namespace are scoped to that namespace.

```cpp
namespace A {
    int x = 10;
}

int main() {
    std::cout << A::x << std::endl; // 10
}
```

---

## Shadowing

- When an inner scope declares a variable with the same name as an outer scope, it **shadows** the outer variable.

---

# Summary

| Scope         | Description                                      | Example Location                |
|---------------|------------------------------------------------|--------------------------------|
| Local         | Inside function                                 | Function body                  |
| Global        | Outside all functions/classes                    | File/global                    |
| Block         | Inside `{}` blocks                               | If/for/while blocks            |
| Class         | Inside class body                                | Class members                 |
| Namespace     | Inside namespace                                 | Namespace block               |

