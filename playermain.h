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
    QProcess * processPlay;

public slots:
    bool playMovieSource(QString media,QString lrc);
    bool playMusicSource(QString media,QString lrc);
    void playerControlCmdSlots(QString);

private:
    Ui::PlayerMain *ui;
    QPushButton *pushbutton_play_pause;
    QPushButton *pushbutton_forward;
    QPushButton *pushbutton_back;
    QPushButton *pushbutton_mute;
    QDial *dial_vol;
    QComboBox *combobox_lrc;
    PlayList *dock_playlist;
    QDockWidget *dock_control;

    QTableView *tabview_playlist_music;
    QTableView *tabview_playlist_video;
    QTabWidget *tabwidge_playlist_tab;

    ControlBar *controlBar;


    QString playCmd;
    QWidget *widgetPlayMain;
    lrcWidget *lrc;

};

#endif // PLAYERMAIN_H
