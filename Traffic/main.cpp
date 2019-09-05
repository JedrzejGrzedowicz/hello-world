#include "dialog.h"
#include <QApplication>


// ustawiam ten ui jako external, żeby obiekty swobodnie z niego korzystały

Dialog *MainDialog;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //zamieniam
    //Dialog w;
    //w.show();

    MainDialog = new Dialog();
    MainDialog->show();

    return a.exec();
}
