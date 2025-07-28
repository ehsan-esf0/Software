## 🎓 **Lesson 1: Introduction to Functions in Python**

*(Essential Background Before Learning Decorators)*~

---

### ✅ Part 1: Functions in Python Are **Objects**

In Python, functions are **first-class objects**. That means you can:

* Assign them to variables
* Pass them as arguments
* Return them from other functions

#### 📌 Example 1: Assigning a function to a variable

```python
def say_hello():
    print("Hello!")

greet = say_hello
greet()  # Output: Hello!
```

> 🔍 Note: We passed the function **without parentheses**, so we assigned the function itself, not the result of calling it.

---

### ✅ Part 2: Nested Functions

You can define a function **inside another function**.

#### 📌 Example 2: Function inside a function

```python
def outer():
    def inner():
        print("Inner function")
    inner()

outer()  # Output: Inner function
```

> 🧠 Note: The `inner()` function is only accessible inside `outer()`.

---

### ✅ Part 3: Returning a Function from Another Function

Functions can **return other functions** — this is key for decorators.

#### 📌 Example 3: Returning a function

```python
def outer():
    def inner():
        print("Returned function!")
    return inner

returned_func = outer()
returned_func()  # Output: Returned function!
```

> 🔥 Important: `outer()` returns the `inner()` function itself, which we can store and call later.

---

### ✅ Part 4: Passing Functions as Arguments (Higher-Order Functions)

A function that takes another function as an argument is called a **higher-order function**.

#### 📌 Example 4: Function as an argument

```python
def shout(text):
    return text.upper()

def whisper(text):
    return text.lower()

def speak(style_func, message):
    return style_func(message)

print(speak(shout, "Hello!"))   # Output: HELLO!
print(speak(whisper, "Hello!")) # Output: hello!
```

> 📌 This is exactly what decorators will do: take a function and return a modified one.

---

### ✅ Summary of Key Concepts

| Concept                | Description                      |
| ---------------------- | -------------------------------- |
| Function as Object     | Can be assigned or passed        |
| Nested Functions       | Functions inside other functions |
| Returning Functions    | Enables dynamic behavior         |
| Functions as Arguments | Basis of higher-order logic      |

