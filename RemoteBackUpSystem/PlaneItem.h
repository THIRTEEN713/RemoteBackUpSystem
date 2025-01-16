#ifndef PLANEITEM_H
#define PLANEITEM_H

#include <QWidget>
#include "Network.h"
namespace Ui {
class PlaneItem;
}

class PlaneItem : public QWidget
{
    Q_OBJECT

public:
    explicit PlaneItem(QWidget *parent = nullptr);
    ~PlaneItem();

    void setLibName(QString);
    void setSrcPath(QString);
    void setStatus(bool);
    void setCheckState(bool);

    QString libName();
    QString srcPath();
    bool status();
    bool checkState();

private slots:
    void on_CheckPath_clicked();

    void on_Config_clicked();

signals:
    void sendData(NW_Package data);

private:
    Ui::PlaneItem *ui;
};

#endif // PLANEITEM_H
