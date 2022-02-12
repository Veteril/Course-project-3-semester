#include "player.h"
#include "mainwindow.h"
#include "palitra.h"

Player::Player( int character1 ,int map, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    if (character1 == 1) {
    player1_Img[0] = "G:/Work/Proga/Palitra/untitled/Images/role1_Up.png";
    player1_Img[1] = "G:/Work/Proga/Palitra/untitled/Images/role1_Up1.png";
    player1_Img[2] = "G:/Work/Proga/Palitra/untitled/Images/role1_Down.png";
    player1_Img[3] = "G:/Work/Proga/Palitra/untitled/Images/role1_Down1.png";
    player1_Img[4] = "G:/Work/Proga/Palitra/untitled/Images/role1_Left.png";
    player1_Img[5] = "G:/Work/Proga/Palitra/untitled/Images/role1_Left1.png";
    player1_Img[6] = "G:/Work/Proga/Palitra/untitled/Images/role1_Right.png";
    player1_Img[7] = "G:/Work/Proga/Palitra/untitled/Images/role1_Right1.png";
    }
    if (character1 == 2) {
    player1_Img[0] = "G:/Work/Proga/Palitra/untitled/Images/role1_Up2.png";
    player1_Img[1] = "G:/Work/Proga/Palitra/untitled/Images/role1_Up21.png";
    player1_Img[2] = "G:/Work/Proga/Palitra/untitled/Images/role1_Down2.png";
    player1_Img[3] = "G:/Work/Proga/Palitra/untitled/Images/role1_Down21.png";
    player1_Img[4] = "G:/Work/Proga/Palitra/untitled/Images/role1_Left2.png";
    player1_Img[5] = "G:/Work/Proga/Palitra/untitled/Images/role1_Left21.png";
    player1_Img[6] = "G:/Work/Proga/Palitra/untitled/Images/role1_Right2.png";
    player1_Img[7] = "G:/Work/Proga/Palitra/untitled/Images/role1_Right21.png";
    }

    moveVertical = true;
    moveHorizontal = true;
    moveVertical2 = true;
    moveHorizontal2 = true;

    setPixmap(QPixmap(player1_Img[2]));

    player1_TimerW = new QTimer(this);
    player1_TimerA = new QTimer(this);
    player1_TimerS = new QTimer(this);
    player1_TimerD = new QTimer(this);

    player2_Timer8 = new QTimer(this);
    player2_Timer4 = new QTimer(this);
    player2_Timer5 = new QTimer(this);
    player2_Timer6 = new QTimer(this);

    createTiles(map);
}


Player::~Player()
{
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 25; j++){
            delete[] tiles[i][j];
        }
    }
    for (int i = 0; i < 18; i++) {
        delete[] tiles[i];
    }
    delete[] tiles;

    delete[] player2;

    delete[] player1_TimerW;
    delete[] player1_TimerA;
    delete[] player1_TimerS;
    delete[] player1_TimerD;

    delete[] player2_Timer8;
    delete[] player2_Timer4;
    delete[] player2_Timer5;
    delete[] player2_Timer6;
}

void Player::createTiles(int map)
{
    tiles = new Tile**[18];
    for (int i = 0; i < 18; i++) {
        tiles[i] = new Tile*[25];
    }
    if (map == 1) {
        tile_Img[0] = "G:/Work/Proga/Palitra/untitled/Images/tile.png";
        tile_Img[1] = "G:/Work/Proga/Palitra/untitled/Images/tile_role1.png";
        tile_Img[2] = "G:/Work/Proga/Palitra/untitled/Images/tile_role2.png";
        tile_Img[3] = "G:/Work/Proga/Palitra/untitled/Images/block.png";
        tile_Img[4] = "G:/Work/Proga/Palitra/untitled/Images/special_tile.png";
    }
    if (map == 2) {
        tile_Img[0] = "G:/Work/Proga/Palitra/untitled/Images/tile2.png";
        tile_Img[1] = "G:/Work/Proga/Palitra/untitled/Images/tile_role1.png";
        tile_Img[2] = "G:/Work/Proga/Palitra/untitled/Images/tile_role2.png";
        tile_Img[3] = "G:/Work/Proga/Palitra/untitled/Images/block2.png";
        tile_Img[4] = "G:/Work/Proga/Palitra/untitled/Images/special_tile.png";
    }


}

