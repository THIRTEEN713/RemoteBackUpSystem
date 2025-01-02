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
