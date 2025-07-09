# 🎓 **Lesson 4: Animations, Behaviors, and States in QML**

---

## 🎯 Lesson Goals:

✅ Create smooth animations
✅ Use `Behavior` to automatically animate property changes
✅ Define multiple `states` for dynamic UI behavior
✅ Animate transitions between states using `Transition`

---

## 📌 Key Concepts

| Concept      | Description                                        |
| ------------ | -------------------------------------------------- |
| `Animation`  | Manual animation on a property (e.g. width, color) |
| `Behavior`   | Auto-animation when a property changes             |
| `State`      | Defines alternate configurations of a component    |
| `Transition` | Animates the change from one state to another      |

---

## ✅ Example 1: Manual Animation with `NumberAnimation`

```qml
Rectangle {
    width: 100
    height: 100
    color: "blue"

    MouseArea {
        anchors.fill: parent
        onClicked: anim.start()
    }

    NumberAnimation on width {
        id: anim
        to: 300
        duration: 500
    }
}
```

📎 When clicked, the `width` increases from 100 to 300 over 0.5 seconds.

---

## ✅ Example 2: Auto Animation with `Behavior`

```qml
Rectangle {
    width: 300; height: 100
    property bool isActive: false
    color: isActive ? "green" : "red"

    Behavior on color {
        ColorAnimation { duration: 500 }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: isActive = !isActive
    }
}
```

📎 Any time `color` changes, the `Behavior` smoothly animates the transition.

---

## ✅ Example 3: Multiple States + Transition

```qml
Rectangle {
    width: 200; height: 200
    color: "lightgray"
    property bool expanded: false

    states: State {
        name: "expanded"
        when: parent.expanded
        PropertyChanges { target: box; width: 300; height: 300; color: "skyblue" }
    }

    transitions: Transition {
        NumberAnimation { properties: "width,height"; duration: 500 }
        ColorAnimation { duration: 500 }
    }

    Rectangle {
        id: box
        width: 100; height: 100
        color: "orange"
        anchors.centerIn: parent

        MouseArea {
            anchors.fill: parent
            onClicked: parent.expanded = !parent.expanded
        }
    }
}
```

📌 What’s happening:

* The component toggles between a default and an `"expanded"` state
* A `Transition` smoothly animates size and color
* Controlled via clicking the orange box

---

## 📋 Summary Table: Lesson 4 Concepts

| Concept           | Description                               |
| ----------------- | ----------------------------------------- |
| `NumberAnimation` | Animates numeric properties (e.g., width) |
| `ColorAnimation`  | Smoothly transitions between colors       |
| `Behavior`        | Automatically animates property changes   |
| `State`           | Defines alternative property sets         |
| `Transition`      | Animates movement between states          |

---
