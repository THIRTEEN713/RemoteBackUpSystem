#include "PlaneConfig.h"
#include "ui_PlaneConfig.h"

#include <QFileDialog>

PlaneConfig::PlaneConfig(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlaneConfig)
{
    ui->setupUi(this);
}

PlaneConfig::~PlaneConfig()
{
    delete ui;
}

void PlaneConfig::on_ChangePath_clicked()
{
    QString url = QFileDialog::getExistingDirectory();
    ui->Path->setText(url);
    ui->Path->setToolTip(url);
}

// 生成备份计划
void PlaneConfig::on_Ok_clicked()
{
    // 获取数据
    QString data = "";

    // 获取备份计划名
    data += ui->Name->text()+":";
    
    // 获取备份路径
    data += ui->Path->text()+":";

    // 通过判断RadioButton获取备份类型
    if(ui->Interal->isChecked()) // 间隔备份
    {
        data += "Interal:";

        // 获取间隔时间
        QString tm = ui->InteralTime->currentText();
        if(tm == "一分钟")
            data += "1";
        else if(tm == "五分钟")
            data += "5";
        else if(tm == "十分钟")
            data += "10";
        else if(tm == "半小时")
            data += "30";
        else if(tm == "一小时")
            data += "60";
    }
    else if(ui->Clock->isChecked()) // 定时备份
    {
        data += "Clock:";

        // 获取备份时间
        QTime tm = ui->ClockTime->time();
        data += tm.toString("hh:mm")+":";

        // 获取备份方式
        int days = 0;
        if(ui->Mon->isChecked())
            days |= 1;
        if(ui->Tue->isChecked())
            days |= 2;
        if(ui->Wed->isChecked())
            days |= 4;
        if(ui->Thu->isChecked())
            days |= 8;
        if(ui->Fri->isChecked())
            days |= 16;
        if(ui->Sat->isChecked())
            days |= 32;
        if(ui->Sun->isChecked())
            days |= 64;

        // 将days转换成ASCII码
        data += QChar(days);
    }

    // 触发 发送消息的信号
    // 构建NW_Package
    NW_Package nw_data;
    nw_data.pa_action = NW_AC_MSG;
    nw_data.pa_type = NW_DT_MSG;
    nw_data.pa_status = NW_DS_ONCE;
    nw_data.pa_size   = data.size();
    strcpy(nw_data.pa_context,data.toStdString().c_str());
    emit sendData(nw_data);
}

