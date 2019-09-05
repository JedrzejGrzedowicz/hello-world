
#ifndef SENSOR_H
#define SENSOR_H

#include <QGraphicsRectItem>
#include <QPoint>
#include <QObject>
//#include "bot_car.h"
//#include "bot_pedestrian.h"
#include "road_beginning.h"



enum SensType{Front,Left,Right,Pedestrian}; // enum zawierający typy czujników

class sensor : public QGraphicsRectItem
{
    public:


        sensor(qreal senX, qreal senY, SensType type);
        ~sensor();


        void FindObjects(); // metoda nadpisująca informacje o znalezionych przez sensor obiektach
        bool FoundObject(); // funkcja testowa - niepotrzebna


        // pobieranie informacji czy znaleziono dany obiekt

        bool GetRoadInterFlagState();
        bool GetPaveInterFlagState();
        bool GetBotPedeFlagState();
        bool GetBotCarFlagState();


        // lista zwracanych punktów i tablic punktów dla ruchomyh obiektów
        // tworzenie i przeglądanie listy "collidingObjects" spowalnia oporowo
        // działanie programu, więc ograniczam tworzenie i przeglądanie listy do minimum


        QPointF GetFoundCarPos(); // funkcja zwracająca punkt, w którym wykryto obiekt - stara funkcja

        QPointF GetFoundCarPosNew(); // metoda zwracająca pozycję wyktytego samochodu
        QPointF GetFoundPedePos(); //zrobić taką samą dla pedestrianów - zwraca punkt !!
        QPointF GetRoadIntPos(); //metoda zwracająca środek skrzyżowania w układzie sceny
        QPointF GetPavIntPos(); // metoda zwracająca środek skrzyżowania - potrzebne???


        //możliwe że trzeba będzie wstawić tu wskaźniki

        void GetFoundRoadBegArr(QPointF qpfArr[],int iNbrOfObj); // metoda zwracająca tablicę położeń znaczników rozpoczęcia dróg i ilość obiektów
        void GetFoundPaveBegArr(QPointF qpfArr[],int iNbrOfObj); // metoda zwracająca tablicę położeń znaczników rozpoczęcia chodników


        //chyba niepotrzebne

        QList<QGraphicsItem *> GetSensCollItemList(); // metoda zwracająca listę obiektów, z którymi koliduje sensor


    protected:

        // flagi zmieniające się na TRUE jeżeli przynajmniej jeden obiekt
        // danego typu został znaleziony przy ostatnim wywołaniu funkcji FindObjects();

        bool bFoundRoadInter;
        bool bFoundPaveInter;
        bool bFoundBotPedestrian;
        bool bFoundBotCar;
        bool bFoundRoadBeg;
        bool bFoundPaveBeg;


        //zmienne do przechowywania pozycji wykrytego obiektu

        QPointF qpfFoundObjectsPos;
        QPointF qpfFoundRoadIntPos;
        QPointF qpfFoundPaveIntPos;
        QPointF qpfFoundBotPedePos;
        QPointF qpfFoundBotCarPos;


        //tablice znalezionych znaczników początku dróg

        int iFoundRoadBeg;
        int iFoundPaveBeg;

        QPointF qpfFoundRoadBegPosAr[4];
        QPointF qpfFoundPaveBegPosAr[4];


};

#endif // SENSOR_H
