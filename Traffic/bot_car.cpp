#include "bot_car.h"
#include "moving_object.h"
#include <QDebug>
#include <QObject>
#include <QTimer>
#include "sensor.h"
#include <QGraphicsRectItem>
#include <stdlib.h>


Bot_Car::Bot_Car()
{
    // losowanie typu samochodu

    int iRandType = rand()%4;
    switch(iRandType)
    {
        case 0:
            setPixmap(QPixmap(":images/car_red.png"));
            this->qrPrivAccel = 0.5;
        break;

        case 1:
            setPixmap(QPixmap(":images/car_orange.png"));
            this->qrPrivAccel = 1;
        break;

        case 2:
            setPixmap(QPixmap(":images/car_yellow.png"));
            this->qrPrivAccel = 1.5;
        break;

        case 3:
            setPixmap(QPixmap(":images/car_green.png"));
            this->qrPrivAccel = 2;
        break;
     };


     FrontSensor = new sensor(x(),y(),Front);
     FrontSensor->setParentItem(this);

     RightSensor = new sensor(x(),y(),Right);
     RightSensor->setParentItem(this);
     LeftSensor = new sensor(x(),y(),Left);
     LeftSensor->setParentItem(this); 

     // inicjalizuje wartość zmiennych

     this->qrAngle = 0;
     this->licz=0;
     this->qrBrakeCoef = 1;

     // wytyczam linie osi obiektu

     CarAxis = QLineF(mapToItem(this,x(),y()),mapToItem(this,x()+30,y()));

    connect(this->ObjectsPrivTimer,SIGNAL(timeout()),this,SLOT(move()));
    this->ObjectTimerStart();

    qDebug() << "Stworzono Bot_Car";

}

Bot_Car::~Bot_Car()
{
    qDebug() << "Usuwam Bot_Car";
}

void Bot_Car::SetBrakeCoef(QPointF qpObject)
{

    // to działa dziwnie

    QPointF qpfThisCar(this->pos().x()+100,this->pos().y()+25);
    QPointF qpfOtherCar = qpObject; // to nie pomogło

    QLineF CarOrientLine(mapToItem(this,x(),y()),mapToItem(this,x()+30,y()));
    QLineF lineToObject(mapToParent(qpfThisCar), mapToParent(qpfOtherCar));

    if(lineToObject.angleTo(lineToObject) > 80 || lineToObject.angleTo(lineToObject) < 280)//jeżli obiekt jest PRZED samochodem
    {

        if(lineToObject.length() <= 120)
        {
           this->qrBrakeCoef = 0.01176470*(lineToObject.length())-0.17647; // funkcja liniowa zmniejszająca prędkość samochodu
        }
    }else this->qrBrakeCoef=1;
}


void Bot_Car::move()
{

    if (Moving_Object::bMovObjTimerState)
    {
        FrontSensor->FindObjects(); // update sensorów

        //funkcja o
        //jeżeli znalazł skrzyżowanie to sprawdza czy odległość od maski x()+150,y()+50 do pos(x+50,y+50)< 10
            // jeżeli tak funkcja sprawdza ile jest możliwych dróg i zwraca punkt losowy wybrany z możliwych


        if(FrontSensor->GetRoadInterFlagState()) // jeżeli wykryt skrzyżowanie
        {

            QPointF RoadPos = mapToItem(this->parentItem(),FrontSensor->GetRoadIntPos()); //mapuje do koordynatów tego obiektu
            QPointF qpfThisCar(this->pos().x()+100,this->pos().y()+25);
            QLineF lineToObject(mapToParent(qpfThisCar), mapToParent(RoadPos));

          //  QLineF DistToInter(mapToScene(this->pos()), RoadPos);//linia od przodu samochodu do srodka skrzyżowania

            // funkcja skręć do punktu:
            //sprawdza z której strony jest punkt sprawdzając jaki jest kąt między osią samochodu a linią stworzoną między
            // punktem początkowym samochodu a sprawdzanym punktem

            if(lineToObject.length() < 20) // jeżeli jestem już prawie na środku skrzyżowania
            {
                QPointF arrPosBeg[3];
                int iNbrOfFoundBeg=0;
                FrontSensor->GetFoundRoadBegArr(arrPosBeg,iNbrOfFoundBeg);

                if(iNbrOfFoundBeg != 0)
                {
                    int iRandRoad = rand()%(iNbrOfFoundBeg);

                    QPointF ChosenRoadBeg = mapToItem(this->parentItem(),arrPosBeg[iRandRoad]);
                    QLineF LineToChosenBeg(mapToParent(qpfThisCar),mapToParent(ChosenRoadBeg));

                    this->setRotation(CarAxis.angleTo(LineToChosenBeg));
                    if(CarAxis.angleTo(LineToChosenBeg)> 220 && CarAxis.angleTo(LineToChosenBeg) < 260)// jeżeli wylosowano prawą stronę, skręć w prawo
                        this->TurnRight();
                    else if (CarAxis.angleTo(LineToChosenBeg)> 30 && CarAxis.angleTo(LineToChosenBeg) < 120)
                        this->TurnLeft();
                }

            }

        }


        if(FrontSensor->GetBotCarFlagState()) // ustal współczynnik hamowania
        {
            SetBrakeCoef(FrontSensor->GetFoundCarPosNew());

        }else qrBrakeCoef = 1; //to jest konieczne - jeżeli nie hamuje to współcynnik == 1


        setPos(mapToScene(5*qrPrivAccel*qrBrakeCoef,0));
/*
        this->licz += 10;
         if (this->licz == 1000000)
         {

            this->setRotation(this->qrAngle += 90);

            this->licz = 0;
          }
*/


    }
    this->DetectLeavingScene();
    this->DetectKillSwitchChange();

}


