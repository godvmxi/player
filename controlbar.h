#ifndef CONTROLBAR_H
#define CONTROLBAR_H

#include <QDockWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include "playlist.h"
class ControlBar : public QDockWidget
{
    Q_OBJECT
public:
    explicit ControlBar(QWidget *parent = 0);

signals:
    void playerCmdSender(QString cmd);

public slots:
    void buttonPausePlaySlot(void);
    void buttonBackSlot(void);
    void buttonForwardSlot(void);
    void buttonMuteSlot(void);
private :
    void paintEvent(QPaintEvent *event);

    QPushButton *pushbutton_play_pause;
    QPushButton *pushbutton_forward;
    QPushButton *pushbutton_back;
    QPushButton *pushbutton_mute;
    QComboBox *modebox;
    PlayList *playlist;


};

#endif // CONTROLBAR_H
