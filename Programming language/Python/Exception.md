### 🔹 What is an Exception?

An **exception** is an error that occurs **during the execution** of a program. If not handled properly, it will **crash** your program.

---

### 🔹 Basic Structure

```python
try:
    # code that might raise an exception
except SomeError:
    # code to handle that exception
```

---

### 🔹 Example with `ZeroDivisionError` and `ValueError`

```python
try:
    num = int(input("Enter a number: "))
    result = 10 / num
    print("Result:", result)
except ZeroDivisionError:
    print("Error: Cannot divide by zero.")
except ValueError:
    print("Error: Please enter a valid number.")
```

---

### 🔹 Using `as` to capture error details

```python
try:
    x = 10 / 0
except ZeroDivisionError as e:
    print("Details:", e)
```

🔸 Output:

```
Details: division by zero
```

---

### 🔹 Common Exception Types

| Exception           | Raised When                     | Example               |
| ------------------- | ------------------------------- | --------------------- |
| `ZeroDivisionError` | Dividing by zero                | `10 / 0`              |
| `ValueError`        | Invalid value for type          | `int("abc")`          |
| `TypeError`         | Invalid operation between types | `"abc" + 1`           |
| `IndexError`        | Index out of range              | `[1,2,3][5]`          |
| `KeyError`          | Missing key in dictionary       | `{"a":1}["b"]`        |
| `FileNotFoundError` | Opening a missing file          | `open("missing.txt")` |

---

### 🔹 Catching Multiple Exceptions

```python
try:
    lst = [10, 20]
    idx = int(input("Enter index: "))
    print(lst[idx])
except (ValueError, IndexError) as e:
    print("Error occurred:", e)
```

## 📙 Advanced Exception Handling Structures in Python

This lesson covers advanced elements of Python's exception handling system that help you write **cleaner, more robust, and professional code**, especially in larger applications.

---

### 🔹 1. `else` Clause in `try/except/else`

#### ✅ What is it?

The `else` block executes **only if the `try` block did not raise any exception**. It's a good place to put code that should only run when everything in `try` was successful.

---

#### 🔍 Example:

```python
try:
    number = int(input("Enter a number: "))
except ValueError:
    print("Error: Invalid input!")
else:
    print("Success! You entered:", number)
```

🔸 If you input `abc`, you'll get a ValueError.
🔸 If you input `123`, the message in `else` will print.

---

### 🔹 2. `finally` Clause

#### ✅ What is it?

The `finally` block always runs — no matter if an exception occurred or not.
Used for **cleanup tasks** like closing files, disconnecting resources, or resetting state.

---

#### 🔍 Example:

```python
try:
    file = open("myfile.txt", "r")
    data = file.read()
except FileNotFoundError:
    print("Error: File not found.")
finally:
    print("Cleaning up... (closing file, releasing resources, etc.)")
```

🔸 Even if the file doesn't exist, the message in `finally` will still be printed.

---

### 🔹 3. Full `try/except/else/finally` Structure

```python
try:
    x = int(input("Enter a number: "))
    result = 10 / x
except ValueError:
    print("Invalid input. Please enter an integer.")
except ZeroDivisionError:
    print("Cannot divide by zero.")
else:
    print("Result is:", result)
finally:
    print("This block always executes.")
```

---

### 🔹 4. Nested `try/except` Blocks

You can put a `try/except` block **inside another**. Useful when errors may happen at different levels or stages.

---

#### 🔍 Example:

```python
try:
    number = int(input("Enter a number: "))
    try:
        result = 10 / number
    except ZeroDivisionError:
        print("Inner error: Division by zero.")
    else:
        print("Inner success: Result is", result)
except ValueError:
    print("Outer error: Input must be a number.")
```

---

### 🔹 5. Exception Handling in Functions

#### Option A: Handle the exception **inside** the function

```python
def divide(a, b):
    try:
        return a / b
    except ZeroDivisionError:
        return "Can't divide by zero"

print(divide(10, 0))
```

