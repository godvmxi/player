#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QAction>
#include <QIcon>
#include <QList>
#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <QMap>

#include <Phonon/AudioOutput>
#include <phonon>
#include <Phonon/MediaObject>
#include <QTimer>
#include "dockwidgetlrc.h"
#include <QCloseEvent>
#include <cstdlib>
#include <stdlib.h>
#include <QTime>
#include <QDateTime>
#include <QDataStream>
#include <QtTest/QTest>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Phonon::MediaObject *audio;
    Phonon::AudioOutput *audioOutput;
    Phonon::MediaObject *msicinfoObj;
    Phonon::VolumeSlider *volumeSlider;
    Phonon::SeekSlider *seekSlider;
    QList<Phonon::MediaSource>  sourceList;
    Phonon::MediaSource currentSource;
    Phonon::MediaSource *audioSource;

    QIcon *iconPause ;
    QIcon *iconPlay ;
    QAction *remove;
    QAction *play;
    QAction *stop;
    QAction *open;
    QAction *sound;
    QAction *exit;

    QTimer songTimer;

    int currentIndex;
    int numberOfMusic;

    int playMode ;

    int lrcHide ;
    bool lrcOK;
    DockWidgetLrc *musicLrc;
    QFile lrcFile;
    QDataStream lrcStream;
    FILE *lrcFd;
    QString totalTime;
    QString lrcPreRead;
    int update_lrc_display(QString time,int type);
protected:
     void closeEvent(QCloseEvent *event);

private slots:
//    void on_toolButton_list_clicked(bool checked);
//    void on_toolButton_lrc_clicked(bool checked);
    void creatActions();
    void removeSlot();
    void refreshTime(qint64);

    void on_toolButton_playpause_clicked();
    void on_toolButton_playstop_clicked();
    void on_toolButton_stop_clicked();
    void on_toolButton_open_clicked();

    void on_toolButton_list_clicked();
    void on_toolButton_lrc_clicked();
    void on_toolButton_next_clicked();
    void on_toolButton_last_clicked();
    void on_doubleClick_listItems(QModelIndex index);
    void on_tableWidget_list_doubleClicked(const QModelIndex &index);
    void next_media();
    bool try_open_lrc(int row);
private:
    QString time_to_string(qint64 time,int type);
};

#endif // FORM_H