void Player::createMap1()
{
    for (int i = 0; i < 18; ) {
        for (int j = 0; j < 25; j++) {
            if (j < 11 || j > 13) {
                tiles[i][j]->setPixmap(QPixmap(tile_Img[3]));
                tiles[i][j]->status = 3;
            }
            else {
                tiles[i][j]->setPixmap(QPixmap(tile_Img[0]));
                tiles[i][j]->specialStatus = 1;
            }
        }
        i += 17;
    }


    for (int j = 0; j < 25; ) {
        for (int i = 0; i < 18; i++) {
            if (i < 8 || i > 9) {
                tiles[i][j]->setPixmap(QPixmap(tile_Img[3]));
                tiles[i][j]->status = 3;
            }
            else{
                tiles[i][j]->setPixmap(QPixmap(tile_Img[0]));
                tiles[i][j]->specialStatus = 1;
            }
        }
        j += 24;
    }

    for (int i = 4; i < 18; ) {
        for (int j = 0; j < 25; j++) {
            if (j < 2 || j > 4 && j != 20 && j != 21 && j != 22) {
                tiles[i][j]->setPixmap(QPixmap(tile_Img[3]));
                tiles[i][j]->status = 3;
            }
            else {
                if (i < 10) {
                    tiles[i + 1][j]->setPixmap(QPixmap(tile_Img[3]));
                    tiles[i + 1][j]->status = 3;
                }
                else {
                    tiles[i - 1][j]->setPixmap(QPixmap(tile_Img[3]));
                    tiles[i - 1][j]->status = 3;
                }
            }
        }
        i += 9;
    }
    tiles[4][12]->setPixmap(QPixmap(tile_Img[0]));
    tiles[4][12]->status = 0;
    tiles[13][12]->setPixmap(QPixmap(tile_Img[0]));
    tiles[13][12]->status = 0;

    for (int i = 7; i < 18; ) {
        for (int j = 0; j < 25; j++) {
            if (j != 1 && j != 23 && j != 4 && j != 5 && j != 6 && j != 12 && j != 15 && j != 18 && j != 19 && j != 20) {
                tiles[i][j]->setPixmap(QPixmap(tile_Img[3]));
                tiles[i][j]->status = 3;
                if (j == 2 || j == 7 || j == 11 || j == 13 || j == 17 || j == 22) {
                    tiles[i + 1][j]->setPixmap(QPixmap(tile_Img[3]));
                    tiles[i + 1][j]->status = 3;
                    tiles[i + 2][j]->setPixmap(QPixmap(tile_Img[3]));
                    tiles[i + 2][j]->status = 3;
                    tiles[i + 3][j]->setPixmap(QPixmap(tile_Img[3]));
                    tiles[i + 3][j]->status = 3;
                }
                if (j == 3 || j == 8 || j == 10 || j == 14 || j == 16 || j == 21) {
                    tiles[i + 3][j]->setPixmap(QPixmap(tile_Img[3]));
                    tiles[i + 3][j]->status = 3;
                }
            }
        }
        i += 17;
    }

    for (int i = 2; i < 18; ) {
        for (int j = 0; j < 25; j++) {
            if (j > 8 && j < 16 && j != 12) {
                tiles[i][j]->setPixmap(QPixmap(tile_Img[3]));
                tiles[i][j]->status = 3;
            }
        }
        i += 13;
    }
    tiles[1][8]->setPixmap(QPixmap(tile_Img[3]));
    tiles[1][8]->status = 3;
    tiles[1][16]->setPixmap(QPixmap(tile_Img[3]));
    tiles[1][16]->status = 3;
    tiles[16][8]->setPixmap(QPixmap(tile_Img[3]));
    tiles[16][8]->status = 3;
    tiles[16][16]->setPixmap(QPixmap(tile_Img[3]));
    tiles[16][16]->status = 3;
    tiles[3][10]->setPixmap(QPixmap(tile_Img[3]));
    tiles[3][10]->status = 3;
    tiles[3][14]->setPixmap(QPixmap(tile_Img[3]));
    tiles[3][14]->status = 3;
    tiles[14][10]->setPixmap(QPixmap(tile_Img[3]));
    tiles[14][10]->status = 3;
    tiles[14][14]->setPixmap(QPixmap(tile_Img[3]));
    tiles[14][14]->status = 3;
    tiles[10][15]->setPixmap(QPixmap(tile_Img[3]));
    tiles[10][15]->status = 3;
    tiles[6][6]->setPixmap(QPixmap(tile_Img[3]));
    tiles[6][6]->status = 3;
    tiles[11][18]->setPixmap(QPixmap(tile_Img[3]));
    tiles[11][18]->status = 3;
    tiles[5][5]->setPixmap(QPixmap(tile_Img[3]));
    tiles[5][5]->status = 3;
    tiles[12][19]->setPixmap(QPixmap(tile_Img[3]));
    tiles[12][19]->status = 3;

    for (int i = 8; i < 9; i++) {
        for (int j = 3; j < 22; j++){
            if((j > 7 && j < 17 && j != 12 && j != 11 && j != 13) || j == 3 || j == 21) {
                tiles[i][j]->specialStatus = 1;
                tiles[i + 1][j]->specialStatus = 1;
            }
        }
    }

    for (int j = 12; j < 13; j++) {
        for (int i = 6; i < 12; i++) {
            tiles[i][j]->specialStatus = 1;
        }
    }








    tiles[9][4]->setPixmap(QPixmap(tile_Img[1]));
    tiles[9][4]->status = 1;

    tiles[9][20]->setPixmap(QPixmap(tile_Img[2]));
    tiles[9][20]->status = 2;

    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 25; j++) {
            if(tiles[i][j]->specialStatus == 1)
                tiles[i][j]->setPixmap((QPixmap(tile_Img[4])));
        }
    }
}

