#include "RemoteFolder.h"
#include "ui_RemoteFolder.h"

#include <FolderItem.h>

RemoteFolder::RemoteFolder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RemoteFolder)
{
    ui->setupUi(this);
}

RemoteFolder::~RemoteFolder()
{
    delete ui;
}

void RemoteFolder::on_PrevPath_clicked()
{
    // 创建一个列表元素
    QListWidgetItem *item = new QListWidgetItem();

    // 创建一个LibListItem组件
    FolderItem *itemWidget = new FolderItem(ui->List);

    // itemWidget->setLibName("备份库-"+QString::number(ui->List->count()+1));

    // 设置一下item的显示范围为组件的显示范围
    item->setSizeHint(itemWidget->sizeHint());

    // 为列表增加元素
    ui->List->addItem(item);

    // 给元素绑定组件
    ui->List->setItemWidget(item,itemWidget);
}

