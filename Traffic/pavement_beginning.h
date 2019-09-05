#ifndef PAVEMENT_BEGINNING_H
#define PAVEMENT_BEGINNING_H

// klasa znacznika początku chodznika wykorzystywana do wykrywania możliwych ścieżek

#include <QObject>
#include <QGraphicsRectItem>
#include "pavement.h"
#include "road.h"
#include "map.h"

class pavement_beginning : public QGraphicsRectItem
{
     protected:
// wymiary i położenie obiektu
        qreal pr_parX;
        qreal pr_parY;
        qreal pr_parLength;
        qreal pr_parWidth;

     public:
        pavement_beginning(qreal parX,qreal parY, qreal parLength, qreal parWidth, pavement *parent);
};

#endif // PAVEMENT_BEGINNING_H
