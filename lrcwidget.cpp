#include "lrcwidget.h"

lrcWidget::lrcWidget(QWidget *parent) :
    QDockWidget(parent)
{

    this->setFeatures(QDockWidget::DockWidgetFloatable);
    this->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);
    //this->setFixedSize(300,600);
    this->setFixedWidth(300);

    this->lrclabel_1=new QLabel();
    this->lrclabel_1->setText("design by fengjiao");

    this->lrclabel_2=new QLabel();
    this->lrclabel_2->setText("lrc");
    QFont ft;
    ft.setBold(true);
    ft.setFamily("simsun");
    ft.setPointSize(15);
    this->lrclabel_1->setFont(ft);
    QFont ft2 =ft;
    ft2.setPointSize(12);
    ft2.setBold(false);
    this->lrclabel_2->setFont(ft2);

    //this->lrclabel_1->setMinimumHeight(50);
    //this->lrclabel_1->setMaximumHeight(200);
    //this->lrclabel_2->setMinimumHeight(50);
    //this->lrclabel_2->setMaximumHeight(200);
    this->lrclabel_1->setFixedHeight(60);
    this->lrclabel_2->setFixedHeight(60);

    QVBoxLayout *backLayout = new QVBoxLayout();
    backLayout->addWidget(this->lrclabel_1);
    backLayout->addWidget(this->lrclabel_2);


    QWidget *backGround = new QWidget();
    //backGround->setMaximumHeight(300);
    backGround->setLayout(backLayout);
    this->setWidget(backGround);



    this->setFeatures(QDockWidget::DockWidgetFloatable);
    this->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);
    this->lrcTimer = new QTimer();
    this->lrcTimer->setSingleShot(false);
    this->lrcTimer->setInterval(timerInterval);
    connect(this->lrcTimer,SIGNAL(timeout()),this,SLOT(updateTimeOut()));
    this->lrcTimer->start();
    this->timer = 0;

}

bool lrcWidget::lrcWidget::setLrcPath(QString file)
{

    QFileInfo fileInfo(file);
    if (fileInfo.exists())
    {
        qDebug()<<"lrc exist -->"<<file;
        return this->anaylseLrcFile(file);
    }
    this->lrcState = false;
    return false;

}
bool lrcWidget::anaylseLrcFile(QString file)
{
    QFile lrcFile(file);

    if(!lrcFile.open(QIODevice::ReadOnly)){
        qDebug()<<"文件打开错误";
        return false;
    }
    this->lrcState = true;
    this->lrcText.clear();
    this->lrcTextIndex = 0;
    while(true)
    {
        QString line = lrcFile.readLine();

        if ( line.indexOf(QRegExp("\[..:.....\]"),0) != -1 )
        {
            QString item = line.mid(10);
            quint64 time = line.mid(1,2).toInt() *60*1000 +line.mid(4,2).toInt()*1000 + line.mid(7,2).toInt()*10;
            LRC_CONTAIN tmp;
            tmp.lrc = item;
            tmp.time = time;
            this->lrcText.append(tmp);
            qDebug()<<""<<time << " --> "<<item;
        }
        if (lrcFile.atEnd())
        {
            qDebug()<<"file read to end,over";
            return true;
        }
    }





    return false;

}
bool lrcWidget::setLrcTime(quint64 time)
{
    this->timer = time;
}

quint64 lrcWidget::getLrcTime(void)
{
    return this->timer;
}

quint64 lrcWidget::startStopLrc(bool type)
{

    if(type)
    {
        this->timer = 0;
        this->lrcTimer->start();
        qDebug()<<"timer start";
        return this->timer;

    }
    else
    {
        this->lrcTimer->stop();
        qDebug()<<"timer stop";
        return this->timer;
    }
}

quint64 lrcWidget::playPauseLrc(bool type)
{
    if(type)
    {
        this->lrcTimer->start();
        qDebug()<<"timer start";
    }
    else
    {
        this->lrcTimer->stop();
        qDebug()<<"timer stop";
    }
    return this->timer;
}
void lrcWidget::updateTimeOut(void)
{
    LRC_CONTAIN tmp;
    this->timer+=timerInterval;
    if (this->lrcTextIndex >= this->lrcText.count())
    {
        qDebug()<<"all lrc deal over";
        this->lrcTimer->stop();
        return;
    }
    tmp = this->lrcText.at(this->lrcTextIndex);
    qDebug()<<this->timer<<"  <--->"  <<tmp.time;
    if (tmp.time <= this->timer )
    {
        this->updateLabel(tmp.lrc);
        this->lrcTextIndex++;
    }

}

bool lrcWidget::updateLabel(QString lrc)
{
    static QString last;
    this->timer += timerInterval;

    this->lrclabel_1->setText(last);
    this->lrclabel_2->setText(lrc);
    last = lrc;

}
