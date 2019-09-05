#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>

#include "sensor.h"
#include "bot_car.h"
#include "bot_pedestrian.h"

#include "road_intersection.h"
#include "pavement_beginning.h"
#include "road_beginning.h"


sensor::sensor(qreal senX,qreal senY, SensType type)
{

    switch(type)
    {
        case Front:

            this->setRect(senX+50,senY-50,120,150);
           // qDebug() << "Stworzono sensor przedni";
            break;

        case Left:

            this->setRect(senX,senY-20,100,20);
           // qDebug() << "Stworzono sensor lewy";
            break;

        case Right:

            this->setRect(senX,senY+50,100,20);
           // qDebug() << "Stworzono sensor prawy";
            break;

        case Pedestrian:

            this->setRect(senX-7.5,senY-6,20,20);
           // qDebug() << "Stworzono sensor pieszego";
            break;
      }
}

sensor::~sensor()
{
    qDebug() << "Usunieto sensor";
}

void sensor::FindObjects()
{
    // tworzę listę obiektów typu QGraphicItem
    QList<QGraphicsItem *> colObj = collidingItems(Qt::IntersectsItemShape);

    //tworzę punkt przechowujący dane położenie
    //qpfFoundObjectsPos = QPointF(0,0);

    // zeruję flagi znalezionych obiektów

    bFoundPaveInter = false;
    bFoundRoadInter = false;
    bFoundBotPedestrian = false;
    bFoundBotCar = false;
    bFoundRoadBeg = false;

    iFoundPaveBeg = 0;
    iFoundRoadBeg = 0;

    // srawdzam czy ta lista zawiera wskazany obiekt
    for(int i=0, n=colObj.size(); i < n; ++i)
    {
        //szukam obiektów Bot_Car
        if (typeid(*(colObj[i])) == typeid (Bot_Car) && (colObj[i]) != this->parentItem())
        {
            bFoundBotCar = true;
             qpfFoundBotCarPos = QPointF(colObj[i]->pos().x(),colObj[i]->pos().y());
             qDebug() << "Wysylana pozycja samochodu" << qpfFoundBotCarPos;

        }

        //szukam obiektów Road Beginning

        if (typeid(*(colObj[i])) == typeid (road_beginning))
        {
            //dodanie do talicy obiektów road beginning i nadpisanie ilości obiektów w danej tablicy

            bFoundRoadBeg = true;
            iFoundRoadBeg++;
            qpfFoundRoadBegPosAr[iFoundRoadBeg-1] = QPointF(this->mapToScene(colObj[i]->pos()));

             //  qDebug() << "iFoundRoadBeg" << iFoundRoadBeg;
            //qDebug() << "Beg pos" << QPointF(this->mapToScene(colObj[i]->pos()));
        }

        //szukam obiektów Pavement Beginning

        if (typeid(*(colObj[i])) == typeid (pavement_beginning))
        {
            //dodanie do talicy obiektów pavement beginning i nadpisanie ilości obiektów w danej tablicy
            bFoundPaveBeg = true;
            iFoundPaveBeg++;
            qpfFoundPaveBegPosAr[iFoundPaveBeg-1] = QPointF(this->mapToScene(colObj[i]->pos()));
        }

        //szukam obiektów Bot Pedestrian

        if (typeid(*(colObj[i])) == typeid (Bot_Pedestrian) && (colObj[i]) != this->parentItem())
        {
            bFoundBotPedestrian = true;
            qpfFoundBotPedePos = QPointF(this->mapToScene(colObj[i]->pos()));
        }

        //szukam obiektów Road Intersection

        if (typeid(*(colObj[i])) == typeid (road_intersection))
        {
            bFoundRoadInter = true;
            qpfFoundRoadIntPos = QPointF(this->mapToScene(colObj[i]->pos()));
        }
    }
}


bool sensor::GetRoadInterFlagState()
{
    return bFoundRoadInter;
}

bool sensor::GetPaveInterFlagState()
{
    return bFoundPaveInter;
}

bool sensor::GetBotPedeFlagState()
{
    return bFoundBotPedestrian;
}

bool sensor::GetBotCarFlagState()
{
    return bFoundBotCar;
}

QPointF sensor::GetFoundCarPosNew()
{
    return qpfFoundBotCarPos;
}

QPointF sensor::GetFoundPedePos()
{
    return qpfFoundBotPedePos;
}

QPointF sensor::GetRoadIntPos()
{
    return qpfFoundRoadIntPos;
}

QPointF sensor::GetPavIntPos()
{
    return qpfFoundPaveIntPos;
}

void sensor::GetFoundRoadBegArr(QPointF qpfArr[], int iNbrOfObj)
{
    iNbrOfObj = iFoundRoadBeg;

    for(int i=0; i<=iNbrOfObj; i++)
    {
      qpfArr[i] = qpfFoundRoadBegPosAr[i];
    }
    //qDebug() << "iNbrOFObj w getarr" << iNbrOfObj;
}

void sensor::GetFoundPaveBegArr(QPointF qpfArr[], int iNbrOfObj)
{
    iNbrOfObj = iFoundPaveBeg;
    for(int i=0; i<=iNbrOfObj; i++)
    {
      qpfArr[i] = qpfFoundPaveBegPosAr[i];
    }
}

QList<QGraphicsItem *> sensor::GetSensCollItemList()
{
     QList<QGraphicsItem *> colObj = collidingItems(Qt::IntersectsItemShape);
     return colObj;
}

