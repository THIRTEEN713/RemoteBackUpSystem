#include "FileTransmission.h"
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

    plane->setWindowTitle(ui->LibraryName->text());

    plane->setAddr(ui->LibraryAddress->text());
    plane->setPort(ui->LibraryPort->text());

    // 在PlaneList窗口点击了确定按钮
    connect(plane,&PlaneList::entered,this,[=](FT_SOCKET sockid){
        // 同步到备份库列表窗口
        ui->LibraryAddress->setText(plane->addr());
        ui->LibraryPort->setText(plane->port());

        // 存储到数据库中
        FT_Package data;
        data.pa_action = FT_AC_MSG;
        data.pa_type   = FT_DT_MSG;
        data.pa_number = 1;
        data.pa_size = ui->LibraryName->text().size();
        strcpy(data.pa_context,ui->LibraryName->text().toStdString().c_str());

        // 库名字段
        FT_Send(sockid,data);

        // 地址字段
        data.pa_size = ui->LibraryAddress->text().size();
        strcpy(data.pa_context,ui->LibraryAddress->text().toStdString().c_str());
        FT_Send(sockid,data);
        
        // 端口字段
        data.pa_size = ui->LibraryPort->text().size();
        strcpy(data.pa_context,ui->LibraryPort->text().toStdString().c_str());
        FT_Send(sockid,data);

        emit update(sockid);
    });

    plane->exec();
    delete plane;
}


void LibListItem::on_ShowLibrary_clicked()
{
    RemoteFolder *folder = new RemoteFolder;

    folder->show();
}

