#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

//klasa abstrakcyjna, z której dziedziczą samochody i piesi

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>


//Dodaje tę bibliotekę, aby dalo się połączyć sygnał ze slotem
#include <QObject>

#include <qmath.h>


// chce zeby wariat był z klasy gotowej i do tego był z QObject
// stąd najpierw

// zmieniam QGraphicsRectItem na Pixmap żeby dodać grafikę
//class Wariat: public QObject, public QGraphicsRectItem

/* QGraphicItem wszystkie obiekty, które znajdą się w scenie muszą być z tej klasy i jej podklas.
Wszystkie obiety: samochody , piesi , droga itd. będą musiały wywodzić się z tej klasy */

class Moving_Object: public QObject, public QGraphicsPixmapItem
{

    // aby obiekt mógł wykorzystać sloty i sygnały muszę jeszcze dodać poniższe makro:
    Q_OBJECT


   public:


    static int iAllMovingObjects; // zmienna do zliczania wszystkich obiekótów
    static bool bMovObjTimerState; //zmienna sygnalizująca zmianę stanu timerów u wszystkich
    static bool bMovObjKillswitch; // flaga do sygnaizowania naciśnięcia klawisz niszczącego wszystkie obiekty


    Moving_Object();
    virtual ~Moving_Object();

    /*Jak bowiem wiemy, zniszczenie obiektu oznacza w pierwszej kolejności wywołanie tej
     * kluczowej metody. Podlega ono identycznym regułom, jakie stosują się do wszystkich innych metod,
     *  a więc także efektom związanym z wirtualnością oraz wczesnym i późnym wiązaniem.
     *  Jeżeli więc nasz destruktor nie będzie oznaczony jako virtual,
     *  to kompilator potraktuje go jako zwyczajną metodę i zastosuje wobec niej technikę wczesnego wiązania.
     */

    //Metody statyczne nie mają dostępu do niestatycznych metod i zmiennych!

    static void ChangeTimerState(); // metoda statyczna do zatrzymywania i włączania Timerów animacji wysztkich obiektów
    static void KillSwitchEngage(); // metoda statyczna do wymuszenia zniszczenia danego obiektu

    // normalizowanie kąta

    static qreal normalizeAngle(qreal angle);


    // tylko funkcje składowe klasy i zaprzyjaźnione
   private:



    //to samo tylko dochodzą jeszcze dziedziczące obiekty
   protected:

    QTimer *ObjectsPrivTimer; // prywatny timer obiektu do animacji ruchu

    qreal qrAngle; //zmienna do przechowywania kąta obiektu
    qreal qrAllAcceleration; //zmienna do zmiany prędkości z zewnątrz
    qreal qrPrivAccel; //zmienna do zmiany prędkości
    qreal qrBrakeCoef; //zmienna przechowująca wartość współczynnika hamowania nadawanego przez metdę SetBrakeCoef

    int licz; // zmienna testowa

    bool bTurning; // sygnalizacja manewru skręcania

    void ObjectTimerStart();// metoda do startowania TIMRA obiektu
    void ObjectTimerStop(); // metoda do stopowania TIMERA obiektu
    void DetectLeavingScene(); // metoda usuwająca obiekt, jeżeli opuści scenę
    void DetectKillSwitchChange(); // wykrycia naciśnięcia klawisza usuwającego obiekty i usuwuająca dany obiekt
    void TurnRight();// metoda do skręcania w prawo o 90 stopni

    void TurnLeft();// metoda do skręcania w lewo o 90 stopni




    virtual void SetBrakeCoef(QPointF qpfObject)=0; // funkcja zmieniająca współczynnki hamowania w zależności od najbliższego
                                                 // punktu obiektu

/*Do animowania wykorzystam sloty i sygnały. Sygnał jest sygnałem a slot reakcją na ten KONKRETNY sygnał.*/
// Slot is a member function that can be connected to the signal. Jedyna różnica jest taka że należy go umieścić w public slot.

public slots:

   virtual void move()=0; // public slot będący metodą czysto wirtualną, nadpisywany w obiekach dziedziczących z tej klasy
};

#endif // MOVING_OBJECT_H
