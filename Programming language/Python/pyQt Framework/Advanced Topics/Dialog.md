## 1. **QMessageBox** (Show messages, warnings, errors, questions)

```python
from PyQt6.QtWidgets import QApplication, QMessageBox, QWidget, QPushButton, QVBoxLayout

class MsgBoxDemo(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("QMessageBox Example")
        layout = QVBoxLayout(self)
        btn_info = QPushButton("Show Information")
        btn_info.clicked.connect(self.show_info)
        layout.addWidget(btn_info)

    def show_info(self):
        QMessageBox.information(self, "Information", "This is an information message!")

if __name__ == "__main__":
    app = QApplication([])
    win = MsgBoxDemo()
    win.show()
    app.exec()
```

---

## 2. **QFileDialog** (Open or Save a File)

### Open File Example:

```python
from PyQt6.QtWidgets import QApplication, QFileDialog, QPushButton, QVBoxLayout, QWidget, QLabel

class FileDialogDemo(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("QFileDialog Example")
        layout = QVBoxLayout(self)
        self.label = QLabel("No file selected")
        btn = QPushButton("Open File")
        btn.clicked.connect(self.open_file)
        layout.addWidget(btn)
        layout.addWidget(self.label)

    def open_file(self):
        filename, _ = QFileDialog.getOpenFileName(self, "Open File", "", "Text Files (*.txt);;All Files (*)")
        if filename:
            self.label.setText(f"Selected: {filename}")

if __name__ == "__main__":
    app = QApplication([])
    win = FileDialogDemo()
    win.show()
    app.exec()
```

---

## 3. **QColorDialog** (Pick a Color)

```python
from PyQt6.QtWidgets import QApplication, QColorDialog, QPushButton, QVBoxLayout, QWidget, QLabel
from PyQt6.QtGui import QColor

class ColorDialogDemo(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("QColorDialog Example")
        layout = QVBoxLayout(self)
        self.label = QLabel("No color selected")
        btn = QPushButton("Pick Color")
        btn.clicked.connect(self.pick_color)
        layout.addWidget(btn)
        layout.addWidget(self.label)

    def pick_color(self):
        color = QColorDialog.getColor()
        if color.isValid():
            self.label.setText(f"Selected color: {color.name()}")

if __name__ == "__main__":
    app = QApplication([])
    win = ColorDialogDemo()
    win.show()
    app.exec()
```

---

## 4. **QFontDialog** (Pick a Font)

```python
from PyQt6.QtWidgets import QApplication, QFontDialog, QPushButton, QVBoxLayout, QWidget, QLabel

class FontDialogDemo(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("QFontDialog Example")
        layout = QVBoxLayout(self)
        self.label = QLabel("Sample Text")
        btn = QPushButton("Pick Font")
        btn.clicked.connect(self.pick_font)
        layout.addWidget(btn)
        layout.addWidget(self.label)

    def pick_font(self):
        font, ok = QFontDialog.getFont()
        if ok:
            self.label.setFont(font)

if __name__ == "__main__":
    app = QApplication([])
    win = FontDialogDemo()
    win.show()
    app.exec()
```

---

## 5. **QInputDialog** (Simple Input: Text or Number)

### Get Text from User:

```python
from PyQt6.QtWidgets import QApplication, QInputDialog, QPushButton, QVBoxLayout, QWidget, QLabel

class InputDialogDemo(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("QInputDialog Example")
        layout = QVBoxLayout(self)
        self.label = QLabel("No input yet")
        btn = QPushButton("Get Text")
        btn.clicked.connect(self.get_text)
        layout.addWidget(btn)
        layout.addWidget(self.label)

    def get_text(self):
        text, ok = QInputDialog.getText(self, "Input Dialog", "Enter your name:")
        if ok and text:
            self.label.setText(f"Hello, {text}!")

if __name__ == "__main__":
    app = QApplication([])
    win = InputDialogDemo()
    win.show()
    app.exec()
```

---

## 6. **QDialog (Custom Dialog)**

Create your own dialog with custom widgets:

```python
from PyQt6.QtWidgets import QApplication, QDialog, QLineEdit, QPushButton, QVBoxLayout, QLabel, QWidget

class CustomDialog(QDialog):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Custom Dialog")
        layout = QVBoxLayout(self)
        self.label = QLabel("Enter something:")
        self.input = QLineEdit()
        btn = QPushButton("OK")
        btn.clicked.connect(self.accept)
        layout.addWidget(self.label)
        layout.addWidget(self.input)
        layout.addWidget(btn)

    def get_value(self):
        return self.input.text()

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Custom QDialog Example")
        layout = QVBoxLayout(self)
        self.label = QLabel("Result will appear here")
        btn = QPushButton("Open Custom Dialog")
        btn.clicked.connect(self.open_dialog)
        layout.addWidget(btn)
        layout.addWidget(self.label)

    def open_dialog(self):
        dlg = CustomDialog()
        if dlg.exec():
            self.label.setText(f"Input: {dlg.get_value()}")

if __name__ == "__main__":
    app = QApplication([])
    win = MainWindow()
    win.show()
    app.exec()
```

---
