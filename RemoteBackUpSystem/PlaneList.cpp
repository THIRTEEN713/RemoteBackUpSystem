#include "PlaneList.h"
#include "ui_PlaneList.h"

#include <LibListItem.h>
#include <PlaneItem.h>

PlaneList::PlaneList(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlaneList)
    , window(nullptr)
{
    ui->setupUi(this);
}

PlaneList::~PlaneList()
{
    delete ui;
}

void PlaneList::setPrevWindow(QObject *object)
{
    this->window = object;
}

void PlaneList::on_PlaneAppend_clicked()
{
    // 创建一个列表元素
    QListWidgetItem *item = new QListWidgetItem();

    // 创建一个LibListItem组件
    PlaneItem *itemWidget = new PlaneItem(ui->List);

    // 组件信息设置的接口
    itemWidget->setLibName("备份库-"+QString::number(ui->List->count()+1));
    itemWidget->setStatus(false);
    itemWidget->setSrcPath("未设置");

    // 捕获消息信号
    connect(itemWidget,&PlaneItem::sendData,this,[=](NW_Package data){
        emit sendData(data);
    });

    // 设置一下item的显示范围为组件的显示范围
    item->setSizeHint(itemWidget->sizeHint());

    // 为列表增加元素
    ui->List->addItem(item);

    // 给元素绑定组件
    ui->List->setItemWidget(item,itemWidget);
}

// 验证
void PlaneList::on_NetEnter_clicked()
{

}

