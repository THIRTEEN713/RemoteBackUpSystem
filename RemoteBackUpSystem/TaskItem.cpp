#include "TaskItem.h"
#include "ui_TaskItem.h"

TaskItem::TaskItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TaskItem)
{
    ui->setupUi(this);
}

TaskItem::~TaskItem()
{
    delete ui;
}

void TaskItem::setStatus(bool state)
{
    ui->TaskLibName->setChecked(state);
    if(state)emit this->checked(this);
    else emit this->unChecked(this);
}

bool TaskItem::status() const
{
    return ui->TaskLibName->isChecked();
}

void TaskItem::on_TaskLibName_clicked(bool checked)
{
    if(checked)emit this->checked(this);
    else emit this->unChecked(this);
}

