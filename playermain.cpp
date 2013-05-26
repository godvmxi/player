#include "playermain.h"
#include "ui_playermain.h"
#include <QCalendarWidget>


PlayerMain::PlayerMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayerMain)
{
    ui->setupUi(this);

    //video = new QProcess();
    //video->setProcessChannelMode(QProcess::MergedChannels);
    //QString cmd;
    //cmd.sprintf("mplayer -slave  -quiet /home/sunbird/media/starwars.mp4 -wid %d",ui->widget_video->winId());
    //cmd.sprintf("mplayer -vo x11 -zoom -quiet -slave -idle /home/sunbird/media/beyond.mp3  ");
    //qDebug()<<cmd;
    //video->start(cmd);
    this->processPlay = new QProcess(this);
    this->processPlay->setProcessChannelMode(QProcess::MergedChannels);



    dock_playlist = new PlayList(this);

    dock_playlist->setFloating(true);
    this->addDockWidget(Qt::NoDockWidgetArea,this->dock_playlist);

    connect(this->dock_playlist,SIGNAL(playMusic(QString,QString)),this,SLOT(playMusicSource(QString,QString)));
    connect(this->dock_playlist,SIGNAL(playMovie(QString,QString)),this,SLOT(playMovieSource(QString,QString)));

    this->controlBar = new ControlBar();
    this->addDockWidget(Qt::BottomDockWidgetArea,(QDockWidget *)(this->controlBar));
    this->controlBar->setFloating(true);
    connect(this->controlBar,SIGNAL(playerCmdSender(QString)),this,SLOT(playerControlCmdSlots(QString)));
    //this->addDockWidget(Qt::NoDockWidgetArea,this->controlBar);

    this->lrc  = new lrcWidget();
    this->addDockWidget(Qt::BottomDockWidgetArea,this->lrc);
    this->lrc->setFloating(true);
    //this->widgetPlayMain = new QWidget();
    //this->widgetPlayMain->setGeometry(0,0,400,200);
    //this->setMinimumSize(400,200);
    //this->widgetPlayMain->show();
    this->hide();

}

PlayerMain::~PlayerMain()
{
    delete ui;
}

bool PlayerMain::playMovieSource(QString media,QString lrc)
{

    this->processPlay->close();
    //this->playCmd = QString("mplayer -slave  -quiet %1 -wid %2").arg(media).arg(this->widgetPlayMain->winId());
    this->playCmd = QString("mplayer -slave  -quiet %1 -wid %2").arg(media).arg(ui->widgetPlayMain->winId());

    qDebug()<<"movie ->  "<<media<<lrc<<this->playCmd ;
    this->processPlay->start(this->playCmd);
    return true;
}

bool PlayerMain::playMusicSource(QString media,QString lrc)
{


    this->processPlay->close();
    media = media.replace(" ","\ ");
    this->playCmd = QString("mplayer -vo x11 -zoom -quiet -slave -idle \"%1\"").arg(media);
    qDebug()<<"music ->  "<<media<<lrc<<this->playCmd;
    this->processPlay->start(this->playCmd);
    return true;
}
void PlayerMain::playerControlCmdSlots(QString cmd)
{
    qDebug()<<"input cmd --> "<<cmd;
    this->processPlay->write(cmd.toAscii());
    qDebug()<<this->processPlay->readAll();
}


