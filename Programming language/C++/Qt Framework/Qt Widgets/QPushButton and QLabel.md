## 🟦 1. QPushButton — Push Button

### ✅ Beginner Level:

| Feature             | Description                                                 |
| ------------------- | ----------------------------------------------------------- |
| **Set Button Text** | Use `setText()` or directly via constructor.                |
| **Connect to Slot** | Connect the `clicked()` signal to a slot using `connect()`. |
| **Enable/Disable**  | Use `setEnabled(false)` to disable.                         |
| **Show/Hide**       | Use `show()` and `hide()` methods.                          |

#### Example:

```cpp
QPushButton *btn = new QPushButton("Click me", this);
connect(btn, &QPushButton::clicked, this, &MyWindow::onButtonClicked);
```

---

### 🔷 Intermediate Level:

| Feature                | Description                                             |
| ---------------------- | ------------------------------------------------------- |
| **Set Icon on Button** | Use `setIcon(QIcon)`.                                   |
| **Icon Size**          | Use `setIconSize(QSize)`.                               |
| **Keyboard Shortcut**  | Example: `"&Exit"` means Alt+E.                         |
| **Default Button**     | Use `setDefault(true)` for login forms, etc.            |
| **Toggle State**       | `setCheckable(true)` and check state via `isChecked()`. |

#### Example:

```cpp
QPushButton *btn = new QPushButton(QIcon(":/icons/save.png"), "Save", this);
btn->setIconSize(QSize(24,24));
btn->setCheckable(true);
```

---

### 🟣 Advanced Level:

| Feature                      | Description                                             |
| ---------------------------- | ------------------------------------------------------- |
| **Styling with CSS**         | Use `setStyleSheet()` to apply custom styles.           |
| **Custom Events**            | Override `mousePressEvent()` for custom behaviors.      |
| **Custom QPushButton Class** | Inherit from `QPushButton` for advanced features.       |
| **Add Button Animations**    | Combine with `QPropertyAnimation`.                      |
| **Handle Multiple Signals**  | `clicked()`, `pressed()`, `released()`, `toggled(bool)` |

#### Advanced Styling:

```cpp
btn->setStyleSheet(
    "QPushButton { background-color: #3498db; color: white; border-radius: 10px; padding: 10px; }"
    "QPushButton:hover { background-color: #2980b9; }"
);
```

---

## 🟩 2. QLabel — Text/Image Label

### ✅ Beginner Level:

| Feature                 | Description                   |
| ----------------------- | ----------------------------- |
| **Display Simple Text** | Use `setText()`.              |
| **Text Alignment**      | Use `setAlignment()`.         |
| **Multiline Text**      | Just set a multi-line string. |
| **Display Image**       | Use `setPixmap(QPixmap)`.     |

#### Example:

```cpp
QLabel *label = new QLabel("Hello, World!", this);
label->setAlignment(Qt::AlignCenter);
```

---

### 🔷 Intermediate Level:

| Feature                      | Description                                    |
| ---------------------------- | ---------------------------------------------- |
| **Change Text Color / Font** | Use `setStyleSheet()` or `setFont()`.          |
| **Display Rich Text (HTML)** | `label->setText("<b>Bold</b> <i>Italic</i>");` |
| **Auto-resize to Fit Text**  | Use `adjustSize()`.                            |
| **Scalable Image**           | Use `setScaledContents(true)`.                 |

#### Example:

```cpp
QLabel *imgLabel = new QLabel(this);
imgLabel->setPixmap(QPixmap(":/images/logo.png"));
imgLabel->setScaledContents(true);
imgLabel->resize(100, 100);
```

---

### 🟣 Advanced Level:

| Feature                  | Description                                                             |
| ------------------------ | ----------------------------------------------------------------------- |
| **Mouse Event Handling** | Override `mousePressEvent()` by subclassing.                            |
| **Clickable QLabel**     | Create a custom QLabel emitting a `clicked()` signal.                   |
| **Dynamic UI Updates**   | Combine with layouts and signal-slot connections.                       |
| **Display Animated GIF** | Use `QMovie`.                                                           |
| **Live Data Display**    | Use `QTimer` to update label in real-time (e.g., clock or sensor data). |

#### Clickable QLabel Example:

```cpp
class ClickableLabel : public QLabel {
    Q_OBJECT
public:
    explicit ClickableLabel(QWidget *parent = nullptr) : QLabel(parent) {}
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent *event) override {
        emit clicked();
    }
};
```
