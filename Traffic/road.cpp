#include "road.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include "road_beginning.h"
#include "pavement.h"
#include "map.h"

road_beginning *NewRoadBeginning;
pavement *NewPavemment;

road::road()
{
   //...
}

road::road(qreal rdX, qreal rdY,qreal rdLength, qreal rdWidth, Map *parent)
{
    //przechowuję wartości zmiennych wejściowych
    this->pr_rdX = rdX;
    this->pr_rdY = rdY;
    this->pr_rdLength = rdLength;
    this->pr_rdWidth = rdWidth;

    this->setParentItem(parent);
    this->setRect(rdX,rdY,rdLength,rdWidth);
    this->setBrush(QPixmap(":/images/road.png"));

    //dodawanie znacznika początku drog

    NewRoadBeginning = new road_beginning(rdX,rdY,rdLength,rdWidth,this);


    //qDebug() << "Stworzono droge.";
}

void road::change_beginning_pos()
{
    NewRoadBeginning->change_beginning_pos();
}
