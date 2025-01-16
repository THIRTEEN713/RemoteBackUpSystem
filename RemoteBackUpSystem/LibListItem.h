#ifndef LIBLISTITEM_H
#define LIBLISTITEM_H

#include "NetWork.h"

#include <QWidget>

namespace Ui {
class LibListItem;
}

class LibListItem : public QWidget
{
    Q_OBJECT

public:
    explicit LibListItem(QWidget *parent = nullptr);
    ~LibListItem();

    // 公开API
    void setLibName(QString);
    void setLibTime(QString);

    QString libName()const;
    QString libTime()const;
private slots:
    void on_ChangePlane_clicked();

    void on_ShowLibrary_clicked();

signals:
    void sendData(NW_Package data);

private:
    Ui::LibListItem *ui;
};

#endif // LIBLISTITEM_H
