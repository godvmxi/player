#ifndef LRCWIDGET_H
#define LRCWIDGET_H

#include <QWidget>
<<<<<<< HEAD
#include <QDockWidget>
#include <QLabel>
#include <QHBoxLayout>
=======
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
>>>>>>> eeef18499b316077e94987f781ec318b9164866d

class lrcWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit lrcWidget(QWidget *parent = 0);

signals:

public slots:
<<<<<<< HEAD
private:
    QLabel *lrclabel;
=======
>>>>>>> eeef18499b316077e94987f781ec318b9164866d

};

#endif // LRCWIDGET_H
