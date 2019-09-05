#include "road_beginning.h"
#include <QObject>
#include <QDebug>
#include "map.h"


road_beginning::road_beginning(qreal parX, qreal parY, qreal parLength, qreal parWidth, road *parent)
{



    this->setParentItem(parent); // ustalam rodzica

    this->pr_parX = parX;
    this->pr_parY = parY;
    this->pr_parLength = parLength;
    this->pr_parWidth = parWidth;

    if(parWidth <= parLength) setRect(parX,parY+(parWidth/2)-5,10,10); // poziomo
        else setRect(parX+(parLength/2)-5,parY,10,10); //pionowo

    qDebug() << "Stworzono poczatek drogi.";
}



void road_beginning::change_beginning_pos()

{//dla pionowych odcinków znaczniki początków dróg będą w inaczej usytułowane

       if(pr_parWidth <= pr_parLength)this->setRect((pr_parX+pr_parLength)-10,pr_parY+(pr_parWidth/2)-5,10,10);//jeżeli droga jest pozioma
                else this->setRect((pr_parX+pr_parLength/2)-5,pr_parY+(pr_parWidth)-10,10,10); // jeżeli droga jest pionowa

}
