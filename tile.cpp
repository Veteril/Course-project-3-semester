#include "tile.h"


Tile::Tile(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    status = 0;
}

Tile::~Tile()
{

}
