# **Signals & Slots in Qt 6 Python (PySide6/PyQt6)**

## **Introduction**

In Qt 6, you can use either **PySide6** (official binding) or **PyQt6**. The concept of signals & slots is the same in both, with minor syntax differences.

---

## **1. Installing PySide6 or PyQt6**

Install with pip (PySide6 is recommended):

```sh
pip install PySide6
```

or, for PyQt6:

```sh
pip install PyQt6
```

---

## **2. Simple Example: Connecting Button to Function**

**PySide6 code:**

```python
from PySide6.QtWidgets import QApplication, QPushButton

def say_hello():
    print("Hello! Button clicked.")

app = QApplication([])
button = QPushButton("Click Me")
button.clicked.connect(say_hello)
button.show()
app.exec()
```

* `button.clicked` is a ready-made signal, emitted when the button is clicked.
* `say_hello` is a regular function (the slot).
* `connect()` connects them.

> In **PyQt6** you also use `app.exec()` (not `exec_()` as in older versions).

---

## **3. Passing Data with Signals**

Some signals send data to the slot. For example, the **textChanged** signal from QLineEdit:

```python
from PySide6.QtWidgets import QApplication, QLineEdit

def show_text(text):
    print("New text:", text)

app = QApplication([])
line_edit = QLineEdit()
line_edit.textChanged.connect(show_text)
line_edit.show()
app.exec()
```

* Every time the text changes, the new text is sent to the slot.

---

## **4. Creating Custom Signals in PySide6**

To define a custom signal in PySide6, use `Signal`:

```python
from PySide6.QtCore import QObject, Signal

class MyObject(QObject):
    my_signal = Signal(str)  # Define a signal with a string parameter

    def do_something(self):
        self.my_signal.emit("Hello from custom signal")

def handle_signal(msg):
    print("Signal received:", msg)

obj = MyObject()
obj.my_signal.connect(handle_signal)
obj.do_something()
```

> **In PyQt6**, use `pyqtSignal` instead:
> `from PyQt6.QtCore import pyqtSignal`

---

## **5. Multiple Slots for One Signal**

A signal can connect to multiple slots:

```python
def show_msg1():
    print("Message 1")

def show_msg2():
    print("Message 2")

button.clicked.connect(show_msg1)
button.clicked.connect(show_msg2)
```

Both functions will run when the button is clicked.

---

## **6. Disconnecting a Signal from a Slot**

To remove a connection:

```python
button.clicked.disconnect(show_msg1)
```

---

## **7. One Slot, Multiple Signals**

You can connect a slot to multiple signals:

```python
button.clicked.connect(some_function)
line_edit.textChanged.connect(some_function)
```

---

## **8. Signal with No Arguments, Slot with Arguments**

If the signal has no parameters but the slot needs arguments, use a lambda:

```python
button.clicked.connect(lambda: show_text("Button was clicked"))
```

---

## **9. Common Built-in Signals in Qt 6**

* `.clicked` (QPushButton)
* `.textChanged` (QLineEdit)
* `.valueChanged` (QSlider, QSpinBox, ...)
* `.currentIndexChanged` (QComboBox)
* etc.

---

## **10. Summary**

* Signals and slots are the main way to connect Qt6 objects.
* Usage is simple and clear.
* Both built-in and custom signals are supported.

