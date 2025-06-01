# Sender in Qt

---

### 1.1 What is a Sender?

In Qt, **Sender** is the QObject that emits a **signal**. When a signal is connected to a slot, sometimes the same slot is connected to multiple signals from different senders. To find out which object triggered the slot, Qt provides the `sender()` method.

---

### 1.2 How to Identify the Sender Object

`QObject::sender()` returns a pointer to the object that sent the signal which caused the slot to be invoked.

```cpp
QObject *obj = sender();
```

You can then inspect this pointer:

* Cast it to a specific widget class (`QPushButton*`, `QLineEdit*`, etc.)
* Check its properties such as `objectName()`, `metaObject()->className()`
* Compare with known pointers to identify it

---

### 1.3 Using `sender()` in Signal-Slot Mechanism

Often useful in situations where a single slot handles multiple signals from different widgets.

---

### Example 1: Identify Which Button Was Clicked

```cpp
void MyWindow::onButtonClicked() {
    QObject *obj = sender();
    if (obj) {
        qDebug() << "Sender object name:" << obj->objectName();
        if (obj == ui->pushButton1)
            qDebug() << "pushButton1 clicked";
        else if (obj == ui->pushButton2)
            qDebug() << "pushButton2 clicked";
    }
}
```

Connect:

```cpp
connect(ui->pushButton1, &QPushButton::clicked, this, &MyWindow::onButtonClicked);
connect(ui->pushButton2, &QPushButton::clicked, this, &MyWindow::onButtonClicked);
```

---

### Example 2: Use `qobject_cast` to Safely Cast Sender

```cpp
void MyWindow::onAnyClicked() {
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn) {
        qDebug() << "Button clicked:" << btn->objectName();
    }
}
```
