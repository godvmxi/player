/********************************************************************************
** Form generated from reading UI file 'dockwidgetlrc.ui'
**
** Created: Fri Apr 5 18:25:07 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCKWIDGETLRC_H
#define UI_DOCKWIDGETLRC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DockWidgetLrc
{
public:
    QWidget *dockWidgetContents;
    QLabel *label_lrc_now;
    QLabel *label_lrc_next;

    void setupUi(QDockWidget *DockWidgetLrc)
    {
        if (DockWidgetLrc->objectName().isEmpty())
            DockWidgetLrc->setObjectName(QString::fromUtf8("DockWidgetLrc"));
        DockWidgetLrc->resize(400, 165);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        label_lrc_now = new QLabel(dockWidgetContents);
        label_lrc_now->setObjectName(QString::fromUtf8("label_lrc_now"));
        label_lrc_now->setGeometry(QRect(110, 20, 66, 17));
        label_lrc_next = new QLabel(dockWidgetContents);
        label_lrc_next->setObjectName(QString::fromUtf8("label_lrc_next"));
        label_lrc_next->setGeometry(QRect(110, 80, 66, 17));
        DockWidgetLrc->setWidget(dockWidgetContents);

        retranslateUi(DockWidgetLrc);

        QMetaObject::connectSlotsByName(DockWidgetLrc);
    } // setupUi

    void retranslateUi(QDockWidget *DockWidgetLrc)
    {
        DockWidgetLrc->setWindowTitle(QApplication::translate("DockWidgetLrc", "lrc tab", 0, QApplication::UnicodeUTF8));
        label_lrc_now->setText(QApplication::translate("DockWidgetLrc", "........", 0, QApplication::UnicodeUTF8));
        label_lrc_next->setText(QApplication::translate("DockWidgetLrc", "........", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DockWidgetLrc: public Ui_DockWidgetLrc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCKWIDGETLRC_H
