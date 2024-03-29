#-------------------------------------------------
#
# Project created by QtCreator 2019-07-19T20:32:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Traffic
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        bot_car.cpp \
        bot_pedestrian.cpp \
        main.cpp \
        dialog.cpp \
        map.cpp \
        moving_object.cpp \
        pavement.cpp \
        pavement_beginning.cpp \
        pavement_intersection.cpp \
        road.cpp \
        road_beginning.cpp \
        road_intersection.cpp \
        sensor.cpp

HEADERS += \
        bot_car.h \
        bot_pedestrian.h \
        dialog.h \
        map.h \
        moving_object.h \
        pavement.h \
        pavement_beginning.h \
        pavement_intersection.h \
        road.h \
        road_beginning.h \
        road_intersection.h \
        sensor.h

FORMS += \
        dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
