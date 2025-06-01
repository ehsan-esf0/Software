```
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>

class MyWindow : public QWidget {
    Q_OBJECT
public:
    MyWindow() {
        button = new QPushButton("Button");
        label = new QLabel("Label");
        lineEdit = new QLineEdit();

        button->setObjectName("myButton");
        label->setObjectName("myLabel");
        lineEdit->setObjectName("myLineEdit");

        button->installEventFilter(this);
        label->installEventFilter(this);
        lineEdit->installEventFilter(this);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(button);
        layout->addWidget(label);
        layout->addWidget(lineEdit);
        setLayout(layout);
    }

protected:
    bool eventFilter(QObject *watched, QEvent *event) override {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            QString className = watched->metaObject()->className();
            QString objectName = watched->objectName();

            qDebug() << "Clicked object name:" << objectName << ", class:" << className;
            qDebug() << "Click position:" << mouseEvent->pos();

            if (className == "QPushButton") {
                qDebug() << "Button clicked!";
            } else if (className == "QLabel") {
                qDebug() << "Label clicked!";
            } else if (className == "QLineEdit") {
                qDebug() << "Line edit clicked!";
            }
        }
        return QWidget::eventFilter(watched, event);
    }

private:
    QPushButton *button;
    QLabel *label;
    QLineEdit *lineEdit;
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MyWindow w;
    w.show();
    return a.exec();
}

#include "main.moc"
```