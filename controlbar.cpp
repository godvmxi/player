#include "controlbar.h"

ControlBar::ControlBar(QWidget *parent) :
    QDockWidget(parent)
{
    //setWindowOpacity(0.7);
    //this->setWindowOpacity(0);
    //QPalette pal = palette();
    //pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));

    //setPalette(pal);
    //setAutoFillBackground(true);
    this->setFixedHeight(100);
    this->setMinimumWidth(300);
    this->setMaximumWidth(800);
   // this->setFloating(true);
    this->setFeatures(QDockWidget::DockWidgetFloatable);
    //setAttribute(Qt::WA_TranslucentBackground,true);

    this->pushbutton_back = new QPushButton();
    this->pushbutton_forward = new QPushButton();
    this->pushbutton_mute = new QPushButton();
    this->pushbutton_play_pause = new QPushButton();

    this->pushbutton_back->setFixedSize(30,30);
    this->pushbutton_forward->setFixedSize(30,30);
    this->pushbutton_mute->setFixedSize(30,30);
    this->pushbutton_play_pause->setFixedSize(30,30);
    QHBoxLayout *backLayout = new QHBoxLayout();
    backLayout->addWidget(this->pushbutton_back);
    backLayout->addWidget(this->pushbutton_play_pause);
    backLayout->addWidget(this->pushbutton_forward);
    backLayout->addWidget(this->pushbutton_mute);
    QWidget *backGround = new QWidget();
    backGround->setLayout(backLayout);
    this->setWidget(backGround);


}
void ControlBar::paintEvent(QPaintEvent *event)
{
    //QPainter p(this);
    //p.setCompositionMode(QPainter::CompositionMode_Clear);
    //p.fillRect(10,10,300,300,Qt::SolidPattern);
    //p.fillRect(10,10,300,300, QColor(0,0xff,0,30));
}
