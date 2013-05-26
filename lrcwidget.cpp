#include "lrcwidget.h"

lrcWidget::lrcWidget(QWidget *parent) :
    QDockWidget(parent)
{
    this->setFixedSize(100,100);
    this->setFeatures(QDockWidget::DockWidgetFloatable);
    this->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);


}
