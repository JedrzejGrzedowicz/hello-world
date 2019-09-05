#ifndef PAVEMENT_INTERSECTION_H
#define PAVEMENT_INTERSECTION_H

// klasa skrzyżowania chodników

#include "map.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class pavement_intersection : public QGraphicsRectItem
{
    protected:

    public:
        pavement_intersection(qreal pavX, qreal pavY, int pavWidth, Map *parent);
};

#endif // PAVEMENT_INTERSECTION_H
