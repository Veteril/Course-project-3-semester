#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <palitra.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Palitra* palitra;

private slots:
    void clickedStartGame();
    void clickedGameSettings();
    void clickedMap1();
    void clickedBack();
    void clickedPlayerSettings();
    void clickedMap2();
    void clickedSelectPlayer1Scin();
    void clickedSelectPlayer1Scin2();
    void clickedSelectPlayer2Scin();
    void clickedSelectPlayer2Scin2();

private:
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 720;
    int map;
    int character1;
    int character2;
    int time;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
