## 1. Importing QMessageBox

```python
from PyQt6.QtWidgets import QMessageBox
```

---

## 2. Types of Messages

QMessageBox provides several standard types of dialogs, which you can show using its static methods:

### - Information Message

```python
QMessageBox.information(self, "Title", "This is an info message")
```

### - Warning Message

```python
QMessageBox.warning(self, "Warning", "This is a warning message")
```

### - Critical (Error) Message

```python
QMessageBox.critical(self, "Error", "An error has occurred!")
```

### - Question Message

```python
result = QMessageBox.question(self, "Question", "Are you sure?",
                              QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No)
if result == QMessageBox.StandardButton.Yes:
    # Do something if Yes
    pass
```

---

## 3. Creating a Custom Message Box

For more control over your dialog, you can create an instance of `QMessageBox` and customize it:

```python
msg = QMessageBox()
msg.setWindowTitle("Custom Message")
msg.setText("This is a custom message")
msg.setIcon(QMessageBox.Icon.Information)
msg.setStandardButtons(QMessageBox.StandardButton.Ok | QMessageBox.StandardButton.Cancel)
msg.setDefaultButton(QMessageBox.StandardButton.Ok)

result = msg.exec()

if result == QMessageBox.StandardButton.Ok:
    print("User clicked OK")
else:
    print("User cancelled")
```

---

## 4. Standard Buttons

Available standard buttons:

* **Ok**
* **Cancel**
* **Yes**
* **No**
* **Abort**
* **Retry**
* **Ignore**

You can combine them like this:

```python
QMessageBox.StandardButton.Ok | QMessageBox.StandardButton.Cancel
```

---

## 5. Advanced Settings

Some useful methods:

* **setInformativeText()**: Adds extra text (informative).
* **setDetailedText()**: Adds collapsible detailed text.
* **setIcon()**: Sets the icon (Information, Warning, Critical, Question).
* **setWindowModality()**: Makes the dialog modal or non-modal.
* **setCheckBox()**: Adds a checkbox to the dialog.

Example:

```python
msg = QMessageBox(self)
msg.setWindowTitle("Info")
msg.setText("Operation completed successfully")
msg.setInformativeText("Click 'Show Details' for more information.")
msg.setDetailedText("Details: Everything went fine!")
msg.setIcon(QMessageBox.Icon.Information)
msg.setStandardButtons(QMessageBox.StandardButton.Ok)
msg.exec()
```

---

## 6. Full Working Example

```python
from PyQt6.QtWidgets import QApplication, QWidget, QPushButton, QMessageBox

class MyWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("QMessageBox Example")
        btn = QPushButton("Show Message", self)
        btn.clicked.connect(self.show_message)

    def show_message(self):
        msg = QMessageBox(self)
        msg.setWindowTitle("Are you sure?")
        msg.setText("This action cannot be undone!")
        msg.setIcon(QMessageBox.Icon.Warning)
        msg.setStandardButtons(QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No)
        msg.setDefaultButton(QMessageBox.StandardButton.No)

        result = msg.exec()
        if result == QMessageBox.StandardButton.Yes:
            QMessageBox.information(self, "Done", "The action was successful.")
        else:
            QMessageBox.information(self, "Cancelled", "The action was cancelled.")

if __name__ == '__main__':
    app = QApplication([])
    window = MyWindow()
    window.show()
    app.exec()
```

---

## Key Points

* QMessageBox dialogs are **modal** by default, meaning the main window is disabled until the user closes the message box.
* Use the `exec()` method to display the message box and get the user’s response.
* The static methods (like `QMessageBox.information()`) are quick and simple, but for more control, create an instance.

