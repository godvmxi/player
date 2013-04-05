#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Media Player"));
    audio=new Phonon::MediaObject();
    audio->setTickInterval(1);
    audioOutput=new Phonon::AudioOutput(Phonon::VideoCategory);
    Phonon::createPath(audio,audioOutput);
    msicinfoObj=new Phonon::MediaObject(this);

    volumeSlider=new Phonon::VolumeSlider(audioOutput,this);
    volumeSlider->move(190,100);
    volumeSlider->resize(50,20);
    volumeSlider->setStyleSheet("background-color:rgb(255,255,255,255,100)");
    volumeSlider->setFixedWidth(100);

    seekSlider=new Phonon::SeekSlider(audio,this);
    seekSlider->move(10,35);
    seekSlider->resize(170,20);
    seekSlider->setStyleSheet("background-color:rgb(255,255,255,255,100)");
    creatActions();
    this->numberOfMusic = 0;
    this->currentIndex = 0;
    connect(ui->listWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_doubleClick_listItems(QModelIndex)));


}

Widget::~Widget()
{
    delete ui;
}








void Widget::creatActions()
{
    QIcon iconremove(":/images/remove.png");
    QIcon iconstop(":/images/gtk-media-stop.png");
    QIcon iconopen(":/images/gtk-open.png");
    QIcon iconsound(":/images/sound.png");
    QIcon iconexit(":/images/exit.png");
    iconPause=new QIcon(":/images/gtk-media-pause.png");
    iconPlay=new QIcon(":/images/gtk-media-play-ltr.png");

    remove=new QAction(iconremove,tr("clear the list"),this);
    connect(remove,SIGNAL(triggered()),this,SLOT(removeSlot()));

    play=new QAction(*iconPlay,tr("play"),this);
    connect(play,SIGNAL(triggered()),this,SLOT(on_toolButton_playpause_clicked()));

    stop=new QAction(iconstop,tr("stop"),this);
    connect(stop,SIGNAL(triggered()),this,SLOT(on_toolButton_playstop_clicked()));

    open=new QAction(iconopen,tr("open"),this);
    connect(open,SIGNAL(triggered()),this,SLOT(on_toolButton_open_clicked()));

    sound=new QAction(iconsound,tr("quite"),this);
    sound->setChecked(true);
    connect(sound,SIGNAL(triggered(bool)),audioOutput,SLOT(setMuted(bool)));

    exit=new QAction(iconexit,tr("exit"),this);
    connect(exit,SIGNAL(triggered()),this,SLOT(exitSlot()));
}

void Widget::on_toolButton_list_clicked()
{
    qDebug()<<"tool button list";
}

void Widget::on_toolButton_lrc_clicked()
{
    qDebug()<<"tool button lrc";
}
void Widget::removeSlot(){

    qDebug()<<"remove slot";

}



void Widget::on_toolButton_next_clicked()
{

    this->currentIndex++;
    if(this->currentIndex >= this->numberOfMusic-1){
        this->currentIndex = 0;
    }

    currentSource = sourceList.at(this->currentIndex);
    qDebug()<<"next music -->" << this->currentIndex+1 <<currentSource.fileName();

    audio->stop();
    audio->setCurrentSource(currentSource);
    audio->play();

}

void Widget::on_toolButton_last_clicked()
{
    qDebug()<<"last music";
    this->currentIndex--;
    if(this->currentIndex < 0){
        this->currentIndex = this->numberOfMusic-1;
    }

    currentSource = sourceList.at(this->currentIndex);
    qDebug()<<"next music -->" << this->currentIndex+1 <<currentSource.fileName();

    audio->stop();
    audio->setCurrentSource(currentSource);
    audio->play();
}
void Widget::on_toolButton_playpause_clicked()
{
    if(sourceList.isEmpty())
    {
        QMessageBox::information(this,tr("No Music"),tr("No Files to play!"));
        return ;
    }
//    audio->setQueue(sourceList);
    if(audio->state()==Phonon::PlayingState)
    {
        audio->pause();

        ui->toolButton_playpause->setIcon(*iconPlay);
    }
    else
    {
        audio->play();

        ui->toolButton_playpause->setIcon(*iconPause);
    }
}
void Widget::on_toolButton_playstop_clicked()
{
    if(sourceList.isEmpty())
    {
        QMessageBox::information(this,tr("No Music"),tr("No Files to play!"));
        return ;
    }
//    audio->setQueue(sourceList);
    if(audio->state()==Phonon::PlayingState)
    {
        audio->pause();

        songTimer.stop();
    }
    else
    {
        audio->play();
        songTimer.start(1000);
    }
}

