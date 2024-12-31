#include "LibListItem.h"
#include "ui_LibListItem.h"

LibListItem::LibListItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LibListItem)
{
    ui->setupUi(this);
}

LibListItem::~LibListItem()
{
    delete ui;
}

void LibListItem::setLibName(QString str)
{
    ui->LibraryName->setText(str);
}

void LibListItem::setLibAddr(QString str)
{
    ui->LibraryAddress->setText(str);
}

void LibListItem::setLibPort(QString str)
{
    ui->LibraryPort->setText(str);
}

QString LibListItem::libName() const
{
    return ui->LibraryName->text();
}

QString LibListItem::libAddr() const
{
    return ui->LibraryAddress->text();
}

QString LibListItem::libPort() const
{
    return ui->LibraryPort->text();
}
