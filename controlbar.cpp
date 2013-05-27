#include "controlbar.h"

ControlBar::ControlBar(QWidget *parent) :
    QDockWidget(parent)
{
     playlist=new PlayList();

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
    this->modebox=new QComboBox();

    this->pushbutton_back->setIcon(QIcon(":/img/images/gtk-media-next-rtl.png"));
    this->pushbutton_forward->setIcon(QIcon(":/img/images/gtk-media-next-ltr.png"));
    this->pushbutton_play_pause->setIcon(QIcon(":/img/images/gtk-media-play-ltr.png"));
    this->pushbutton_mute->setIcon(QIcon(":/img/images/sound.png"));
    this->modebox->setEditText("mode");

    this->pushbutton_back->setFixedSize(30,30);
    this->pushbutton_forward->setFixedSize(30,30);
    this->pushbutton_mute->setFixedSize(30,30);
    this->pushbutton_play_pause->setFixedSize(30,30);
    this->modebox->setFixedSize(110,30);

    QHBoxLayout *HbackLayout = new QHBoxLayout();
    HbackLayout->addWidget(this->pushbutton_back);
    HbackLayout->addWidget(this->pushbutton_play_pause);
    HbackLayout->addWidget(this->pushbutton_forward);
    HbackLayout->addWidget(this->pushbutton_mute);
    HbackLayout->addWidget(this->modebox);
    QWidget *backGround = new QWidget();
    backGround->setLayout(HbackLayout);
    this->setWidget(backGround);

    this->modebox->addItem("Single cycle");
    this->modebox->addItem("List cycle");
    this->modebox->addItem("Random");
    this->modebox->addItem("Normal");

    connect(this->pushbutton_play_pause,SIGNAL(clicked()),this,SLOT(buttonPausePlaySlot()));
    connect(this->pushbutton_back,SIGNAL(clicked()),playlist,SLOT(getBackMusic()));
    connect(this->pushbutton_forward,SIGNAL(clicked()),this,SLOT(buttonForwardSlot(void)));
    connect(this->pushbutton_mute,SIGNAL(clicked()),this,SLOT(buttonMuteSlot()));
    connect(this->modebox,SIGNAL(activated(int)),this,SLOT());

}
void ControlBar::paintEvent(QPaintEvent *event)
{
    //QPainter p(this);
    //p.setCompositionMode(QPainter::CompositionMode_Clear);
    //p.fillRect(10,10,300,300,Qt::SolidPattern);
    //p.fillRect(10,10,300,300, QColor(0,0xff,0,30));
}
void ControlBar::buttonPausePlaySlot(void)
{
    static bool play = true;
    play = play? false:true;
    if (!play)
        this->pushbutton_play_pause->setIcon(QIcon(":/img/images/gtk-media-play-ltr.png"));
    else
        this->pushbutton_play_pause->setIcon(QIcon(":/img/images/gtk-media-pause.png"));
    emit this->playerCmdSender("pause\n");
 //   emit this->playerCmdSender("get_time_pos\n");
}
void ControlBar::buttonBackSlot(void)
{

}
void ControlBar::buttonForwardSlot(void)
{
    qDebug()<<"play forward --> ";
}
void ControlBar::buttonMuteSlot(void)
{
    static bool mute = false;
    mute = mute? false:true;
    emit this->playerCmdSender("mute\n");
}
