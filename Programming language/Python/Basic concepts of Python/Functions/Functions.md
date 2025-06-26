# Python Functions 

## What is a Function?

A **function** is a reusable block of code designed to perform a specific task. Functions help break programs into smaller, modular pieces, making code easier to read, maintain, and reuse.

---

## Defining a Function

Syntax:

```python
def function_name(parameters):
    """
    Optional docstring: Describe what the function does.
    """
    function_body
    return value  # Optional
```

* `def` keyword starts the function definition.
* `function_name` should follow naming conventions (lowercase with underscores).
* `parameters` are inputs; can be zero or more.
* `return` is used to send back a result from the function.

Example:

```python
def greet(name):
    """Print a greeting message."""
    print(f"Hello, {name}!")

greet("Alice")  # Output: Hello, Alice!
```

---

## Function Parameters and Arguments

* **Parameters:** Variables listed in the function definition.
* **Arguments:** Actual values passed when calling the function.

---

## Types of Parameters

### 1. Positional (Required) Parameters

Arguments must be passed in order.

```python
def add(x, y):
    return x + y

print(add(3, 4))  # 7
```

### 2. Default Parameters

Parameters can have default values.

```python
def greet(name="friend"):
    print(f"Hello, {name}!")

greet()          # Hello, friend!
greet("Bob")     # Hello, Bob!
```

Rules:

* Parameters with default values must come after positional parameters.

### 3. Keyword Arguments

Call functions with explicit parameter names.

```python
def power(base, exponent=2):
    return base ** exponent

print(power(exponent=3, base=4))  # 64
```

### 4. Variable-length Arguments

#### `*args` — Non-keyword Variable Arguments

Allows passing any number of positional arguments as a tuple.

```python
def func(*args):
    print(args)

func(1, 2, 3)  # (1, 2, 3)
```

#### `**kwargs` — Keyword Variable Arguments

Allows passing any number of keyword arguments as a dictionary.

```python
def func(**kwargs):
    print(kwargs)

func(a=1, b=2)  # {'a': 1, 'b': 2}
```

#### Combining `*args` and `**kwargs`

```python
def func(*args, **kwargs):
    print("args:", args)
    print("kwargs:", kwargs)

func(1, 2, a=3, b=4)
# args: (1, 2)
# kwargs: {'a': 3, 'b': 4}
```

---

## Returning Values

* Use `return` to send back a value.
* Without `return` or with `return` alone, function returns `None`.

```python
def square(x):
    return x * x

print(square(5))  # 25
```

You can return multiple values as a tuple:

```python
def min_max(numbers):
    return min(numbers), max(numbers)

minimum, maximum = min_max([3, 1, 7, 4])
print(minimum, maximum)  # 1 7
```

---

## Function Annotations (Type Hints)

Python supports optional type hints for parameters and return values to improve readability and tooling support:

```python
def greet(name: str) -> None:
    print(f"Hello, {name}!")

def add(x: int, y: int) -> int:
    return x + y
```

These hints do not enforce types at runtime but are useful for static analysis.

---

## Docstrings (Documentation Strings)

Docstrings explain what the function does and how to use it. They appear immediately after the function header, enclosed in triple quotes.

Example:

```python
def factorial(n: int) -> int:
    """
    Calculate factorial of n recursively.
    
    Args:
        n (int): non-negative integer
    
    Returns:
        int: factorial of n
    """
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
```

You can access a function's docstring using `help()` or `.__doc__`.

---

## Scope and Lifetime of Variables in Functions

* Variables defined inside a function are **local** to that function.
* Variables defined outside are **global**.
* Use `global` keyword to modify global variables inside functions.
* Use `nonlocal` keyword to modify variables in enclosing (non-global) scopes in nested functions.

Example of `global`:

```python
count = 0

def increment():
    global count
    count += 1

increment()
print(count)  # 1
```

Example of `nonlocal`:

```python
def outer():
    x = "local"

    def inner():
        nonlocal x
        x = "nonlocal"
        print("inner:", x)

    inner()
    print("outer:", x)

outer()
# Output:
# inner: nonlocal
# outer: nonlocal
```

---

## Nested Functions and Closures

Functions can be defined inside other functions.

A **closure** is a nested function that captures variables from its enclosing scope.

Example:

```python
def make_multiplier(x):
    def multiplier(n):
        return n * x
    return multiplier

times3 = make_multiplier(3)
print(times3(10))  # 30
```

Here, `multiplier` remembers `x` even after `make_multiplier` returns.

---

## Lambda Functions (Anonymous Functions)

* Short, unnamed functions defined with the `lambda` keyword.
* Useful for small, simple functions.

Syntax:

```python
lambda arguments: expression
```

Example:

```python
square = lambda x: x * x
print(square(5))  # 25

# Using with built-in functions like sorted()
points = [(1, 2), (4, 1), (5, -1)]
points_sorted = sorted(points, key=lambda point: point[1])
print(points_sorted)  # [(5, -1), (4, 1), (1, 2)]
```

---

## Decorators (Function Wrappers)

A **decorator** is a function that takes another function and extends its behavior without explicitly modifying it.

Basic syntax:

```python
def decorator(func):
    def wrapper(*args, **kwargs):
        # Code before function call
        result = func(*args, **kwargs)
        # Code after function call
        return result
    return wrapper
```

Using the decorator:

```python
@decorator
def say_hello():
    print("Hello!")

say_hello()
```

Decorators are widely used for logging, access control, memoization, and more.

---

## Higher-Order Functions

Functions that take other functions as arguments or return functions.

Example:

```python
def apply_function(f, value):
    return f(value)

print(apply_function(lambda x: x ** 2, 5))  # 25
```

---

## Recursive Functions

Functions that call themselves to solve smaller instances of a problem.

Example (factorial):

```python
def factorial(n):
    if n <= 1:
        return 1
    else:
        return n * factorial(n - 1)

print(factorial(5))  # 120
```

Be careful with base cases to avoid infinite recursion.

---

## Function Closures and `nonlocal`

Closures capture variables from the outer scope:

```python
def outer():
    count = 0

    def inner():
        nonlocal count
        count += 1
        return count

    return inner

counter = outer()
print(counter())  # 1
print(counter())  # 2
```

---

## Summary of Key Concepts

| Concept              | Description                                |
| -------------------- | ------------------------------------------ |
| Function Definition  | Use `def` to create functions              |
| Parameters           | Inputs to the function                     |
| Arguments            | Values passed when calling functions       |
| Default Parameters   | Parameters with default values             |
| Keyword Arguments    | Specify arguments by name                  |
| Variable-length Args | `*args` and `**kwargs` for flexible inputs |
| Return Values        | Use `return` to output results             |
| Docstrings           | Describe function usage and behavior       |
| Scope                | Local vs global variables                  |
| Nested Functions     | Functions defined inside other functions   |
| Closures             | Inner functions capturing outer variables  |
| Lambda Functions     | Anonymous, small functions                 |
| Decorators           | Modify behavior of functions               |
| Recursive Functions  | Functions that call themselves             |

---

## Additional Tips

* Keep functions **short** and **focused** on one task.
* Use **meaningful names** for functions and parameters.
* Use **type hints** to improve readability and help static analyzers.
* Write **docstrings** for public functions.
* Test functions independently for **modularity** and easier debugging.
