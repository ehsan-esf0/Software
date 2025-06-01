### 🔹 Lambda Expressions in Qt

#### ✅ Basic Lambda

```cpp
[]() {
    qDebug() << "Hello from lambda!";
};
```

#### ✅ Lambda as Slot (No Args)

```cpp
connect(button, &QPushButton::clicked, []() {
    qDebug() << "Button clicked!";
});
```

#### ✅ Lambda with Parameters

```cpp
connect(lineEdit, &QLineEdit::textChanged, [](const QString &text) {
    qDebug() << "Text changed to:" << text;
});
```

#### ✅ Capturing Variables

| Capture  | Description                   | Example                      |
| -------- | ----------------------------- | ---------------------------- |
| `[]`     | Captures nothing              | `[](){}`                     |
| `[=]`    | Capture all by value          | `[=](){ qDebug() << name; }` |
| `[&]`    | Capture all by reference      | `[&](){ name = "Ali"; }`     |
| `[var]`  | Capture specific by value     | `[prefix](){}`               |
| `[&var]` | Capture specific by reference | `[&prefix](){}`              |

#### ✅ Lambda with `this`

```cpp
connect(button, &QPushButton::clicked, [this]() {
    this->setWindowTitle("Clicked!");
});
```

#### ✅ Lambda with `mutable`

```cpp
int count = 0;
auto f = [count]() mutable {
    count++;
    qDebug() << count;
};
f();  // prints: 1
f();  // prints: 1 again
```

#### ✅ Lambda with Disconnect

```cpp
QMetaObject::Connection c;
c = connect(button, &QPushButton::clicked, this, [=]() {
    qDebug() << "Clicked once!";
    disconnect(c);
});
```

#### ✅ Lambda with Return Type

```cpp
auto square = [](int x) -> int {
    return x * x;
};
```

---

## 🧠 Lambda Expressions in Qt (C++11+)

Lambda expressions are anonymous functions that are especially powerful when used with Qt’s signal/slot mechanism.

### ✅ General Syntax:

```cpp
[captures](parameters) -> return_type {
    // function body
};
```

---

### 🔹 Breakdown of Lambda Components

| Part            | Syntax    | Description                                              |
| --------------- | --------- | -------------------------------------------------------- |
| **Captures**    | `[]`      | Capture external variables from the surrounding scope    |
| **Parameters**  | `()`      | Arguments passed to the lambda (typically from a signal) |
| **Return Type** | `-> type` | Optional return type (usually deduced automatically)     |
| **Body**        | `{}`      | The code to run when the lambda is invoked               |

---

### 🔹 Lambda Examples

#### ➤ Lambda with No Captures or Parameters

```cpp
[]() {
    qDebug() << "Hello from lambda!";
};
```

#### ➤ Capturing Variables

```cpp
int x = 10, y = 5;

[=]() { qDebug() << x + y; };  // Capture all by value
[&]() { x++; y++; };           // Capture all by reference
[x]() { qDebug() << x; };      // Capture only x by value
[&y]() { y *= 2; };            // Capture only y by reference
```

#### ➤ Capturing `this` in Class Context

```cpp
[this]() {
    this->setWindowTitle("Lambda Activated");
};
```

---

### 🔹 Connecting Lambda to Signal

```cpp
QPushButton *button = new QPushButton("Click Me");

connect(button, &QPushButton::clicked, []() {
    qDebug() << "Button clicked!";
});

QLineEdit *lineEdit = new QLineEdit;

connect(lineEdit, &QLineEdit::textChanged, [](const QString &text) {
    qDebug() << "Text changed to:" << text;
});
```

---

### 🔹 Lambda with Return Type

```cpp
auto multiply = [](int a, int b) -> int {
    return a * b;
};

int result = multiply(3, 4); // result = 12
```

---

### 🔹 Mutable Lambdas

Allows modification of variables captured **by value** inside the lambda.

```cpp
int count = 0;

auto inc = [count]() mutable {
    count++;
    qDebug() << "Count is now:" << count;
};

inc(); // prints 1
inc(); // prints 1 again (count resets each time)
```

