# Detecting Which Object Was Clicked in Qt 

---

## 1. Subclassing and Emitting Custom Signals

### What?

* Subclass widgets (e.g., QLabel).
* Override `mousePressEvent`.
* Emit a custom signal like `clicked()`.
* Connect signal to a slot and use `sender()` to identify the source.

### Example:

```cpp
class ClickableLabel : public QLabel {
    Q_OBJECT
public:
    ClickableLabel(const QString& text, QWidget* parent = nullptr) : QLabel(text, parent) {}
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event) override {
        emit clicked();
        QLabel::mousePressEvent(event);
    }
};
```

---

## 2. Using `eventFilter` to Intercept Events Centrally

### What?

* Install an event filter on multiple widgets.
* Intercept mouse events in one place.
* Identify the sender by casting the `QObject*`.

### Example:

```cpp
bool MyWidget::eventFilter(QObject* watched, QEvent* event) {
    if (event->type() == QEvent::MouseButtonPress) {
        if (QLabel* label = qobject_cast<QLabel*>(watched)) {
            qDebug() << "Clicked label:" << label->objectName();
            return true; // Event handled
        }
    }
    return QWidget::eventFilter(watched, event);
}
```

---

## 3. Using Built-in Signals like `clicked()` for Clickable Widgets

### What?

* For widgets like QPushButton that have `clicked()` signals.
* Connect signals to a slot.
* Use `sender()` inside the slot to know which widget emitted the signal.

---

## 4. Using Gesture Events with `QGestureRecognizer`

### What?

* For complex interactions like touch gestures.
* Register gesture recognizers and handle gesture events.

*More advanced; used for touch-enabled applications.*

---

## 5. Using `childAt()` with Mouse Events in Parent Widget

### What?

* Handle mouse events in a parent widget.
* Use `childAt(event->pos())` to find which child widget was clicked.

### Example:

```cpp
void MyWidget::mousePressEvent(QMouseEvent* event) {
    QWidget* child = childAt(event->pos());
    if (child) {
        qDebug() << "Clicked child widget:" << child->objectName();
    }
}
```

---

## 6. Using `QSignalMapper` (Older Qt Versions)

### What?

* Map multiple signals to a single slot with an identifier.
* Pass a string or widget pointer to identify sender.

### Example:

```cpp
QSignalMapper* mapper = new QSignalMapper(this);

connect(label1, SIGNAL(clicked()), mapper, SLOT(map()));
connect(label2, SIGNAL(clicked()), mapper, SLOT(map()));

mapper->setMapping(label1, "label1");
mapper->setMapping(label2, "label2");

connect(mapper, SIGNAL(mapped(QString)), this, SLOT(handleLabelClicked(QString)));
```

*Note: Deprecated in newer Qt versions in favor of lambdas or `sender()`.*

---

# Summary Table

| Method                    | Advantages                      | Disadvantages               | When to Use                           |
| ------------------------- | ------------------------------- | --------------------------- | ------------------------------------- |
| Subclass + custom signals | Full control, customizable      | Need custom classes         | When you want fine-grained control    |
| Event filter              | Centralized event handling      | More complex implementation | Many widgets, want one handling point |
| Built-in signals          | Simple, no extra code           | Only for clickable widgets  | When widgets already emit signals     |
| Gesture events            | Supports complex touch gestures | More advanced, specific use | Touch apps needing gestures           |
| `childAt()` in parent     | No subclassing needed           | Only within parent's area   | Manage clicks in parent widget        |
| QSignalMapper             | Central slot with IDs           | Deprecated, legacy code     | Older Qt projects                     |

---