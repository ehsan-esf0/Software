# PyQt6 Event 

## 🔹 What Are Events in PyQt?

In PyQt6, the **event system** allows widgets to **react to user interactions** such as:

* Mouse clicks
* Key presses
* Window resizing
* Focus changes
* Painting
* Entering or leaving the widget area

This is **different from signals/slots**, which are high-level wrappers. Events provide **low-level, precise control**.

---

## 🔸 Events vs Signals/Slots

| Concept         | Description                                                                |
| --------------- | -------------------------------------------------------------------------- |
| **Signal/Slot** | High-level mechanism, easy to use (e.g. `button.clicked.connect(...)`)     |
| **Event**       | Low-level method overriding (e.g. `mousePressEvent`) for detailed behavior |

---

## 🔹 Basic Event Handling – Overriding Methods

PyQt6 lets you override widget methods like:

| Event Method                   | Triggered When...            |
| ------------------------------ | ---------------------------- |
| `mousePressEvent(event)`       | Mouse is clicked             |
| `mouseReleaseEvent(event)`     | Mouse click is released      |
| `mouseDoubleClickEvent(event)` | Mouse double-clicked         |
| `mouseMoveEvent(event)`        | Mouse is moved over widget   |
| `keyPressEvent(event)`         | Keyboard key is pressed      |
| `keyReleaseEvent(event)`       | Key is released              |
| `enterEvent(event)`            | Mouse enters the widget area |
| `leaveEvent(event)`            | Mouse leaves widget area     |
| `focusInEvent(event)`          | Widget gains keyboard focus  |
| `focusOutEvent(event)`         | Widget loses focus           |
| `resizeEvent(event)`           | Widget is resized            |
| `closeEvent(event)`            | Window is closed             |
| `paintEvent(event)`            | Widget is redrawn            |

---

## 🔸 Example: Mouse Click Event

```python
class MyWidget(QWidget):
    def mousePressEvent(self, event):
        print("Mouse clicked at:", event.position())
```

---

## 🔸 Example: Key Press Event

```python
class MyWidget(QWidget):
    def keyPressEvent(self, event):
        if event.key() == Qt.Key.Key_Enter:
            print("Enter was pressed")
        else:
            print("Key:", event.key())
```

---

## 🔹 Event Object Details

Each event object provides detailed info depending on the type:

### Mouse Event

```python
event.pos()          # Position relative to widget
event.globalPosition() # Global screen position
event.button()       # Left/right/middle button
```

### Key Event

```python
event.key()          # Key code (e.g. Qt.Key_A)
event.text()         # Unicode character
event.modifiers()    # Shift, Ctrl, Alt, etc.
```

---

## 🔹 Focus & Window Events

### Focus events

```python
def focusInEvent(self, event):
    print("Widget focused")

def focusOutEvent(self, event):
    print("Focus lost")
```

### Resize / Close

```python
def resizeEvent(self, event):
    print("New size:", self.size())

def closeEvent(self, event):
    print("Window is closing")
    event.accept()  # or event.ignore() to cancel
```

---

## 🔹 paintEvent – Custom Drawing

Use `paintEvent()` and `QPainter` for custom graphics:

```python
def paintEvent(self, event):
    painter = QPainter(self)
    painter.setBrush(QColor("blue"))
    painter.drawRect(self.rect())
```

---

## 🔹 Advanced: `event()` Method

Every widget has a general `event(self, event)` method that catches **all event types**. You can override it to monitor or intercept any event:

```python
def event(self, event):
    if event.type() == QEvent.Type.MouseButtonPress:
        print("General mouse press event")
    return super().event(event)
```

---

## 🔹 Expert: Event Filter System

Use **event filters** to monitor events of **other widgets**.

### Example: Filtering all children

```python
class MyFilter(QObject):
    def eventFilter(self, obj, event):
        if event.type() == QEvent.Type.MouseButtonPress:
            print(f"Mouse clicked on {obj}")
        return False  # Let it continue normally

# Apply filter
my_filter = MyFilter()
for widget in parent.findChildren(QWidget):
    widget.installEventFilter(my_filter)
```

---

## ✅ Summary Table

| Technique                        | Use Case                         |
| -------------------------------- | -------------------------------- |
| Override `mousePressEvent`       | Handle mouse clicks directly     |
| Use `event()`                    | Catch any event for deep control |
| Use `eventFilter()`              | Monitor other widgets’ events    |
| Use `QPainter` in `paintEvent()` | Custom drawing                   |
| Use `closeEvent`, `resizeEvent`  | React to window behavior         |

# ✅ Problem: Why is `eventFilter` not detecting mouse clicks on widgets like `QRadioButton`?

### ❓ Your code:

You installed the event filter **only on the main window**:

```python
self.installEventFilter(MyFilter(self))
```

### ⚠️ Why it's not working:

Mouse clicks on child widgets like `QRadioButton` are **handled by those widgets directly**, not by the main window.
So the event filter on `self` (the main window) doesn’t see mouse events directed at the radio buttons.

---

## ✅ Solution: Install the event filter on each widget you want to monitor

### 🔧 Option 1: Install individually

```python
filter = MyFilter(self)
self.radio_button1.installEventFilter(filter)
self.radio_button2.installEventFilter(filter)
self.radio_button3.installEventFilter(filter)
```

---

### 🔧 Option 2: Install filter on **all child widgets**

A more dynamic and scalable way:

```python
filter = MyFilter(self)
for widget in self.findChildren(QWidget):
    widget.installEventFilter(filter)
```

> This will install the event filter on all child widgets (buttons, labels, etc.).

---

## 🧠 Bonus: Difference between `.geometry()`, `.rect()`, `.frameGeometry()`

Inside the event filter, you were printing:

```python
print(obj.geometry())
print(obj.rect())
print(obj.frameGeometry())
```

Here’s what they mean:

| Method            | Description                                                        |
| ----------------- | ------------------------------------------------------------------ |
| `geometry()`      | Position & size relative to the **parent widget**                  |
| `rect()`          | Rectangle from (0,0) to (width,height), **local to widget itself** |
| `frameGeometry()` | Includes frame/margin, **relative to screen**                      |

---

## ✅ Summary

| Issue                                    | Fix                                                  |
| ---------------------------------------- | ---------------------------------------------------- |
| Filter doesn’t catch child widget clicks | Install it on each widget explicitly                 |
| Want full control                        | Use `findChildren(QWidget)` to batch apply           |
| Want object info                         | Use `obj.objectName()` or `type(obj)` in your prints |

---

## 🔄 Optional: Enhance your filter

You can even print widget name/type:

```python
print(f"Clicked widget: {obj.metaObject().className()} at {obj.geometry()}")
```

