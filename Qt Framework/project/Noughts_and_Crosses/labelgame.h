#ifndef LABELGAME_H
#define LABELGAME_H

#include <QLabel>

class LabelGame : public QLabel
{
    Q_OBJECT
public:
    LabelGame(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
private:

signals:
    void clicked();
};

#endif // LABELGAME_H
