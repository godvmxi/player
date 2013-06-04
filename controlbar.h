#ifndef CONTROLBAR_H
#define CONTROLBAR_H

#include <QDockWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QPalette>
#include <QComboBox>
class ControlBar : public QDockWidget
{
    Q_OBJECT
public:
    explicit ControlBar(QWidget *parent = 0);
    QSlider *slider_progress;

signals:
    void playerCmdSender(QString cmd);
    void BackMusic(bool);
    void ForwardMusic(bool);
    void modeChanged(int);

private slots:
    void buttonPausePlaySlot(void);
    void buttonMuteSlot(void);
    void buttonBackSlot(bool);
    void buttonForwardSlot(bool);
    void modeBoxSlot(int);
    void buttonFastforward();
    void buttonFastbackward();

private :
    void paintEvent(QPaintEvent *event);
    QPushButton *pushbutton_play_pause;
    QPushButton *pushbutton_mute;
    QPushButton *pushbutton_forward;
    QPushButton *pushbutton_back;
    QPushButton *pushbutton_fastforward;
    QPushButton *pushbutton_fastbackward;
    QComboBox *modebox;


    int playmode;


};

#endif // CONTROLBAR_H
