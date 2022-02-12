#ifndef PLAYER2_H
#define PLAYER2_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Player2 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit Player2(int character2,QGraphicsItem *parent = 0);
    ~Player2();
    QString player2_Img[8];

    float i;
    float j;


private:


};

#endif // PLAYER2_H
