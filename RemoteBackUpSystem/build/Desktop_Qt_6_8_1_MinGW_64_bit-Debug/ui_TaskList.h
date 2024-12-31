/********************************************************************************
** Form generated from reading UI file 'TaskList.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKLIST_H
#define UI_TASKLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TaskList
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *WidgetTip;
    QTabWidget *ListTab;
    QHBoxLayout *ToolLayout;
    QRadioButton *CheckAll;
    QSpacerItem *ToolSpacer;
    QPushButton *pushButton;
    QPushButton *CleanTask;

    void setupUi(QDialog *TaskList)
    {
        if (TaskList->objectName().isEmpty())
            TaskList->setObjectName("TaskList");
        TaskList->resize(600, 500);
        TaskList->setMinimumSize(QSize(600, 500));
        TaskList->setMaximumSize(QSize(600, 500));
        verticalLayout = new QVBoxLayout(TaskList);
        verticalLayout->setObjectName("verticalLayout");
        WidgetTip = new QLabel(TaskList);
        WidgetTip->setObjectName("WidgetTip");
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        WidgetTip->setFont(font);

        verticalLayout->addWidget(WidgetTip);

        ListTab = new QTabWidget(TaskList);
        ListTab->setObjectName("ListTab");

        verticalLayout->addWidget(ListTab);

        ToolLayout = new QHBoxLayout();
        ToolLayout->setObjectName("ToolLayout");
        CheckAll = new QRadioButton(TaskList);
        CheckAll->setObjectName("CheckAll");
        CheckAll->setMinimumSize(QSize(0, 30));
        CheckAll->setMaximumSize(QSize(16777215, 30));

        ToolLayout->addWidget(CheckAll);

        ToolSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        ToolLayout->addItem(ToolSpacer);

        pushButton = new QPushButton(TaskList);
        pushButton->setObjectName("pushButton");

        ToolLayout->addWidget(pushButton);

        CleanTask = new QPushButton(TaskList);
        CleanTask->setObjectName("CleanTask");
        CleanTask->setMinimumSize(QSize(0, 30));
        CleanTask->setMaximumSize(QSize(16777215, 30));

        ToolLayout->addWidget(CleanTask);


        verticalLayout->addLayout(ToolLayout);


        retranslateUi(TaskList);

        ListTab->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(TaskList);
    } // setupUi

    void retranslateUi(QDialog *TaskList)
    {
        TaskList->setWindowTitle(QCoreApplication::translate("TaskList", "Form", nullptr));
        WidgetTip->setText(QCoreApplication::translate("TaskList", "\345\244\207\344\273\275\344\273\273\345\212\241\345\210\227\350\241\250", nullptr));
        CheckAll->setText(QCoreApplication::translate("TaskList", "\351\200\211\346\213\251\345\205\250\351\203\250", nullptr));
        pushButton->setText(QCoreApplication::translate("TaskList", "\345\242\236\345\212\240\344\273\273\345\212\241\347\232\204\346\265\213\350\257\225\346\214\211\351\222\256", nullptr));
        CleanTask->setText(QCoreApplication::translate("TaskList", "\346\270\205\351\231\244\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskList: public Ui_TaskList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKLIST_H
