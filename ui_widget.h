/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Fri Apr 5 21:21:10 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *labelTime;
    QListWidget *listWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_last;
    QToolButton *toolButton_playpause;
    QToolButton *toolButton_stop;
    QToolButton *toolButton_next;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_open;
    QToolButton *toolButton_list;
    QToolButton *toolButton_lrc;
    QTableWidget *tableWidget_list;
    QComboBox *comboBox_playMode;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 495);
        labelTime = new QLabel(Widget);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(270, 10, 81, 20));
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 200, 0, 0));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 140, 151, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_last = new QToolButton(layoutWidget);
        toolButton_last->setObjectName(QString::fromUtf8("toolButton_last"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/gtk-media-next-rtl.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_last->setIcon(icon);

        horizontalLayout->addWidget(toolButton_last);

        toolButton_playpause = new QToolButton(layoutWidget);
        toolButton_playpause->setObjectName(QString::fromUtf8("toolButton_playpause"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/gtk-media-play-ltr.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_playpause->setIcon(icon1);

        horizontalLayout->addWidget(toolButton_playpause);

        toolButton_stop = new QToolButton(layoutWidget);
        toolButton_stop->setObjectName(QString::fromUtf8("toolButton_stop"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/gtk-media-stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_stop->setIcon(icon2);

        horizontalLayout->addWidget(toolButton_stop);

        toolButton_next = new QToolButton(layoutWidget);
        toolButton_next->setObjectName(QString::fromUtf8("toolButton_next"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/gtk-media-next-ltr.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_next->setIcon(icon3);

        horizontalLayout->addWidget(toolButton_next);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(260, 140, 125, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton_open = new QToolButton(layoutWidget1);
        toolButton_open->setObjectName(QString::fromUtf8("toolButton_open"));

        horizontalLayout_2->addWidget(toolButton_open);

        toolButton_list = new QToolButton(layoutWidget1);
        toolButton_list->setObjectName(QString::fromUtf8("toolButton_list"));

        horizontalLayout_2->addWidget(toolButton_list);

        toolButton_lrc = new QToolButton(layoutWidget1);
        toolButton_lrc->setObjectName(QString::fromUtf8("toolButton_lrc"));

        horizontalLayout_2->addWidget(toolButton_lrc);

        tableWidget_list = new QTableWidget(Widget);
        if (tableWidget_list->columnCount() < 4)
            tableWidget_list->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_list->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_list->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_list->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_list->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_list->setObjectName(QString::fromUtf8("tableWidget_list"));
        tableWidget_list->setGeometry(QRect(20, 190, 350, 271));
        comboBox_playMode = new QComboBox(Widget);
        comboBox_playMode->setObjectName(QString::fromUtf8("comboBox_playMode"));
        comboBox_playMode->setGeometry(QRect(260, 90, 111, 27));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        labelTime->setToolTip(QApplication::translate("Widget", "time", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelTime->setText(QApplication::translate("Widget", "00:00/00:00", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_last->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>last</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_last->setText(QApplication::translate("Widget", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_playpause->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>play</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_playpause->setText(QApplication::translate("Widget", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_stop->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>pause</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_stop->setText(QApplication::translate("Widget", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_next->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>next</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_next->setText(QApplication::translate("Widget", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_open->setToolTip(QApplication::translate("Widget", "open", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_open->setText(QApplication::translate("Widget", "open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_list->setToolTip(QApplication::translate("Widget", "list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_list->setText(QApplication::translate("Widget", "list", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_lrc->setToolTip(QApplication::translate("Widget", "lrc", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_lrc->setText(QApplication::translate("Widget", "lrc", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_list->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\346\255\214\350\257\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_list->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "\351\237\263\344\271\220", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_list->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "\351\237\263\344\271\220\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_list->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "\346\255\214\350\257\215\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
        comboBox_playMode->clear();
        comboBox_playMode->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\351\241\272\345\272\217\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\345\205\250\351\203\250\345\276\252\347\216\257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\345\215\225\346\233\262\345\276\252\347\216\257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\351\232\217\346\234\272\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
