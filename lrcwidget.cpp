#include "lrcwidget.h"

lrcWidget::lrcWidget(QWidget *parent) :
    QDockWidget(parent)
{
<<<<<<< HEAD
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
=======
    this->setFixedSize(100,100);
    this->setFeatures(QDockWidget::DockWidgetFloatable);
    this->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);


>>>>>>> eeef18499b316077e94987f781ec318b9164866d
}
