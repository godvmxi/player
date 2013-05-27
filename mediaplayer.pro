#-------------------------------------------------
#
# Project created by QtCreator 2013-04-08T20:24:13
#
#-------------------------------------------------

QT       += core gui xml

TARGET = mediaplayer
TEMPLATE = app


SOURCES += main.cpp\
        playermain.cpp \
    playlist.cpp \
    controlbar.cpp \
    lrcwidget.cpp

HEADERS  += playermain.h \
    playlist.h \
    controlbar.h \
    lrcwidget.h

FORMS    += playermain.ui

RESOURCES += \
    res.qrc
