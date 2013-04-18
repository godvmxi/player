#include "playermain.h"
#include "ui_playermain.h"
#include <QCalendarWidget>


PlayerMain::PlayerMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayerMain)
{
    ui->setupUi(this);
    //ui->verticalLayout_left->SetFixedSize()
    //video = new QProcess();
    //video->setProcessChannelMode(QProcess::MergedChannels);
    //QString cmd;
    //cmd.sprintf("mplayer -slave  -quiet /home/sunbird/media/starwars.mp4 -wid %d",ui->widget_video->winId());
    //cmd.sprintf("mplayer -vo x11 -zoom -quiet -slave -idle /home/sunbird/media/beyond.mp3  ");
    //qDebug()<<cmd;
    //video->start(cmd);

    pushbutton_play_pause = new QPushButton() ;
    pushbutton_forward = new QPushButton();
    pushbutton_back = new QPushButton();
    pushbutton_mute = new QPushButton();
    dial_vol = new QDial();
    dial_vol->resize(200,200);
    combobox_lrc = new QComboBox();


    tabview_playlist_music  = new QTableView();
    tabview_playlist_video  = new QTableView();
    tabwidge_playlist_tab = new QTabWidget();
    tabwidge_playlist_tab->setFixedSize(100,100);


    /*
    QVBoxLayout *dock_playlist_layout = new QVBoxLayout();
    dock_playlist_layout->addWidget(tabwidge_playlist_tab);
    dock_playlist_layout->addWidget(dial_vol);
    dock_playlist->setLayout(dock_playlist_layout);
    */


    dock_playlist = new PlayList(this);
    dock_control = new QDockWidget();
    //dock_playlist->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);
    //dock_playlist->setFixedSize(200,200);
    dock_playlist->setFloating(true);
    //dock_playlist->setWindowTitle("play list");

    //this->dock_playlist->setAllowedAreas(Qt::LeftDockWidgetArea);




    this->addDockWidget(Qt::NoDockWidgetArea,this->dock_playlist);





    /*;
    QVBoxLayout *left = new QVBoxLayout();

    QVBoxLayout *playButtonsLayout = new QVBoxLayout();
    playButtonsLayout->addWidget(ui->pushButton_play_pause);
    playButtonsLayout->addWidget(ui->pushButton_forward);
    playButtonsLayout->addWidget(ui->pushButton_back);
    QHBoxLayout *leftTop1Layout = new QHBoxLayout();
    leftTop1Layout->addWidget(ui->horizontalSlider_process);

    leftTop1Layout->setSizeConstraint(QLayout::SetFixedSize);

    QVBoxLayout *muteButtonsLayout = new QVBoxLayout();
    playButtonsLayout->addWidget(ui->pushButton_mute);
    playButtonsLayout->addWidget(ui->checkBox_lrc);

    QVBoxLayout *volLayout = new QVBoxLayout();
    playButtonsLayout->addWidget(ui->dial_vol);

    QHBoxLayout *leftTop2Layout = new QHBoxLayout();
    leftTop2Layout->addLayout(playButtonsLayout);
    leftTop2Layout->addLayout(volLayout);
    leftTop2Layout->addLayout(muteButtonsLayout);

    QHBoxLayout *leftTop3Layout = new QHBoxLayout();
    leftTop3Layout->addWidget(ui->tabWidget);

    left->addLayout(leftTop1Layout);
    left->addLayout(leftTop2Layout);
    left->addLayout(leftTop3Layout);
    */

}

PlayerMain::~PlayerMain()
{
    delete ui;
}
