/********************************************************************************
** Form generated from reading UI file 'lrc.ui'
**
** Created: Fri Apr 5 16:20:04 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LRC_H
#define UI_LRC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_lrc
{
public:
    QLabel *label_now;
    QLabel *label_next;

    void setupUi(QDialog *lrc)
    {
        if (lrc->objectName().isEmpty())
            lrc->setObjectName(QString::fromUtf8("lrc"));
        lrc->resize(400, 107);
        label_now = new QLabel(lrc);
        label_now->setObjectName(QString::fromUtf8("label_now"));
        label_now->setGeometry(QRect(90, 20, 181, 17));
        label_next = new QLabel(lrc);
        label_next->setObjectName(QString::fromUtf8("label_next"));
        label_next->setGeometry(QRect(90, 60, 201, 17));

        retranslateUi(lrc);

        QMetaObject::connectSlotsByName(lrc);
    } // setupUi

    void retranslateUi(QDialog *lrc)
    {
        lrc->setWindowTitle(QApplication::translate("lrc", "Dialog", 0, QApplication::UnicodeUTF8));
        label_now->setText(QApplication::translate("lrc", "MUSIC", 0, QApplication::UnicodeUTF8));
        label_next->setText(QApplication::translate("lrc", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class lrc: public Ui_lrc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LRC_H
