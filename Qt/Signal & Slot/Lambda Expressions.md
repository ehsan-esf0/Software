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

