#include "controlbar.h"

ControlBar::ControlBar(QWidget *parent) :
    QDockWidget(parent)
{

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

    this->pushbutton_back->setIcon(QIcon(":/img/images/gtk-media-next-rtl.png"));
    this->pushbutton_forward->setIcon(QIcon(":/img/images/gtk-media-next-ltr.png"));
    this->pushbutton_play_pause->setIcon(QIcon(":/img/images/gtk-media-play-ltr.png"));
    this->pushbutton_mute->setIcon(QIcon(":/img/images/sound.png"));

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
    connect(this->pushbutton_play_pause,SIGNAL(clicked()),this,SLOT(buttonPausePlayLost()));
}
void ControlBar::paintEvent(QPaintEvent *event)
{
    //QPainter p(this);
    //p.setCompositionMode(QPainter::CompositionMode_Clear);
    //p.fillRect(10,10,300,300,Qt::SolidPattern);
    //p.fillRect(10,10,300,300, QColor(0,0xff,0,30));
}
void ControlBar::buttonPausePlayLost(void)
{
    static bool play = true;
    play = play? false:true;
    if (!play)
        this->pushbutton_play_pause->setIcon(QIcon(":/img/images/gtk-media-play-ltr.png"));
    else
        this->pushbutton_play_pause->setIcon(QIcon(":/img/images/gtk-media-pause.png"));
    emit this->playerCmdSender("pause\n");
}
