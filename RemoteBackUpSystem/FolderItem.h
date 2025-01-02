#ifndef FOLDERITEM_H
#define FOLDERITEM_H

#include <QWidget>

namespace Ui {
class FolderItem;
}

class FolderItem : public QWidget
{
    Q_OBJECT

public:
    explicit FolderItem(QWidget *parent = nullptr);
    ~FolderItem();

    void changeName();

private:
    void mousePressEvent(QMouseEvent*);

private:
    Ui::FolderItem *ui;
    QMenu *menu;
};

#endif // FOLDERITEM_H
