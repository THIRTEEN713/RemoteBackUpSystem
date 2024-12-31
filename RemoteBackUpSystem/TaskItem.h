#ifndef TASKITEM_H
#define TASKITEM_H

#include <QWidget>

namespace Ui {
class TaskItem;
}

class TaskItem : public QWidget
{
    Q_OBJECT

public:
    explicit TaskItem(QWidget *parent = nullptr);
    ~TaskItem();

    // 公开的接口
    void setStatus(bool);

    bool status()const;

signals:
    void checked();
    void unChecked();

private slots:
    void on_TaskLibName_clicked(bool checked);

private:
    Ui::TaskItem *ui;
};

#endif // TASKITEM_H
