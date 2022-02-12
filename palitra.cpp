#include "palitra.h"

Palitra::Palitra(int map, int character1, int character2) {
    if (map == 1) {
        time = 60;
    }
    else
        time = 40;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,720);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,720);
    setWindowTitle("Palitra");

    player1 = new Player(character1 ,map);
    player1->player2 = new Player2(character2);
    if (map == 1) {
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 25 ; j++) {
            player1->tiles[i][j] = new Tile();
            scene->addItem(player1->tiles[i][j]);
            player1->tiles[i][j]->setPos(j * 40, i * 40);
            player1->tiles[i][j]->setPixmap(QPixmap("G:/Work/Proga/Palitra/untitled/Images/tile.png"));
        }
    }
    }
    else {
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 25 ; j++) {
                player1->tiles[i][j] = new Tile();
                scene->addItem(player1->tiles[i][j]);
                player1->tiles[i][j]->setPos(j * 40, i * 40);
                player1->tiles[i][j]->setPixmap(QPixmap("G:/Work/Proga/Palitra/untitled/Images/tile2.png"));
            }
        }
    }

    if (map == 1){
        player1->createMap1();
    }
    if (map == 2) {
        player1->createMap2();
    }
    scene->addItem(player1);
    scene->addItem(player1->player2);
    if(map == 1) {
        player1->setFlag(QGraphicsItem::ItemIsFocusable);
        player1->setFocus();
        player1->j = 4;
        player1->i = 9;
        player1->setPos(player1->j * 40,player1->i * 40);
        player1->player2->j = 20;
        player1->player2->i = 9;
        player1->player2->setPos(player1->player2->j * 40,player1->player2->i * 40);
    }
    else {
        player1->setFlag(QGraphicsItem::ItemIsFocusable);
        player1->setFocus();
        player1->j = 12;
        player1->i = 4;
        player1->setPos(player1->j * 40,player1->i * 40);
        player1->player2->j = 12;
        player1->player2->i = 13;
        player1->player2->setPos(player1->player2->j * 40,player1->player2->i * 40);
    }

    quitButton = new QPushButton();
    quitButton->setText("Quit");
    quitButton->setFixedSize(200,50);
    scene->addWidget(quitButton);
    quitButton->move(400,430);
    quitButton->hide();
    restartButton = new QPushButton();
    restartButton->setFixedSize(200,50);
    restartButton->setText("Restart");
    scene->addWidget(restartButton);
    restartButton->move(400,360);
    restartButton->hide();
    connect(restartButton,SIGNAL(clicked()),this,SLOT(clickedRestart()));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(clickedQuit()));

    timer = new QLabel();
    player1result = new QLabel();
    player2result = new QLabel();
    scene->addWidget(player1result);
    scene->addWidget(player2result);
    player1result->setFixedSize(120,80);
    player1result->setAlignment(Qt::AlignCenter);
    player2result->setFixedSize(120,80);
    player2result->setAlignment(Qt::AlignCenter);
    player1result->move(320,200);
    player2result->move(560,200);
    player1result->hide();
    player2result->hide();


    scene->addWidget(timer);
    timer->setFixedSize(80,40);

    gameTime = new QTimer();
    timer->setAlignment(Qt::AlignCenter);
    timer->move(280,0);
    QFont font = timer->font();
    font.setPixelSize(20);
    timer->setFont(font);
    connect(gameTime,SIGNAL(timeout()),this,SLOT(GameTimer()));
    gameTime->start(1000);
    timer->show();

    this->map = map;
    this->character1 = character1;
    this->character2 = character2;

}

Palitra::~Palitra()
{
    delete[] scene;

    delete[] restartButton;
    delete[] quitButton;

    delete[]  timer;
    delete[] player1result;
    delete[] player2result;

    delete[] gameTime;

    delete[] player1;
}

void Palitra::clickedQuit()
{
    hide();
}

