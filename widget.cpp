#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Pretty Girl Player"));


    this->audioSource = NULL;
    ui->tableWidget_list->setEditTriggers ( QAbstractItemView::NoEditTriggers );
    ui->tableWidget_list->setSelectionMode ( QAbstractItemView::SingleSelection);
 //   ui->tableWidget_list->setColumnWidth(0,50);
 //   ui->tableWidget_list->setColumnWidth(1,300);
   // ui->tableWidget_list->resize(QSize(100));
    this->lrcHide = 0;
    musicLrc = new DockWidgetLrc;
    qDebug()<<"lrchide"<<this->lrcHide;
    if(this->lrcHide)
    {
        musicLrc->hide();
    }
    else
        musicLrc->show();

    this->playMode = ui->comboBox_playMode->currentIndex();
    qDebug()<<"play mode ->"<<ui->comboBox_playMode->currentText();



    audio=new Phonon::MediaObject();
    audio->setTickInterval(1);
    audioOutput=new Phonon::AudioOutput(Phonon::VideoCategory);
    Phonon::createPath(audio,audioOutput);
    msicinfoObj=new Phonon::MediaObject(this);

    connect(audio,SIGNAL(finished()),this,SLOT(next_media()));

    volumeSlider=new Phonon::VolumeSlider(audioOutput,this);
    volumeSlider->move(10,100);
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
    next_media();
    return ;
    qDebug()<<"tool button list";
    this->musicLrc->update_lrc("test",1);
}