void Widget::on_toolButton_stop_clicked()
{
    audio->stop();
}
void Widget::on_toolButton_open_clicked()
{
    qDebug()<<"open file list";
    QStringList files=QFileDialog::getOpenFileNames(this,tr("selete files to play"),"/media/dan/DOWN/music/","Music (*.wma *.mp3)");
    QString file;

    if(files.count() == 0){
        qDebug()<<"I didn't find the music";
        QMessageBox::information(this,tr("No Music added"),tr("No Music added!"));
        return;
    }
    this->numberOfMusic += files.count();
    qDebug()<<"get music number -> "<<this->numberOfMusic;


    QFileInfo fileinfo;
    foreach(file,files)
    {

        sourceList.append(file);
        fileinfo.setFile(file);
        qDebug()<<"file path"<<fileinfo.absoluteFilePath()<<"file baseName:"<<fileinfo.baseName()<<"bundleName"<<fileinfo.bundleName();
        ui->listWidget->addItem(fileinfo.baseName());

    }
    audio->setQueue(sourceList);
    currentSource = sourceList.at(this->currentIndex);
    qDebug()<<"next music -->" << this->currentIndex+1 <<currentSource.fileName();
    audio->setCurrentSource(this->currentSource);
    audio->setTickInterval(1000);
    connect(audio,SIGNAL(tick(qint64)),this,SLOT(refreshTime()));

    audio->play();
    ui->toolButton_playpause->setIcon(*iconPause);
//    QMap<QString,QString> metaData = audio->metaData();
//    QList<QString> title = metaData.value("TITLE");
//    qDebug()<<"title -> "<<file;
//    foreach(file,title){
//        qDebug()<<"title -> "<<file;
//    }



 //   QMediaObject metaData = audio->metaData();
//    qDebug()<<  audio->metaData.value(0).at(0);
//    qDebug()<<  audio->metaData.value(1).at(0);
//    qDebug()<<  audio->metaData.value(2).at(0);
//    qDebug()<<  audio->metaData.value(3).at(0);
//    qDebug()<<  audio->metaData.value(4).at(0);
//    qDebug()<<  audio->metaData.value(5).at(0);
//    qDebug()<<  audio->metaData.value(6).at(0);
//    qDebug()<< audio->metaData.value(7).at(0);


}
void Widget::refreshTime()
{
//    songTimer.stop();
//    songTimer.setInterval(1000);
//    currentSource = sourceList.at(this->currentIndex);
//  songTimer.start(1000);
    qint64 currentMinute = audio->currentTime()/60000;
    qint64 currentSecond= audio->currentTime()%60000 /1000;
    qint64 totalMinute = audio->totalTime()/60000;
    qint64 totalSecond= audio->totalTime()%60000 /1000;
    QString timeLabel;
    timeLabel.sprintf("%2d:%2d / %2d:%2d",currentMinute,currentSecond,totalMinute,totalSecond);
    ui->labelTime->setText(timeLabel);
//    qDebug()<<"i am in timer"<<audio->currentTime()<<audio->totalTime();

}
void Widget::on_doubleClick_listItems(QModelIndex index)
{
 //   qDebug()<<"double click"<<index.column()<<index.row();
    currentIndex = index.row();
    audio->stop();
    audio->setCurrentSource(this->sourceList.at(currentIndex));
    audio->play();
    //get all necessary message for you
    QMap<QString,QString> metaData = audio->metaData();

    qDebug()<<"meta data -> "<<metaData.value("ARTIST")<<metaData.value("ALBUM")<<metaData.value("TITLE")<<metaData.value("DATA")<<metaData.value("GENRE")\
           <<metaData.value("TRACK")<<metaData.value("DESCRIPTION")<<metaData.value("MUSICBRAINZDISCID");

}