void Player::createMap2()
{
    for (int j = 7; j < 8; j++) {
        for (int i = 4; i < 16; i++){
            tiles[i][j]->setPixmap((QPixmap(tile_Img[3])));
            tiles[i][j]->status = 3;
        }
    }
    for (int j = 17; j < 18; j++) {
        for (int i = 2; i < 14; i++){
            tiles[i][j]->setPixmap((QPixmap(tile_Img[3])));
            tiles[i][j]->status = 3;
        }
    }
    for (int i = 3; i < 15; ) {
        for (int j = 8; j < 17; j ++ ) {
            if (i == 3) {
                if (j == 8 || (j > 9 && j < 15)) {
                    tiles[i][j]->setPixmap((QPixmap(tile_Img[3])));
                    tiles[i][j]->status = 3;
                }
            }
            else if (j == 16 || (j > 9 && j < 15)) {
                tiles[i][j]->setPixmap((QPixmap(tile_Img[3])));
                tiles[i][j]->status = 3;
            }
        }
        i += 11;
    }

    for (int j = 10; j < 15;) {
        for (int i = 0; i < 18; i++) {
            if (i !=2 && i !=15 && i!= 6 && i != 7 && i != 8 && i != 9 && i != 10 && i != 11) {
                tiles[i][j]->setPixmap((QPixmap(tile_Img[3])));
                tiles[i][j]->status = 3;
            }
        }
        j += 4;
    }
    tiles[0][11]->setPixmap((QPixmap(tile_Img[3])));
    tiles[0][11]->status = 3;
    tiles[0][13]->setPixmap((QPixmap(tile_Img[3])));
    tiles[0][13]->status = 3;
    tiles[1][15]->setPixmap((QPixmap(tile_Img[3])));
    tiles[1][15]->status = 3;
    tiles[1][16]->setPixmap((QPixmap(tile_Img[3])));
    tiles[1][16]->status = 3;
    tiles[2][9]->setPixmap((QPixmap(tile_Img[3])));
    tiles[2][9]->status = 3;
    tiles[6][9]->setPixmap((QPixmap(tile_Img[3])));
    tiles[6][9]->status = 3;
    tiles[7][9]->setPixmap((QPixmap(tile_Img[3])));
    tiles[7][9]->status = 3;
    tiles[8][9]->setPixmap((QPixmap(tile_Img[3])));
    tiles[8][9]->status = 3;
    tiles[9][15]->setPixmap((QPixmap(tile_Img[3])));
    tiles[9][15]->status = 3;
    tiles[10][15]->setPixmap((QPixmap(tile_Img[3])));
    tiles[10][15]->status = 3;
    tiles[11][15]->setPixmap((QPixmap(tile_Img[3])));
    tiles[11][15]->status = 3;
    tiles[15][15]->setPixmap((QPixmap(tile_Img[3])));
    tiles[15][15]->status = 3;
    tiles[6][11]->setPixmap((QPixmap(tile_Img[3])));
    tiles[6][11]->status = 3;
    tiles[6][12]->setPixmap((QPixmap(tile_Img[3])));
    tiles[6][12]->status = 3;
    tiles[7][12]->setPixmap((QPixmap(tile_Img[3])));
    tiles[7][12]->status = 3;
    tiles[8][11]->setPixmap((QPixmap(tile_Img[3])));
    tiles[8][11]->status = 3;
    tiles[9][13]->setPixmap((QPixmap(tile_Img[3])));
    tiles[9][13]->status = 3;
    tiles[10][12]->setPixmap((QPixmap(tile_Img[3])));
    tiles[10][12]->status = 3;
    tiles[11][12]->setPixmap((QPixmap(tile_Img[3])));
    tiles[11][12]->status = 3;
    tiles[11][13]->setPixmap((QPixmap(tile_Img[3])));
    tiles[11][13]->status = 3;
    tiles[17][11]->setPixmap((QPixmap(tile_Img[3])));
    tiles[17][11]->status = 3;
    tiles[17][13]->setPixmap((QPixmap(tile_Img[3])));
    tiles[17][13]->status = 3;
    tiles[16][8]->setPixmap((QPixmap(tile_Img[3])));
    tiles[16][8]->status = 3;
    tiles[16][9]->setPixmap((QPixmap(tile_Img[3])));
    tiles[16][9]->status = 3;
    tiles[1][6]->setPixmap((QPixmap(tile_Img[3])));
    tiles[1][6]->status = 3;
    tiles[1][7]->setPixmap((QPixmap(tile_Img[3])));
    tiles[1][7]->status = 3;
    tiles[1][8]->setPixmap((QPixmap(tile_Img[3])));
    tiles[1][8]->status = 3;
    tiles[1][9]->setPixmap((QPixmap(tile_Img[3])));
    tiles[1][9]->status = 3;
    tiles[0][6]->setPixmap((QPixmap(tile_Img[3])));
    tiles[0][6]->status = 3;
    tiles[0][9]->setPixmap((QPixmap(tile_Img[3])));
    tiles[0][9]->status = 3;

    tiles[4][12]->setPixmap((QPixmap(tile_Img[1])));
    tiles[4][12]->status = 1;
    tiles[13][12]->setPixmap((QPixmap(tile_Img[2])));
    tiles[13][12]->status = 2;

    for (int i = 4; i < 9; i++) {
        tiles[i][8]->specialStatus = 1;
    }
    for (int i = 9; i < 14; i++) {
        tiles[i][16]->specialStatus = 1;
    }
    tiles[3][9]->specialStatus = 1;
    tiles[4][9]->specialStatus = 1;
    tiles[5][9]->specialStatus = 1;
    tiles[12][15]->specialStatus = 1;
    tiles[13][15]->specialStatus = 1;
    tiles[14][15]->specialStatus = 1;
    tiles[0][12]->specialStatus = 1;
    tiles[1][12]->specialStatus = 1;
    tiles[16][12]->specialStatus = 1;
    tiles[17][12]->specialStatus = 1;
    tiles[1][11]->specialStatus = 1;
    tiles[4][11]->specialStatus = 1;
    tiles[5][11]->specialStatus = 1;
    tiles[9][11]->specialStatus = 1;
    tiles[12][11]->specialStatus = 1;
    tiles[13][11]->specialStatus = 1;
    tiles[16][11]->specialStatus = 1;
    tiles[8][12]->specialStatus = 1;
    tiles[9][12]->specialStatus = 1;
    tiles[5][12]->specialStatus = 1;
    tiles[12][12]->specialStatus = 1;
    tiles[1][13]->specialStatus = 1;
    tiles[4][13]->specialStatus = 1;
    tiles[5][13]->specialStatus = 1;
    tiles[8][13]->specialStatus = 1;
    tiles[12][13]->specialStatus = 1;
    tiles[13][13]->specialStatus = 1;
    tiles[16][13]->specialStatus = 1;







    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 25; j++) {
            if(tiles[i][j]->specialStatus == 1)
                tiles[i][j]->setPixmap((QPixmap(tile_Img[4])));
        }
    }
}


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_W)
    {
        if(!(player1_TimerW->isActive()) && moveHorizontal) {
            if(player1_TimerS->isActive())
                player1_TimerS->stop();
            if(player1_TimerA->isActive())
                player1_TimerA->stop();
            if(player1_TimerD->isActive())
                player1_TimerD->stop();

            player1_TimerW=new QTimer(this);
            player1_TimerW->start(150);
            connect(player1_TimerW,SIGNAL(timeout()),this,SLOT(player1_ActionW()));
        }
    }
    if(event->key()==Qt::Key_S) {

        if(!(player1_TimerS->isActive()) && moveHorizontal) {
        if(player1_TimerW->isActive())
            player1_TimerW->stop();
        if(player1_TimerA->isActive())
            player1_TimerA->stop();
        if(player1_TimerD->isActive())
            player1_TimerD->stop();

        player1_TimerS=new QTimer(this);
        if(!player1_TimerS->isActive())
            player1_TimerS->start(150);
        connect(player1_TimerS,SIGNAL(timeout()),this,SLOT(player1_ActionS()));
        }
    }
    if(event->key()==Qt::Key_D) {
        if(!(player1_TimerD->isActive()) && moveVertical) {
        if(player1_TimerW->isActive())
            player1_TimerW->stop();
        if(player1_TimerS->isActive())
            player1_TimerS->stop();
        if(player1_TimerA->isActive())
            player1_TimerA->stop();

        player1_TimerD=new QTimer(this);
        if(!player1_TimerD->isActive())
            player1_TimerD->start(150);
        connect(player1_TimerD,SIGNAL(timeout()),this,SLOT(player1_ActionD()));
        }
    }
    if(event->key()==Qt::Key_A) {
        if(!(player1_TimerA->isActive()) && moveVertical) {
        if(player1_TimerW->isActive())
            player1_TimerW->stop();
        if(player1_TimerS->isActive())
            player1_TimerS->stop();
        if(player1_TimerD->isActive())
            player1_TimerD->stop();

        player1_TimerA=new QTimer(this);
        if(!player1_TimerA->isActive())
            player1_TimerA->start(150);
        connect(player1_TimerA,SIGNAL(timeout()),this,SLOT(player1_ActionA()));
        }
    }
    if(event->key()==Qt::Key_8  && moveHorizontal2) {
        if(!(player2_Timer8->isActive())) {
        if(player2_Timer4->isActive())
            player2_Timer4->stop();
        if(player2_Timer5->isActive())
            player2_Timer5->stop();
        if(player2_Timer6->isActive())
            player2_Timer6->stop();

        player2_Timer8=new QTimer(this);
        if(!player2_Timer8->isActive())
            player2_Timer8->start(150);
        connect(player2_Timer8,SIGNAL(timeout()),this,SLOT(player2_Action8()));
        }
    }
    if(event->key()==Qt::Key_5  && moveHorizontal2) {
        if(!(player2_Timer5->isActive())) {
        if(player2_Timer4->isActive())
            player2_Timer4->stop();
        if(player2_Timer8->isActive())
            player2_Timer8->stop();
        if(player2_Timer6->isActive())
            player2_Timer6->stop();

        player2_Timer5=new QTimer(this);
        if(!player2_Timer5->isActive())
            player2_Timer5->start(150);
        connect(player2_Timer5,SIGNAL(timeout()),this,SLOT(player2_Action5()));
        }
    }
    if(event->key()==Qt::Key_4 && moveVertical2) {
        if(!(player2_Timer4->isActive())) {
        if(player2_Timer8->isActive())
            player2_Timer8->stop();
        if(player2_Timer5->isActive())
            player2_Timer5->stop();
        if(player2_Timer6->isActive())
            player2_Timer6->stop();

        player2_Timer4=new QTimer(this);
        if(!player2_Timer4->isActive())
            player2_Timer4->start(150);
        connect(player2_Timer4,SIGNAL(timeout()),this,SLOT(player2_Action4()));
        }
    }

    if(event->key()==Qt::Key_6 && moveVertical2) {
        if(!(player2_Timer6->isActive())) {
        if(player2_Timer8->isActive())
            player2_Timer8->stop();
        if(player2_Timer5->isActive())
            player2_Timer5->stop();
        if(player2_Timer4->isActive())
            player2_Timer4->stop();

        player2_Timer6=new QTimer(this);
        if(!player2_Timer6->isActive())
            player2_Timer6->start(150);
        connect(player2_Timer6,SIGNAL(timeout()),this,SLOT(player2_Action6()));
        }
    }
}

