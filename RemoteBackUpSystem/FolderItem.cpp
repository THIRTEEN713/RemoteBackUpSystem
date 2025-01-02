#include "FolderItem.h"
#include "ui_FolderItem.h"

#include <QLineEdit>
#include <QMenu>
#include <QMouseEvent>

FolderItem::FolderItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FolderItem)
{
    ui->setupUi(this);
    ui->lineEdit->setVisible(false);

    menu = new QMenu(this);
    menu->addAction("重命名",[=]{changeName();});
    menu->addAction("删除");
    menu->addAction("移动");
    menu->addAction("下载");
}

FolderItem::~FolderItem()
{
    delete ui;
}

void FolderItem::changeName()
{
    qDebug() << "重命名";
    ui->Name->setVisible(false);
    ui->lineEdit->setVisible(true);
    ui->lineEdit->setText(ui->Name->text());

    // 连接信号
    connect(ui->lineEdit,&QLineEdit::returnPressed,this,[=]{
        ui->Name->setText(ui->lineEdit->text());
        ui->Name->setVisible(true);
        ui->lineEdit->setVisible(false);
    });

}

void FolderItem::mousePressEvent(QMouseEvent *ev)
{
    // 判断是否点击了右键
    if(ev->button() == Qt::RightButton)
    {
        menu->move(ev->globalPosition().toPoint());
        menu->exec();
    }

}
