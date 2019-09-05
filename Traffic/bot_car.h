#ifndef BOT_CAR_H
#define BOT_CAR_H
// klasa reprezentująca samochód jeżdżący bez celu

#include "moving_object.h"
#include "sensor.h"
//Dodaje tę bibliotekę, aby dalo się połączyć sygnał ze slotem
#include <QObject>

//zmieniam na dziedziczenie public bo inaczej nie mogę dodawać do sceny
class Bot_Car : public Moving_Object
{

Q_OBJECT

public:
    Bot_Car();
    ~Bot_Car() override;
private:

//wskaźniki na sensory dodawane w konstruktorze

    sensor *FrontSensor;
    sensor *RightSensor;
    sensor *LeftSensor;
// oś samochodu ustalana w konstruktorze

    QLineF CarAxis;

    bool TurnToRoad(QPointF qpfRoadBegPos);
    void SetBrakeCoef(QPointF qpfObject) override; // przedefiniowanie metody zwracającej współczynnik hamowania w zależności odległości od innego samochodu

private slots:
    void move() override; // przedefiniowanie metody metody do poruszania się
};

#endif // BOT_CAR_H
