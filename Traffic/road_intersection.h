#ifndef ROAD_INTERSECTION_H
#define ROAD_INTERSECTION_H

//klasa skrzyżowania dróg

#include "map.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class road_intersection : public QGraphicsRectItem
{
    protected:

    public:
        road_intersection();
        road_intersection(qreal rdX, qreal rdY, int rdWidth, Map *parent);
};

#endif // ROAD_INTERSECTION_H
