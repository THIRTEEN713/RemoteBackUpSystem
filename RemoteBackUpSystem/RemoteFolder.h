#ifndef REMOTEFOLDER_H
#define REMOTEFOLDER_H

#include <QWidget>

namespace Ui {
class RemoteFolder;
}

class RemoteFolder : public QWidget
{
    Q_OBJECT

public:
    explicit RemoteFolder(QWidget *parent = nullptr);
    ~RemoteFolder();

private slots:
    void on_PrevPath_clicked();

private:
    Ui::RemoteFolder *ui;
};

#endif // REMOTEFOLDER_H
