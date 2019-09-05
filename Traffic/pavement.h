#ifndef PAVEMENT_H
#define PAVEMENT_H
//klasa chodnika


#include "map.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class pavement : public QGraphicsRectItem
{
    protected:
    // wymiary i położenie obiektu
        qreal pr_pvX;
        qreal pr_pvY;
        qreal pr_pvLength;
        qreal pr_pvWidth;

    public:
        pavement(qreal pavX, qreal pavY,qreal pavLength, qreal pavWidth, Map *parent); // konstruktor wskazujący rodzica oraz miejsce, w którym ma powstać chodnik
                                                                                       // oraz jego rozmiar
        void change_beginning_pos(); // metoda do zmiany położenia znacznika wjazdu na przeciwną stronę - niepotrzebne dla chodnika
};

#endif // PAVEMENT_H
