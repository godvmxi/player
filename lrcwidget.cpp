#include "lrcwidget.h"

lrcWidget::lrcWidget(QWidget *parent) :
    QDockWidget(parent)
{

    this->setFeatures(QDockWidget::DockWidgetFloatable);
    this->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);
    this->setFixedSize(300,600);


    this->lrclabel_1=new QLabel();
    this->lrclabel_1->setText("hello1");

    this->lrclabel_2=new QLabel();
    this->lrclabel_2->setText("hello2");

    QVBoxLayout *backLayout = new QVBoxLayout();
    backLayout->addWidget(this->lrclabel_1);
    backLayout->addWidget(this->lrclabel_2);
    QWidget *backGround = new QWidget();
    backGround->setLayout(backLayout);
    this->setWidget(backGround);

    this->setFixedSize(300,100);
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
    lrcText.clear();
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

}

quint64 lrcWidget::getLrcTime(void)
{

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
    this->updateLabel("fuck");
}

bool lrcWidget::updateLabel(QString lrc)
{
    QString test;
    this->timer += timerInterval;
    test = QString("current time -->  %1").arg(this->timer);
    this->lrclabel_1->setText(test);
    this->lrclabel_2->setText(test);

}
