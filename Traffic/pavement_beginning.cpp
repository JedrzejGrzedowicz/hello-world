#include "pavement_beginning.h"
#include <QObject>
#include <QDebug>
#include "map.h"


pavement_beginning::pavement_beginning(qreal parX, qreal parY, qreal parLength, qreal parWidth, pavement *parent)
{
    this->setParentItem(parent); // ustalam rodzica

    this->pr_parX = parX;
    this->pr_parY = parY;
    this->pr_parLength = parLength;
    this->pr_parWidth = parWidth;

    if(parWidth <= parLength) setRect(parX,parY+(parWidth/2)-1,2,2); //poziomo
        else setRect(parX+(parLength/2)-1,parY,2,2); // pionowo

    //qDebug() << "Stworzono poczatek chodnika.";
}

