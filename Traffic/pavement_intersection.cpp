#include "pavement_intersection.h"
#include "map.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsPixmapItem>


pavement_intersection::pavement_intersection(qreal pavX, qreal pavY, int pavWidth, Map *parent)
{

    this->setParentItem(parent);
    this->setRect(pavX,pavY,pavWidth,pavWidth);
    this->setBrush(QPixmap(":/images/pavement.png"));

}
