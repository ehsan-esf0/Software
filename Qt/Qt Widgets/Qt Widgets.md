# 🌟 Qt Widgets

---

## 1. QPushButton — **Push Button**

* **Description:** A clickable button to trigger actions.
* **Use Cases:** Trigger commands, toggle states.
* **Key Methods & Signals:**

| Method / Signal            | Description                               |
| -------------------------- | ----------------------------------------- |
| `setText(const QString &)` | Set button text                           |
| `text()`                   | Get button text                           |
| `setEnabled(bool)`         | Enable or disable the button              |
| `clicked()` (signal)       | Emitted when button is clicked            |
| `pressed()` (signal)       | Emitted when button is pressed            |
| `released()` (signal)      | Emitted when button is released           |
| `setCheckable(bool)`       | Make button checkable (toggle)            |
| `isChecked()`              | Check if button is checked (toggle state) |

---

## 2. QLabel — **Label**

* **Description:** Displays non-editable text or images.
* **Use Cases:** Titles, descriptions, icons.
* **Key Methods:**

| Method                        | Description             |
| ----------------------------- | ----------------------- |
| `setText(const QString &)`    | Set displayed text      |
| `text()`                      | Get current text        |
| `setPixmap(const QPixmap &)`  | Set an image            |
| `pixmap()`                    | Get the displayed image |
| `setAlignment(Qt::Alignment)` | Align text or image     |
| `setWordWrap(bool)`           | Enable text wrapping    |

---

## 3. QLineEdit — **Single-line Text Input**

* **Description:** Editable single-line text field.
* **Use Cases:** Username, email, password input.
* **Key Methods & Signals:**

| Method / Signal                         | Description                    |
| --------------------------------------- | ------------------------------ |
| `setText(const QString &)`              | Set text                       |
| `text()`                                | Get current text               |
| `setPlaceholderText(const QString &)`   | Set hint text                  |
| `clear()`                               | Clear text                     |
| `setEchoMode(QLineEdit::EchoMode)`      | Display mode (normal/password) |
| `editingFinished()` (signal)            | Editing finished by user       |
| `textChanged(const QString &)` (signal) | Text is being edited           |

---

## 4. QTextEdit — **Multi-line Text Input**

* **Description:** Editable multi-line rich text editor.
* **Use Cases:** Comments, long notes, text editing.
* **Key Methods & Signals:**

| Method / Signal            | Description          |
| -------------------------- | -------------------- |
| `setText(const QString &)` | Set text             |
| `toPlainText()`            | Get plain text       |
| `append(const QString &)`  | Append text          |
| `clear()`                  | Clear all text       |
| `setReadOnly(bool)`        | Set read-only mode   |
| `textChanged()` (signal)   | Text content changed |

---

## 5. QComboBox — **Drop-down List**

* **Description:** Dropdown menu to select from list.
* **Use Cases:** Language, theme, options.
* **Key Methods & Signals:**

| Method / Signal                     | Description          |
| ----------------------------------- | -------------------- |
| `addItem(const QString &)`          | Add one item         |
| `addItems(const QStringList &)`     | Add multiple items   |
| `currentIndex()`                    | Get selected index   |
| `setCurrentIndex(int)`              | Set selected index   |
| `currentText()`                     | Get selected text    |
| `clear()`                           | Remove all items     |
| `activated(int)` (signal)           | User selects an item |
| `currentIndexChanged(int)` (signal) | Selection changed    |

---

## 6. QListWidget — **List Widget**

* **Description:** Selectable list of items.
* **Use Cases:** File lists, options, selections.
* **Key Methods & Signals:**

| Method / Signal                           | Description               |
| ----------------------------------------- | ------------------------- |
| `addItem(const QString &)`                | Add an item               |
| `takeItem(int)`                           | Remove item               |
| `currentItem()`                           | Get current selected item |
| `currentRow()`                            | Get selected row index    |
| `clear()`                                 | Clear all items           |
| `itemClicked(QListWidgetItem *)` (signal) | Item clicked              |

---

## 7. QCheckBox — **Checkbox**

* **Description:** Toggleable box for on/off states.
* **Use Cases:** Settings, preferences.
* **Key Methods & Signals:**

| Method / Signal          | Description          |
| ------------------------ | -------------------- |
| `setChecked(bool)`       | Set check state      |
| `isChecked()`            | Get check state      |
| `toggled(bool)` (signal) | State changed signal |

---

# Example Usage

```cpp
QPushButton *button = new QPushButton("Click me");
connect(button, &QPushButton::clicked, []() {
    qDebug() << "Button clicked!";
});
```

---

# Visual Layout

```
+-------------------------+
| Widget Box (Toolbox)    |
+-------------------------+
| Form Editor (Design)    |
+-------------------------+
| Properties Editor       |
+-------------------------+
| Signal/Slot Editor      |
+-------------------------+
```

