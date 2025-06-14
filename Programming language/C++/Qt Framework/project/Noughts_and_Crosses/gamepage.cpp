#include "gamepage.h"
#include "ui_gamepage.h"
#include "labelgame.h"
#include <iostream>

GamePage::GamePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GamePage)
{
    ui->setupUi(this);

    QString styleSheet = R"(
    QLabel {
        background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,
                                          stop:0 #ffffff, stop:1 #dcdcdc);
        border: 2px solid #444;
        border-radius: 12px;
        font-size: 42px;
        font-weight: 600;
        color: #2c3e50;
        min-width: 80px;
        min-height: 80px;
        margin: 4px;
        padding: 10px;
        qproperty-alignment: AlignCenter;
        box-shadow: 0px 4px 8px rgba(0,0,0,0.2);
        transition: all 0.3s ease;
    }

    QLabel:hover {
        background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,
                                          stop:0 #f0f0f0, stop:1 #bfbfbf);
        border: 2px solid #555;
    }

    QLabel:pressed {
        background-color: #aaa;
    }

    QLabel[player="X"] {
        color: #e74c3c;
        text-shadow: 1px 1px 2px #000;
    }

    QLabel[player="O"] {
        color: #3498db;
        text-shadow: 1px 1px 2px #000;
    }

    QLabel[winner="true"] {
        background-color: #fdf5c9;
        border: 2px solid #f1c40f;
        box-shadow: 0 0 12px #f1c40f;
        font-size: 48px;
    }
    )";

    QString resultLabelStyle = R"(
    QLabel {
        background-color: #2ecc71;
        color: white;
        font-size: 32px;
        font-weight: bold;
        border: 3px solid #27ae60;
        border-radius: 15px;
        padding: 10px 10px;
        margin: 20px;
        qproperty-alignment: AlignCenter;
        box-shadow: 0px 8px 20px rgba(0,0,0,0.3);
    }

    QLabel[status="draw"] {
        background-color: #95a5a6;
        border-color: #7f8c8d;
    }

    QLabel[status="winnerX"] {
        background-color: #e74c3c;
        border-color: #c0392b;
    }

    QLabel[status="winnerO"] {
        background-color: #3498db;
        border-color: #2980b9;
    }
    )";

    playerX = 0;
    playerO = 0;
    char winPlayer = 'a';
    bool check = true;

    createLable(resultLabelStyle);

    home = new LabelGame**[3];
    for ( int i = 0 ; i < 3 ; i++ ){
        home[i] = new LabelGame*[3];
        for ( int j = 0 ; j < 3; j++ )
        {
            home[i][j] = new LabelGame(this);
            home[i][j]->setStyleSheet(styleSheet);
            home[i][j]->move(i*120 + 75 , j*120 + 100);
            home[i][j]->show();
            connect( home[i][j] , &LabelGame::clicked , this , [&](){
                LabelGame *lbl = qobject_cast<LabelGame*>(sender());
                if ( check == true ){
                    lbl->setText("X");
                    check = false;
                }else {
                    lbl->setText("O");
                    check = true;
                }

                if (checkGame( winPlayer )){
                    if ( winPlayer == 'X' ){
                        playerX += 1;
                    }else {
                        playerO += 1;
                    }
                    resultsBoard->setText(QString("X = %1 | O = %2").arg(playerX).arg(playerO));

                    // ❌ Problem 1: The memory of home[i][j] is not contiguous
                    // ❌ Problem 2: LabelGame is a complex class

                    // LabelGame* ptr = home[0][0];

                    // for (int i = 0; i < 3 * 3; ++i) {
                    //     (ptr + i)->setText("");
                    // }

                    clearMap();
                }else {
                    if (!checkGameFull()){
                        clearMap();
                    }
                }
            });
        }
    }
}

void GamePage::createLable(QString Style){
    resultsBoard = new QLabel(this);
    resultsBoard->setStyleSheet(Style);
    resultsBoard->move(100 , 0);
    resultsBoard->setFixedSize(300,100);
    resultsBoard->setText("X = 0 | O = 0");
}

void GamePage::clearMap(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            home[i][j]->setText("");
        }
    }
}

bool GamePage::checkGame( char& wp ){

    char player[2] = { 'X' , 'O' };
    for ( char p : player ){
        for (int i = 0; i < 3; ++i) {
            if ( home[0][i]->text() == p && home[1][i]->text() == p && home[2][i]->text() == p){
                wp = p;
                return true;
            }

            if ( home[i][0]->text() == p && home[i][1]->text() == p && home[i][2]->text() == p){
                wp = p;
                return true;
            }

        }
        if ( home[0][0]->text() == p && home[1][1]->text() == p && home[2][2]->text() == p){
            wp = p;
            return true;
        }
    }
    return false;
}

bool GamePage::checkGameFull(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ( home[i][j]->text() != 'X' && home[i][j]->text() != 'O' )
            {
                return true;
            }
        }
    }
    return false;
}

GamePage::~GamePage()
{
    delete ui;
}
