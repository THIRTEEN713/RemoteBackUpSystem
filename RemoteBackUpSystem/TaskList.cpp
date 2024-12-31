#include "TaskList.h"
#include "ui_TaskList.h"

#include <TaskItem.h>

TaskList::TaskList(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TaskList)
{
    ui->setupUi(this);
    finished = new QListWidget(ui->ListTab);
    progress = new QListWidget(ui->ListTab);
    failed = new QListWidget(ui->ListTab);
    ui->ListTab->addTab(finished,"已完成");
    ui->ListTab->addTab(progress,"备份中");
    ui->ListTab->addTab(failed,"已失败");
}

TaskList::~TaskList()
{
    delete ui;
}

// 增加任务
void TaskList::on_pushButton_clicked()
{
    QListWidgetItem *item = new QListWidgetItem();
    TaskItem *itemWidget = new TaskItem(finished);

    // 连接信号
    connect(itemWidget,&TaskItem::checked,this,[=]{on_Checked(itemWidget,item);});
    connect(itemWidget,&TaskItem::unChecked,this,[=]{on_UnChecked(itemWidget,item);});

    item->setSizeHint(itemWidget->sizeHint());

    // 增加item元素
    finished->addItem(item);
    finished->setItemWidget(item,itemWidget);
}

void TaskList::on_CheckAll_clicked()
{
    if(ui->CheckAll->isChecked())
    {
        for(int i = 0;i < finished->count();i++)
        {
            QListWidgetItem *item = finished->item(i);
            TaskItem *itemWidget  = static_cast<TaskItem*>(finished->itemWidget(item));
            itemWidget->setStatus(true);
        }
        ui->CheckAll->setText("取消全选");
    }
    else
    {
        for(int i = 0;i < finished->count();i++)
        {
            QListWidgetItem *item = finished->item(i);
            TaskItem *itemWidget  = static_cast<TaskItem*>(finished->itemWidget(item));
            itemWidget->setStatus(false);
        }
        ui->CheckAll->setText("选择全部");
    }
}

void TaskList::on_Checked(TaskItem*itemWidget,QListWidgetItem*item)
{
    items[itemWidget] = item;
    // 判断itemVector的数量和finished数量是否一致
    if(items.count() == finished->count())
    {
        ui->CheckAll->setChecked(true);
    }
}

void TaskList::on_UnChecked(TaskItem*itemWidget,QListWidgetItem*item)
{
    // 判断itemVector的数量和finished数量是否一致
    items.remove(itemWidget);
    if(items.size() != finished->count())
    {
        ui->CheckAll->setChecked(false);
    }
}


void TaskList::on_CleanTask_clicked()
{
    for(TaskItem * itemWidget : items.keys())
    {
        finished->removeItemWidget(items[itemWidget]);
        int index = finished->row(items[itemWidget]);
        finished->takeItem(index);
        delete items[itemWidget];
        itemWidget->deleteLater();
        items.remove(itemWidget);
    }
    ui->CheckAll->setChecked(false);
    ui->CheckAll->setText("选择全部");
}

