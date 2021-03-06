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
    connect(this->processPlay,SIGNAL(stateChanged(QProcess::ProcessState)),this,SLOT(mediaStateChanged(QProcess::ProcessState)));

    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/img/images/music.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    dock_playlist = new PlayList(this);
    dock_playlist->setFloating(true);
    this->addDockWidget(Qt::NoDockWidgetArea,this->dock_playlist);


    connect(this->dock_playlist,SIGNAL(playMusic(QString,QString)),this,SLOT(playMusicSource(QString,QString)));
    connect(this->dock_playlist,SIGNAL(playMovie(QString,QString)),this,SLOT(playMovieSource(QString,QString)));

    this->controlBar = new ControlBar();
    this->addDockWidget(Qt::BottomDockWidgetArea,(QDockWidget *)(this->controlBar));
    this->controlBar->setFloating(true);
    connect(this->controlBar,SIGNAL(playerCmdSender(QString)),this,SLOT(playerControlCmdSlots(QString)));
    connect(this->controlBar,SIGNAL(BackMusic(bool)),this->dock_playlist,SLOT(getBackMusic(bool)));
    connect(this->controlBar,SIGNAL(ForwardMusic(bool)),this->dock_playlist,SLOT(getForwardMusic(bool)));
    connect(this->controlBar->slider_progress,SIGNAL(valueChanged(int)),this,SLOT(mediaProgessChanged(int)));

    connect(this->controlBar,SIGNAL(modeChanged(int)),this->dock_playlist,SLOT(getplayMode(int)));
    connect(this,SIGNAL(getNextMedia()),this->dock_playlist,SLOT(getNextMusic()));




    this->lrc  = new lrcWidget();
    this->addDockWidget(Qt::BottomDockWidgetArea,this->lrc);
    this->lrc->setFloating(true);


    //this->widgetPlayMain = new QWidget();
    //this->widgetPlayMain->setGeometry(0,0,400,200);
    //this->setMinimumSize(400,200);
    //this->widgetPlayMain->show();

//    this->musicStyle =new QLabel();
//    this->musicGif = new QMovie();
//    this->musicGif->setFileName(":/img/images/style.gif");
//    this->musicStyle->setMovie(this->musicGif);
//    this->musicGif->start();

//    QHBoxLayout *gif = new QHBoxLayout();
//    this->musicStyle->move(15,5);
//    gif->addWidget(this->musicStyle);

 //   ui->widgetPlayMain->setLayout(gif);
    ui->widgetPlayMain->move(15,5);


}

PlayerMain::~PlayerMain()
{
    delete ui;
}
void PlayerMain::mediaStateChanged(QProcess::ProcessState newstate)
{
    if(newstate == QProcess::NotRunning)
        emit getNextMedia();
}
void PlayerMain::mediaProgessChanged(int Newprogess)
{

}

bool PlayerMain::playMovieSource(QString media,QString lrc)
{
    //add your lrc set method
    this->processPlay->close();
    //this->playCmd = QString("mplayer -slave  -quiet %1 -wid %2").arg(media).arg(this->widgetPlayMain->winId());
    //this->playCmd = QString("mplayer -slave  -quiet %1 -wid %2").arg(media).arg(ui->widgetPlayMain->winId());

    this->playCmd = QString("mplayer -slave  -quiet %1 -wid %2").arg(media).arg(ui->centralWidget->winId());

    qDebug()<<"movie ->  "<<media<<lrc<<this->playCmd ;
    this->processPlay->start(this->playCmd);

    this->changBackGroud(false);
    return true;
}

bool PlayerMain::playMusicSource(QString media,QString lrc)
{

    this->lrc->setLrcPath(lrc);
    //this->lrc->startStopLrc(true);

    this->changBackGroud(true);

    this->processPlay->close();
    media = media.replace(" ","\ ");
    this->playCmd = QString("mplayer -vo x11 -zoom -quiet -slave -idle \"%1\"").arg(media);
    qDebug()<<"music ->  "<<media<<lrc<<this->playCmd;
    this->processPlay->start(this->playCmd);

    this->lrc->startStopLrc(true);


    return true;
}
void PlayerMain::playerControlCmdSlots(QString cmd)
{
    qDebug()<<"input cmd --> "<<cmd;
    this->processPlay->write(cmd.toAscii());
    qDebug()<<this->processPlay->readAll();
}
void PlayerMain::changBackGroud(bool type)
{
//    if(type){
//        //show music

//        //QStringList gifLib;
//        //gitLib <<":/img/images/style.gif"<<":/img/images/style1.gif"<<":/img/images/style2.gif"<<":/img/images/style3.gif";

////        this->musicGif->stop();
////        this->musicGif->setFileName(":/img/images/style.gif");
////        this->musicGif->start();

//        ui->widgetPlayMain->show();
//    }
//    else{
//        //show movie
//        ui->widgetPlayMain->hide();
//    }
}

