#ifndef LRCWIDGET_H
#define LRCWIDGET_H

#include <QWidget>
#include <QDockWidget>
#include <QLabel>
#include <QHBoxLayout>

class lrcWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit lrcWidget(QWidget *parent = 0);

signals:

public slots:
private:
    QLabel *lrclabel;

};

#endif // LRCWIDGET_H
