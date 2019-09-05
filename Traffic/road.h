#ifndef ROAD_H
#define ROAD_H

// klasa reprezentująca drogę

#include "map.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class road : public QGraphicsRectItem
{
    protected:
// wymiary i położenie obiektu
        qreal pr_rdX;
        qreal pr_rdY;
        qreal pr_rdLength;
        qreal pr_rdWidth;


    public:
        road();
        road(qreal rdX, qreal rdY,qreal rdLength, qreal rdWidth, Map *parent);
        void change_beginning_pos();// metoda do zmiany położenia znacznika wjazdu na przeciwną stronę
};


#endif // ROAD_H
