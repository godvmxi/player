/********************************************************************************
** Form generated from reading UI file 'dialoglrc.ui'
**
** Created: Fri Apr 5 16:23:40 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLRC_H
#define UI_DIALOGLRC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogLrc
{
public:
    QLabel *label_now;
    QLabel *label_next;

    void setupUi(QDialog *DialogLrc)
    {
        if (DialogLrc->objectName().isEmpty())
            DialogLrc->setObjectName(QString::fromUtf8("DialogLrc"));
        DialogLrc->resize(400, 300);
        label_now = new QLabel(DialogLrc);
        label_now->setObjectName(QString::fromUtf8("label_now"));
        label_now->setGeometry(QRect(90, 60, 66, 17));
        label_next = new QLabel(DialogLrc);
        label_next->setObjectName(QString::fromUtf8("label_next"));
        label_next->setGeometry(QRect(170, 180, 66, 17));

        retranslateUi(DialogLrc);

        QMetaObject::connectSlotsByName(DialogLrc);
    } // setupUi

    void retranslateUi(QDialog *DialogLrc)
    {
        DialogLrc->setWindowTitle(QApplication::translate("DialogLrc", "Dialog", 0, QApplication::UnicodeUTF8));
        label_now->setText(QApplication::translate("DialogLrc", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_next->setText(QApplication::translate("DialogLrc", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogLrc: public Ui_DialogLrc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLRC_H
