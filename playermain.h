#ifndef PLAYERMAIN_H
#define PLAYERMAIN_H

#include <QMainWindow>
#include <QProcess>
#include <QString>
#include <QDebug>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDial>
#include <QDockWidget>
#include <QComboBox>
#include <QSlider>
#include <QTabWidget>
#include <QTableView>
#include <QProcess>
#include <QWidget>
#include "lrcwidget.h"
#include "controlbar.h"
#include "playlist.h"
#include "lrcwidget.h"
namespace Ui {
    class PlayerMain;
}

class PlayerMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayerMain(QWidget *parent = 0);
    ~PlayerMain();

signals:
    void  getNextMedia();

public slots:

private slots:

    bool playMovieSource(QString media,QString lrc);
    bool playMusicSource(QString media,QString lrc);
    void playerControlCmdSlots(QString);
    void mediaStateChanged(QProcess::ProcessState);
    void mediaProgessChanged(int);

private:
    Ui::PlayerMain *ui;
  /*  QPushButton *pushbutton_play_pause;
    QPushButton *pushbutton_forward;
    QPushButton *pushbutton_back;
    QPushButton *pushbutton_mute;
    QDial *dial_vol;
    QComboBox *combobox_lrc;

    QDockWidget *dock_control;

    QTableView *tabview_playlist_music;
    QTableView *tabview_playlist_video;
    QTabWidget *tabwidge_playlist_tab;
*/
    QWidget *widgetPlayMain;
    QProcess * processPlay;

    ControlBar *controlBar;
    PlayList *dock_playlist;
    lrcWidget *lrc;

    int playMode;
    QString playCmd;

};

#endif // PLAYERMAIN_H
