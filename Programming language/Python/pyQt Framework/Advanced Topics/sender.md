# **About sender() in Qt 6 Python (PySide6 / PyQt6)**

## **Main Use of sender()**

The `sender()` method lets you find out **which object emitted the signal** that called the slot.
This is useful when you connect multiple widgets (like several buttons) to the same slot and need to know exactly which one triggered the event.

---

### **Simple Example with PySide6:**

```python
from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout

class MyWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Testing sender()")

        self.button1 = QPushButton("Button 1")
        self.button2 = QPushButton("Button 2")

        self.button1.clicked.connect(self.handle_click)
        self.button2.clicked.connect(self.handle_click)

        layout = QVBoxLayout(self)
        layout.addWidget(self.button1)
        layout.addWidget(self.button2)

    def handle_click(self):
        sender = self.sender()
        print("Clicked by:", sender.text())

app = QApplication([])
window = MyWindow()
window.show()
app.exec()
```

**Explanation:**

* Both buttons are connected to the same slot (`handle_click`).
* Inside the slot, `self.sender()` returns the button that emitted the signal.
* You can read its properties (like `text()`).

---

### **Typical Use Cases for sender():**

* Creating multiple buttons/widgets managed by a single slot.
* Cleaner and shorter code.
* Identifying which item in a table/list/form was activated.

---

### **Important Note about sender():**

* `sender()` only works inside slots that are **directly connected** to a signal (not if you call the function manually).
* If you use a lambda to connect the signal to a slot, `sender()` may not work as expected, because the connection is indirect.

---

### **Advanced Example: List of Buttons**

```python
from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout

class MyWindow(QWidget):
    def __init__(self):
        super().__init__()
        layout = QVBoxLayout(self)
        self.buttons = []
        for i in range(5):
            btn = QPushButton(f"Button {i+1}")
            btn.clicked.connect(self.handle_click)
            layout.addWidget(btn)
            self.buttons.append(btn)

    def handle_click(self):
        sender = self.sender()
        print(f"{sender.text()} was clicked.")

app = QApplication([])
window = MyWindow()
window.show()
app.exec()
```

* Now you can handle all button clicks with a single function, and still know which button was clicked.

---

### **Summary:**

* The `sender()` method inside a slot returns the **object that emitted the signal**.
* Perfect for managing many widgets with shared code.
* The slot must be **directly** connected to the signal.