void Widget::on_toolButton_lrc_clicked()
{
    lrcHide = !lrcHide;
    qDebug()<<"tool button lrc"<< lrcHide;
    if(this->lrcHide)
    {
        musicLrc->hide();
    }
    else
        musicLrc->show();
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
    int oldTableCount = ui->tableWidget_list->rowCount();
    ui->tableWidget_list->setRowCount(oldTableCount+ files.count());
 //   ui->tableWidget_list->setColumnCount(2);
    QFileInfo fileinfo;
    int i = 0;
    foreach(file,files)
    {
        //update play list
        sourceList.append(file);
        //get file information
        fileinfo.setFile(file);
        qDebug()<<"file path"<<fileinfo.absoluteFilePath()<<"file baseName:"<<fileinfo.baseName()<<"bundleName"<<fileinfo.bundleName();


        ui->listWidget->addItem(fileinfo.baseName());

        //checkout lrc whether exist
        QString abspath = fileinfo.absoluteFilePath();
        abspath.replace(QRegExp("wma"),"lrc");
        abspath.replace(QRegExp("WMA"),"lrc");
        abspath.replace(QRegExp("mp3"),"lrc");
        abspath.replace(QRegExp("MP3"),"lrc");

        QFileInfo lrcInfo(abspath);
        QTableWidgetItem *lrcIcon = new QTableWidgetItem();//
        QTableWidgetItem *lrcAbsPath = new QTableWidgetItem();//
        QTableWidgetItem *musicName = new QTableWidgetItem(fileinfo.baseName());
        QTableWidgetItem *musicAbsPath = new QTableWidgetItem(fileinfo.absoluteFilePath());

        if(lrcInfo.exists())
        {
            //musicLrc->setIcon(QIcon"(":/images/lrcok.png"));
            lrcIcon->setText("YES");
            lrcIcon->setBackground(QBrush(QColor(Qt::green),Qt::SolidPattern));
            //save lrc full path
            lrcAbsPath->setText(lrcInfo.absoluteFilePath());
            //musicLrc->setData(1,0);

        }
        else
        {
            //musicLrc->setIcon(QIcon(":/images/lrcerr.png"));
            lrcIcon->setText("ERROR");
            lrcIcon->setBackground(QBrush(QColor(Qt::red),Qt::SolidPattern));
           // musicLrc->setData(1,1);
         }



        //check the file types
        QString suffix = fileinfo.suffix();
        if(suffix == QString("mp3") || suffix == QString("MP3"))
            musicName->setIcon(QIcon(":/images/mp3.png"));
        else if(suffix == QString("WMA") || suffix == QString("wma"))
            musicName->setIcon(QIcon(":/images/wma.png"));

        ui->tableWidget_list->setItem(oldTableCount,0,lrcIcon);
        ui->tableWidget_list->setItem(oldTableCount,1,musicName);
        ui->tableWidget_list->setItem(oldTableCount,2,musicAbsPath);
        ui->tableWidget_list->setItem(oldTableCount,3,lrcAbsPath);
        oldTableCount++;

    }
    audio->setTickInterval(100);
    connect(audio,SIGNAL(tick(qint64)),this,SLOT(refreshTime(qint64)));
    next_media();
    return;
    audio->setQueue(sourceList);
    currentSource = sourceList.at(this->currentIndex);
    qDebug()<<"next music -->" << this->currentIndex+1 <<currentSource.fileName();
    audio->setCurrentSource(this->currentSource);
    audio->setTickInterval(100);
    connect(audio,SIGNAL(tick(qint64)),this,SLOT(refreshTime(qint64)));

    //audio->play();
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
void Widget::refreshTime(qint64 time)
{

    QString min,sec,mm;
    qint64 currentMinute = time/60000;
    qint64 currentSecond= time%60000 /1000;
    qint64 currentMSecond= time%60000 %1000 /10;
    if(currentMinute == 0)
        min.sprintf("00:");
    else if(currentMinute <10)
        min.sprintf("0%d:",currentMinute);
    else
        min.sprintf("%d:",currentMinute);

    if(currentSecond == 0)
        sec.sprintf("00.");
    else if(currentSecond <10)
        sec.sprintf("0%d.",currentSecond);
    else
        sec.sprintf("%d.",currentSecond);

    if(currentMSecond <= 0)
        mm.sprintf("00");
    else if(currentMSecond < 10)
        mm.sprintf("0%d",currentMSecond);
    else
        mm.sprintf("%d",currentMSecond);

    QString cur = min + sec + mm;

    static qint64 change = -1000;



        totalTime = min + sec + mm;
    }

   // qDebug()<< total <<"  " << cur;

    totalTime = time_to_string(audio->totalTime());
    cur = time_to_string();
    QString timeLabel = totalTime +"/" + cur;

    ui->labelTime->setText(timeLabel);
    if(this->lrcOK)
        update_lrc_display("["+cur+"]",1);

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

void Widget::closeEvent(QCloseEvent *event)
{
    this->musicLrc->close();
    this->close();

}



void Widget::on_tableWidget_list_doubleClicked(const QModelIndex &index)
{
    qDebug()<<"doulbe click index ->"<<index.row()<<" <->"<<index.column() << "   " << index.data().toString();
    this->currentIndex = index.row();
    audio->stop();
    if(this->audioSource != NULL)
        delete audioSource;
    Phonon::MediaSource *audioSource = new Phonon::MediaSource(ui->tableWidget_list->item(index.row(),2)->text());

  //  this->currentSource  = new Phonon::MediaSource(index.data().toString());
    audio->setCurrentSource(*audioSource);
    audio->play();
    this->lrcOK = try_open_lrc(this->currentIndex);




}

void Widget::next_media()
{
    this->playMode = ui->comboBox_playMode->currentIndex();
    QTime seed = QTime::currentTime();
    if(this->currentIndex <0 || this->ui->tableWidget_list->rowCount())
        this->currentIndex = 0;
    QDateTime date;
    switch(this->playMode){
        case 0://顺序播放
        qDebug()<<"play mode -->"<<this->playMode;
        if(this->playMode == ui->tableWidget_list->rowCount()-1)
            this->currentIndex = this->currentIndex;
        break;
    case 1://全部播放
        qDebug()<<"play mode -->"<<this->playMode;
        if(this->playMode == ui->tableWidget_list->rowCount()-1)
            this->currentIndex = 0;
        break;
    case 2://单曲循环
        qDebug()<<"play mode -->"<<this->playMode;
        if(this->playMode == ui->tableWidget_list->rowCount()-1)
            this->currentIndex = 0;
        break;
    case 3://随机播放
        qDebug()<<"play mode -->"<<this->playMode;
        qsrand(seed.second());

        this->currentIndex = qrand() % ui->tableWidget_list->rowCount();
        qDebug() <<seed.second()<<qrand() << this->currentIndex << ui->tableWidget_list->rowCount();
        break;
    default:
         qDebug()<<"play mode -->"<<this->playMode;

         break;

    }

    audio->stop();
    if(this->audioSource != NULL)
        delete audioSource;

    Phonon::MediaSource *audioSource = new Phonon::MediaSource(ui->tableWidget_list->item(this->currentIndex,2)->text());

  //  this->currentSource  = new Phonon::MediaSource(index.data().toString());
    audio->setCurrentSource(*audioSource);

    audio->play();
    this->lrcOK = try_open_lrc(this->currentIndex);
//    this->musicLrc->update_lrc("Music 。。。。。。",0);


    //try to add lrc



}

int Widget::update_lrc_display(QString time,int type)
{
    char buf[1024];
    int len;

    if(this->lrcPreRead.at(0)=='[' && this->lrcPreRead.at(9)==']')
    {
        QString sub = this->lrcPreRead.left(10);
        qDebug()<<"wait for com ->  "<<sub << "  --  " <<time;
        if(sub.compare(time) <= 0)
        {
            this->musicLrc->update_lrc(this->lrcPreRead.mid(10,this->lrcPreRead.size()-10),1);
            memset(buf,0,1024);
            len = this->lrcFile.readLine(buf, 1000);
            this->lrcPreRead = QString("%1").arg(buf);
            qDebug()<<"re read in new line->"<<this->lrcPreRead;

        }

    }
    else
    {
        memset(buf,0,1024);
        len = this->lrcFile.readLine(buf, 1000);
        this->lrcPreRead = QString("%1").arg(buf);
        qDebug()<<"read in new line->"<<this->lrcPreRead;
        this->musicLrc->update_lrc(this->lrcPreRead,1);

    }


}
bool Widget::try_open_lrc(int row)
{
    this->musicLrc->update_lrc("Music 。。。。。。",0);
    if(ui->tableWidget_list->item(row,0)->text() == QString("YES"))
    {

        this->lrcFile.close();
        this->lrcFile.setFileName(ui->tableWidget_list->item(this->currentIndex,3)->text());

        if(!this->lrcFile.open(QIODevice::ReadOnly))
        {
            qDebug()<<"open file error";
            return false;
        }
        this->lrcStream.setDevice(&this->lrcFile);
        qDebug()<<"open file ok and stream in"  << this->lrcFile.fileName();

        char buf[1024];
        qint64 lineLength = 0 ;

        memset(buf,0,1024);
        lineLength = this->lrcFile.readLine(buf, 1000);
        this->lrcPreRead = QString("%1").arg(buf);
        qDebug()<<"len ->"<<lineLength<<" content ->"<<this->lrcPreRead;
        this->musicLrc->update_lrc(this->lrcPreRead,1);
        return true;

    }
    else
        return false;
}

QString Widget::time_to_string(qint64 time,int type)
{
    QString min,sec,mm;
    qint64 currentMinute = time/60000;
    qint64 currentSecond= time%60000 /1000;
    qint64 currentMSecond= time%60000 %1000 /10;
    static qint64 tmp1 = tmp2 = -1;
    if(type == 1)
    {

    }
    if(currentMinute == 0)
        min.sprintf("00:");
    else if(currentMinute <10)
        min.sprintf("0%d:",currentMinute);
    else
        min.sprintf("%d:",currentMinute);

    if(currentSecond == 0)
        sec.sprintf("00.");
    else if(currentSecond <10)
        sec.sprintf("0%d.",currentSecond);
    else
        sec.sprintf("%d.",currentSecond);

    if(currentMSecond <= 0)
        mm.sprintf("00");
    else if(currentMSecond < 10)
        mm.sprintf("0%d",currentMSecond);
    else
        mm.sprintf("%d",currentMSecond);




    return min+sec+mm;

}
