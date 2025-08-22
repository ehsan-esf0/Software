/********************************************************************************
** Form generated from reading UI file 'gamepage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPAGE_H
#define UI_GAMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePage
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GamePage)
    {
        if (GamePage->objectName().isEmpty())
            GamePage->setObjectName("GamePage");
        GamePage->resize(500, 500);
        GamePage->setStyleSheet(QString::fromUtf8("background-color:#1c1c1c;"));
        centralwidget = new QWidget(GamePage);
        centralwidget->setObjectName("centralwidget");
        GamePage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GamePage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 25));
        GamePage->setMenuBar(menubar);
        statusbar = new QStatusBar(GamePage);
        statusbar->setObjectName("statusbar");
        GamePage->setStatusBar(statusbar);

        retranslateUi(GamePage);

        QMetaObject::connectSlotsByName(GamePage);
    } // setupUi

    void retranslateUi(QMainWindow *GamePage)
    {
        GamePage->setWindowTitle(QCoreApplication::translate("GamePage", "GamePage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GamePage: public Ui_GamePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
