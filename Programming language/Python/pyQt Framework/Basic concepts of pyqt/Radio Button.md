# ✅ QRadioButton in PyQt6

### 📌 What is QRadioButton?

`QRadioButton` allows the user to **select one option among multiple choices**. Typically used in forms or grouped settings where a single selection is required.

---

## 📦 Basic Usage Example

```python
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QRadioButton, QLabel, QPushButton
import sys

class RadioExample(QWidget):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QRadioButton Example")
        layout = QVBoxLayout()

        # Create radio buttons
        self.radio1 = QRadioButton("Option 1")
        self.radio2 = QRadioButton("Option 2")
        self.radio3 = QRadioButton("Option 3")

        # Connect signal
        self.radio1.toggled.connect(self.selection_changed)
        self.radio2.toggled.connect(self.selection_changed)
        self.radio3.toggled.connect(self.selection_changed)

        # Add widgets
        layout.addWidget(self.radio1)
        layout.addWidget(self.radio2)
        layout.addWidget(self.radio3)

        self.label = QLabel("Choose an option")
        layout.addWidget(self.label)

        self.setLayout(layout)

    def selection_changed(self):
        if self.radio1.isChecked():
            self.label.setText("You selected: Option 1")
        elif self.radio2.isChecked():
            self.label.setText("You selected: Option 2")
        elif self.radio3.isChecked():
            self.label.setText("You selected: Option 3")

app = QApplication(sys.argv)
window = RadioExample()
window.show()
sys.exit(app.exec())
```

---

## 🧠 Key Methods and Properties

| Method / Property      | Description                  |
| ---------------------- | ---------------------------- |
| `setText(str)`         | Set the text label           |
| `text()`               | Get the text label           |
| `setChecked(bool)`     | Set as checked/unchecked     |
| `isChecked()`          | Returns True if selected     |
| `toggle()`             | Toggle checked state         |
| `click()`              | Simulates user click         |
| `setEnabled(bool)`     | Enable or disable the button |
| `setVisible(bool)`     | Show or hide the button      |
| `setShortcut('Alt+X')` | Assign keyboard shortcut     |
| `setIcon(QIcon(...))`  | Set an icon                  |

---

## ⚡ Useful Signals

| Signal          | Description                          |
| --------------- | ------------------------------------ |
| `toggled(bool)` | Emitted when selection state changes |
| `clicked(bool)` | Emitted when the button is clicked   |

---

## 📚 Grouping Radio Buttons

When you want **multiple independent radio button groups**, use `QButtonGroup`:

```python
from PyQt6.QtWidgets import QButtonGroup

group = QButtonGroup()
group.addButton(radio1, id=1)
group.addButton(radio2, id=2)

group.idClicked.connect(lambda id: print("Button ID clicked:", id))
```

---

## 💡 Tips

* Only **one radio button** in a group can be selected at a time.
* Use `setChecked(True)` to **preselect** a button.
* Grouping buttons manually using `QButtonGroup` is useful for **logic separation**.
* Use signals like `toggled` to dynamically update labels or forms.

---

## 🧩 Real-world Use Case Ideas

* Gender selection: Male / Female / Other
* Payment method: Credit Card / PayPal / Cash
* Language choice: English / French / Arabic
* Difficulty level: Easy / Medium / Hard

