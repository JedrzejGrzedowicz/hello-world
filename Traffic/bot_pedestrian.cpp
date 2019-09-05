#include "bot_pedestrian.h"
#include "moving_object.h"
#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "sensor.h"



Bot_Pedestrian::Bot_Pedestrian()
{

    int iRandType = rand()%4;
    switch(iRandType)
    {
        case 0:
          //  setPixmap(QPixmap(":images/car_red.png"));
            this->qrPrivAccel = 0.5;
        break;

        case 1:
           // setPixmap(QPixmap(":images/car_orange.png"));
            this->qrPrivAccel = 1;
        break;

        case 2:
            //setPixmap(QPixmap(":images/car_yellow.png"));
            this->qrPrivAccel = 1.5;
        break;

        case 3:
           // setPixmap(QPixmap(":images/car_green.png"));
            this->qrPrivAccel = 2;
        break;
    };

    PedestrianSensor = new sensor(x(),y(),Pedestrian);
    PedestrianSensor->setParentItem(this);

    // inicjalizuje wartość zmiennych

    this->qrAngle = 0;
    this->licz=0;
    // nadaję pixmape
    setPixmap(QPixmap(":images/pedestrian.png"));

    qDebug() << "Stworzono pieszego";

    connect(this->ObjectsPrivTimer,SIGNAL(timeout()),this,SLOT(move()));
    this->ObjectTimerStart();

}

Bot_Pedestrian::~Bot_Pedestrian()
{
    qDebug() << "Usuwam Bot_Pedestrian";
}

void Bot_Pedestrian::SetBrakeCoef(QPointF qpfObject)
{

     QPointF qpfThisPede(this->pos().x()+100,this->pos().y()+25);
     QPointF qpfOtherPede = qpfObject; // to nie pomogło

     QLineF CarOrientLine(mapToItem(this,x(),y()),mapToItem(this,x()+30,y()));
     QLineF lineToObject(mapToParent(qpfThisPede), mapToParent(qpfOtherPede));

     if(lineToObject.angleTo(lineToObject) > 80 || lineToObject.angleTo(lineToObject) < 280)
     {
         if(lineToObject.length() <= 20) // do poprawy bounding rect
         {
            this->qrBrakeCoef = 0.01176470*(lineToObject.length())-0.17647;
            //this->qrBrakeCoef = 0;
            //qDebug() << "qrBrakeCoef = " << this->qrBrakeCoef;
         }
     }else this->qrBrakeCoef=1;
}


void Bot_Pedestrian::move()
{


    if (Moving_Object::bMovObjTimerState)
    {
        PedestrianSensor->FindObjects();

        if(PedestrianSensor->GetBotPedeFlagState())
        {
            SetBrakeCoef(PedestrianSensor->GetFoundPedePos());

        }else qrBrakeCoef = 1; //to jest konieczne

        setPos(mapToScene(5*qrPrivAccel*qrBrakeCoef,0));
       // test ruchu pieszego, chodzi po kwadraci
       this->licz += 10;
        if (this->licz == 500)
        {
           setRotation(this->qrAngle += 90);
           this->licz = 0;
         }
    }
     this->DetectLeavingScene();
     this->DetectKillSwitchChange();

}

