#include "player2.h"

Player2::Player2(int character2,QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    if (character2 == 1) {
    player2_Img[0] = "G:/Work/Proga/Palitra/untitled/Images/role2_Up.png";
    player2_Img[1] = "G:/Work/Proga/Palitra/untitled/Images/role2_Up1.png";
    player2_Img[2] = "G:/Work/Proga/Palitra/untitled/Images/role2_Down.png";
    player2_Img[3] = "G:/Work/Proga/Palitra/untitled/Images/role2_Down1.png";
    player2_Img[4] = "G:/Work/Proga/Palitra/untitled/Images/role2_Left.png";
    player2_Img[5] = "G:/Work/Proga/Palitra/untitled/Images/role2_Left1.png";
    player2_Img[6] = "G:/Work/Proga/Palitra/untitled/Images/role2_Right.png";
    player2_Img[7] = "G:/Work/Proga/Palitra/untitled/Images/role2_Right1.png";
    setPixmap(QPixmap(player2_Img[2]));
    }
    if (character2 == 2) {
    player2_Img[0] = "G:/Work/Proga/Palitra/untitled/Images/role2_Up2.png";
    player2_Img[1] = "G:/Work/Proga/Palitra/untitled/Images/role2_Up21.png";
    player2_Img[2] = "G:/Work/Proga/Palitra/untitled/Images/role2_Down2.png";
    player2_Img[3] = "G:/Work/Proga/Palitra/untitled/Images/role2_Down21.png";
    player2_Img[4] = "G:/Work/Proga/Palitra/untitled/Images/role2_Left2.png";
    player2_Img[5] = "G:/Work/Proga/Palitra/untitled/Images/role2_Left21.png";
    player2_Img[6] = "G:/Work/Proga/Palitra/untitled/Images/role2_Right2.png";
    player2_Img[7] = "G:/Work/Proga/Palitra/untitled/Images/role2_Right21.png";
    setPixmap(QPixmap(player2_Img[2]));
    }
}
Player2::~Player2()
{

}
