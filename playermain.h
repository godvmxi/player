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

#include "playlist.h"

namespace Ui {
    class PlayerMain;
}

class PlayerMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayerMain(QWidget *parent = 0);
    ~PlayerMain();
    QProcess  *video;

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

};

#endif // PLAYERMAIN_H
