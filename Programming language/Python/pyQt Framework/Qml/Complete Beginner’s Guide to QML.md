# 🎓 **QML Lesson 1: Complete Beginner’s Guide to QML**

---

## 🧠 What is QML?

| Feature               | Description                       |
| --------------------- | --------------------------------- |
| Type                  | Declarative language              |
| Syntax                | Similar to JSON + JavaScript      |
| Purpose               | UI design in Qt                   |
| Powerful for          | Animations, transitions, graphics |
| Connectable to Python | Via **PyQt6** or **PySide6**      |

---

## 📁 Project Structure (for PyQt6)

```
my_first_qml_project/
├── main.py
└── main.qml
```

---

## ✨ `main.qml` — Your First QML File

```qml
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 400
    height: 300
    visible: true
    title: "My First QML App"

    Rectangle {
        anchors.fill: parent
        color: "lightblue"

        Text {
            anchors.centerIn: parent
            text: "Hello QML!"
            font.pixelSize: 24
            color: "navy"
        }
    }
}
```

---

### 🔍 Line-by-Line Explanation:

| Line                   | Description                     |
| ---------------------- | ------------------------------- |
| `import QtQuick`       | Imports the basic QML UI module |
| `ApplicationWindow`    | The main app window             |
| `width`, `height`      | Size of the window              |
| `visible: true`        | Make the window show            |
| `title`                | Window title                    |
| `Rectangle`            | Background box with color       |
| `anchors.fill: parent` | Fill the parent window          |
| `Text`                 | Shows some text                 |
| `anchors.centerIn`     | Center the text in the parent   |
| `font.pixelSize`       | Font size                       |
| `color`                | Color of the rectangle or text  |

---

## 🛠️ Python Code to Run QML

```python
# main.py
import sys
from PyQt6.QtWidgets import QApplication
from PyQt6.QtQml import QQmlApplicationEngine

app = QApplication(sys.argv)
engine = QQmlApplicationEngine()
engine.load("main.qml")

if not engine.rootObjects():
    sys.exit(-1)

sys.exit(app.exec())
```

---

## 📦 Basic QML Elements Table

| Element     | Purpose              | Key Properties              |
| ----------- | -------------------- | --------------------------- |
| `Rectangle` | Simple colored block | `width`, `height`, `color`  |
| `Text`      | Display static text  | `text`, `font`, `color`     |
| `Button`    | Interactive button   | `text`, `onClicked`         |
| `Image`     | Display images       | `source`, `width`, `height` |
| `MouseArea` | Capture clicks       | `onClicked`, `hoverEnabled` |

---

## 📘 More Examples for Practice

---

### ✅ Example 1: Show multiple texts in different positions

```qml
Rectangle {
    width: 300; height: 200
    color: "#f0f0f0"

    Text {
        text: "Top"
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10
    }

    Text {
        text: "Bottom"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
    }

    Text {
        text: "Center"
        anchors.centerIn: parent
        font.pixelSize: 22
    }
}
```

---

### ✅ Example 2: Change rectangle color using a button

```qml
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400; height: 300
    title: "Color Toggle"

    property bool isBlue: true

    Rectangle {
        id: box
        anchors.fill: parent
        color: isBlue ? "skyblue" : "salmon"

        Button {
            text: "Toggle Color"
            anchors.centerIn: parent
            onClicked: isBlue = !isBlue
        }
    }
}
```

🧠 Concepts used:

* `property` defines a reactive variable
* `? :` is a ternary condition
* `!isBlue` toggles boolean value

---

### ✅ Example 3: Use `MouseArea` without a button

```qml
Rectangle {
    width: 300; height: 200
    color: "orange"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("Rectangle clicked!")
        }
    }

    Text {
        anchors.centerIn: parent
        text: "Click Me"
    }
}
```

---

## 📝 Practice Task (Recommended)

Build a simple UI with:

* A `Rectangle` that changes color
* A `Text` label that updates
* A `Button` that controls the changes

---

## 📋 Lesson 1 Summary

| Topic                | Covered? |
| -------------------- | -------- |
| What is QML          | ✅        |
| Create a `.qml` file | ✅        |
| Run QML in Python    | ✅        |
| Basic Elements       | ✅        |
| Handle Events        | ✅        |
| Use `property`       | ✅        |