void Player::player1_ActionW()
{
    if(moveVertical) {
        if (i == 0) {
            setPos(x() ,y() + 700);
            i = 17.5;
            setPixmap(QPixmap(player1_Img[0]));
            moveVertical = false;
            return;
        }
        if (tiles[int(i-1)][int(j)]->status == 3)
            return;
        setPixmap(QPixmap(player1_Img[0]));
        moveVertical = false;
        i -= 0.5;
    }
    else {

        tiles[int(i)][int(j)]->setPixmap(QPixmap(tile_Img[1]));
        tiles[int(i)][int(j)]->status = 1;
        setPixmap(QPixmap(player1_Img[1]));
        moveVertical = true;
        i -= 0.5;
    }
    setPos(x(),y()-20);
}

void Player::player1_ActionS()
{
    if(moveVertical) {
        if (i == 17) {
            setPos(x() ,y() - 700);
            i = -0.5;
            setPixmap(QPixmap(player1_Img[2]));
            moveVertical = false;
            return;
        }
        if (tiles[int(i+1)][int(j)]->status == 3)
            return;
        setPixmap(QPixmap(player1_Img[2]));
        moveVertical = false;
        i += 0.5;
    }
    else {
        tiles[int(i+1)][int(j)]->setPixmap(QPixmap(tile_Img[1]));
        tiles[int(i+1)][int(j)]->status = 1;
        setPixmap(QPixmap(player1_Img[3]));
        moveVertical = true;
        i += 0.5;
    }
    setPos(x(),y() + 20);
}

