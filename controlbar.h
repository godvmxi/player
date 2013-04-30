#ifndef CONTROLBAR_H
#define CONTROLBAR_H

#include <QDockWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
class ControlBar : public QDockWidget
{
    Q_OBJECT
public:
    explicit ControlBar(QWidget *parent = 0);

signals:

public slots:
private :
    void paintEvent(QPaintEvent *event);

    QPushButton *pushbutton_play_pause;
    QPushButton *pushbutton_forward;
    QPushButton *pushbutton_back;
    QPushButton *pushbutton_mute;

};

#endif // CONTROLBAR_H
