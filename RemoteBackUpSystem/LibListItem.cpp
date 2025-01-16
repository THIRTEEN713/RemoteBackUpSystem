#include "LibListItem.h"
#include "ui_LibListItem.h"

#include <PlaneList.h>
#include <QListWidgetItem>
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

QString LibListItem::libName() const
{
    return ui->LibraryName->text();
}

void LibListItem::setLibTime(QString str)
{
    ui->LibraryTime->setText(str);
}

QString LibListItem::libTime() const
{
    return ui->LibraryTime->text();
}

// 更改备份库的备份计划
void LibListItem::on_ChangePlane_clicked()
{
    // 新开一个更改计划的窗口
    PlaneList *plane=new PlaneList;

    plane->setWindowTitle(ui->LibraryName->text());

    // 在PlaneList窗口点击了确定按钮
    connect(plane,&PlaneList::sendData,this,[=](NW_Package data){
        emit sendData(data);
    });

    plane->exec();
    delete plane;
}


void LibListItem::on_ShowLibrary_clicked()
{
    RemoteFolder *folder = new RemoteFolder;

    folder->show();
}

