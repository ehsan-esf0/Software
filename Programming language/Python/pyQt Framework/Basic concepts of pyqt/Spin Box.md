# ✅ QSpinBox Full Tutorial in PyQt6 (English)

## 📌 What is QSpinBox?

`QSpinBox` is a widget that lets users **select an integer value** by either typing it or using up/down arrows. You can control its **range**, **step size**, **default value**, and **display format** (like prefix/suffix).

---

## 🧪 Basic Example

```python
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QSpinBox, QLabel
import sys

class SpinBoxExample(QWidget):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QSpinBox Example")
        layout = QVBoxLayout()

        self.spin = QSpinBox()
        self.spin.setMinimum(0)
        self.spin.setMaximum(100)
        self.spin.setSingleStep(5)
        self.spin.setValue(20)
        self.spin.setPrefix("Age: ")
        self.spin.setSuffix(" years")

        self.label = QLabel("Current value: 20")

        self.spin.valueChanged.connect(self.update_label)

        layout.addWidget(self.spin)
        layout.addWidget(self.label)
        self.setLayout(layout)

    def update_label(self, value):
        self.label.setText(f"Current value: {value}")

app = QApplication(sys.argv)
window = SpinBoxExample()
window.show()
sys.exit(app.exec())
```

---

## 🧠 Useful Methods and Properties

| Method / Property        | Description                         |
| ------------------------ | ----------------------------------- |
| `setMinimum(int)`        | Set minimum allowed value           |
| `setMaximum(int)`        | Set maximum allowed value           |
| `setRange(min, max)`     | Set both min and max                |
| `setValue(int)`          | Set initial value                   |
| `value()`                | Get current value                   |
| `setSingleStep(int)`     | Set the step size                   |
| `setPrefix(str)`         | Text before the number              |
| `setSuffix(str)`         | Text after the number               |
| `valueChanged.connect()` | Trigger function when value changes |

---

## 🧠 Extra Tips

* Use `QDoubleSpinBox` for **decimal/floating point** values.
* Use `setKeyboardTracking(False)` if you want to **delay value updates** until focus is lost or Enter is pressed.

