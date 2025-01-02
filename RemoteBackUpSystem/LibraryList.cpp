#include "LibraryList.h"
#include "ui_LibraryList.h"

#include <LibListItem.h>
#include <TaskList.h>

LibraryList::LibraryList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LibraryList)
{
    ui->setupUi(this);
}

LibraryList::~LibraryList()
{
    delete ui;
}

// 增加一个备份库元素
void LibraryList::on_AppedLib_clicked()
{
    // 创建一个列表元素
    QListWidgetItem *item = new QListWidgetItem();

    // 创建一个LibListItem组件
    LibListItem *itemWidget = new LibListItem(ui->List);

    itemWidget->setLibName("备份库-"+QString::number(ui->List->count()+1));

    // 设置一下item的显示范围为组件的显示范围
    item->setSizeHint(itemWidget->sizeHint());

    // 为列表增加元素
    ui->List->addItem(item);

    // 给元素绑定组件
    ui->List->setItemWidget(item,itemWidget);
}

// 删除选中的备份库元素
void LibraryList::on_DeleteLib_clicked()
{
    // 获取被选中的备份库元素
    QListWidgetItem *item = ui->List->currentItem();
    if(!item)return;

    // 先把备份库组件获取出来
    LibListItem *itemWidget = static_cast<LibListItem*>(ui->List->itemWidget(item));

    // 从列表中解除item和widget绑定
    ui->List->removeItemWidget(item);

    // 移除item元素
    int index = ui->List->row(item);
    ui->List->takeItem(index);

    // 销毁item和widget
    delete item;
    delete itemWidget;
}

// 查看正在进行，已完成等相关的任务信息
void LibraryList::on_ShowTasks_clicked()
{
    TaskList task;

    setVisible(false);

    // 阻塞当前窗口显示子窗口
    task.exec();

    setVisible(true);
}

