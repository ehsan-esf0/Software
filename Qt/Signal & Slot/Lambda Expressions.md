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
