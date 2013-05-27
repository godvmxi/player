#include "lrcwidget.h"

lrcWidget::lrcWidget(QWidget *parent) :
    QDockWidget(parent)
{
    this->setFeatures(QDockWidget::DockWidgetFloatable);
    this->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);
    this->setFixedSize(300,600);


    this->lrclabel=new QLabel();
    this->lrclabel->setText("hello");

    QHBoxLayout *backLayout = new QHBoxLayout();
    backLayout->addWidget(this->lrclabel);
    QWidget *backGround = new QWidget();
    backGround->setLayout(backLayout);
    this->setWidget(backGround);
}
