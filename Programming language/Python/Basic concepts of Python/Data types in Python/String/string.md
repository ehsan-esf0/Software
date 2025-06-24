# 📘 **Python Strings**

Strings in Python are **sequences of characters**, used to represent text. Python makes string handling very powerful and easy.

---

## 🔹 1. **Creating Strings**

Strings can be defined using **single quotes**, **double quotes**, or **triple quotes** for multiline:

```python
s1 = 'Hello'
s2 = "World"
s3 = """This is
a multiline
string."""
```

---

## 🔹 2. **String Type**

```python
s = "Python"
print(type(s))  # <class 'str'>
```

---

## 🔹 3. **Accessing Characters (Indexing)**

Python uses **zero-based indexing**. You can also use **negative indices**.

```python
text = "Python"
print(text[0])    # P
print(text[-1])   # n
```

---

## 🔹 4. **Slicing Strings**

You can extract substrings using slicing:

```python
s = "Hello, World"
print(s[0:5])     # Hello
print(s[7:])      # World
print(s[:5])      # Hello
print(s[::2])     # Hlo ol
print(s[::-1])    # dlroW ,olleH (reversed)
```

---

## 🔹 5. **String Immutability**

Strings in Python are **immutable**, meaning they cannot be changed after creation:

```python
s = "Hi"
# s[0] = 'h'  # ❌ Error
s = "hello"   # ✅ You must create a new string
```

---

## 🔹 6. **String Concatenation and Repetition**

```python
print("Hello" + " World")  # Hello World
print("Hi! " * 3)          # Hi! Hi! Hi!
```

---

## 🔹 7. **Membership Testing**

```python
print("a" in "apple")     # True
print("z" not in "apple") # True
```

---

## 🔹 8. **String Iteration**

```python
for ch in "Python":
    print(ch)
```

---

## 🔹 9. **Useful String Methods**

| Method              | Description                    | Example                              |
| ------------------- | ------------------------------ | ------------------------------------ |
| `len(s)`            | Length of string               | `len("abc") → 3`                     |
| `s.lower()`         | Lowercase                      | `"HELLO".lower() → "hello"`          |
| `s.upper()`         | Uppercase                      | `"hi".upper() → "HI"`                |
| `s.strip()`         | Remove leading/trailing spaces | `" hi ".strip() → "hi"`              |
| `s.replace(a, b)`   | Replace substring              | `"cat".replace("c", "b") → "bat"`    |
| `s.find(sub)`       | First index of substring       | `"hello".find("e") → 1`              |
| `s.split(",")`      | Split into list                | `"a,b,c".split(",") → ['a','b','c']` |
| `'sep'.join(list)`  | Join list into string          | `"-".join(['a','b']) → "a-b"`        |
| `s.startswith("H")` | Check beginning                | `"Hello".startswith("H") → True`     |
| `s.endswith("d")`   | Check ending                   | `"World".endswith("d") → True`       |
| `s.isdigit()`       | Check if digits only           | `"123".isdigit() → True`             |
| `s.isalpha()`       | Check if letters only          | `"abc".isalpha() → True`             |

---

## 🔹 10. **String Comparison**

```python
a = "apple"
b = "banana"
print(a == b)   # False
print(a < b)    # True (lexicographically)
```

---

## 🔹 11. **Escape Characters**

| Symbol | Meaning         |
| ------ | --------------- |
| `\n`   | New line        |
| `\t`   | Tab             |
| `\\`   | Backslash (`\`) |
| `\"`   | Double quote    |
| `\'`   | Single quote    |

Example:

```python
print("Line1\nLine2")
print("He said, \"Hello!\"")
```

---

## 🔹 12. **String Formatting Methods**

See previous message for full explanation of:

1. `f"{}"` → f-strings
2. `"{}".format()`
3. `"..." % (...)`
4. `Template` from `string` module

---

## 🔹 13. **Multilingual (Unicode) Support**

Python strings are Unicode by default — it supports all languages:

```python
txt = "سلام دنیا"
print(txt[::-1])  # reverses Persian text
```

---

# ✅ Summary: Key Properties of Strings

| Feature    | Value           |
| ---------- | --------------- |
| Type       | `str`           |
| Mutable?   | ❌ Immutable     |
| Indexable? | ✅ Yes           |
| Iterable?  | ✅ Yes           |
| Methods?   | ✅ Many built-in |
