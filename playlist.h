#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QDockWidget>
#include <QTableView>
#include <QTableWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QDebug>
#include <QCalendarWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QFileDialog>
#include <QMessageBox>
#include <QDomDocument>
#include <QFile>
#include <QTime>
#include <QProcess>
#include <QPalette>

class PlayList : public QDockWidget
{
    Q_OBJECT
public:
    QTableWidget *tableWidgePlayListMusic;

    explicit PlayList(QWidget *parent = 0);

signals:

    void playMusic(QString music,QString lrc);
    void playMovie(QString movie,QString subtitle);

    void readyBackMusic();
    void readyForwardMusic();
    void readyModeMusic();

public slots:



private slots:

    void getBackMusic(bool);
    void getForwardMusic(bool);
    void getplayMode(int);



    void getNextMusic();
    void addMusicSlot(void);
    void addMovieSlot(void);
    void savePlayList();
    void movieClick(const QModelIndex &index);
    void musicClick(const QModelIndex &index);
    void musicDoubleClick(int row, int column);
    void movieDoubleClick(int row, int column);
private:
   // QTableWidget *tableWidgePlayListMusic;
    QTableWidget *tableWidgePlayListMovie;
    QTabWidget *tabWidgetPlayList;
    QPushButton *pushButtonAddMusic;
    QPushButton *pushButtonAddMovie;
    QPushButton *pushButtonSavePlayList;

    int currentMusicIndex;
    int currentMovieIndex;
    int playMode;
    bool back;
    bool forward;

    bool autoLoadPlayList(void);
    void playNextMusic(int playMode);
    void playNextMovie(int playMode);
    bool loadPlayList(QString);

};

#endif // PLAYLIST_H
