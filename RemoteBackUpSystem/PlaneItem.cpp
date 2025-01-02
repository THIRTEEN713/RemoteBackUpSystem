#include "PlaneItem.h"
#include "ui_PlaneItem.h"
#include <PlaneConfig.h>
#include <QFileDialog>

PlaneItem::PlaneItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlaneItem)
{
    ui->setupUi(this);
}

PlaneItem::~PlaneItem()
{
    delete ui;
}

void PlaneItem::setLibName(QString str)
{
    ui->LibName->setText(str);
}

void PlaneItem::setSrcPath(QString str)
{
    ui->SrcPath->setText(str);
}

void PlaneItem::setStatus(bool b)
{
    QString style="";
    if(b)
    {
        ui->Status->setText("运行");
        style = "color:#02C39A;";
    }
    else
    {
        ui->Status->setText("停止");
        style = "color:#D90429;";
    }
    ui->Status->setStyleSheet(style);
}

void PlaneItem::setCheckState(bool b)
{
    ui->LibName->setChecked(b);
}

QString PlaneItem::libName()
{
    return ui->LibName->text();
}

QString PlaneItem::srcPath()
{
    return ui->SrcPath->text();
}

bool PlaneItem::status()
{
    return ui->Status->text() == "运行";
}

bool PlaneItem::checkState()
{
    return ui->LibName->isChecked();
}

void PlaneItem::on_CheckPath_clicked()
{
    QString url = QFileDialog::getExistingDirectory();
    ui->SrcPath->setText(url);
    ui->SrcPath->setToolTip(url);
}


void PlaneItem::on_Config_clicked()
{
    PlaneConfig *config = new PlaneConfig;

    config->exec();
    delete config;
}

