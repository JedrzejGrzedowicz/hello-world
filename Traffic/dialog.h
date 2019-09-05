#ifndef DIALOG_H
#define DIALOG_H

//klasa Dialog wyświetla UI oraz wszystkie elementy symulacji

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
#include "moving_object.h"
#include "bot_pedestrian.h"
#include "bot_car.h"
#include "map.h"
#include "pavement.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
// metody klaswiszy

private slots:
    void on_pushButton_AddPedestrian_clicked();

    void on_pushButton_StartStopTimer_clicked();

    void on_pushButton_AddRandomBotCar_clicked();

    void on_pushButton_KillSwitch_pressed();

private:
    // wskaźnik do tworzenia UI
    Ui::Dialog *ui;

    // dodaję wskaźniki pomocnicze

    QGraphicsScene *scene;
    Moving_Object *CAllMovingObjects;
    Bot_Pedestrian *AllBotPedestrian;
    Bot_Pedestrian *BotPedestrian;
    Bot_Car *BotCar;
    Map *NewMap;

};

#endif // DIALOG_H
