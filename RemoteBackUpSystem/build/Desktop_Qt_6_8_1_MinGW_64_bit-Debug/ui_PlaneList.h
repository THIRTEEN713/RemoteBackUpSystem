/********************************************************************************
** Form generated from reading UI file 'PlaneList.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANELIST_H
#define UI_PLANELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PlaneList
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *PlaneTip;
    QListWidget *List;
    QHBoxLayout *ToolLayout;
    QCheckBox *checkBox;
    QSpacerItem *ToolSpacer;
    QPushButton *PlaneStart;
    QPushButton *PlaneStop;
    QPushButton *PlaneDelete;
    QPushButton *PlaneAppend;

    void setupUi(QDialog *PlaneList)
    {
        if (PlaneList->objectName().isEmpty())
            PlaneList->setObjectName("PlaneList");
        PlaneList->resize(600, 500);
        PlaneList->setMinimumSize(QSize(600, 500));
        PlaneList->setMaximumSize(QSize(600, 500));
        verticalLayout = new QVBoxLayout(PlaneList);
        verticalLayout->setObjectName("verticalLayout");
        PlaneTip = new QLabel(PlaneList);
        PlaneTip->setObjectName("PlaneTip");
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        PlaneTip->setFont(font);

        verticalLayout->addWidget(PlaneTip);

        List = new QListWidget(PlaneList);
        List->setObjectName("List");

        verticalLayout->addWidget(List);

        ToolLayout = new QHBoxLayout();
        ToolLayout->setObjectName("ToolLayout");
        checkBox = new QCheckBox(PlaneList);
        checkBox->setObjectName("checkBox");
        checkBox->setMinimumSize(QSize(70, 30));
        checkBox->setMaximumSize(QSize(70, 30));

        ToolLayout->addWidget(checkBox);

        ToolSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        ToolLayout->addItem(ToolSpacer);

        PlaneStart = new QPushButton(PlaneList);
        PlaneStart->setObjectName("PlaneStart");
        PlaneStart->setMinimumSize(QSize(70, 30));
        PlaneStart->setMaximumSize(QSize(70, 30));

        ToolLayout->addWidget(PlaneStart);

        PlaneStop = new QPushButton(PlaneList);
        PlaneStop->setObjectName("PlaneStop");
        PlaneStop->setMinimumSize(QSize(70, 30));
        PlaneStop->setMaximumSize(QSize(70, 30));

        ToolLayout->addWidget(PlaneStop);

        PlaneDelete = new QPushButton(PlaneList);
        PlaneDelete->setObjectName("PlaneDelete");
        PlaneDelete->setMinimumSize(QSize(70, 30));
        PlaneDelete->setMaximumSize(QSize(70, 30));

        ToolLayout->addWidget(PlaneDelete);

        PlaneAppend = new QPushButton(PlaneList);
        PlaneAppend->setObjectName("PlaneAppend");
        PlaneAppend->setMinimumSize(QSize(70, 30));
        PlaneAppend->setMaximumSize(QSize(70, 30));

        ToolLayout->addWidget(PlaneAppend);


        verticalLayout->addLayout(ToolLayout);


        retranslateUi(PlaneList);

        QMetaObject::connectSlotsByName(PlaneList);
    } // setupUi

    void retranslateUi(QDialog *PlaneList)
    {
        PlaneList->setWindowTitle(QCoreApplication::translate("PlaneList", "Dialog", nullptr));
        PlaneTip->setText(QCoreApplication::translate("PlaneList", "\345\244\207\344\273\275\350\256\241\345\210\222\345\210\227\350\241\250", nullptr));
        checkBox->setText(QCoreApplication::translate("PlaneList", "\351\200\211\346\213\251\345\205\250\351\203\250", nullptr));
        PlaneStart->setText(QCoreApplication::translate("PlaneList", "\345\274\200\345\220\257\350\256\241\345\210\222", nullptr));
        PlaneStop->setText(QCoreApplication::translate("PlaneList", "\345\201\234\346\255\242\350\256\241\345\210\222", nullptr));
        PlaneDelete->setText(QCoreApplication::translate("PlaneList", "\345\210\240\351\231\244\350\256\241\345\210\222", nullptr));
        PlaneAppend->setText(QCoreApplication::translate("PlaneList", "\346\267\273\345\212\240\350\256\241\345\210\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaneList: public Ui_PlaneList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANELIST_H
