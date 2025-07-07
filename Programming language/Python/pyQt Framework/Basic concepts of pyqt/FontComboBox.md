## What is QFontComboBox?

**QFontComboBox** is a widget in PyQt6 that provides a dropdown list of system fonts, allowing the user to select a font family. It’s commonly used in applications where the user can change the font of text (like a text editor).

---

## 1. Importing QFontComboBox

```python
from PyQt6.QtWidgets import QFontComboBox
```

---

## 2. Basic Usage

To create and add a QFontComboBox to your window or layout:

```python
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QFontComboBox, QLabel

class MyWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("QFontComboBox Example")
        layout = QVBoxLayout()

        self.font_combo = QFontComboBox(self)
        self.font_combo.currentFontChanged.connect(self.font_changed)

        self.label = QLabel("Sample Text", self)

        layout.addWidget(self.font_combo)
        layout.addWidget(self.label)

        self.setLayout(layout)

    def font_changed(self, font):
        self.label.setFont(font)

if __name__ == '__main__':
    app = QApplication([])
    window = MyWindow()
    window.show()
    app.exec()
```

---

## 3. Key Methods & Properties

* **currentFont()**
  Returns the currently selected QFont.

  ```python
  selected_font = font_combo.currentFont()
  ```
* **setCurrentFont(QFont)**
  Set the currently selected font programmatically.

  ```python
  from PyQt6.QtGui import QFont
  font_combo.setCurrentFont(QFont("Arial"))
  ```
* **currentFontChanged** (Signal)
  Signal that is emitted whenever the selected font changes.

  ```python
  font_combo.currentFontChanged.connect(your_function)
  ```

---

## 4. Customization

* **setFontFilters()**
  You can filter the fonts shown in the combo box:

  ```python
  from PyQt6.QtWidgets import QFontComboBox
  font_combo.setFontFilters(QFontComboBox.FontFilter.MonospacedFonts)
  ```

  Options include:

  * `QFontComboBox.FontFilter.AllFonts` (default)
  * `QFontComboBox.FontFilter.ProportionalFonts`
  * `QFontComboBox.FontFilter.MonospacedFonts`
  * You can combine them using the `|` operator.

* **setWritingSystem()**
  Filters fonts for a specific writing system (e.g., Latin, Arabic, etc.):

  ```python
  from PyQt6.QtGui import QFontDatabase
  font_combo.setWritingSystem(QFontDatabase.WritingSystem.Latin)
  ```

---

## 5. Example: Font Selection for a Text Editor

Here’s how you might use QFontComboBox to let the user change the font of a QTextEdit:

```python
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QFontComboBox, QTextEdit

class EditorWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Text Editor Font Selection")

        layout = QVBoxLayout()
        self.font_combo = QFontComboBox()
        self.text_edit = QTextEdit("Type something...")

        layout.addWidget(self.font_combo)
        layout.addWidget(self.text_edit)
        self.setLayout(layout)

        self.font_combo.currentFontChanged.connect(self.change_font)

    def change_font(self, font):
        self.text_edit.setFont(font)

if __name__ == "__main__":
    app = QApplication([])
    win = EditorWindow()
    win.show()
    app.exec()
```

---

## Summary

* **QFontComboBox** is a widget for selecting font families.
* You can get/set the selected font and filter the font list.
* Commonly used in UIs where users can customize text appearance.
