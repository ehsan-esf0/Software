## 📘 Qt Signals & Slots

---

### 🔹 What are Signals and Slots?

Signals and slots are Qt's powerful way to allow communication between objects.

* **Signal:** Emits when an event occurs.
* **Slot:** A function that receives the signal.

```cpp
connect(sender, SIGNAL(signalName()), receiver, SLOT(slotName())); // Qt4 style
connect(sender, &SenderClass::signalName, receiver, &ReceiverClass::slotName); // Qt5+ style
```

---

### 🔹 Creating Custom Signals

You can define your own signals in any `QObject`-derived class:

```cpp
class MyObject : public QObject {
    Q_OBJECT

signals:
    void dataReady(int number);
    void messageReady(QString msg);
    void complexData(int code, QString text);
};
```

---

### 🔹 Emitting Signals

Use the `emit` keyword to trigger a signal:

```cpp
void MyObject::doSomething() {
    emit dataReady(42);
    emit messageReady("Hello from Qt!");
    emit complexData(200, "OK");
}
```

---

### 🔹 Receiving Signals (Slots)

Slots are functions (can be regular or lambdas) that are called when a signal is emitted.

#### ✔️ Method 1: Regular Slot Functions

```cpp
class Receiver : public QObject {
    Q_OBJECT

public slots:
    void onDataReady(int number);
    void onMessage(QString msg);
    void onComplex(int code, QString text);
};
```

#### ✔️ Method 2: Lambda Functions

```cpp
QObject::connect(&obj, &MyObject::dataReady, [](int n) {
    qDebug() << "Lambda received number:" << n;
});

QObject::connect(&obj, &MyObject::complexData, [](int code, const QString &msg) {
    qDebug() << "Lambda got status:" << code << ", msg:" << msg;
});
```

---

### 🔹 Connecting Signal to Slot

```cpp
QObject::connect(&obj, &MyObject::dataReady, &receiver, &Receiver::onDataReady);
QObject::connect(&obj, &MyObject::messageReady, &receiver, &Receiver::onMessage);
QObject::connect(&obj, &MyObject::complexData, &receiver, &Receiver::onComplex);
```

---

### 🔹 Why use Pointers in connect()?

Because `QObject::connect` needs a **pointer** to the sender and receiver:

```cpp
connect(&button, &QPushButton::clicked, &receiver, &Receiver::onClick);
```

* `&button` is the address (i.e., a pointer) to the QPushButton instance.
* Signals/slots operate on **actual instances**, not copies (copying QObjects is not allowed).

---

### 🔹 Signal with Multiple Parameters

```cpp
signals:
    void dataProcessed(int id, QString result);

slots:
    void handleData(int id, QString result);

QObject::connect(&obj, &MyObject::dataProcessed, &receiver, &Receiver::handleData);
```

---

### ⚠️ Important Notes

* Types must match exactly between signal and slot.
* Lambdas must have same parameters as the signal.
* QObject-derived classes must have `Q_OBJECT` macro.
* You cannot copy `QObject` objects — always use pointers.

---

### ✅ Summary Table

| Step          | Action                                                 |
| ------------- | ------------------------------------------------------ |
| Define Signal | In `signals:` section of QObject class                 |
| Emit Signal   | Use `emit signalName(args...)`                         |
| Define Slot   | As regular method or lambda                            |
| Connect       | Use `QObject::connect(sender, signal, receiver, slot)` |
| Run           | When signal is emitted, slot is automatically called   |

---

### 🧪 Optional: Sending Custom Types

If you want to pass custom types in signals:

```cpp
Q_DECLARE_METATYPE(MyCustomType)
qRegisterMetaType<MyCustomType>();
```

---
