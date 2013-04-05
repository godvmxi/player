#ifndef DOCKWIDGETLRC_H
#define DOCKWIDGETLRC_H

#include <QDockWidget>
#include <QDebug>

namespace Ui {
class DockWidgetLrc;
}

class DockWidgetLrc : public QDockWidget
{
    Q_OBJECT
    
public:
    explicit DockWidgetLrc(QWidget *parent = 0);
    ~DockWidgetLrc();
public:
    int update_lrc(QString lrc,int action);
    
private:
    Ui::DockWidgetLrc *ui;
};

#endif // DOCKWIDGETLRC_H
