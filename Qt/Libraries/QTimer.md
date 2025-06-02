# 📘 QTimer in Qt

## 1. 🔍 What is `QTimer`?

* `QTimer` is a non-blocking timer class.
* Works with Qt’s event loop.
* Sends the `timeout()` signal at specified intervals.
* Can be **repeating** or **single-shot**.

---

## 2. ⚙️ Creating a Basic Timer

```cpp
QTimer *timer = new QTimer(this);
connect(timer, &QTimer::timeout, this, []() {
    qDebug() << "Timer triggered!";
});
timer->start(1000); // Fires every 1000 milliseconds (1 second)
```

### Output:

```
Timer triggered!
Timer triggered!
...
```

---

## 3. 🔁 One-shot vs. Repeating Timers

### 🔄 Repeating Timer (default)

```cpp
timer->start(500); // fires every 500ms
```

### 🔂 One-shot Timer

```cpp
timer->setSingleShot(true);
timer->start(2000); // triggers once after 2 seconds
```

Or use `QTimer::singleShot`:

```cpp
QTimer::singleShot(3000, []() {
    qDebug() << "Executed once after 3 seconds!";
});
```

---

## 4. 📌 Important Methods and Signals

| Function              | Description                             |
| --------------------- | --------------------------------------- |
| `start(int ms)`       | Starts the timer with an interval in ms |
| `stop()`              | Stops the timer                         |
| `isActive()`          | Checks if timer is currently active     |
| `setInterval(int)`    | Changes the interval during runtime     |
| `setSingleShot(bool)` | Makes the timer fire only once          |
| `timeout()` (signal)  | Emitted each time interval expires      |
| `remainingTime()`     | Returns time left until next timeout    |

---

## 5. 📥 Connecting to Slots

Using a class with a slot method:

```cpp
class Worker : public QObject {
    Q_OBJECT

public:
    Worker() {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Worker::doWork);
        timer->start(1000);
    }

public slots:
    void doWork() {
        qDebug() << "Doing periodic work...";
    }
};
```

---

## 6. ⏱ Using `QTimer::singleShot`

### Execute lambda after delay

```cpp
QTimer::singleShot(1500, []() {
    qDebug() << "Delayed execution!";
});
```

### Execute slot method after delay

```cpp
QTimer::singleShot(1000, myObject, SLOT(onTimeout()));
```

---

## 7. 🎛 Timer Control (Start, Stop, Restart)

```cpp
timer->start(2000);       // Starts or restarts with new interval
timer->stop();            // Stops the timer
bool active = timer->isActive();
int timeLeft = timer->remainingTime();
```

---

## 8. 🧪 Real-World Examples

### Countdown Timer (stops after 5 times)

```cpp
class Countdown : public QObject {
    Q_OBJECT
    QTimer *timer;
    int count = 0;

public:
    Countdown() {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Countdown::tick);
        timer->start(1000);
    }

public slots:
    void tick() {
        count++;
        qDebug() << "Tick #" << count;
        if (count == 5) {
            timer->stop();
            qDebug() << "Countdown complete.";
        }
    }
};
```

---

## 9. ⚙️ Thread Safety and Multithreading

* `QTimer` **must be created in the same thread** where it will run.
* It relies on the event loop of that thread.
* If you move an object with a timer to a different thread, re-create the timer there.

```cpp
QThread *thread = new QThread;
Worker *worker = new Worker;
worker->moveToThread(thread);
thread->start();
```

---

## 10. 🚨 Common Pitfalls

| Problem            | Solution                                                          |
| ------------------ | ----------------------------------------------------------------- |
| Timer doesn’t fire | Ensure the object has a parent and is not deleted.                |
| No output          | Make sure the event loop is running (e.g. `QApplication::exec()`) |
| Using `sleep()`    | Avoid blocking; use timers instead                                |
| GUI freezing       | You’re likely blocking the main thread; switch to async or timers |

---
