# 📘 **String Formatting in Python**

String formatting allows you to **insert variables or expressions** into a string. Python provides **four main methods** to do this.

---

## ✅ 1. **f-strings (Formatted String Literals)** – *Python 3.6+*

```python
name = "Ali"
age = 25
print(f"My name is {name} and I am {age} years old.")
```

🔹 You can also include **expressions**:

```python
print(f"Next year I will be {age + 1}")
```

🔹 Supports formatting numbers:

```python
pi = 3.14159
print(f"Pi is approximately {pi:.2f}")  # Pi is approximately 3.14
```

✅ **Pros**: Fast, readable, powerful
🚫 **Cons**: Only works in Python 3.6+

---

## ✅ 2. **`.format()` Method** – *Works in Python 2.7+ and 3.x*

```python
name = "Sara"
age = 30
print("My name is {} and I am {} years old.".format(name, age))
```

🔹 **Positional arguments**:

```python
print("Name: {0}, Age: {1}".format(name, age))
```

🔹 **Named arguments**:

```python
print("Name: {n}, Age: {a}".format(n=name, a=age))
```

🔹 **Formatting numbers**:

```python
pi = 3.14159
print("Pi is {:.2f}".format(pi))  # Pi is 3.14
```

✅ **Pros**: Very flexible, works in most Python versions
🚫 **Cons**: Slightly more verbose than f-strings

---

## ✅ 3. **Percent `%` Formatting** – *Old style (like in C)*

```python
name = "Reza"
age = 22
print("My name is %s and I am %d years old." % (name, age))
```

🔹 Format specifiers:

| Code | Meaning | Example |
| ---- | ------- | ------- |
| `%s` | String  | `'Ali'` |
| `%d` | Integer | `25`    |
| `%f` | Float   | `3.14`  |

🔹 Example with float formatting:

```python
pi = 3.14159
print("Pi is %.2f" % pi)  # Pi is 3.14
```

✅ **Pros**: Familiar to C programmers
🚫 **Cons**: Old, less readable, error-prone with many variables

---

## ✅ 4. **Template Strings** – *From `string` module*

```python
from string import Template

template = Template("Hello, $name! You are $age years old.")
result = template.substitute(name="Mina", age=27)
print(result)
```

✅ **Pros**:

* Safer when dealing with **user input**
* Used in **security-sensitive** applications (e.g., templating engines)

🚫 **Cons**:

* Less flexible than other methods
* Requires importing `string`

---

# 🧠 **Quick Comparison Table**

| Method       | Version    | Features                          | Pros                       | Cons                      |
| ------------ | ---------- | --------------------------------- | -------------------------- | ------------------------- |
| f-string     | 3.6+       | Inline variables & expressions    | Fast, readable, modern     | Not available in Python 2 |
| `.format()`  | 2.7+ / 3.x | Positional and named placeholders | Flexible, widely supported | More verbose              |
| `%` operator | All        | Old-style formatting (like C)     | Simple for short strings   | Obsolete, not recommended |
| Template     | All        | Uses `$name` syntax, safer        | Safe for user input        | Less powerful             |

---

# 📌 Final Tips

* Prefer **f-strings** if you're using Python 3.6+.
* Use **`.format()`** for compatibility.
* Avoid `%` formatting unless you're maintaining old code.
* Use **`Template`** when working with untrusted input or in templating systems.
