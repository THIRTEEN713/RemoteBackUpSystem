/********************************************************************************
** Form generated from reading UI file 'PlaneItem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANEITEM_H
#define UI_PLANEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlaneItem
{
public:
    QHBoxLayout *horizontalLayout;
    QRadioButton *LibName;
    QLabel *Status;
    QLabel *SrcTip;
    QLabel *SrcPath;
    QToolButton *CheckPath;
    QPushButton *Config;

    void setupUi(QWidget *PlaneItem)
    {
        if (PlaneItem->objectName().isEmpty())
            PlaneItem->setObjectName("PlaneItem");
        PlaneItem->resize(711, 45);
        horizontalLayout = new QHBoxLayout(PlaneItem);
        horizontalLayout->setObjectName("horizontalLayout");
        LibName = new QRadioButton(PlaneItem);
        LibName->setObjectName("LibName");
        LibName->setMinimumSize(QSize(150, 0));
        LibName->setMaximumSize(QSize(150, 16777215));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        LibName->setFont(font);

        horizontalLayout->addWidget(LibName);

        Status = new QLabel(PlaneItem);
        Status->setObjectName("Status");
        Status->setMinimumSize(QSize(40, 0));
        Status->setMaximumSize(QSize(40, 16777215));
        QFont font1;
        font1.setBold(true);
        Status->setFont(font1);
        Status->setStyleSheet(QString::fromUtf8("color:#D90429;"));
        Status->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(Status);

        SrcTip = new QLabel(PlaneItem);
        SrcTip->setObjectName("SrcTip");
        SrcTip->setMinimumSize(QSize(50, 0));
        SrcTip->setMaximumSize(QSize(50, 16777215));
        SrcTip->setFont(font);

        horizontalLayout->addWidget(SrcTip);

        SrcPath = new QLabel(PlaneItem);
        SrcPath->setObjectName("SrcPath");

        horizontalLayout->addWidget(SrcPath);

        CheckPath = new QToolButton(PlaneItem);
        CheckPath->setObjectName("CheckPath");

        horizontalLayout->addWidget(CheckPath);

        Config = new QPushButton(PlaneItem);
        Config->setObjectName("Config");
        Config->setMinimumSize(QSize(60, 0));
        Config->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(Config);


        retranslateUi(PlaneItem);

        QMetaObject::connectSlotsByName(PlaneItem);
    } // setupUi

    void retranslateUi(QWidget *PlaneItem)
    {
        PlaneItem->setWindowTitle(QCoreApplication::translate("PlaneItem", "Form", nullptr));
        LibName->setText(QCoreApplication::translate("PlaneItem", "RadioButton", nullptr));
        Status->setText(QCoreApplication::translate("PlaneItem", "\345\201\234\346\255\242", nullptr));
        SrcTip->setText(QCoreApplication::translate("PlaneItem", "\345\244\207\344\273\275\346\272\220\357\274\232", nullptr));
        SrcPath->setText(QCoreApplication::translate("PlaneItem", "null", nullptr));
        CheckPath->setText(QCoreApplication::translate("PlaneItem", "...", nullptr));
        Config->setText(QCoreApplication::translate("PlaneItem", "\351\205\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaneItem: public Ui_PlaneItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANEITEM_H
