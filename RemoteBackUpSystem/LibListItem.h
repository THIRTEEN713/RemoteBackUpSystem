#ifndef LIBLISTITEM_H
#define LIBLISTITEM_H

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
    void setLibAddr(QString);
    void setLibPort(QString);

    QString libName()const;
    QString libAddr()const;
    QString libPort()const;
private slots:
    void on_ChangePlane_clicked();

    void on_ShowLibrary_clicked();

private:
    Ui::LibListItem *ui;
};

#endif // LIBLISTITEM_H
