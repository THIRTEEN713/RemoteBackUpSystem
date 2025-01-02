#ifndef PLANELIST_H
#define PLANELIST_H

#include <QDialog>

namespace Ui {
class PlaneList;
}

class PlaneList : public QDialog
{
    Q_OBJECT

public:
    explicit PlaneList(QWidget *parent = nullptr);
    ~PlaneList();

    void setAddr(QString);
    void setPort(QString);

    QString addr();
    QString port();

private slots:
    void on_PlaneAppend_clicked();
    void on_NetEnter_clicked();

signals:
    void entered();

private:
    Ui::PlaneList *ui;
};

#endif // PLANELIST_H
