#include "FileTransmission.h"
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

void PlaneList::setAddr(QString str)
{
    ui->NetAddr->setText(str);
}

void PlaneList::setPort(QString str)
{
    ui->NetPort->setText(str);
}

QString PlaneList::addr()
{
    return ui->NetAddr->text();
}

QString PlaneList::port()
{
    return ui->NetPort->text();
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
    // 判断四个框是否都有输入
    if(ui->NetAddr->text()==""||ui->NetPort->text()==""||
       ui->userName->text()==""||ui->userPasswd->text()=="")
    {
        QDialog log;
        log.setToolTip("验证信息必须都不能为空！");
        QLabel *label=new QLabel(&log);
        label->setText("验证信息必须都不能为空！");
        log.setWindowTitle("提示");
        log.exec();
        return;
    }

    // 访问服务器，验证用户信息，并且获取备份计划
    QString ipv4 = ui->NetAddr->text();
    int     port = ui->NetPort->text().toInt();
    FT_SOCKET sockid = FT_TcpClient(ipv4.toStdString(),port);
    if(sockid.socketId == FT_INVALID)
    {
        // 弹窗提示
        return;
    }

    // 发送用户信息，获取验证状态
    QString name = ui->userName->text();
    QString pswd = ui->userPasswd->text();
    FT_Package data;
    data.pa_action = FT_AC_GET;
    data.pa_type   = FT_DT_MSG;
    data.pa_number = 1;
    data.pa_size   = name.size();
    strcpy(data.pa_context,name.toStdString().c_str());
    FT_Send(sockid,data);

    data.clear();
    data.pa_action = FT_AC_GET;
    data.pa_type   = FT_DT_MSG;
    data.pa_number = 2;
    data.pa_size   = pswd.size();
    strcpy(data.pa_context,pswd.toStdString().c_str());
    FT_Send(sockid,data);

    // 等待服务器的验证状态
    data.clear();
    FT_Recv(sockid,data);
    if(QString(data.pa_context) != "success")
    {
        // 弹窗
        ui->checkState->setText("验证失败");
        FT_ShutDown(sockid);
        return;
    }
    ui->checkState->setText("验证成功");

    // 发送验证完毕的信号
    emit entered(sockid);
}

