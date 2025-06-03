#include "labelgame.h"

LabelGame::LabelGame(QWidget *parent) : QLabel(parent) {}

void LabelGame::mousePressEvent(QMouseEvent *event){
    emit clicked();
}
