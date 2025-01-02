#include "LibListItem.h"
#include "ui_LibListItem.h"

#include <PlaneList.h>
#include <RemoteFolder.h>

LibListItem::LibListItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LibListItem)
{
    ui->setupUi(this);
}

LibListItem::~LibListItem()
{
    delete ui;
}

void LibListItem::setLibName(QString str)
{
    ui->LibraryName->setText(str);
}

void LibListItem::setLibAddr(QString str)
{
    ui->LibraryAddress->setText(str);
}

void LibListItem::setLibPort(QString str)
{
    ui->LibraryPort->setText(str);
}

QString LibListItem::libName() const
{
    return ui->LibraryName->text();
}

QString LibListItem::libAddr() const
{
    return ui->LibraryAddress->text();
}

QString LibListItem::libPort() const
{
    return ui->LibraryPort->text();
}

// 更改备份库的备份计划
void LibListItem::on_ChangePlane_clicked()
{
    // 新开一个更改计划的窗口
    PlaneList *plane=new PlaneList;

    plane->setAddr(ui->LibraryAddress->text());
    plane->setPort(ui->LibraryPort->text());

    // 在PlaneList窗口点击了确定按钮
    connect(plane,&PlaneList::entered,this,[=]{
        // 存储到数据中

        // 同步到备份库列表窗口
        ui->LibraryAddress->setText(plane->addr());
        ui->LibraryPort->setText(plane->port());
    });

    plane->exec();
    delete plane;
}


void LibListItem::on_ShowLibrary_clicked()
{
    RemoteFolder *folder = new RemoteFolder;

    folder->show();
}