---

### 🔹 One-Time Connection Example

```cpp
QPushButton *btn = new QPushButton("Click Once");
QMetaObject::Connection c;

c = connect(btn, &QPushButton::clicked, [=]() {
    qDebug() << "Clicked just once!";
    QObject::disconnect(c);
});
```

---

### 🔹 Full Example with All Components

```cpp
int a = 5;
QPushButton *btn = new QPushButton("Click Me");

connect(btn, &QPushButton::clicked, [=]() -> void {
    qDebug() << "Captured a:" << a;
    qDebug() << "Button was clicked!";
});
```

---

### 🎨 Recap Table

| Element | Symbol | Description                                       |
| ------- | ------ | ------------------------------------------------- |
| Capture | `[]`   | External variables captured by value or reference |
| Params  | `()`   | Input from the signal (like event parameters)     |
| Return  | `->`   | Return type of lambda (optional)                  |
| Body    | `{}`   | Function body (like slot content)                 |


## 📘 Qt `connect()` — Understanding `this` vs `nullptr`

---

### 🔹 Function Signature Reminder

```cpp
QObject::connect(sender, signal, receiver, lambda);
```

* **`sender`**: the object emitting the signal.
* **`signal`**: the signal emitted (e.g., `&QPushButton::clicked`).
* **`receiver`**: the object that "owns" the connection.
* **`lambda`**: the slot (anonymous function in this case).

---

### 🔍 Difference Between `this` and `nullptr`

#### ✅ `this` as Receiver

```cpp
connect(button, &QPushButton::clicked, this, [this]() {
    qDebug() << "Handled safely within this object";
});
```

✔️ **Benefits:**

* The connection is **owned by `this` object**.
* If `this` gets destroyed (e.g., closing a widget), the connection is automatically disconnected.
* Prevents **crashes or memory leaks**.
* Ensures **safe access** to `this` and its members inside the lambda.

---

#### ⚠️ `nullptr` as Receiver

```cpp
connect(button, &QPushButton::clicked, nullptr, []() {
    qDebug() << "Lambda has no receiver object";
});
```

❌ **Risks:**

* The connection is **not owned** by any object.
* It will **not automatically disconnect** when any related object is destroyed.
* If the lambda captures local or class variables (like `this`), and those objects are destroyed → **undefined behavior or crash**.
* Manual `disconnect()` is required to clean it up.

---

### ✅ Use Case Comparison

| Aspect                 | `this`                                 | `nullptr`                               |
| ---------------------- | -------------------------------------- | --------------------------------------- |
| Ownership              | Owned by the current object            | No ownership                            |
| Auto disconnect        | ✅ Yes, when `this` is deleted          | ❌ No, must be manually disconnected     |
| Safe for member access | ✅ Safe to use `this` inside the lambda | ⚠️ Dangerous if using `this` or members |
| Memory leak risk       | ❌ Very low                             | ⚠️ High, if not disconnected manually   |
| Recommended for        | GUI widgets, class-based connections   | One-time or stateless lambdas           |

---

### 🧠 Practical Advice

* **Always use `this` as the receiver** if you're connecting inside a class or method and accessing members.
* Use `nullptr` **only** for:

  * Simple stateless lambdas.
  * Short-lived operations.
  * Global/static contexts.

---

### 🧪 Example with `this` (Safe)

```cpp
connect(button, &QPushButton::clicked, this, [this]() {
    this->setWindowTitle("Clicked!");
});
```

---

### 🧪 Example with `nullptr` (Dangerous)

```cpp
connect(button, &QPushButton::clicked, nullptr, [this]() {
    this->setWindowTitle("May crash if this is deleted!");
});
```

💣 **If `this` is deleted before the button is clicked, this lambda will crash.**

---

### ✅ Safer Alternative: Capture `this` only if needed

```cpp
connect(button, &QPushButton::clicked, this, []() {
    qDebug() << "Simple handler with no captured variables";
});
```

---
