#include <QtGui/QApplication>
#include "playermain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlayerMain w;
    w.show();

    return a.exec();
}
