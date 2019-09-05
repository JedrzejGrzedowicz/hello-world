#include "road_intersection.h"
#include "map.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsPixmapItem>

road_intersection::road_intersection()
{
    //...
}

road_intersection::road_intersection(qreal rdX, qreal rdY, int rdWidth, Map *parent)
{
    this->setParentItem(parent); // usalam rodzica
    this->setRect(rdX,rdY,rdWidth,rdWidth); // ustalam wymiar i położenie
    this->setBrush(QPixmap(":/images/road.png")); // przypisuje obraz
}