void Palitra::clickedRestart()
{
    if (map == 1) {
        time = 60;
    }
    else
        time = 40;
    hide();
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,720);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,720);
    setWindowTitle("Palitra");

    player1 = new Player(character1, map);
    player1->player2 = new Player2(character2);
    if (map == 1) {
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 25 ; j++) {
            player1->tiles[i][j] = new Tile();
            scene->addItem(player1->tiles[i][j]);
            player1->tiles[i][j]->setPos(j * 40, i * 40);
            player1->tiles[i][j]->setPixmap(QPixmap("G:/Work/Proga/Palitra/untitled/Images/tile.png"));
        }
    }
    }
    else {
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 25 ; j++) {
                player1->tiles[i][j] = new Tile();
                scene->addItem(player1->tiles[i][j]);
                player1->tiles[i][j]->setPos(j * 40, i * 40);
                player1->tiles[i][j]->setPixmap(QPixmap("G:/Work/Proga/Palitra/untitled/Images/tile2.png"));
            }
        }
    }
    if (map == 1) {
    player1->createMap1();
    }
    else {
        player1->createMap2();
    }

    scene->addItem(player1);
    scene->addItem(player1->player2);

    if (map == 1) {
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();
    player1->j = 4;
    player1->i = 9;
    player1->setPos(player1->j * 40,player1->i * 40);
    player1->player2->j = 20;
    player1->player2->i = 9;
    player1->player2->setPos(player1->player2->j * 40,player1->player2->i * 40);
    }
    else {
        player1->setFlag(QGraphicsItem::ItemIsFocusable);
        player1->setFocus();
        player1->j = 12;
        player1->i = 4;
        player1->setPos(player1->j * 40,player1->i * 40);
        player1->player2->j = 12;
        player1->player2->i = 13;
        player1->player2->setPos(player1->player2->j * 40,player1->player2->i * 40);
    }

    quitButton = new QPushButton();
    quitButton->setText("Quit");
    quitButton->setFixedSize(200,50);
    scene->addWidget(quitButton);
    quitButton->move(400,430);
    quitButton->hide();
    restartButton = new QPushButton();
    restartButton->setFixedSize(200,50);
    restartButton->setText("Restart");
    scene->addWidget(restartButton);
    restartButton->move(400,360);
    restartButton->hide();
    connect(restartButton,SIGNAL(clicked()),this,SLOT(clickedRestart()));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(clickedQuit()));

    timer = new QLabel();
    player1result = new QLabel();
    player2result = new QLabel();
    scene->addWidget(player1result);
    scene->addWidget(player2result);
    player1result->setFixedSize(120,80);
    player1result->setAlignment(Qt::AlignCenter);
    player2result->setFixedSize(120,80);
    player2result->setAlignment(Qt::AlignCenter);
    player1result->move(320,200);
    player2result->move(560,200);
    player1result->hide();
    player2result->hide();


    scene->addWidget(timer);
    timer->setFixedSize(80,40);

    gameTime = new QTimer();
    timer->setAlignment(Qt::AlignCenter);
    timer->move(280,0);
    QFont font = timer->font();
    font.setPixelSize(20);
    timer->setFont(font);
    connect(gameTime,SIGNAL(timeout()),this,SLOT(GameTimer()));
    gameTime->start(1000);
    timer->show();
    show();
}

void Palitra::GameTimer()
{
    if (time == 0) {
        gameTime->stop();
        restartButton->show();
        quitButton->show();
        player1->player2->setFlag(QGraphicsItem::ItemIsFocusable);
        player1->player2->setFocus();
        player1->player1_TimerA->stop();
        player1->player1_TimerW->stop();
        player1->player1_TimerS->stop();
        player1->player1_TimerD->stop();

        player1->player2_Timer8->stop();
        player1->player2_Timer5->stop();
        player1->player2_Timer4->stop();
        player1->player2_Timer6->stop();

        player1Score = 0;
        player2Score = 0;

        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 25; j++) {
                if (player1->tiles[i][j]->status == 1) {
                    player1Score++;
                    if (player1->tiles[i][j]->specialStatus == 1)
                        player1Score++;
                }
                if (player1->tiles[i][j]->status == 2) {
                    player2Score++;
                    if (player1->tiles[i][j]->specialStatus == 1)
                        player2Score++;
                }
            }
        }
        player1result->setText("Player 1 :" + QString::number(player1Score));
        player2result->setText("Player 2 :" + QString::number(player2Score));
        player1result->show();
        player2result->show();
    }
    else {
    time--;
    timer->setText(QString::number(time));
    }
}




