# 🎓 **Lesson 3: Properties, Bindings, and JavaScript Interaction in QML**

---

## 🎯 Lesson Goals:

✅ Understand what `property` means in QML
✅ Use **binding** (automatic dependency updates)
✅ Add **JavaScript logic** inside QML
✅ Use **signals** to communicate between elements

---

## 📌 1. What is `property`?

A `property` in QML defines a **reactive variable** that QML elements can observe and bind to.

```qml
property int counter: 0
```

* Types: `int`, `bool`, `string`, `real`, `color`, `variant`, ...
* Any element that depends on a property automatically updates when it changes.
* Think of it like **state** in React or **observable** in Vue.

---

## ✅ Example 1: A Simple Counter Using Binding

```qml
ApplicationWindow {
    visible: true
    width: 300
    height: 200

    property int counter: 0

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: "Count: " + counter
            font.pixelSize: 20
        }

        Button {
            text: "Increase"
            onClicked: counter += 1
        }

        Button {
            text: "Reset"
            onClicked: counter = 0
        }
    }
}
```

📎 The `Text` element is automatically updated when `counter` changes. That’s **binding**.

---

## ✅ Example 2: Binding Between Elements

```qml
Rectangle {
    width: 200
    height: 200
    color: "lightgray"

    Rectangle {
        width: parent.width / 2
        height: width
        color: "tomato"
    }
}
```

📎 The inner rectangle always has width = half of the parent. If the parent resizes, the child updates automatically.

---

## ✅ Example 3: Conditional Color Change

```qml
property bool isActive: false

Rectangle {
    width: 300; height: 200
    color: isActive ? "green" : "red"

    MouseArea {
        anchors.fill: parent
        onClicked: isActive = !isActive
    }

    Text {
        text: isActive ? "Active" : "Inactive"
        anchors.centerIn: parent
    }
}
```

📎 Toggling `isActive` flips both the color and the label.

---

## ✅ Example 4: Custom JavaScript Functions in QML

```qml
property int price: 25000

Text {
    text: "Price: " + formatPrice(price)

    function formatPrice(p) {
        return p + " Toman"
    }
}
```

📎 You can define JavaScript functions **inline** in QML for formatting, conditions, etc.

---

## 📢 Signals in QML

Signals allow you to **send custom events** between components.

```qml
signal mySignal(int value)

Button {
    text: "Send Signal"
    onClicked: mySignal(123)
}
```

📎 Another element can use `onMySignal:` to react to this.

---

## 📋 Summary Table of Key Concepts

| Concept     | Description                        |
| ----------- | ---------------------------------- |
| `property`  | Defines a reactive value in QML    |
| `Binding`   | Automatically updates values       |
| JavaScript  | Adds logic and formatting          |
| `signal`    | Sends events between components    |
| `onClicked` | Event handler for user interaction |
