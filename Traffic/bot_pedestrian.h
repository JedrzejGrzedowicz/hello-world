#ifndef BOT_PEDESTRIAN_H
#define BOT_PEDESTRIAN_H
// klasa reprezentująca pieszego

#include "moving_object.h"
#include "sensor.h"
//Dodaje tę bibliotekę, aby dalo się połączyć sygnał ze slotem
#include <QObject>

class Bot_Pedestrian : public Moving_Object
{

Q_OBJECT

public:
    Bot_Pedestrian();
   ~Bot_Pedestrian() override;
private:

    //wskaźnik na sensor do wykrywania innych pieszych
     sensor *PedestrianSensor;

     void SetBrakeCoef(QPointF qpfObject) override;// funkcja zwracająca współczynnik hamowania w zależności od punktu

     void turn(QPointF qpfObject); // metoda do skręcania w prawo jeżeli wykryje innego na swojej drodze (pobierane położenie z metody sensora)


private slots:

    void move() override; // przedefiniowanie metody metody do poruszania się
};

#endif // BOT_PEDESTRIAN_H
