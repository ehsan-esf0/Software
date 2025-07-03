# QTime & QTimer in PyQt6

---

## 🔹 Part 1: `QTime` – Time Management

### 📌 What is QTime?

`QTime` represents **a specific time of day** (hours, minutes, seconds, milliseconds).
It does **not** include date information — it's purely for time.

---

### 🧱 Creating a Time

```python
from PyQt6.QtCore import QTime

time = QTime(14, 30, 0)  # 2:30:00 PM
```

---

### 🧠 Common QTime Methods

| Method                               | Description                    |
| ------------------------------------ | ------------------------------ |
| `QTime(h, m, s=0, ms=0)`             | Create a time                  |
| `currentTime()`                      | Get current system time        |
| `hour(), minute(), second(), msec()` | Get parts of time              |
| `toString(format)`                   | Format time as a string        |
| `addSecs(n)`                         | Add seconds                    |
| `addMSecs(n)`                        | Add milliseconds               |
| `secsTo(other)`                      | Get seconds between two QTimes |
| `isValid()`                          | Check if time is valid         |

---

### 📌 Example

```python
from PyQt6.QtCore import QTime

now = QTime.currentTime()
print("Now:", now.toString("HH:mm:ss"))

after = now.addSecs(3600)
print("One hour later:", after.toString("HH:mm:ss"))

diff = now.secsTo(after)
print("Difference in seconds:", diff)
```

---

## 🔹 Part 2: `QTimer` – Repeated or Delayed Execution

### 📌 What is QTimer?

`QTimer` is used to **run a function periodically or after a delay**.
Use it for:

* Repeating actions (like a live clock),
* Single-shot executions (like a delayed message).

---

### 🧪 Basic Usage

```python
from PyQt6.QtCore import QTimer

timer = QTimer()
timer.timeout.connect(my_function)
timer.start(1000)  # Fires every 1000 ms (1 second)
```

---

### 🧠 Common QTimer Methods

| Method                | Description                       |
| --------------------- | --------------------------------- |
| `start(ms)`           | Start the timer with interval     |
| `stop()`              | Stop the timer                    |
| `isActive()`          | Check if it's running             |
| `setInterval(ms)`     | Change interval                   |
| `timeout` (signal)    | Signal triggered on each interval |
| `setSingleShot(True)` | Run only once                     |

---

### 🔁 One-time Delayed Execution

```python
from PyQt6.QtCore import QTimer

QTimer.singleShot(3000, lambda: print("Executed after 3 seconds"))
```

---

## ⏰ Full Example: Live Digital Clock

```python
from PyQt6.QtWidgets import QApplication, QWidget, QLabel, QVBoxLayout
from PyQt6.QtCore import QTimer, QTime
import sys

class DigitalClock(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Live Clock")
        self.label = QLabel()

        layout = QVBoxLayout()
        layout.addWidget(self.label)
        self.setLayout(layout)

        self.timer = QTimer()
        self.timer.timeout.connect(self.update_time)
        self.timer.start(1000)

        self.update_time()

    def update_time(self):
        now = QTime.currentTime()
        self.label.setText(now.toString("HH:mm:ss"))

app = QApplication(sys.argv)
window = DigitalClock()
window.show()
sys.exit(app.exec())
```

---

## 🎯 Real Use Cases for QTimer

| Use Case        | Description                              |
| --------------- | ---------------------------------------- |
| Live Clock      | Combine `QTime` + `QTimer`               |
| Countdown Timer | Decrease seconds and update label        |
| Stopwatch       | Increase time every second               |
| Auto-refresh    | Periodically update data or UI           |
| Animations      | Step through animation frames with delay |

---

## 🔥 Advanced Example: Countdown Timer

```python
from PyQt6.QtWidgets import QWidget, QLabel, QVBoxLayout, QApplication
from PyQt6.QtCore import QTimer
import sys

class Countdown(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Countdown")
        self.label = QLabel()
        self.seconds = 10

        layout = QVBoxLayout()
        layout.addWidget(self.label)
        self.setLayout(layout)

        self.timer = QTimer()
        self.timer.timeout.connect(self.update)
        self.timer.start(1000)

        self.update()

    def update(self):
        self.label.setText(f"{self.seconds} seconds remaining")
        self.seconds -= 1
        if self.seconds < 0:
            self.timer.stop()
            self.label.setText("Time's up!")

app = QApplication(sys.argv)
w = Countdown()
w.show()
sys.exit(app.exec())
```

---

## 🧠 Summary

### ✅ Use `QTime` to:

* Get current system time
* Format or display time
* Do time arithmetic (add, subtract, compare)

### ✅ Use `QTimer` to:

* Run code at intervals
* Create clocks, countdowns, or delayed actions
* Handle repeating tasks like auto-save, polling, etc.
