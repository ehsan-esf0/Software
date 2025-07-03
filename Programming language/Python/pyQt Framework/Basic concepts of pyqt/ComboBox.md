##  QComboBox in PyQt6

## 📌 What is QComboBox?

A `QComboBox` is a **drop-down list** that lets the user select **one option from multiple items**. It can also be made **editable** so the user can type custom input.

---

## 🧪 Basic Example

```python
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QComboBox, QLabel
import sys

class ComboBoxExample(QWidget):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QComboBox Example")
        layout = QVBoxLayout()

        self.combo = QComboBox()
        self.combo.addItems(["New York", "London", "Tokyo", "Paris"])

        self.label = QLabel("Selected: New York")

        self.combo.currentTextChanged.connect(self.update_label)

        layout.addWidget(self.combo)
        layout.addWidget(self.label)

        self.setLayout(layout)

    def update_label(self, text):
        self.label.setText("Selected: " + text)

app = QApplication(sys.argv)
window = ComboBoxExample()
window.show()
sys.exit(app.exec())
```

---

## 🧠 Useful QComboBox Methods

| Method                    | Description                     |
| ------------------------- | ------------------------------- |
| `addItem(text)`           | Add a single item               |
| `addItems(list)`          | Add multiple items              |
| `insertItem(index, text)` | Insert item at specific index   |
| `removeItem(index)`       | Remove item by index            |
| `clear()`                 | Remove all items                |
| `currentText()`           | Get selected text               |
| `currentIndex()`          | Get index of selected item      |
| `setCurrentIndex(i)`      | Select a specific item          |
| `setEditable(True)`       | Make the combobox user-editable |
| `setItemText(i, text)`    | Modify item text                |
| `count()`                 | Get number of items             |

---

## 🎯 Common Signals

| Signal                     | Description                                    |
| -------------------------- | ---------------------------------------------- |
| `currentIndexChanged(int)` | Fires when selection index changes             |
| `currentTextChanged(str)`  | Fires when selected text changes               |
| `activated(int)`           | Fires when user selects an item (even if same) |

