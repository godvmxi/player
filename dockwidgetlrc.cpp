#include "dockwidgetlrc.h"
#include "ui_dockwidgetlrc.h"

DockWidgetLrc::DockWidgetLrc(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::DockWidgetLrc)
{
    this->setFeatures(QDockWidget::NoDockWidgetFeatures);
    this->setWindowFlags (Qt::FramelessWindowHint);
    ui->setupUi(this);
}

DockWidgetLrc::~DockWidgetLrc()
{
    delete ui;
}
int DockWidgetLrc::update_lrc(QString lrc,int action)
{
    switch(action){
        case 0:
        qDebug()<<"reset lrc tool";
        ui->label_lrc_next->setText("Music....");
        ui->label_lrc_now->clear();
        break;
    case 1:
        qDebug()<<"insert lrc"<<lrc;
        ui->label_lrc_now->setText( ui->label_lrc_next->text() );
        ui->label_lrc_next->setText(lrc);
    default:
        qDebug()<<"action error";
        return -1;
    }
    return 1;


}
