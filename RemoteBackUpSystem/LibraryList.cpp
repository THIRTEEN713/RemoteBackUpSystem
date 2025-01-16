#include "LibraryList.h"
#include "ui_LibraryList.h"
#include <LibListItem.h>
#include <QCloseEvent>
#include <QDateTime>
#include <TaskList.h>
#include <QMenu>

LibraryList::LibraryList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LibraryList)
    , tray(new QSystemTrayIcon(this))
    , dataProcess(new DataProcess(this))
{
    ui->setupUi(this);

    setWindowTitle("云端备份软件");
    setWindowIcon(QIcon(":/icon/icon.png"));

    setConnectStatus(false,"未连接");

    // 调用系统托盘初始化
    initTray();

    connect(this,&LibraryList::addGourpNewItem,this,&LibraryList::addGroupItem);
}

LibraryList::~LibraryList()
{
    delete ui;
}

void LibraryList::addGroupItem(QString name,QString time)
{
    // 创建一个列表元素
    QListWidgetItem *item = new QListWidgetItem();

    // 创建一个LibListItem组件
    LibListItem *itemWidget = new LibListItem(ui->List);

    // 槽函数

    itemWidget->setLibName(name);

    // 设置时间
    itemWidget->setLibTime(time);

    // 设置一下item的显示范围为组件的显示范围
    item->setSizeHint(itemWidget->sizeHint());

    // 为列表增加元素
    ui->List->addItem(item);

    // 给元素绑定组件
    ui->List->setItemWidget(item,itemWidget);
}

// 增加一个备份库元素
void LibraryList::on_AppedLib_clicked()
{
    addGroupItem("备份组-"+QString::number(ui->List->count()+1),QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm"));
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

// 设置连接状态
void LibraryList::setConnectStatus(bool b,QString str)
{
    if(!b)
    {
        ui->List->clear();
        // 设置按钮文本
        ui->Check->setText("验证");
    }
    else ui->Check->setText("解除");

    // 设置按钮状态
    ui->ShowTasks->setEnabled(b);
    ui->DeleteLib->setEnabled(b);
    ui->AppedLib->setEnabled(b);

    // 设置状态
    qDebug() << str;
    ui->Status->setText(str);

    // 设置样式
    if(str == "验证成功")
        ui->Status->setStyleSheet("color:#02C39A;");
    else if(str == "验证失败")
        ui->Status->setStyleSheet("color:#D90429;");
    else if(str == "未验证")
        ui->Status->setStyleSheet("color:#F2F2F2;");
}

void LibraryList::getBackupList()
{
    // 获取备份库列表
    NW_Package data;
    data.pa_action = NW_AC_GET;
    data.pa_type   = NW_DT_MSG;
    data.pa_status = NW_DS_ONCE;
    data.pa_size   = strlen("getbackuplist");
    strcpy(data.pa_context,"getbackuplist");
    dataProcess->sendData(data); 
}

void LibraryList::initTray()
{
    // 设置系统托盘的图标
    tray->setIcon(QIcon(":/icon/icon.png"));

    // 设置一下系统托盘的提示标签
    tray->setToolTip("云端备份软件-v0.0.01");

    tray->show();

    // 关联信号
    connect(tray,&QSystemTrayIcon::activated,this,&LibraryList::on_TrayChecked);

    // 关联菜单
    QMenu *menu = new QMenu(this);
    menu->addAction("云端备份软件v0.0.01");
    menu->addAction("退出",[=]{QCoreApplication::quit();});

    // 添加到托盘上
    tray->setContextMenu(menu);
}

void LibraryList::addGNItem(QString name, QString time)
{
    addGroupItem(name,time);
}

// 登录服务器，获取备份库列表
void LibraryList::on_Check_clicked()
{
    // 判断是否已经连接服务器
    if(dataProcess->isConnect())
    {
        // 断开连接
        dataProcess->shutDown();
        // 设置按钮状态
        setConnectStatus(false,"未连接");
        return;
    }

    // 获取服务器地址和端口
    QString addr = ui->Address->text();
    QString port = ui->Port->text();

    // 开启网络线程
    dataProcess->connectServer(ui->Address->text(),ui->Port->text().toInt());
    if(!dataProcess->isConnect())
    {
        // 设置按钮状态
        setConnectStatus(false,"验证失败");
        return;
    }

    dataProcess->start();

    // 发送登录请求
    NW_Package data;
    data.pa_action = NW_AC_LOGIN;
    std::string context = ui->Name->text().toStdString()+":"+ui->Password->text().toStdString();
    strcpy(data.pa_context,context.c_str());
    dataProcess->sendData(data);

    connect(dataProcess,&DataProcess::newRecv,this,[=](NW_Package data){

        // 拆包来判断什么类型的数据，然后执行对应的操作
        switch(data.pa_action)
        {
            case NW_AC_LOGIN:
                if(data.pa_context == QString("success"))
                {
                    // 设置按钮状态
                    setConnectStatus(true,"验证成功");
                    // 获取备份库列表
                    getBackupList();
                }
                else
                {
                    // 设置按钮状态
                    setConnectStatus(false,"验证失败");
                    // 断开连接
                    dataProcess->shutDown();
                    break;
                }
                break;
            case NW_AC_QUIT:
                // 断开连接
                dataProcess->shutDown();
                // 设置按钮状态
                setConnectStatus(false,"未连接");
                break;
            case NW_AC_MSG:
                // 获取行为
                // 判断数据类型
                switch(data.pa_type)
                {
                    case NW_DT_MSG:
                        // 解析数据
                        std::vector<std::string> row = NW_Parse(data.pa_context);
                        qDebug() << row.size();
                        emit addGourpNewItem(row[1].c_str(),"0.0.0.0");
                        break;
                }
            case NW_AC_PUT:

            // 忽略行为
            case NW_AC_IGN:
            default:
                break;
        }
    });
}

// 恢复窗口显示
void LibraryList::on_TrayChecked(QSystemTrayIcon::ActivationReason reson)
{
    if(reson==QSystemTrayIcon::DoubleClick)show();
}

void LibraryList::closeEvent(QCloseEvent *ev)
{
    // 隐藏窗口
    hide();

    // 忽略事件
    ev->ignore();
}