void Player::player1_ActionA()
{
    if(moveHorizontal) {
        if (j == 0) {
            setPos(x() + 980, y());
            j = 24.5;
            setPixmap(QPixmap(player1_Img[4]));
            moveHorizontal = false;
            return;
        }
        if (tiles[int(i)][int(j - 1)]->status == 3)
            return;
        setPixmap(QPixmap(player1_Img[4]));
        moveHorizontal = false;
        j -= 0.5;
    }
    else {
        tiles[int(i)][int(j)]->setPixmap(QPixmap(tile_Img[1]));
        tiles[int(i)][int(j)]->status = 1;
        setPixmap(QPixmap(player1_Img[5]));
        moveHorizontal = true;
        j -= 0.5;
    }
    setPos(x() - 20 ,y());
}

void Player::player1_ActionD()
{
    if(moveHorizontal) {
        if (j == 24) {
            setPos(x() - 980, y());
            j = -0.5;
            setPixmap(QPixmap(player1_Img[6]));
            moveHorizontal = false;
            return;
        }
        if (tiles[int(i)][int(j + 1)]->status == 3)
            return;
        setPixmap(QPixmap(player1_Img[6]));
        moveHorizontal = false;
        j += 0.5;
    }
    else {
        tiles[int(i)][int(j+1)]->setPixmap(QPixmap(tile_Img[1]));
        tiles[int(i)][int(j+1)]->status = 1;
        setPixmap(QPixmap(player1_Img[7]));
        moveHorizontal = true;
        j += 0.5;
    }
    setPos(x() + 20 ,y());
}

