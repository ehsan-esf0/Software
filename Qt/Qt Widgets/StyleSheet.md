# 📘 Qt Style Sheets

## 🧾 Introduction

Qt Style Sheets allow developers to customize the appearance of widgets using a CSS-like syntax. While it resembles CSS, it is specifically adapted for Qt and is used primarily with Qt Widgets.

---

## 🎯 How to Apply Style Sheets

### 1. **In C++ Code**

```cpp
QPushButton *btn = new QPushButton("Click Me");
btn->setStyleSheet("background-color: blue; color: white;");
```

### 2. **In `.ui` Files (Qt Designer)**

* Select a widget.
* Go to the **Property Editor**.
* Find the `styleSheet` property and write your style code.

---

## 🧱 Basic Structure

```css
QWidget {
    property: value;
}

QPushButton:hover {
    property: value;
}
```

---

## 🎨 Common Properties

| Property                  | Description                     |
| ------------------------- | ------------------------------- |
| `color`                   | Text color                      |
| `background-color`        | Background color                |
| `font-size`               | Font size (e.g., `14px`)        |
| `font-family`             | Font type (e.g., `Arial`)       |
| `font-weight`             | `normal`, `bold`, `600`         |
| `border`                  | Full border definition          |
| `border-color`            | Border color                    |
| `border-style`            | `solid`, `dashed`, `none`       |
| `border-radius`           | Rounded corners                 |
| `padding`, `margin`       | Internal/External spacing       |
| `image`, `border-image`   | Set background or border images |
| `min-width`, `max-height` | Widget size constraints         |

---

## 🧠 Pseudo-States (Widget States)

| Pseudo-State | Description                         |
| ------------ | ----------------------------------- |
| `:hover`     | When the mouse hovers over a widget |
| `:pressed`   | While the button is pressed         |
| `:checked`   | For checkboxes and radio buttons    |
| `:disabled`  | When the widget is disabled         |
| `:focus`     | When the widget has keyboard focus  |

**Example:**

```css
QPushButton:hover {
    background-color: #3498db;
}

QPushButton:pressed {
    background-color: #2980b9;
}
```

---

## 💡 Widget-Specific Elements

### 🔘 QPushButton

```cpp
qproperty-icon
qproperty-iconSize
```

### 📝 QLineEdit, QTextEdit

```css
selection-color: white;
selection-background-color: blue;
```

### 📜 QScrollBar

```css
QScrollBar::handle { background: gray; }
QScrollBar::add-line, ::sub-line { background: darkgray; }
```

### 🎚️ QSlider

```css
QSlider::groove:horizontal { height: 6px; background: #ccc; }
QSlider::handle:horizontal { width: 10px; background: #555; }
```

---

## 🧪 Complete Example

```cpp
QString style = R"(
QPushButton {
    background-color: #2ecc71;
    color: white;
    border: 2px solid #27ae60;
    border-radius: 10px;
    padding: 8px 16px;
    font-weight: bold;
}
QPushButton:hover {
    background-color: #27ae60;
}
QPushButton:pressed {
    background-color: #1e8449;
}
)";
button->setStyleSheet(style);
```

---

## ❌ Unsupported CSS Features

Qt Style Sheets **do not support**:

* `display`, `position`, `float`
* CSS layout (Flexbox, Grid)
* Transitions or animations (`transition`, `animation`)
* Complex CSS selectors like `div > p`, `div p.class`

---

## 📚 Tips

* Use `objectName` to target a specific widget:

```cpp
myButton->setObjectName("customBtn");

this->setStyleSheet("#customBtn { background-color: red; }");
```

* Apply styles globally with `qApp->setStyleSheet(...)`.

---