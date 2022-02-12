#ifndef PALITRA_H
#define PALITRA_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <player.h>
#include <tile.h>
#include <QTimer>
#include <QPushButton>
#include <QLabel>


class Palitra : public QGraphicsView
{
    Q_OBJECT

public:
    Palitra(QWidget *parent = 0);
    Palitra(int map, int character1, int character2);
    ~Palitra();
    QGraphicsScene * scene;

    QPushButton* restartButton;
    QPushButton* quitButton;

    QLabel * timer;
    QLabel * player1result;
    QLabel * player2result;

    QTimer *gameTime;

    Player *player1;

    int time;
    int player1Score;
    int player2Score;

    int map;
    int character1;
    int character2;

private slots:
    void clickedQuit();
    void clickedRestart();
    void GameTimer();
};

#endif // PALITRA_H
