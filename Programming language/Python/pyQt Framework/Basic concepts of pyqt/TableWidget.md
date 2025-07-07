## What is QTableWidget?

**QTableWidget** is a widget in PyQt6 that provides a table view similar to a spreadsheet or Excel. It allows you to display and edit tabular data with rows and columns, and each cell can contain text, widgets, checkboxes, etc. Unlike **QTableView**, which is model/view-based, **QTableWidget** is simpler to use for static or moderate-sized tables.

---

## 1. Importing QTableWidget

```python
from PyQt6.QtWidgets import QTableWidget, QTableWidgetItem
```

---

## 2. Basic Usage

Here’s how to create a simple table with 3 rows and 2 columns:

```python
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QTableWidget, QTableWidgetItem

class MyWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("QTableWidget Example")

        layout = QVBoxLayout()
        self.table = QTableWidget(3, 2, self)  # 3 rows, 2 columns
        self.table.setHorizontalHeaderLabels(["Name", "Age"])

        # Fill the table
        self.table.setItem(0, 0, QTableWidgetItem("Alice"))
        self.table.setItem(0, 1, QTableWidgetItem("25"))
        self.table.setItem(1, 0, QTableWidgetItem("Bob"))
        self.table.setItem(1, 1, QTableWidgetItem("30"))
        self.table.setItem(2, 0, QTableWidgetItem("Charlie"))
        self.table.setItem(2, 1, QTableWidgetItem("22"))

        layout.addWidget(self.table)
        self.setLayout(layout)

if __name__ == '__main__':
    app = QApplication([])
    window = MyWindow()
    window.show()
    app.exec()
```

---

## 3. Key Methods & Properties

* **setRowCount(rows)** and **setColumnCount(cols)**
  Change the number of rows/columns.
* **setItem(row, col, QTableWidgetItem)**
  Set the value of a cell.
* **item(row, col)**
  Get the QTableWidgetItem at (row, col).
* **setHorizontalHeaderLabels(list\_of\_strings)**
  Set column headers.
* **setVerticalHeaderLabels(list\_of\_strings)**
  Set row headers.
* **insertRow(row)** / **removeRow(row)**
  Add or remove rows dynamically.
* **insertColumn(col)** / **removeColumn(col)**
* **clear()**
  Clears the contents (but not the headers).

---

## 4. Editing and Signals

* **Item Editing:** By default, users can double-click a cell to edit it (unless the item is set as not editable).
* **Signals:**

  * `cellClicked(row, col)`
  * `cellChanged(row, col)`
  * `itemChanged(item)`

Example of connecting to a signal:

```python
self.table.cellClicked.connect(self.on_cell_clicked)

def on_cell_clicked(self, row, column):
    item = self.table.item(row, column)
    print(f"Cell ({row}, {column}) clicked: {item.text()}")
```

---

## 5. Adding Widgets and Checkboxes

You can add widgets (like buttons or checkboxes) to cells:

```python
from PyQt6.QtWidgets import QCheckBox

checkbox = QCheckBox()
self.table.setCellWidget(0, 1, checkbox)
```

---

## 6. Selecting Rows, Columns, or Cells

* **setSelectionBehavior(QTableWidget.SelectionBehavior.SelectRows)**
* **setSelectionMode(QTableWidget.SelectionMode.SingleSelection)**

Example (select whole rows):

```python
self.table.setSelectionBehavior(QTableWidget.SelectionBehavior.SelectRows)
```

---

## 7. Example: Editable Table with Signal Handling

```python
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QTableWidget, QTableWidgetItem

class MyTable(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Editable QTableWidget")
        layout = QVBoxLayout(self)
        self.table = QTableWidget(2, 2)
        self.table.setHorizontalHeaderLabels(["Product", "Price"])
        self.table.setItem(0, 0, QTableWidgetItem("Pen"))
        self.table.setItem(0, 1, QTableWidgetItem("5"))
        self.table.setItem(1, 0, QTableWidgetItem("Book"))
        self.table.setItem(1, 1, QTableWidgetItem("12"))
        self.table.cellChanged.connect(self.cell_changed)
        layout.addWidget(self.table)
    def cell_changed(self, row, column):
        value = self.table.item(row, column).text()
        print(f"Cell ({row},{column}) changed to: {value}")

if __name__ == "__main__":
    app = QApplication([])
    w = MyTable()
    w.show()
    app.exec()
```

---

## 8. Useful Tips

* **QTableWidgetItem**: Used for storing cell data (text, icon, tooltip, etc.).
* **Non-editable Cell**: To make a cell read-only:

  ```python
  item = QTableWidgetItem("Read-only")
  item.setFlags(item.flags() & ~Qt.ItemFlag.ItemIsEditable)
  table.setItem(0, 0, item)
  ```
* **Sorting**: Enable column sorting with:

  ```python
  table.setSortingEnabled(True)
  ```

---

## Summary

* **QTableWidget** is ideal for simple, spreadsheet-like tables.
* Cells can contain text, widgets, or checkboxes.
* Supports editing, sorting, selecting, and signals for interaction.

