#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    this->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    this->setWindowIcon(QIcon("G:/Work/Proga/Palitra/untitled/Images/icon.png"));
    this->setWindowTitle("Palitra");


    connect(ui->pushButton_1p,SIGNAL(clicked()),this,SLOT(clickedStartGame()));
    connect(ui->ChangeMap,SIGNAL(clicked()),this,SLOT(clickedGameSettings()));
    connect(ui->Back,SIGNAL(clicked()),this,SLOT(clickedBack()));
    connect(ui->map1,SIGNAL(clicked()),this,SLOT(clickedMap1()));
    connect(ui->PlayersSettings,SIGNAL(clicked()),this,SLOT(clickedPlayerSettings()));
    connect(ui->map2,SIGNAL(clicked()),this,SLOT(clickedMap2()));
    connect(ui->Scin1,SIGNAL(clicked()),this,SLOT(clickedSelectPlayer1Scin()));
    connect(ui->Scin1_2,SIGNAL(clicked()),this,SLOT(clickedSelectPlayer1Scin2()));
    connect(ui->Scin2,SIGNAL(clicked()),this,SLOT(clickedSelectPlayer2Scin()));
    connect(ui->Scin2_2,SIGNAL(clicked()),this,SLOT(clickedSelectPlayer2Scin2()));
    map = 1;
    character1 = 1;
    character2 = 1;
    ui->Back->hide();
    ui->map1->hide();
    ui->map2->hide();
    QPixmap pix;
    pix.load("G:/Work/Proga/Palitra/untitled/Images/map1.png");
    ui->map1picture->setPixmap(pix);
    pix.load("G:/Work/Proga/Palitra/untitled/Images/map2.png");
    ui->map2picture->setPixmap(pix);
    pix.load("G:/Work/Proga/Palitra/untitled/Images/role1_Down.png");
    ui->Scin1picture->setPixmap(pix);
    pix.load("G:/Work/Proga/Palitra/untitled/Images/role1_Down2.png");
    ui->Scin1picture2->setPixmap(pix);
    pix.load("G:/Work/Proga/Palitra/untitled/Images/role2_Down.png");
    ui->Scin2picture->setPixmap(pix);
    pix.load("G:/Work/Proga/Palitra/untitled/Images/role2_Down2.png");
    ui->Scin2picture2->setPixmap(pix);
    ui->map1picture->hide();
    ui->Scin1picture->hide();
    ui->Scin1picture2->hide();
    ui->Scin2picture->hide();
    ui->Scin2picture2->hide();
    ui->Scin1->hide();
    ui->Scin1_2->hide();
    ui->Scin2->hide();
    ui->Scin2_2->hide();
    ui->map2picture->hide();
}

MainWindow::~MainWindow()
{
    //delete[] palitra;
    delete ui;
}




void MainWindow::clickedStartGame()
{
    palitra = new Palitra(map, character1, character2);
    palitra->show();
}

void MainWindow::clickedGameSettings()
{
    ui->pushButton_1p->hide();
    ui->ChangeMap->hide();
    ui->PlayersSettings->hide();
    ui->Back->show();
    ui->map1->show();
    ui->map2->show();
    ui->map1picture->show();
    ui->map2picture->show();

}

void MainWindow::clickedMap1()
{
    map = 1;
}

void MainWindow::clickedBack()
{
    ui->pushButton_1p->show();
    ui->ChangeMap->show();
    ui->PlayersSettings->show();
    ui->Back->hide();
    ui->map1->hide();
    ui->map2->hide();
    ui->map1picture->hide();
    ui->map2picture->hide();
    ui->Scin1picture->hide();
    ui->Scin1picture2->hide();
    ui->Scin2picture->hide();
    ui->Scin2picture2->hide();
    ui->Scin1->hide();
    ui->Scin1_2->hide();
    ui->Scin2->hide();
    ui->Scin2_2->hide();
}

void MainWindow::clickedPlayerSettings()
{
    ui->pushButton_1p->hide();
    ui->ChangeMap->hide();
    ui->PlayersSettings->hide();
    ui->Back->show();
    ui->Scin1->show();
    ui->Scin1picture->show();
    ui->Scin1picture2->show();
    ui->Scin2picture->show();
    ui->Scin2picture2->show();
    ui->Scin1_2->show();
    ui->Scin2->show();
    ui->Scin2_2->show();

}

void MainWindow::clickedMap2()
{
    map = 2;
}

void MainWindow::clickedSelectPlayer1Scin()
{
    character1 = 1;
}

void MainWindow::clickedSelectPlayer1Scin2()
{
    character1 = 2;
}

void MainWindow::clickedSelectPlayer2Scin()
{
    character2 = 1;
}

void MainWindow::clickedSelectPlayer2Scin2()
{
    character2 = 2;
}




