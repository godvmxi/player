#include <QtGui/QApplication>
#include "widget.h"
#include<QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    return a.exec();
}
