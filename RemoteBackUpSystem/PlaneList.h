#ifndef PLANELIST_H
#define PLANELIST_H

#include <QDialog>
#include "Network.h"
namespace Ui {
class PlaneList;
}

class PlaneList : public QDialog
{
    Q_OBJECT

public:
    explicit PlaneList(QWidget *parent = nullptr);
    ~PlaneList();

    void setPrevWindow(QObject *);

private slots:
    void on_PlaneAppend_clicked();
    void on_NetEnter_clicked();

signals:
    void sendData(NW_Package data);

private:
    Ui::PlaneList *ui;
    QObject *window;
};

#endif // PLANELIST_H
