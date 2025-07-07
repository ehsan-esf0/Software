## What is QCalendarWidget?

**QCalendarWidget** is a built-in widget in PyQt6 that displays a monthly calendar. It allows users to select dates and navigate between months and years easily. It’s very useful for date picking (for example: choosing a birthday, scheduling, etc).

---

## 1. Importing QCalendarWidget

```python
from PyQt6.QtWidgets import QCalendarWidget
```

---

## 2. Basic Usage

Here’s a simple example of how to add a calendar widget to your window and respond to date selection:

```python
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QCalendarWidget, QLabel

class MyWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("QCalendarWidget Example")
        layout = QVBoxLayout(self)
        
        self.calendar = QCalendarWidget(self)
        self.calendar.selectionChanged.connect(self.on_date_selected)
        
        self.label = QLabel("Selected date will appear here", self)
        
        layout.addWidget(self.calendar)
        layout.addWidget(self.label)
    
    def on_date_selected(self):
        date = self.calendar.selectedDate()  # returns a QDate object
        self.label.setText(f"Selected Date: {date.toString('yyyy-MM-dd')}")

if __name__ == "__main__":
    app = QApplication([])
    window = MyWindow()
    window.show()
    app.exec()
```

---

## 3. Key Methods & Properties

* **selectedDate()**
  Returns the currently selected date as a `QDate` object.
* **setSelectedDate(QDate)**
  Programmatically selects a date on the calendar.
* **setMinimumDate(QDate)** and **setMaximumDate(QDate)**
  Limit selectable dates.
* **setGridVisible(True/False)**
  Show or hide grid lines on the calendar.
* **setFirstDayOfWeek(Qt.DayOfWeek)**
  Set which day is the start of the week (e.g., Monday or Sunday).
* **setLocale(QLocale)**
  Change the language/region of the calendar.

Example: Setting minimum and maximum selectable dates

```python
from PyQt6.QtCore import QDate
self.calendar.setMinimumDate(QDate.currentDate().addDays(-30))
self.calendar.setMaximumDate(QDate.currentDate().addDays(30))
```

---

## 4. Signals

* **selectionChanged**
  Emitted whenever the user selects a new date.
* **activated\[QDate]**
  Emitted when the user double-clicks or presses Enter on a date.
* **clicked\[QDate]**
  Emitted when the user clicks on a date.

Example:

```python
self.calendar.clicked.connect(self.on_date_clicked)

def on_date_clicked(self, date):
    print("Clicked date:", date.toString())
```

---

## 5. Customizing Appearance

* **setGridVisible(True)**
  Shows grid lines between days.
* **setVerticalHeaderFormat()** and **setHorizontalHeaderFormat()**
  Change how days and weeks are displayed.
* **setNavigationBarVisible(False)**
  Hide or show the month/year navigation bar.

---

## 6. Example: Restrict to Current Year

```python
from PyQt6.QtCore import QDate
year = QDate.currentDate().year()
start = QDate(year, 1, 1)
end = QDate(year, 12, 31)
self.calendar.setMinimumDate(start)
self.calendar.setMaximumDate(end)
```

---

## 7. Full Example: Date Picker

```python
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QCalendarWidget, QPushButton, QLabel
from PyQt6.QtCore import QDate

class DatePickerDemo(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Date Picker Example")
        layout = QVBoxLayout(self)
        
        self.calendar = QCalendarWidget()
        self.label = QLabel("No date selected")
        self.button = QPushButton("Get Selected Date")
        
        layout.addWidget(self.calendar)
        layout.addWidget(self.button)
        layout.addWidget(self.label)
        
        self.button.clicked.connect(self.show_date)
    
    def show_date(self):
        date = self.calendar.selectedDate()
        self.label.setText(f"Picked: {date.toString('dddd, MMMM d, yyyy')}")
        
if __name__ == "__main__":
    app = QApplication([])
    window = DatePickerDemo()
    window.show()
    app.exec()
```

---

## Summary

* **QCalendarWidget** provides an interactive calendar.
* Users can pick dates, and you can respond to selection changes with signals.
* You can set minimum/maximum selectable dates, change locale, and customize its look.