void Player::player2_Action8()
{
    if(moveVertical2) {
        if (player2->i == 0) {
            player2->setPos(player2->x() ,player2->y() + 700);
            player2->i = 17.5;
            player2->setPixmap(QPixmap(player2->player2_Img[0]));
            moveVertical2 = false;
            return;
        }

        if (tiles[int(player2->i-1)][int(player2->j)]->status == 3)
            return;
        player2->setPixmap(QPixmap(player2->player2_Img[0]));
        moveVertical2 = false;
        player2->i -= 0.5;
    }
    else {
        tiles[int(player2->i)][int(player2->j)]->setPixmap(QPixmap(tile_Img[2]));
        tiles[int(player2->i)][int(player2->j)]->status = 2;
        player2->setPixmap(QPixmap(player2->player2_Img[1]));
        moveVertical2 = true;
        player2->i -= 0.5;
    }
    player2->setPos(player2->x() ,player2->y() - 20);
}

void Player::player2_Action5()
{
    if(moveVertical2) {
        if (player2->i == 17) {
            player2->setPos(player2->x() ,player2->y() - 700);
            player2->i = -0.5;
            player2->setPixmap(QPixmap(player2->player2_Img[2]));
            moveVertical2 = false;
            return;
        }
        if (tiles[int(player2->i+1)][int(player2->j)]->status == 3)
            return;
        player2->setPixmap(QPixmap(player2->player2_Img[2]));
        moveVertical2 = false;
        player2->i += 0.5;
    }
    else {
        tiles[int(player2->i + 1)][int(player2->j)]->setPixmap(QPixmap(tile_Img[2]));
        tiles[int(player2->i + 1)][int(player2->j)]->status = 2;
        player2->setPixmap(QPixmap(player2->player2_Img[3]));
        moveVertical2 = true;
        player2->i += 0.5;
    }
    player2->setPos(player2->x() ,player2->y() + 20);
}

