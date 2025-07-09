# 🎓 **Lesson 2: Layouts, Interactive Elements, and Simple Form**

---

## 🎯 Lesson Goals

You’ll learn:

✅ How to use interactive UI elements: `TextField`, `Button`, `Label`
✅ How to arrange elements using `Row`, `Column`, `GridLayout`, and `anchors`
✅ Build a basic input form (name + email)
✅ Use event handlers like `onClicked`, `onTextChanged`

---

## 🧱 Layout Options in QML

| Layout       | Description                              |
| ------------ | ---------------------------------------- |
| `anchors`    | Attach elements to parent or other items |
| `Row`        | Arrange elements horizontally            |
| `Column`     | Arrange elements vertically              |
| `GridLayout` | Tabular grid layout (rows and columns)   |

---

## ✅ Example 1: Simple Input Form

```qml
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Simple Form"

    Column {
        anchors.centerIn: parent
        spacing: 10

        TextField {
            id: nameInput
            placeholderText: "Enter your name"
            width: 250
        }

        TextField {
            id: emailInput
            placeholderText: "Enter your email"
            width: 250
        }

        Button {
            text: "Submit"
            onClicked: {
                console.log("Name:", nameInput.text)
                console.log("Email:", emailInput.text)
            }
        }
    }
}
```

---

## ✅ Example 2: Row Layout

```qml
Row {
    spacing: 20
    anchors.centerIn: parent

    Rectangle { width: 50; height: 50; color: "red" }
    Rectangle { width: 50; height: 50; color: "green" }
    Rectangle { width: 50; height: 50; color: "blue" }
}
```

---

## ✅ Example 3: GridLayout for Labeled Fields

```qml
import QtQuick.Layouts 1.15

GridLayout {
    anchors.centerIn: parent
    columns: 2
    rowSpacing: 10
    columnSpacing: 10

    Label { text: "Name:" }
    TextField { id: name }

    Label { text: "Password:" }
    TextField { echoMode: TextInput.Password }
}
```

---

## 🧠 Key Elements Summary

| Element         | Key Property                               | Purpose             |
| --------------- | ------------------------------------------ | ------------------- |
| `TextField`     | `text`, `onTextChanged`, `placeholderText` | Input fields        |
| `Button`        | `text`, `onClicked`                        | Trigger actions     |
| `Label`         | `text`                                     | Display static text |
| `Row`, `Column` | `spacing`                                  | Neat arrangement    |

