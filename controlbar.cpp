#include "controlbar.h"

ControlBar::ControlBar(QWidget *parent) :
    QDockWidget(parent)
{
    this->setFixedHeight(100);
    this->setMinimumWidth(300);
    this->setMaximumWidth(800);
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/img/images/background4.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
  //  this->setBackgroundRole(QPalette::Window);
   // this->setFloating(true);
    this->setFeatures(QDockWidget::DockWidgetFloatable);
    //setAttribute(Qt::WA_TranslucentBackground,true);

    this->pushbutton_back = new QPushButton();
    this->pushbutton_forward = new QPushButton();
    this->pushbutton_mute = new QPushButton();
    this->pushbutton_play_pause = new QPushButton();
    this->pushbutton_fastforward = new QPushButton();
    this->pushbutton_fastbackward = new QPushButton();

    this->slider_progress = new QSlider(Qt::Horizontal);
    this->modebox=new QComboBox();

    this->pushbutton_back->setIcon(QIcon(":/img/images/gtk-media-next-rtl.png"));
    this->pushbutton_forward->setIcon(QIcon(":/img/images/gtk-media-next-ltr.png"));
    this->pushbutton_play_pause->setIcon(QIcon(":/img/images/gtk-media-play-ltr.png"));
    this->pushbutton_mute->setIcon(QIcon(":/img/images/sound.png"));
    this->pushbutton_fastforward->setIcon(QIcon(":/img/images/next.png"));
    this->pushbutton_fastbackward->setIcon(QIcon(":/img/images/previous.png"));

  // this->modebox->setEditText("mode");

    this->pushbutton_back->setFixedSize(30,30);
    this->pushbutton_forward->setFixedSize(30,30);
    this->pushbutton_mute->setFixedSize(30,30);
    this->pushbutton_play_pause->setFixedSize(30,30);
    this->pushbutton_play_pause->setFixedSize(30,30);
    this->slider_progress->setFixedSize(150,50);

    this->modebox->setFixedSize(110,30);

    QHBoxLayout *HbackLayout = new QHBoxLayout();
    HbackLayout->addWidget(this->pushbutton_back);
    HbackLayout->addWidget(this->pushbutton_fastbackward);
    HbackLayout->addWidget(this->pushbutton_play_pause);
    HbackLayout->addWidget(this->pushbutton_fastforward);
    HbackLayout->addWidget(this->pushbutton_forward);
    HbackLayout->addWidget(this->pushbutton_mute);
  //  HbackLayout->addWidget(this->slider_progress);
    HbackLayout->addWidget(this->modebox);
    QWidget *backGround = new QWidget();
    backGround->setLayout(HbackLayout);
    this->setWidget(backGround);

    this->modebox->addItem("play once");
    this->modebox->addItem("Single cycle");
    this->modebox->addItem("Normal");
    this->modebox->addItem("Random");

    connect(this->pushbutton_play_pause,SIGNAL(clicked(void)),this,SLOT(buttonPausePlaySlot(void)));
    connect(this->pushbutton_mute,SIGNAL(clicked()),this,SLOT(buttonMuteSlot()));
    connect(this->pushbutton_back,SIGNAL(clicked(bool)),this,SLOT(buttonBackSlot(bool)));
    connect(this->pushbutton_forward,SIGNAL(clicked(bool)),this,SLOT(buttonForwardSlot(bool)));
    connect(this->modebox,SIGNAL(activated(int)),this,SLOT(modeBoxSlot(int)));
    connect(this->pushbutton_fastforward,SIGNAL(clicked()),this,SLOT(buttonFastforward()));
    connect(this->pushbutton_fastbackward,SIGNAL(clicked()),this,SLOT(buttonFastbackward()));



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
}
void ControlBar::buttonFastforward()
{
     emit this->playerCmdSender("seek 22\n");
}
void ControlBar::buttonFastbackward()
{
     emit this->playerCmdSender("seek -22\n");
}
void ControlBar::buttonMuteSlot(void)
{
    emit this->playerCmdSender("mute\n");
   // emit this->playerCmdSender("get_time_pos\n");
   //  emit this->playerCmdSender("get_time_length\n");
}
void ControlBar::buttonBackSlot(bool back)
{
    emit BackMusic(back);
}
void ControlBar::buttonForwardSlot(bool forward)
{
    emit ForwardMusic(forward);
}
void ControlBar::modeBoxSlot(int mode)
{
    emit modeChanged(mode);
}

