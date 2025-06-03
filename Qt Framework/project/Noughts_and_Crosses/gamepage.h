#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include "labelgame.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class GamePage;
}
QT_END_NAMESPACE

class GamePage : public QMainWindow
{
    Q_OBJECT

public:
    GamePage(QWidget *parent = nullptr);
    bool checkGame( char& wp );
    bool checkGameFull();
    void clearMap();
    void createLable(QString Style);
    ~GamePage();

private:
    Ui::GamePage *ui;
    LabelGame ***home;
    QLabel *resultsBoard;
    int playerX;
    int playerO;
};
#endif // GAMEPAGE_H