void Player::player2_Action4()
{
    if(moveHorizontal2) {

        if (player2->j == 0) {
            player2->setPos(player2->x() + 980 ,player2->y());
            player2->j = 24.5;
            player2->setPixmap(QPixmap(player2->player2_Img[4]));
            moveHorizontal2 = false;
            return;
        }

        if (tiles[int(player2->i)][int(player2->j - 1)]->status == 3)
            return;
        player2->setPixmap(QPixmap(player2->player2_Img[4]));
        moveHorizontal2 = false;
        player2->j -= 0.5;
    }
    else {
        tiles[int(player2->i)][int(player2->j)]->setPixmap(QPixmap(tile_Img[2]));
        tiles[int(player2->i)][int(player2->j)]->status = 2;
        player2->setPixmap(QPixmap(player2->player2_Img[5]));
        moveHorizontal2 = true;
        player2->j -= 0.5;
    }
    player2->setPos(player2->x() - 20,player2->y());
}

void Player::player2_Action6()
{
    if(moveHorizontal2) {

        if (player2->j == 24) {
            player2->setPos(player2->x() - 980 ,player2->y());
            player2->j = -0.5;
            player2->setPixmap(QPixmap(player2->player2_Img[6]));
            moveHorizontal2 = false;
            return;
        }

        if (tiles[int(player2->i)][int(player2->j + 1)]->status == 3)
            return;
        player2->setPixmap(QPixmap(player2->player2_Img[6]));
        moveHorizontal2 = false;
        player2->j += 0.5;
    }
    else {
        tiles[int(player2->i)][int(player2->j + 1)]->setPixmap(QPixmap(tile_Img[2]));
        tiles[int(player2->i)][int(player2->j + 1)]->status = 2;
        player2->setPixmap(QPixmap(player2->player2_Img[7]));
        moveHorizontal2 = true;
        player2->j += 0.5;
    }
    player2->setPos(player2->x() + 20,player2->y());
}



