#include "map.h"
#include "pavement.h"
#include "road.h"
#include "road_intersection.h"
#include "pavement_intersection.h"


Map::Map()
{
    //wskaźnik pomocniczy do tworzenia obiektów
    pavement *NewPavement;
    road *NewRoad;
    road_intersection *NewRoadIntersection;
    pavement_intersection *NewPavementIntersection;

    //setRect(0,0,1500,900);

    // dodaję drogi
    //1
    NewRoad = new road(0,150,300,100,this);
    //2
    NewRoad = new road(400,150,1000,100,this);
    //3
    NewRoad = new road(1500,150,650,100,this);
    //4
    NewRoad = new road(2250,150,745,100,this);
    NewRoad->change_beginning_pos();

    //5
    NewRoad = new road(300,250,100,700,this);
    //6
    NewRoad = new road(1400,250,100,700,this);
    NewRoad->change_beginning_pos();
    //7
    NewRoad = new road(2150,250,100,700,this);


    //8
    NewRoad = new road(400,950,1000,100,this);
    NewRoad->change_beginning_pos();
    //9
    NewRoad = new road(1500,950,650,100,this);
    NewRoad->change_beginning_pos();
    //10
    NewRoad = new road(2250,950,745,100,this);


    //11
    NewRoad = new road(300,1050,100,500,this);
    //12
    NewRoad = new road(1400,1050,100,500,this);
    NewRoad->change_beginning_pos();

    //13
    NewRoad = new road(0,1550,300,100,this);
    //14
    NewRoad = new road(400,1550,1000,100,this);
    //15
    NewRoad = new road(1500,1550,1500,100,this);



    //dodaję skrzyżowania dróg
    //1
    NewRoadIntersection = new road_intersection(300,150,100,this);
    //2
    NewRoadIntersection = new road_intersection(1400,150,100,this);
    //3
    NewRoadIntersection = new road_intersection(2150,150,100,this);
    //4
    NewRoadIntersection = new road_intersection(300,950,100,this);
    //5
    NewRoadIntersection = new road_intersection(1400,950,100,this);
    //6
    NewRoadIntersection = new road_intersection(2150,950,100,this);
    //7
    NewRoadIntersection = new road_intersection(300,1550,100,this);
    //8
    NewRoadIntersection = new road_intersection(1400,1550,100,this);

    // dodaje chodniki
    //1
    NewPavement = new pavement(0,100,2995,50,this);

    //2
    NewPavement = new pavement(0,250,250,50,this);
    //3
    NewPavement = new pavement(450,250,900,50,this);
    //4
    NewPavement = new pavement(1550,250,550,50,this);
    //5
    NewPavement = new pavement(2300,250,695,50,this);
    //6
    NewPavement = new pavement(250,300,50,1200,this);
    //7
    NewPavement = new pavement(400,300,50,600,this);
    //8
    NewPavement = new pavement(1350,300,50,600,this);
    //9
    NewPavement = new pavement(1500,300,50,600,this);
    //10
    NewPavement = new pavement(2100,300,50,600,this);
    //11
    NewPavement = new pavement(2250,300,50,600,this);


    //12
    NewPavement = new pavement(450,900,900,50,this);
    //13
    NewPavement = new pavement(1550,900,550,50,this);
    //14
    NewPavement = new pavement(2300,900,695,50,this);

    //15
    NewPavement = new pavement(450,1050,900,50,this);
    //16
    NewPavement = new pavement(1550,1050,1445,50,this);

    //17
    NewPavement = new pavement(400,1100,50,400,this);
    //18
    NewPavement = new pavement(1350,1100,50,400,this);
    //19
    NewPavement = new pavement(1500,1100,50,400,this);

    //20
    NewPavement = new pavement(0,1500,250,50,this);
    //21
    NewPavement = new pavement(450,1500,900,50,this);
    //22
    NewPavement = new pavement(1550,1500,1445,50,this);

    //23
    NewPavement = new pavement(0,1650,2995,50,this);


    //dodaję skrzyżowania chodników
    //1
    NewPavementIntersection = new pavement_intersection(250,250,50,this);
    //2
    NewPavementIntersection = new pavement_intersection(400,250,50,this);
    //3
    NewPavementIntersection = new pavement_intersection(1350,250,50,this);
    //4
    NewPavementIntersection = new pavement_intersection(1500,250,50,this);
    //5
    NewPavementIntersection = new pavement_intersection(2100,250,50,this);
    //6
    NewPavementIntersection = new pavement_intersection(2250,250,50,this);

    //7
    NewPavementIntersection = new pavement_intersection(400,900,50,this);
    //8
    NewPavementIntersection = new pavement_intersection(1350,900,50,this);
    //9
    NewPavementIntersection = new pavement_intersection(1500,900,50,this);
    //10
    NewPavementIntersection = new pavement_intersection(2100,900,50,this);
    //11
    NewPavementIntersection = new pavement_intersection(2250,900,50,this);

    //12
    NewPavementIntersection = new pavement_intersection(400,1050,50,this);
    //13
    NewPavementIntersection = new pavement_intersection(1350,1050,50,this);
    //14
    NewPavementIntersection = new pavement_intersection(1500,1050,50,this);

    //15
    NewPavementIntersection = new pavement_intersection(250,1500,50,this);
    //16
    NewPavementIntersection = new pavement_intersection(400,1500,50,this);
    //17
    NewPavementIntersection = new pavement_intersection(1350,1500,50,this);
    //18
    NewPavementIntersection = new pavement_intersection(1500,1500,50,this);

    //przeskalowuję

    this->setScale(0.5);
}

