#ifndef PLANECONFIG_H
#define PLANECONFIG_H

#include <QDialog>
#include "Network.h"
namespace Ui {
class PlaneConfig;
}

class PlaneConfig : public QDialog
{
    Q_OBJECT

public:
    explicit PlaneConfig(QWidget *parent = nullptr);
    ~PlaneConfig();

private slots:
    void on_ChangePath_clicked();

    void on_Ok_clicked();

signals:
    void sendData(NW_Package data);
    
private:
    Ui::PlaneConfig *ui;
};

#endif // PLANECONFIG_H