---

#### Option B: Let the caller handle the exception using `raise`

```python
def divide(a, b):
    if b == 0:
        raise ZeroDivisionError("You cannot divide by zero.")
    return a / b

try:
    print(divide(5, 0))
except ZeroDivisionError as e:
    print("Caught in caller:", e)
```

✅ This gives **more control** to the caller of the function.

---

### 🔹 6. Skipping Errors (`pass`) or Logging Them

#### ❗ Silently ignoring an exception:

```python
try:
    something_risky()
except SomeError:
    pass  # Intentionally ignore the error (not always recommended)
```

---

#### ✅ Logging the error:

```python
import logging

try:
    1 / 0
except ZeroDivisionError as e:
    logging.error(f"An error occurred: {e}")
```

---

| Feature        | Purpose                         | Note                             |
| -------------- | ------------------------------- | -------------------------------- |
| `else`         | Runs when no exception in `try` | Comes **after** all `except`s    |
| `finally`      | Always runs (cleanup code)      | Runs no matter what              |
| Nested `try`   | Handle multiple error points    | Helps isolate error handling     |
| In functions   | Handle locally or raise upward  | Use `raise` to let caller decide |
| `pass/logging` | Skip or record exceptions       | Prefer logging in real projects  |


## ❓ Does `finally` always execute in Python?

### ✅ **Short Answer:**

**Almost always, yes.**
The `finally` block is designed to **always run**, regardless of whether an exception occurred or not, even if the `try` block has a `return`, `break`, or `continue`.

But—there are **a few rare exceptions** where `finally` might **not** execute.

---

## 🔹 Cases where `finally` **does execute**

### 🟢 Common situations where `finally` will run:

1. No exception occurs
2. An exception is raised and caught
3. An exception is raised and not caught
4. A `return` statement is used in `try` or `except`
5. A `break` or `continue` is used in loops

---

### 🔍 Example: `return` inside `try`

```python
def test():
    try:
        return "Returning from try"
    finally:
        print("In finally block")

print(test())
```

🟢 **Output:**

```
In finally block  
Returning from try
```

✅ As you can see, `finally` runs **before** the value is returned from the function.

---

## 🚫 When `finally` might **NOT** run

These are **rare and low-level cases**:

---

### 🔻 1. Using `os._exit()` (bypasses all cleanup)

```python
import os

try:
    print("Before exit")
    os._exit(0)
finally:
    print("This will NOT be printed")
```

🛑 **Output:**
Only “Before exit” will print. The `finally` block is **skipped**.

> ⚠️ `os._exit()` terminates the process immediately without:
>
> * executing `finally`
> * flushing buffers
> * running destructors

---

### 🔻 2. Fatal interpreter crash or system termination

* Power failure
* Kill signal (`kill -9`) from the OS
* Python interpreter crash (e.g., C extension crash)

---

### 🔻 3. Extreme signals like unhandled `SIGKILL` or hardware faults

E.g., memory fault, segmentation fault, abrupt shutdown

---

### 🔻 4. Error inside the `finally` block

```python
try:
    print("Try block")
finally:
    print("Finally block")
    1 / 0  # This raises an exception
```

⚠️ **Output:**

```
Try block  
Finally block  
Traceback (most recent call last):  
  ... ZeroDivisionError ...
```

✅ The `finally` block **did run**, but it crashed during its execution.

---

## 🧾 Summary Table

| Situation                          | Will `finally` run?    | Notes                     |
| ---------------------------------- | ---------------------- | ------------------------- |
| Normal execution                   | ✅ Yes                  | Always                    |
| Exception raised & caught          | ✅ Yes                  | Still runs                |
| Exception raised & not caught      | ✅ Yes                  | Then crash                |
| `return`, `break`, or `continue`   | ✅ Yes                  | Runs before control exits |
| `raise` inside `try` or `except`   | ✅ Yes                  | Before bubbling up        |
| Error occurs inside `finally`      | ✅ Yes (but will crash) |                           |
| `os._exit()`, fatal crash, kill -9 | ❌ No                   | Bypasses cleanup          |

