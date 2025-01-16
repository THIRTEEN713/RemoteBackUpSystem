#ifndef LIBRARYLIST_H
#define LIBRARYLIST_H

#include "DataProcess.h"
#include <QSystemTrayIcon>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class LibraryList;
}
QT_END_NAMESPACE

class LibraryList : public QWidget
{
    Q_OBJECT

public:
    LibraryList(QWidget *parent = nullptr);
    ~LibraryList();

private slots:
    void on_AppedLib_clicked();

    void on_DeleteLib_clicked();

    void on_ShowTasks_clicked();

    void on_Check_clicked();

    void on_TrayChecked(QSystemTrayIcon::ActivationReason reson);
private:
    void closeEvent(QCloseEvent *ev);
    void addGroupItem(QString,QString);
    void setConnectStatus(bool,QString);
    void getBackupList();
    void initTray();
    void addGNItem(QString,QString);
signals:
    void addGourpNewItem(QString,QString);
private:
    Ui::LibraryList *ui;

    // 系统托盘
    QSystemTrayIcon *tray;

    // 定义网络线程
    DataProcess *dataProcess;

};
#endif // LIBRARYLIST_H
