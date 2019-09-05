#include "moving_object.h"
#include <QTimer>
//biblioteka obsługującą wiadomości do debugowania kodu
#include <QDebug>
#include <QGraphicsScene>


//inicjalizuje atrybuty statyczne

//ilość wszystkich ruchomych obiektów
int Moving_Object::iAllMovingObjects = 0;
bool Moving_Object::bMovObjTimerState;
bool Moving_Object::bMovObjKillswitch;


// stałe do obrotów

const qreal Pi = M_PI;
const qreal TwoPi = 2 * M_PI;

Moving_Object::Moving_Object()
{
    iAllMovingObjects++;

    // każdy obiekt inicjalizuje tworzy i inicjalizuje swój time
    Moving_Object::ObjectsPrivTimer = new QTimer();
    qDebug() << "Stworzono obiekt ruszajacy sie...";

    //podłączam Timer do odpowiednich metod, będą wywoływane co podany interwał
    // to chyba muszę już dać do dziedziczących
   //connect(Moving_Object::TimerAllMovingObjects,SIGNAL(timeout()),this,SLOT(move()));
  // this->AllObjectTimerStart();

    //przeskalowuję

   this->setScale(0.5);

}

Moving_Object::~Moving_Object()
{
    iAllMovingObjects--;
    qDebug() << "Usunieto obiekt ruszajacy sie...";
}

void Moving_Object::ChangeTimerState()
{
    if (Moving_Object::bMovObjTimerState)
    {
        Moving_Object::bMovObjTimerState = false;
        qDebug() << "Zmienam bool Timera na false";
    }else
        {
            Moving_Object::bMovObjTimerState = true;
            qDebug() << "Zmienam bool Timera na true";
        }
}

void Moving_Object::KillSwitchEngage()
{
    Moving_Object::bMovObjKillswitch = true;
    qDebug() << "KillSwitch enagage!";
}

qreal Moving_Object::normalizeAngle(qreal angle)
{
        while (angle < 0)
            angle += TwoPi;
        while (angle > TwoPi)
            angle -= TwoPi;
        return angle;
}

// metoda do włączania timera co ustalony interwał (ms)

void Moving_Object::ObjectTimerStart()
{
    this->ObjectsPrivTimer->start(25);
    qDebug() << "Private timer start!";
}

// metoda do stopowania timera

void Moving_Object::ObjectTimerStop()
{
    this->ObjectsPrivTimer->stop();
    qDebug() << "Private timer STOP!";
}

// metoda wykrywająca zejście ze sceny i kasująca obiekt


void Moving_Object::DetectLeavingScene()
{
    if(pos().y() < -200 || pos().x() > 1700 || pos().x() < -200 || pos().y() > 1200)
    {
        scene()->removeItem(this);
        qDebug() << "Obiekt opuscil scene. Usuwam go...";
        delete this;
    }
}

void Moving_Object::DetectKillSwitchChange()
{
    if(this->bMovObjKillswitch)
    {
        //jeżeli jest ostatni to resetuj flagę killswitch
       if(Moving_Object::iAllMovingObjects == 1) Moving_Object::bMovObjKillswitch = false;

       //usuń się ze sceny
       scene()->removeItem(this);
       qDebug() << "Killswitch - usuwam obiekt.";
       delete this;
    }
}

void Moving_Object::TurnRight()
{
    this->setRotation(this->qrAngle += 90);
}

void Moving_Object::TurnLeft()
{
    this->setRotation(this->qrAngle -= 90);
}



// dodaje definicje tej metody WIRTUALNEJ bo inaczej kompilator wywala błąd że jej nie ma...
//EDIT: przestał się czepiać jak zmieniłem na metodę czysto wirtualną
/*void Moving_Object::move()
{
    //...
}

*/
