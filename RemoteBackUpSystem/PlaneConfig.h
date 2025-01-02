#ifndef PLANECONFIG_H
#define PLANECONFIG_H

#include <QDialog>

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

private:
    Ui::PlaneConfig *ui;
};

#endif // PLANECONFIG_H
