#ifndef ROAD_BEGINNING_H
#define ROAD_BEGINNING_H

// klasa znacznika początku drogi wykorzystywana do wykrywania możliwych ścieżek

#include <QObject>
#include <QGraphicsRectItem>
#include "pavement.h"
#include "road.h"
#include "map.h"

class road_beginning : public QGraphicsRectItem
{
    protected:
// wymiary i położenie obiektu
        qreal pr_parX;
        qreal pr_parY;
        qreal pr_parLength;
        qreal pr_parWidth;

    public:
        road_beginning(qreal parX,qreal parY, qreal parLength, qreal parWidth, road *parent);
        void change_beginning_pos(); // zmień położenie znacznika początku drogi (pionowo i poziomo są w innych miejscach)
};

#endif // ROAD_BEGINNING_H
