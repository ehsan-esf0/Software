## 🔹 Type Hint in Python

A **type hint** tells humans and tools what type a variable or argument is **supposed** to be.
It does **not** enforce the type at runtime.

Example:

```python
age: int = 25
name: str = "Ali"
```

This means:

* `age` is expected to be an integer.
* `name` is expected to be a string.

But:

```python
age: int = "Ali"  # No error at runtime!
```

Python will still run it without complaint.
Type hints are just annotations.

---

## 🔹 In Django models

When you write:

```python
product: Product = instance
```

You are telling:

* Your **IDE** (PyCharm, VSCode, etc.): "`product` is an instance of the `Product` model".
* This helps with **autocompletion** (so `.name`, `.price`, etc. will show up).
* Type checkers like **mypy** or **pylance** can verify if your code matches the declared type.

---

## 🔹 Benefits

1. **Better autocompletion** in IDEs.
2. **More readable code** for other developers.
3. **Type checking before runtime** (if you run a static type checker).

---

## 🔹 Example in a Django signal

```python
from django.db.models.signals import post_save
from django.dispatch import receiver
from .models import Product

@receiver(post_save, sender=Product)
def handle_product_save(sender, instance, created, **kwargs):
    product: Product = instance  # Just a type hint, no real casting
    
    if created:
        print(f"Product created: {product.name}")
    else:
        print(f"Product updated: {product.name}")
```

Here:

* `product` is actually the same object as `instance`.
* The type hint just tells tools that it’s a `Product` so they can suggest the right fields.

---

## 🔹 Important

A type hint **does not** perform a real type conversion (casting).
If you need to be sure of the type, use:

```python
if isinstance(instance, Product):
    ...
```
