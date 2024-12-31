#ifndef TASKLIST_H
#define TASKLIST_H

#include <QListWidget>
#include <QDialog>
#include <TaskItem.h>

namespace Ui {
class TaskList;
}

class TaskList : public QDialog
{
    Q_OBJECT

public:
    explicit TaskList(QWidget *parent = nullptr);
    ~TaskList();

private slots:
    void on_pushButton_clicked();
    void on_CheckAll_clicked();
    void on_Checked(TaskItem*itemWidget,QListWidgetItem*item);
    void on_UnChecked(TaskItem*itemWidget,QListWidgetItem*item);

    void on_CleanTask_clicked();

private:
    Ui::TaskList *ui;
    QListWidget *finished;
    QListWidget *progress;
    QListWidget *failed;
    QMap<TaskItem*,QListWidgetItem*>items;
};

#endif // TASKLIST_H
