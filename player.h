#ifndef PLAYER_H
#define PLAYER_H

#include <QPixmap>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <player2.h>
#include <QKeyEvent>
#include "tile.h"


class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit Player( int character1,int map, QGraphicsItem *parent = 0);
    ~Player();

    float i;
    float j;

    Tile*** tiles;

    Player2 *player2;

    QTimer *player1_TimerW;
    QTimer *player1_TimerA;
    QTimer *player1_TimerS;
    QTimer *player1_TimerD;

    QTimer *player2_Timer8;
    QTimer *player2_Timer4;
    QTimer *player2_Timer5;
    QTimer *player2_Timer6;

    void createMap1();
    void createMap2();
    void createTiles(int map);

protected:

void keyPressEvent(QKeyEvent *event);

private slots:

     void player1_ActionW();
     void player1_ActionS();
     void player1_ActionA();
     void player1_ActionD();

     void player2_Action8();
     void player2_Action5();
     void player2_Action4();
     void player2_Action6();

private:
    QString player1_Img[8];

    bool moveVertical;
    bool moveHorizontal;
    bool moveVertical2;
    bool moveHorizontal2;



    QString tile_Img[5];


};

#endif // PLAYER_H