---

✅ In conclusion:
`finally` is **very reliable**, but not **absolutely guaranteed**. Avoid using `os._exit()` or letting fatal signals crash your program if you depend on cleanup inside `finally`.


## 📗 Custom Exceptions in Python

In this lesson, you'll learn how to define your **own exception classes**, raise them in your code, and use them to build clearer, more maintainable applications.

---

### 🔹 Why create custom exceptions?

Python includes many built-in exceptions (e.g., `ValueError`, `ZeroDivisionError`, etc.), but real-world applications often need **custom error types** to:

* Signal **specific problems** in your domain (e.g., weak passwords, invalid user actions)
* Make code more **readable and descriptive**
* Enable **clean exception handling** and **better logging**
* Group related errors using an **exception hierarchy**

---

## 🔸 1. Defining a Basic Custom Exception

To define a custom exception, create a class that inherits from `Exception`:

```python
class WeakPasswordError(Exception):
    pass

def check_password(password):
    if len(password) < 6:
        raise WeakPasswordError("Password is too short.")

try:
    check_password("123")
except WeakPasswordError as e:
    print("Custom error caught:", e)
```

### ✅ Output:

```
Custom error caught: Password is too short.
```

---

## 🔸 2. Adding Custom Attributes and Messages

You can customize the exception class by adding a constructor (`__init__`) and a custom string output (`__str__`):

```python
class InvalidAgeError(Exception):
    def __init__(self, age):
        self.age = age

    def __str__(self):
        return f"Invalid age: {self.age}. Age must be 18 or older."

def register(age):
    if age < 18:
        raise InvalidAgeError(age)

try:
    register(16)
except InvalidAgeError as e:
    print("Registration error:", e)
```

### ✅ Output:

```
Registration error: Invalid age: 16. Age must be 18 or older.
```

---

## 🔸 3. Creating an Exception Hierarchy

You can define a **base exception class** and have other exceptions inherit from it. This allows you to catch related errors using a single `except`.

```python
class AuthError(Exception):  # Base class
    pass

class UserNotFound(AuthError):
    pass

class PasswordIncorrect(AuthError):
    pass

try:
    raise PasswordIncorrect("Wrong password.")
except AuthError as e:
    print("Authentication error:", e)
```

### ✅ Output:

```
Authentication error: Wrong password.
```

---

## 🔸 4. Raising Your Exceptions

Use the `raise` keyword to trigger your custom exceptions at any point in the code:

```python
raise WeakPasswordError("Your password must be at least 6 characters long.")
```

You can raise them manually when:

* Validating user input
* Enforcing business rules
* Catching unexpected logic conditions

---

## 🔸 5. Custom Exceptions in Real-World Code

Imagine a financial app:

```python
class InsufficientFundsError(Exception):
    def __init__(self, balance, amount):
        self.balance = balance
        self.amount = amount

    def __str__(self):
        return f"Balance is ${self.balance}, cannot withdraw ${self.amount}."

def withdraw(balance, amount):
    if amount > balance:
        raise InsufficientFundsError(balance, amount)
    return balance - amount

try:
    withdraw(100, 200)
except InsufficientFundsError as e:
    print("Transaction error:", e)
```

✅ This makes the code more self-explanatory and easier to debug.

---

## 🧾 Summary Table

| Concept              | Example                                | Notes                                  |
| -------------------- | -------------------------------------- | -------------------------------------- |
| Define exception     | `class MyError(Exception): pass`       | Inherit from `Exception`               |
| Raise it             | `raise MyError("message")`             | Use it when needed in your logic       |
| Add attributes       | Use `__init__` and `__str__`           | Provide more error details             |
| Exception hierarchy  | Base class with child exceptions       | Useful for catching related exceptions |
| Real-world use cases | Input validation, access control, etc. | Makes apps more robust and clear       |

