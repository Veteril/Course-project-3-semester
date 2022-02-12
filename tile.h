#ifndef TILE_H
#define TILE_H

#include <QPixmap>
#include <QGraphicsObject>
#include <QGraphicsPixmapItem>

class Tile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit Tile(QGraphicsItem *parent = 0);
    ~Tile();

    int status;
    int specialStatus;

};

#endif // TILE_H
