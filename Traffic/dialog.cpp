#include "ui_dialog.h"
//biblioteka obsługującą wiadomości do debugowania kodu
#include <QDebug>
#include "moving_object.h"
#include "bot_pedestrian.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "dialog.h"
#include "bot_car.h"
#include <QApplication>
#include "sensor.h"





Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //tworzę scenę i przypisuję rodzica
    scene = new QGraphicsScene(this);

    //ustawiam scenę w widoku
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setBackgroundBrush(QPixmap(":/images/background.png"));
    // będzie identycznego rozmiaru jak widok i będzie w tym samym miejscu
    scene->setSceneRect(0,0,1500,900);

    // tworzę mapę
    NewMap = new Map();
    scene->addItem(NewMap);

    // zalecane w razie spowalniania animacji przy dużej ilości obiektów
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_AddPedestrian_clicked()
{

    qDebug() << "Kliknieto 'add pedestrian'";
    BotPedestrian = new Bot_Pedestrian();

    // funkcja wyszukująca (lub losująca) miejsca spawnu?
    scene->addItem(BotPedestrian);

    //zaczęło działać bez tego, więc nie wymuszam mu rodzica
    //BotPedestrian->setParent(ui->graphicsView);

    BotPedestrian->setPos(0,10);
}

void Dialog::on_pushButton_StartStopTimer_clicked()
{
    AllBotPedestrian->ChangeTimerState();
}

void Dialog::on_pushButton_AddRandomBotCar_clicked()
{
    //dodawanie samochodu do sceny
    BotCar = new Bot_Car();
    scene->addItem(BotCar);
    BotCar->setParent(scene);
    BotCar->setPos(50,85);

}

void Dialog::on_pushButton_KillSwitch_pressed()
{
    AllBotPedestrian->KillSwitchEngage();
}
