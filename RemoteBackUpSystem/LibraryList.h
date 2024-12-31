#ifndef LIBRARYLIST_H
#define LIBRARYLIST_H

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

private:
    Ui::LibraryList *ui;
};
#endif // LIBRARYLIST_H
