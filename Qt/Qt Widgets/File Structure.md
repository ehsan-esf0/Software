# 🎓 **Qt Project File Structure **

---

## 📁 `.pro` File (Project Configuration)

```pro
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyApp
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp

HEADERS += mainwindow.h
FORMS   += mainwindow.ui
```

🔹 **Purpose:** Configures build options and lists all source/UI files.
🔹 **Used by:** `qmake` to generate `Makefile`.

---

## 🧠 `main.cpp` — Application Entry Point

```cpp
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
```

🔹 **Creates Qt application object**
🔹 **Instantiates and shows MainWindow**
🔹 **Starts the event loop**

---

## 🧱 `mainwindow.h` — Class Declaration

```cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui; // Pointer to UI class generated from .ui file
};

#endif // MAINWINDOW_H
```

🎯 **Key Concepts:**

| Component                            | Meaning                                        |
| ------------------------------------ | ---------------------------------------------- |
| `namespace Ui { class MainWindow; }` | Forward declaration of auto-generated UI class |
| `Ui::MainWindow *ui;`                | Pointer to UI elements                         |
| `Q_OBJECT`                           | Enables signals/slots in Qt                    |

---

## ⚙️ `mainwindow.cpp` — Class Implementation

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}
```

🔹 **`ui->setupUi(this)`** loads all widgets designed in `mainwindow.ui`
🔹 **Constructor** connects logic to the GUI
🔹 **Destructor** safely deletes the UI pointer

---

## 🧩 `mainwindow.ui` — The GUI Design File

🛠️ Created with Qt Designer. It’s an XML file.

➡️ Auto-translated into a C++ class:

```cpp
namespace Ui {
    class MainWindow {
        void setupUi(QMainWindow *MainWindow);
        // Other widgets: QPushButton *button1, QLabel *label1, ...
    };
}
```

Used in your `mainwindow.cpp` via:

```cpp
ui->setupUi(this);
```

---

## 🧵 Flow Overview

```plaintext
main.cpp
  └── creates QApplication
      └── shows MainWindow

mainwindow.h
  └── declares MainWindow class
      └── includes pointer to Ui::MainWindow

mainwindow.cpp
  └── sets up UI via setupUi()

mainwindow.ui
  └── created via Qt Designer
      └── compiled to ui_mainwindow.h
```

---
