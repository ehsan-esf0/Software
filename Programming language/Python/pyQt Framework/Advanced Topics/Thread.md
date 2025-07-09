# 🧠 Basics of `QThread` in PyQt6

```python
from PyQt6.QtCore import QThread, pyqtSignal

class Worker(QThread):
    progress = pyqtSignal(int)
    finished = pyqtSignal()

    def run(self):
        for i in range(1, 6):
            self.sleep(1)
            self.progress.emit(i)
        self.finished.emit()
```

This `Worker` class is a custom thread that emits progress and a finished signal during a time-consuming task.

---

# ✅ Example 1: Countdown Timer with QThread

```python
import sys
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QLabel, QPushButton
from PyQt6.QtCore import QThread, pyqtSignal
import time

class CountdownThread(QThread):
    progress = pyqtSignal(int)

    def run(self):
        for i in range(10, 0, -1):
            time.sleep(1)
            self.progress.emit(i)

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Countdown Example")
        self.label = QLabel("Not started")
        self.button = QPushButton("Start")

        layout = QVBoxLayout()
        layout.addWidget(self.label)
        layout.addWidget(self.button)
        self.setLayout(layout)

        self.button.clicked.connect(self.start_countdown)

    def start_countdown(self):
        self.thread = CountdownThread()
        self.thread.progress.connect(self.update_label)
        self.thread.start()

    def update_label(self, number):
        self.label.setText(f"Remaining: {number}")

app = QApplication(sys.argv)
window = MainWindow()
window.show()
sys.exit(app.exec())
```

---

# ✅ Example 2: File Processing with QThread

```python
class FileReaderThread(QThread):
    progress = pyqtSignal(int)

    def __init__(self, filepath):
        super().__init__()
        self.filepath = filepath

    def run(self):
        with open(self.filepath, 'r', encoding='utf-8') as f:
            for i, _ in enumerate(f, 1):
                if i % 100 == 0:
                    self.progress.emit(i)
                time.sleep(0.01)  # Simulate processing time
```

---

# ✅ Example 3: Downloading Multiple Files with QThreadPool

```python
from PyQt6.QtCore import QRunnable, QThreadPool
import requests

class Downloader(QRunnable):
    def __init__(self, url, filename):
        super().__init__()
        self.url = url
        self.filename = filename

    def run(self):
        r = requests.get(self.url)
        with open(self.filename, 'wb') as f:
            f.write(r.content)
        print(f"Downloaded: {self.filename}")

# Usage
pool = QThreadPool()
pool.start(Downloader("https://example.com/file1.jpg", "file1.jpg"))
pool.start(Downloader("https://example.com/file2.jpg", "file2.jpg"))
```

---

# ✅ Example 4: Real-Time Clock Thread

```python
class TimerThread(QThread):
    tick = pyqtSignal(str)

    def run(self):
        while True:
            now = time.strftime("%H:%M:%S")
            self.tick.emit(now)
            time.sleep(1)
```

---

# ✅ Example 5: Concurrent Factorial Calculations

```python
class FactorialWorker(QThread):
    result = pyqtSignal(int, int)  # (n, factorial)

    def __init__(self, n):
        super().__init__()
        self.n = n

    def run(self):
        f = 1
        for i in range(1, self.n + 1):
            f *= i
            time.sleep(0.1)
        self.result.emit(self.n, f)
```

And in your GUI:

```python
self.worker = FactorialWorker(6)
self.worker.result.connect(lambda n, r: print(f"{n}! = {r}"))
self.worker.start()
```

---

# 🔒 Using QMutex for Thread-Safe Shared Resources

```python
from PyQt6.QtCore import QMutex

mutex = QMutex()

class SafeWorker(QThread):
    def run(self):
        mutex.lock()
        # Access shared data here
        mutex.unlock()
```

---

# 📌 Advanced Tips:

| Feature                         | Description                                                      |
| ------------------------------- | ---------------------------------------------------------------- |
| `thread.quit()`                 | Gracefully stop a thread                                         |
| `thread.wait()`                 | Wait for thread to finish                                        |
| `isRunning()`                   | Check if the thread is active                                    |
| `moveToThread()`                | Move QObject to another thread                                   |
| `QObject.moveToThread(QThread)` | Useful for moving objects to threads without subclassing QThread |

---
