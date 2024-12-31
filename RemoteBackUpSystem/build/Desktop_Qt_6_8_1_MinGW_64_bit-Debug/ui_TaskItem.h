/********************************************************************************
** Form generated from reading UI file 'TaskItem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKITEM_H
#define UI_TASKITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskItem
{
public:
    QHBoxLayout *horizontalLayout;
    QRadioButton *TaskLibName;
    QLabel *TaskPlaneName;
    QProgressBar *progressBar;
    QLabel *NeedTimeTip;
    QTimeEdit *TaskTime;
    QPushButton *ToolButton;

    void setupUi(QWidget *TaskItem)
    {
        if (TaskItem->objectName().isEmpty())
            TaskItem->setObjectName("TaskItem");
        TaskItem->resize(502, 47);
        horizontalLayout = new QHBoxLayout(TaskItem);
        horizontalLayout->setObjectName("horizontalLayout");
        TaskLibName = new QRadioButton(TaskItem);
        TaskLibName->setObjectName("TaskLibName");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TaskLibName->sizePolicy().hasHeightForWidth());
        TaskLibName->setSizePolicy(sizePolicy);
        TaskLibName->setChecked(false);

        horizontalLayout->addWidget(TaskLibName);

        TaskPlaneName = new QLabel(TaskItem);
        TaskPlaneName->setObjectName("TaskPlaneName");
        TaskPlaneName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(TaskPlaneName);

        progressBar = new QProgressBar(TaskItem);
        progressBar->setObjectName("progressBar");
        progressBar->setMinimumSize(QSize(100, 0));
        progressBar->setMaximumSize(QSize(100, 16777215));
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{border-radius:12px;}\n"
"QProgressBar::chunk{border-radius:12px;background-color:#22B14C;}"));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        horizontalLayout->addWidget(progressBar);

        NeedTimeTip = new QLabel(TaskItem);
        NeedTimeTip->setObjectName("NeedTimeTip");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(NeedTimeTip->sizePolicy().hasHeightForWidth());
        NeedTimeTip->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(NeedTimeTip);

        TaskTime = new QTimeEdit(TaskItem);
        TaskTime->setObjectName("TaskTime");
        TaskTime->setMinimumSize(QSize(65, 0));
        TaskTime->setMaximumSize(QSize(65, 16777215));
        TaskTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        TaskTime->setReadOnly(true);
        TaskTime->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        TaskTime->setKeyboardTracking(true);

        horizontalLayout->addWidget(TaskTime);

        ToolButton = new QPushButton(TaskItem);
        ToolButton->setObjectName("ToolButton");
        ToolButton->setMinimumSize(QSize(55, 25));
        ToolButton->setMaximumSize(QSize(55, 25));

        horizontalLayout->addWidget(ToolButton);


        retranslateUi(TaskItem);

        QMetaObject::connectSlotsByName(TaskItem);
    } // setupUi

    void retranslateUi(QWidget *TaskItem)
    {
        TaskItem->setWindowTitle(QCoreApplication::translate("TaskItem", "Form", nullptr));
        TaskLibName->setText(QCoreApplication::translate("TaskItem", "\345\244\207\344\273\275\345\272\223\345\220\215", nullptr));
        TaskPlaneName->setText(QCoreApplication::translate("TaskItem", "\345\244\207\344\273\275\350\256\241\345\210\222", nullptr));
        NeedTimeTip->setText(QCoreApplication::translate("TaskItem", "\351\242\204\350\256\241\350\212\261\350\264\271\357\274\232", nullptr));
        ToolButton->setText(QCoreApplication::translate("TaskItem", "\346\232\202\345\201\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskItem: public Ui_TaskItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKITEM_H
