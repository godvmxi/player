#-------------------------------------------------
#
# Project created by QtCreator 2012-11-02T22:04:11
#
#-------------------------------------------------

QT       += core gui
QT       += phonon
TARGET = MyMusicPlayer.exe
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    dockwidgetlrc.cpp

HEADERS  += widget.h \
    dockwidgetlrc.h

FORMS    += widget.ui \
    dockwidgetlrc.ui

RESOURCES += \
    images.qrc
