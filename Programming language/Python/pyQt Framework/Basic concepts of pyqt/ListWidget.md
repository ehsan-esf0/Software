## **QListWidget in Qt 6 Python**

### **What is QListWidget?**

`QListWidget` is a convenient widget to display a list of items, each managed as a `QListWidgetItem`.
It allows you to easily add, remove, or edit items, and is great for displaying names, files, to-dos, etc.

---

### **1. Basic Example**

```python
from PySide6.QtWidgets import QApplication, QWidget, QListWidget, QVBoxLayout

app = QApplication([])

window = QWidget()
layout = QVBoxLayout(window)

list_widget = QListWidget()
layout.addWidget(list_widget)

# Add items
list_widget.addItem("First Item")
list_widget.addItem("Second Item")
list_widget.addItem("Third Item")

window.show()
app.exec()
```

---

### **2. Adding, Removing, Editing Items**

**Add item:**

```python
list_widget.addItem("New Item")
from PySide6.QtWidgets import QListWidgetItem
item = QListWidgetItem("Special Item")
list_widget.addItem(item)
```

**Remove item:**

```python
list_widget.takeItem(1)  # Remove second item (index starts at 0)
list_widget.clear()  # Remove all items
```

**Edit item:**

```python
item = list_widget.item(0)
item.setText("Changed Item")
```

---

### **3. Reacting to Item Selection (Signals)**

**On item click:**

```python
def on_item_clicked(item):
    print("Clicked:", item.text())

list_widget.itemClicked.connect(on_item_clicked)
```

**Get current selected item:**

```python
selected_item = list_widget.currentItem()
if selected_item:
    print("Selected:", selected_item.text())
```

---

### **4. Multi-Selection**

```python
from PySide6.QtWidgets import QAbstractItemView
list_widget.setSelectionMode(QAbstractItemView.MultiSelection)
```

* Now users can select multiple items.
* Get selected items:

```python
selected_items = list_widget.selectedItems()
for item in selected_items:
    print(item.text())
```

---

### **5. Customize Item Appearance**

Each `QListWidgetItem` can have an icon, background color, foreground color, etc.:

```python
from PySide6.QtGui import QIcon, QColor

item = QListWidgetItem("With icon and color")
item.setIcon(QIcon("icon.png"))
item.setBackground(QColor("yellow"))
item.setForeground(QColor("blue"))
list_widget.addItem(item)
```

---

### **6. Drag & Drop Reordering**

```python
list_widget.setDragDropMode(QListWidget.InternalMove)
```

* Now users can reorder items by dragging.

---

### **7. Find Item by Text**

```python
items = list_widget.findItems("Second Item", Qt.MatchExactly)
for item in items:
    print("Found:", item.text())
```

Import `Qt`:

```python
from PySide6.QtCore import Qt
```

---

### **8. Extra Tips**

* **Disable item:**

  ```python
  item.setFlags(item.flags() & ~Qt.ItemIsEnabled)
  ```
* **Tooltip:**

  ```python
  item.setToolTip("More info about this item")
  ```

---

### **9. Important Signals of QListWidget**

* `itemClicked(QListWidgetItem*)` — when an item is clicked
* `itemDoubleClicked(QListWidgetItem*)` — double click
* `currentItemChanged(current, previous)` — current item changes
* `itemSelectionChanged()` — selection changes

---

### **10. Combined Practical Example**

```python
from PySide6.QtWidgets import QApplication, QWidget, QVBoxLayout, QListWidget, QPushButton

class MyWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.list_widget = QListWidget()
        for i in range(1, 6):
            self.list_widget.addItem(f"Item {i}")
        self.list_widget.itemClicked.connect(self.show_item)
        self.btn_remove = QPushButton("Remove selected item")
        self.btn_remove.clicked.connect(self.remove_selected)
        layout = QVBoxLayout(self)
        layout.addWidget(self.list_widget)
        layout.addWidget(self.btn_remove)
    
    def show_item(self, item):
        print("Clicked:", item.text())

    def remove_selected(self):
        item = self.list_widget.currentItem()
        if item:
            self.list_widget.takeItem(self.list_widget.currentRow())

app = QApplication([])
window = MyWindow()
window.show()
app.exec()
```
