# Events in Qt

---

### 2.1 What are Events?

Events are low-level messages sent by Qt or the operating system to widgets to notify them about user actions or system changes, such as:

* Mouse clicks
* Key presses
* Resize events
* Paint requests

They differ from signals — **events are system-driven notifications**, while **signals are Qt-level communication objects**.

---

### 2.2 Event System Overview

When an event occurs, Qt creates an event object (`QEvent` or subclass) and delivers it to the target widget’s `event()` method.

The widget can:

* Handle the event by overriding `event()` or specific event handlers (e.g., `mousePressEvent()`)
* Ignore the event, passing it up the hierarchy

---

### 2.3 Types of Events

Common event types and corresponding handler functions:

| Event Type                   | Event Handler Method              | Description           |
| ---------------------------- | --------------------------------- | --------------------- |
| `QEvent::MouseButtonPress`   | `mousePressEvent(QMouseEvent*)`   | Mouse button pressed  |
| `QEvent::MouseButtonRelease` | `mouseReleaseEvent(QMouseEvent*)` | Mouse button released |
| `QEvent::MouseMove`          | `mouseMoveEvent(QMouseEvent*)`    | Mouse moved           |
| `QEvent::KeyPress`           | `keyPressEvent(QKeyEvent*)`       | Key pressed           |
| `QEvent::KeyRelease`         | `keyReleaseEvent(QKeyEvent*)`     | Key released          |
| `QEvent::Resize`             | `resizeEvent(QResizeEvent*)`      | Widget resized        |
| `QEvent::Paint`              | `paintEvent(QPaintEvent*)`        | Widget needs repaint  |
| `QEvent::Enter`              | `enterEvent(QEvent*)`             | Mouse enters widget   |
| `QEvent::Leave`              | `leaveEvent(QEvent*)`             | Mouse leaves widget   |

---

### 2.4 Handling Events by Overriding Event Handlers

You can override these handlers in your custom widget class.

---

### Example: Override Mouse Press Event

```cpp
void MyWidget::mousePressEvent(QMouseEvent *event) {
    qDebug() << "Mouse pressed at:" << event->pos();
}
```

---

### 2.5 Using `event()` Method for Custom Event Processing

You can override the generic `event(QEvent *e)` method to intercept all events before specific handlers.

```cpp
bool MyWidget::event(QEvent *e) {
    if (e->type() == QEvent::MouseButtonDblClick) {
        qDebug() << "Double click detected!";
        return true; // event handled
    }
    return QWidget::event(e); // default processing
}
```

---

### 2.6 Event Filters (`eventFilter`)

You can install an event filter on any QObject to intercept events before they reach their target.

---

### How to Use `eventFilter`

1. Subclass `QObject` (or QWidget) and override `eventFilter()` method
2. Install filter with `installEventFilter()` on target objects

---

### Example: Event Filter to Detect Mouse Enter on Button

```cpp
bool MyWindow::eventFilter(QObject *watched, QEvent *event) {
    if (watched == myButton && event->type() == QEvent::Enter) {
        qDebug() << "Mouse entered button!";
        return true; // event consumed
    }
    return QWidget::eventFilter(watched, event);
}
```

---

### 2.7 Example: Distinguish Clicked Widget by Event Filter

```cpp
bool MyWindow::eventFilter(QObject *watched, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        qDebug() << "Clicked widget:" << watched->objectName()
                 << ", class:" << watched->metaObject()->className();
    }
    return QWidget::eventFilter(watched, event);
}
```

---

### 2.8 Sending Events Programmatically

You can create and post events manually using `QApplication::postEvent()` or `QCoreApplication::sendEvent()`.

---

### Example: Sending a Key Press Event

```cpp
QKeyEvent *keyEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier);
QApplication::postEvent(myWidget, keyEvent);
```

---

## Summary

| Concept | Description                         | Key Function(s)                            |
| ------- | ----------------------------------- | ------------------------------------------ |
| Sender  | The QObject that emits a signal     | `sender()`, `qobject_cast`                 |
| Event   | Low-level system or Qt notification | `event()`, event handlers, `eventFilter()` |

---

## Additional Tips:

* Use **sender()** inside **slots** to know which object triggered the slot
* Use **eventFilter()** when you want to intercept or monitor events on objects you don’t own
* Use **event()** override for centralized event handling
* Use specific event handler overrides for handling specific event types
