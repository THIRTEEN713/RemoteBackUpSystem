/********************************************************************************
** Form generated from reading UI file 'PlaneConfig.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANECONFIG_H
#define UI_PLANECONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PlaneConfig
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *ConfigTip;
    QHBoxLayout *NameLayout;
    QLabel *NameTip;
    QLineEdit *Name;
    QHBoxLayout *PathLayout;
    QLabel *PathTip;
    QLineEdit *Path;
    QToolButton *ChangePath;
    QHBoxLayout *WayLayout;
    QLabel *WayTip;
    QRadioButton *Interal;
    QRadioButton *Clock;
    QSpacerItem *WaySpacer;
    QHBoxLayout *InteralLayout;
    QLabel *InteralTip;
    QComboBox *InteralTime;
    QSpacerItem *InteralSpacer;
    QGridLayout *ClockLayout;
    QCheckBox *checkBox_4;
    QCheckBox *Mon;
    QLabel *ClockDate;
    QCheckBox *Tue;
    QRadioButton *WorkDay;
    QCheckBox *Fri;
    QRadioButton *DoubleDay;
    QRadioButton *EveryDay;
    QRadioButton *SingleDay;
    QRadioButton *UserDefine;
    QCheckBox *Thi;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_6;
    QRadioButton *Holiday;
    QLabel *ClockTip;
    QTimeEdit *timeEdit;
    QHBoxLayout *ToolLayout;
    QSpacerItem *ToolSpacer;
    QPushButton *Cancel;
    QPushButton *Ok;

    void setupUi(QDialog *PlaneConfig)
    {
        if (PlaneConfig->objectName().isEmpty())
            PlaneConfig->setObjectName("PlaneConfig");
        PlaneConfig->resize(455, 400);
        PlaneConfig->setMinimumSize(QSize(455, 400));
        PlaneConfig->setMaximumSize(QSize(455, 400));
        verticalLayout_2 = new QVBoxLayout(PlaneConfig);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        ConfigTip = new QLabel(PlaneConfig);
        ConfigTip->setObjectName("ConfigTip");
        ConfigTip->setMaximumSize(QSize(16777215, 60));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        ConfigTip->setFont(font);

        verticalLayout_2->addWidget(ConfigTip);

        NameLayout = new QHBoxLayout();
        NameLayout->setObjectName("NameLayout");
        NameTip = new QLabel(PlaneConfig);
        NameTip->setObjectName("NameTip");
        QFont font1;
        font1.setBold(true);
        NameTip->setFont(font1);

        NameLayout->addWidget(NameTip);

        Name = new QLineEdit(PlaneConfig);
        Name->setObjectName("Name");

        NameLayout->addWidget(Name);


        verticalLayout_2->addLayout(NameLayout);

        PathLayout = new QHBoxLayout();
        PathLayout->setObjectName("PathLayout");
        PathLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        PathTip = new QLabel(PlaneConfig);
        PathTip->setObjectName("PathTip");
        PathTip->setFont(font1);

        PathLayout->addWidget(PathTip);

        Path = new QLineEdit(PlaneConfig);
        Path->setObjectName("Path");

        PathLayout->addWidget(Path);

        ChangePath = new QToolButton(PlaneConfig);
        ChangePath->setObjectName("ChangePath");

        PathLayout->addWidget(ChangePath);


        verticalLayout_2->addLayout(PathLayout);

        WayLayout = new QHBoxLayout();
        WayLayout->setObjectName("WayLayout");
        WayTip = new QLabel(PlaneConfig);
        WayTip->setObjectName("WayTip");
        WayTip->setFont(font1);

        WayLayout->addWidget(WayTip);

        Interal = new QRadioButton(PlaneConfig);
        Interal->setObjectName("Interal");

        WayLayout->addWidget(Interal);

        Clock = new QRadioButton(PlaneConfig);
        Clock->setObjectName("Clock");

        WayLayout->addWidget(Clock);

        WaySpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        WayLayout->addItem(WaySpacer);


        verticalLayout_2->addLayout(WayLayout);

        InteralLayout = new QHBoxLayout();
        InteralLayout->setObjectName("InteralLayout");
        InteralTip = new QLabel(PlaneConfig);
        InteralTip->setObjectName("InteralTip");
        InteralTip->setFont(font1);

        InteralLayout->addWidget(InteralTip);

        InteralTime = new QComboBox(PlaneConfig);
        InteralTime->addItem(QString());
        InteralTime->addItem(QString());
        InteralTime->addItem(QString());
        InteralTime->addItem(QString());
        InteralTime->addItem(QString());
        InteralTime->setObjectName("InteralTime");

        InteralLayout->addWidget(InteralTime);

        InteralSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        InteralLayout->addItem(InteralSpacer);


        verticalLayout_2->addLayout(InteralLayout);

        ClockLayout = new QGridLayout();
        ClockLayout->setObjectName("ClockLayout");
        ClockLayout->setHorizontalSpacing(5);
        ClockLayout->setVerticalSpacing(15);
        ClockLayout->setContentsMargins(-1, 15, -1, -1);
        checkBox_4 = new QCheckBox(PlaneConfig);
        checkBox_4->setObjectName("checkBox_4");

        ClockLayout->addWidget(checkBox_4, 2, 3, 1, 1);

        Mon = new QCheckBox(PlaneConfig);
        Mon->setObjectName("Mon");

        ClockLayout->addWidget(Mon, 2, 0, 1, 1);

        ClockDate = new QLabel(PlaneConfig);
        ClockDate->setObjectName("ClockDate");
        ClockDate->setFont(font1);

        ClockLayout->addWidget(ClockDate, 1, 0, 1, 1);

        Tue = new QCheckBox(PlaneConfig);
        Tue->setObjectName("Tue");

        ClockLayout->addWidget(Tue, 2, 1, 1, 1);

        WorkDay = new QRadioButton(PlaneConfig);
        WorkDay->setObjectName("WorkDay");

        ClockLayout->addWidget(WorkDay, 1, 3, 1, 1);

        Fri = new QCheckBox(PlaneConfig);
        Fri->setObjectName("Fri");

        ClockLayout->addWidget(Fri, 2, 4, 1, 1);

        DoubleDay = new QRadioButton(PlaneConfig);
        DoubleDay->setObjectName("DoubleDay");

        ClockLayout->addWidget(DoubleDay, 1, 5, 1, 1);

        EveryDay = new QRadioButton(PlaneConfig);
        EveryDay->setObjectName("EveryDay");

        ClockLayout->addWidget(EveryDay, 1, 1, 1, 1);

        SingleDay = new QRadioButton(PlaneConfig);
        SingleDay->setObjectName("SingleDay");

        ClockLayout->addWidget(SingleDay, 1, 4, 1, 1);

        UserDefine = new QRadioButton(PlaneConfig);
        UserDefine->setObjectName("UserDefine");

        ClockLayout->addWidget(UserDefine, 1, 6, 1, 1);

        Thi = new QCheckBox(PlaneConfig);
        Thi->setObjectName("Thi");

        ClockLayout->addWidget(Thi, 2, 2, 1, 1);

        checkBox_7 = new QCheckBox(PlaneConfig);
        checkBox_7->setObjectName("checkBox_7");

        ClockLayout->addWidget(checkBox_7, 2, 6, 1, 1);

        checkBox_6 = new QCheckBox(PlaneConfig);
        checkBox_6->setObjectName("checkBox_6");

        ClockLayout->addWidget(checkBox_6, 2, 5, 1, 1);

        Holiday = new QRadioButton(PlaneConfig);
        Holiday->setObjectName("Holiday");

        ClockLayout->addWidget(Holiday, 1, 2, 1, 1);

        ClockTip = new QLabel(PlaneConfig);
        ClockTip->setObjectName("ClockTip");
        ClockTip->setFont(font1);

        ClockLayout->addWidget(ClockTip, 0, 0, 1, 1);

        timeEdit = new QTimeEdit(PlaneConfig);
        timeEdit->setObjectName("timeEdit");

        ClockLayout->addWidget(timeEdit, 0, 1, 1, 1);


        verticalLayout_2->addLayout(ClockLayout);

        ToolLayout = new QHBoxLayout();
        ToolLayout->setObjectName("ToolLayout");
        ToolSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        ToolLayout->addItem(ToolSpacer);

        Cancel = new QPushButton(PlaneConfig);
        Cancel->setObjectName("Cancel");

        ToolLayout->addWidget(Cancel);

        Ok = new QPushButton(PlaneConfig);
        Ok->setObjectName("Ok");

        ToolLayout->addWidget(Ok);


        verticalLayout_2->addLayout(ToolLayout);


        retranslateUi(PlaneConfig);

        QMetaObject::connectSlotsByName(PlaneConfig);
    } // setupUi

    void retranslateUi(QDialog *PlaneConfig)
    {
        PlaneConfig->setWindowTitle(QCoreApplication::translate("PlaneConfig", "Dialog", nullptr));
        ConfigTip->setText(QCoreApplication::translate("PlaneConfig", "\345\244\207\344\273\275\350\256\241\345\210\222\351\205\215\347\275\256", nullptr));
        NameTip->setText(QCoreApplication::translate("PlaneConfig", "\350\256\241\345\210\222\345\220\215\357\274\232", nullptr));
        PathTip->setText(QCoreApplication::translate("PlaneConfig", "\346\272\220\350\267\257\345\276\204\357\274\232", nullptr));
        ChangePath->setText(QCoreApplication::translate("PlaneConfig", "...", nullptr));
        WayTip->setText(QCoreApplication::translate("PlaneConfig", "\345\244\207\344\273\275\346\226\271\345\274\217\357\274\232", nullptr));
        Interal->setText(QCoreApplication::translate("PlaneConfig", "\351\227\264\351\232\224\345\244\207\344\273\275", nullptr));
        Clock->setText(QCoreApplication::translate("PlaneConfig", "\345\256\232\346\227\266\345\244\207\344\273\275", nullptr));
        InteralTip->setText(QCoreApplication::translate("PlaneConfig", "\345\244\207\344\273\275\351\227\264\351\232\224", nullptr));
        InteralTime->setItemText(0, QCoreApplication::translate("PlaneConfig", "\344\270\200\345\210\206\351\222\237", nullptr));
        InteralTime->setItemText(1, QCoreApplication::translate("PlaneConfig", "\344\272\224\345\210\206\351\222\237", nullptr));
        InteralTime->setItemText(2, QCoreApplication::translate("PlaneConfig", "\345\215\201\345\210\206\351\222\237", nullptr));
        InteralTime->setItemText(3, QCoreApplication::translate("PlaneConfig", "\345\215\212\345\260\217\346\227\266", nullptr));
        InteralTime->setItemText(4, QCoreApplication::translate("PlaneConfig", "\344\270\200\345\260\217\346\227\266", nullptr));

        checkBox_4->setText(QCoreApplication::translate("PlaneConfig", "\345\221\250\345\233\233", nullptr));
        Mon->setText(QCoreApplication::translate("PlaneConfig", "\345\221\250\344\270\200", nullptr));
        ClockDate->setText(QCoreApplication::translate("PlaneConfig", "\345\244\207\344\273\275\346\227\245\346\234\237", nullptr));
        Tue->setText(QCoreApplication::translate("PlaneConfig", "\345\221\250\344\272\214", nullptr));
        WorkDay->setText(QCoreApplication::translate("PlaneConfig", "\345\267\245\344\275\234\346\227\245", nullptr));
        Fri->setText(QCoreApplication::translate("PlaneConfig", "\345\221\250\344\272\224", nullptr));
        DoubleDay->setText(QCoreApplication::translate("PlaneConfig", "\345\217\214\346\225\260\345\244\251", nullptr));
        EveryDay->setText(QCoreApplication::translate("PlaneConfig", "\346\257\217\345\244\251", nullptr));
        SingleDay->setText(QCoreApplication::translate("PlaneConfig", "\345\215\225\346\225\260\345\244\251", nullptr));
        UserDefine->setText(QCoreApplication::translate("PlaneConfig", "\350\207\252\345\256\232\344\271\211", nullptr));
        Thi->setText(QCoreApplication::translate("PlaneConfig", "\345\221\250\344\270\211", nullptr));
        checkBox_7->setText(QCoreApplication::translate("PlaneConfig", "\345\221\250\346\227\245", nullptr));
        checkBox_6->setText(QCoreApplication::translate("PlaneConfig", "\345\221\250\345\205\255", nullptr));
        Holiday->setText(QCoreApplication::translate("PlaneConfig", "\345\221\250\346\234\253", nullptr));
        ClockTip->setText(QCoreApplication::translate("PlaneConfig", "\345\244\207\344\273\275\346\227\266\351\227\264", nullptr));
        Cancel->setText(QCoreApplication::translate("PlaneConfig", "\345\217\226\346\266\210", nullptr));
        Ok->setText(QCoreApplication::translate("PlaneConfig", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaneConfig: public Ui_PlaneConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANECONFIG_H
