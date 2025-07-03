# QCheckBox in PyQt6

## 📌 What is QCheckBox?

A `QCheckBox` allows the user to select or deselect options independently. Unlike `QRadioButton`, multiple checkboxes can be checked at the same time.

---

## 🛠️ Basic Example

```python
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QCheckBox, QLabel
import sys

class Example(QWidget):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QCheckBox Example")
        layout = QVBoxLayout()

        self.checkbox1 = QCheckBox("Coffee")
        self.checkbox2 = QCheckBox("Tea")
        self.checkbox3 = QCheckBox("Juice")

        self.label = QLabel("Please make your selection")

        # Connect state change
        self.checkbox1.stateChanged.connect(self.update_label)
        self.checkbox2.stateChanged.connect(self.update_label)
        self.checkbox3.stateChanged.connect(self.update_label)

        layout.addWidget(self.checkbox1)
        layout.addWidget(self.checkbox2)
        layout.addWidget(self.checkbox3)
        layout.addWidget(self.label)

        self.setLayout(layout)

    def update_label(self):
        selected = []
        if self.checkbox1.isChecked():
            selected.append("Coffee")
        if self.checkbox2.isChecked():
            selected.append("Tea")
        if self.checkbox3.isChecked():
            selected.append("Juice")

        if selected:
            self.label.setText("You selected: " + ", ".join(selected))
        else:
            self.label.setText("No option selected.")

app = QApplication(sys.argv)
w = Example()
w.show()
sys.exit(app.exec())
```

---

## 🔧 Common Methods and Properties

| Method / Property        | Description                                               |
| ------------------------ | --------------------------------------------------------- |
| `setChecked(bool)`       | Set checked state (True/False)                            |
| `isChecked()`            | Returns True if checked                                   |
| `setText(str)`           | Set the checkbox label                                    |
| `text()`                 | Get the checkbox label                                    |
| `stateChanged.connect()` | Trigger function on state change                          |
| `toggle()`               | Toggle between states                                     |
| `setTristate(True)`      | Enable third (partially-checked) state                    |
| `checkState()`           | Returns state: 0=Unchecked, 1=PartiallyChecked, 2=Checked |

---

## 💡 Tips

* You can use `checkState()` for precise 3-state tracking.
* `QCheckBox` is perfect for optional features or multiple selections.
* Use `setTristate(True)` when you need a "mixed" or indeterminate state.

