# 🌟 Qt Layouts

---

## What is a Layout?

* A **Layout** is a container that **automatically arranges child widgets** inside a window or widget.
* It manages **position, size, and spacing** of widgets dynamically.
* Using layouts prevents hardcoding widget positions and makes GUIs **responsive** and **adaptive** to window resizing.

---

## Why use Layouts?

* Automatically adjust widgets when window resizes
* Maintain consistent spacing & alignment
* Save time compared to manual positioning
* Improve usability and look of the application

---

## Main Types of Layouts in Qt

| Layout Type     | Description                      | Example Use                     |
| --------------- | -------------------------------- | ------------------------------- |
| **QHBoxLayout** | Arrange widgets **horizontally** | Toolbar buttons, navigation bar |
| **QVBoxLayout** | Arrange widgets **vertically**   | Stacking buttons, forms         |
| **QGridLayout** | Arrange widgets in a **grid**    | Complex forms, calculators      |
| **QFormLayout** | Arrange label-widget pairs       | Forms with labels and inputs    |

---

## 1. QHBoxLayout (Horizontal Layout)

* Places widgets side by side in a **row**.
* Widgets are added from **left to right**.

### Example:

```cpp
QHBoxLayout *hLayout = new QHBoxLayout;
hLayout->addWidget(new QPushButton("Left"));
hLayout->addWidget(new QPushButton("Center"));
hLayout->addWidget(new QPushButton("Right"));
this->setLayout(hLayout);
```

---

## 2. QVBoxLayout (Vertical Layout)

* Places widgets stacked **top to bottom**.

### Example:

```cpp
QVBoxLayout *vLayout = new QVBoxLayout;
vLayout->addWidget(new QLabel("Name:"));
vLayout->addWidget(new QLineEdit);
vLayout->addWidget(new QPushButton("Submit"));
this->setLayout(vLayout);
```

---

## 3. QGridLayout (Grid Layout)

* Arrange widgets in **rows and columns**.
* Widgets can **span multiple rows/columns**.

### Example:

```cpp
QGridLayout *grid = new QGridLayout;
grid->addWidget(new QLabel("Username:"), 0, 0);
grid->addWidget(new QLineEdit, 0, 1);
grid->addWidget(new QLabel("Password:"), 1, 0);
grid->addWidget(new QLineEdit, 1, 1);
grid->addWidget(new QPushButton("Login"), 2, 0, 1, 2); // span 2 columns
this->setLayout(grid);
```

---

## 4. QFormLayout

* Layout specialized for **forms**.
* Each row contains a **label and a field**.

### Example:

```cpp
QFormLayout *form = new QFormLayout;
form->addRow("Name:", new QLineEdit);
form->addRow("Email:", new QLineEdit);
form->addRow("Password:", new QLineEdit);
this->setLayout(form);
```

---

## Important Methods in Layouts

| Method                                  | Description                         |
| --------------------------------------- | ----------------------------------- |
| `addWidget(QWidget *widget)`            | Add widget to layout                |
| `addLayout(QLayout *layout)`            | Nest a layout inside another layout |
| `setSpacing(int)`                       | Set space between widgets           |
| `setMargin(int)`                        | Set outer margin of the layout      |
| `setAlignment(QWidget*, Qt::Alignment)` | Align a widget within layout        |

---

## Nesting Layouts

* Layouts can be nested inside each other for complex UI designs.
* Example: Vertical layout with a horizontal layout inside.

```cpp
QVBoxLayout *mainLayout = new QVBoxLayout;

QHBoxLayout *topRow = new QHBoxLayout;
topRow->addWidget(new QPushButton("Button 1"));
topRow->addWidget(new QPushButton("Button 2"));

mainLayout->addLayout(topRow);
mainLayout->addWidget(new QTextEdit);

this->setLayout(mainLayout);
```

---

## Tips for Using Layouts

* **Never mix manual widget positioning (`setGeometry`) with layouts.**
* Use `setLayout()` on the parent widget/container.
* Use `QSpacerItem` or `addStretch()` for flexible empty spaces.
* Use `setSizePolicy()` on widgets to control how they expand/shrink.

---

## Visual Summary

```
+----------------------------------+
| QVBoxLayout                      |
| +------------------------------+|
| | QHBoxLayout                  ||
| | [Btn1] [Btn2]               ||
| +------------------------------+|
| | QTextEdit                   ||
| +------------------------------+|
+----------------------------------+
```

---

## Summary

| Layout      | Arrangement                | Best For              |
| ----------- | -------------------------- | --------------------- |
| QHBoxLayout | Horizontal (left to right) | Toolbars, buttons     |
| QVBoxLayout | Vertical (top to bottom)   | Stacked forms, lists  |
| QGridLayout | Grid (rows & columns)      | Complex forms, tables |
| QFormLayout | Label-field pairs          | Simple forms          |
