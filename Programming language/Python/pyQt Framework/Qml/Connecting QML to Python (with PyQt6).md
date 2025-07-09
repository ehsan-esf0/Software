# 🎓 **Lesson 5: Connecting QML to Python (with PyQt6)**

---

## 🎯 Lesson Goals:

✅ Run and load a `.qml` file from Python
✅ Send data from **Python → QML**
✅ Call Python functions from **QML → Python**
✅ Use a **backend class** to manage logic
✅ Handle **signals** between QML and Python (both directions)

---

## 📁 Project Structure

```
my_project/
├── main.py
├── backend.py
└── main.qml
```

---

## ✅ Step 1: Create the QML UI (main.qml)

```qml
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: "QML + Python Integration"

    Column {
        anchors.centerIn: parent
        spacing: 10

        TextField {
            id: nameInput
            placeholderText: "Enter your name"
        }

        Button {
            text: "Send to Python"
            onClicked: backend.receiveName(nameInput.text)
        }

        Label {
            text: backend.responseText
        }
    }
}
```

📌 Notes:

* `backend.receiveName(...)` is a function in Python
* `backend.responseText` is a property exposed from Python

---

## ✅ Step 2: Python Backend Class (backend.py)

```python
from PyQt6.QtCore import QObject, pyqtSlot, pyqtProperty

class Backend(QObject):
    def __init__(self):
        super().__init__()
        self._response = "..."

    @pyqtSlot(str)
    def receiveName(self, name):
        print("Received from QML:", name)
        self._response = f"Hello, {name}!"

    @pyqtProperty(str)
    def responseText(self):
        return self._response
```

📌 This class:

* Accepts input from QML (`@pyqtSlot`)
* Exposes a property (`@pyqtProperty`) QML can read

---

## ✅ Step 3: Run the QML App via Python (main.py)

```python
import sys
from PyQt6.QtWidgets import QApplication
from PyQt6.QtQml import QQmlApplicationEngine
from backend import Backend

app = QApplication(sys.argv)
engine = QQmlApplicationEngine()

backend = Backend()
engine.rootContext().setContextProperty("backend", backend)

engine.load("main.qml")

if not engine.rootObjects():
    sys.exit(-1)

sys.exit(app.exec())
```

---

## ✅ Bonus: Add Signal from Python → QML

Let’s say Python wants to **notify QML** using a custom signal:

### Python (backend.py):

```python
from PyQt6.QtCore import QObject, pyqtSignal, pyqtSlot

class Backend(QObject):
    greetingReady = pyqtSignal(str)

    @pyqtSlot(str)
    def sayHello(self, name):
        message = f"Hi {name}, welcome!"
        self.greetingReady.emit(message)
```

### QML:

```qml
TextField {
    id: nameInput
}

Button {
    text: "Say Hello"
    onClicked: backend.sayHello(nameInput.text)
}

Connections {
    target: backend
    function onGreetingReady(msg) {
        console.log("Received from Python:", msg)
    }
}
```

---

## 📋 Summary Table

| Concept                | Description                            |
| ---------------------- | -------------------------------------- |
| `@pyqtSlot()`          | Python method callable from QML        |
| `@pyqtProperty()`      | Python property readable by QML        |
| `pyqtSignal(...)`      | Signal from Python to QML              |
| `Connections` (QML)    | Listen to signals from Python          |
| `setContextProperty()` | Bind Python object as `backend` in QML |

