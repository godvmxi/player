#ifndef LRCWIDGET_H
#define LRCWIDGET_H

#include <QWidget>
#include <QDockWidget>
#include <QLabel>
#include <QHBoxLayout>
#include<QDebug>
#include <QCalendarWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QFileDialog>
#include <QMessageBox>
#include <QDomDocument>
#include <QFile>
#include <QTime>
#include <QDockWidget>
#include <QList>
#include <QTimer>
#include <QDebug>
#include<QFile>
#include<QFileInfo>
#include <QPalette>
#define timerInterval 200
typedef struct {
    quint64 time;
    QString lrc;
}LRC_CONTAIN;

class lrcWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit lrcWidget(QWidget *parent = 0);
    bool setLrcPath(QString);
    bool setLrcTime(quint64 time);
    quint64 getLrcTime(void);
    quint64 startStopLrc(bool type);
    quint64 playPauseLrc(bool type);


signals:

public slots:
    void updateTimeOut(void);

private:
    QString fileName;
    bool anaylseLrcFile(QString file);
    //void updateTimeOut(void);
    bool updateLabel(QString lrc);
    QLabel *lrclabel_1;
    QLabel *lrclabel_2;
    bool lrcState ;
    QList<LRC_CONTAIN>  lrcText;
    int lrcTextIndex ;

    QTimer *lrcTimer;
    quint64 timer;
};

#endif // LRCWIDGET_H
