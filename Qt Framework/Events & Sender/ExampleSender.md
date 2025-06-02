```cpp
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>

class MyWindow : public QWidget {
    Q_OBJECT
public:
    MyWindow() {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QPushButton *button1 = new QPushButton("Button 1");
        QPushButton *button2 = new QPushButton("Button 2");

        button1->setObjectName("button1");
        button2->setObjectName("button2");

        layout->addWidget(button1);
        layout->addWidget(button2);

        connect(button1, &QPushButton::clicked, this, &MyWindow::handleButton);
        connect(button2, &QPushButton::clicked, this, &MyWindow::handleButton);
    }

public slots:
    void handleButton() {
        QObject *obj = sender();
        if (obj) {
            qDebug() << "Clicked sender object name:" << obj->objectName();
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MyWindow w;
    w.show();
    return a.exec();
}
```