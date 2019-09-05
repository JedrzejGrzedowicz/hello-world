#include "pavement.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include "pavement_beginning.h"


pavement_beginning *NewPavBeg;

pavement::pavement(qreal pavX, qreal pavY,qreal pavLength, qreal pavWidth, Map *parent)
{

    //przechowuję wartości zmiennych wejściowych

    this->pr_pvX = pavX;
    this->pr_pvY = pavY;
    this->pr_pvLength = pavLength;
    this->pr_pvWidth = pavWidth;

    this->setParentItem(parent);
    this->setRect(pavX,pavY,pavLength,pavWidth);

    NewPavBeg = new pavement_beginning(pavX,pavY,pavLength,pavWidth,this);

    this->setBrush(QPixmap(":/images/pavement.png"));

    // 2x2 - road beginning

   // qDebug() << "Stworzono chodnik.";
}


