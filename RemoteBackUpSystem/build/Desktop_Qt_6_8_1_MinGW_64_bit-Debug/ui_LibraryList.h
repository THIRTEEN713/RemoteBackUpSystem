/********************************************************************************
** Form generated from reading UI file 'LibraryList.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARYLIST_H
#define UI_LIBRARYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibraryList
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *WidgetTip;
    QHBoxLayout *InforLayout;
    QLineEdit *Address;
    QLineEdit *Port;
    QLineEdit *Name;
    QLineEdit *Password;
    QLabel *Status;
    QPushButton *Check;
    QListWidget *List;
    QHBoxLayout *ToolLayout;
    QSpacerItem *ToolSpacer;
    QPushButton *ShowTasks;
    QPushButton *DeleteLib;
    QPushButton *AppedLib;

    void setupUi(QWidget *LibraryList)
    {
        if (LibraryList->objectName().isEmpty())
            LibraryList->setObjectName("LibraryList");
        LibraryList->resize(600, 500);
        LibraryList->setMinimumSize(QSize(600, 500));
        LibraryList->setMaximumSize(QSize(600, 500));
        verticalLayout = new QVBoxLayout(LibraryList);
        verticalLayout->setObjectName("verticalLayout");
        WidgetTip = new QLabel(LibraryList);
        WidgetTip->setObjectName("WidgetTip");
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        WidgetTip->setFont(font);

        verticalLayout->addWidget(WidgetTip);

        InforLayout = new QHBoxLayout();
        InforLayout->setObjectName("InforLayout");
        Address = new QLineEdit(LibraryList);
        Address->setObjectName("Address");
        Address->setMaximumSize(QSize(120, 16777215));

        InforLayout->addWidget(Address);

        Port = new QLineEdit(LibraryList);
        Port->setObjectName("Port");
        Port->setMaximumSize(QSize(80, 16777215));

        InforLayout->addWidget(Port);

        Name = new QLineEdit(LibraryList);
        Name->setObjectName("Name");

        InforLayout->addWidget(Name);

        Password = new QLineEdit(LibraryList);
        Password->setObjectName("Password");
        Password->setEchoMode(QLineEdit::EchoMode::Password);

        InforLayout->addWidget(Password);

        Status = new QLabel(LibraryList);
        Status->setObjectName("Status");
        Status->setMinimumSize(QSize(50, 0));
        Status->setMaximumSize(QSize(50, 16777215));
        QFont font1;
        font1.setBold(true);
        Status->setFont(font1);
        Status->setStyleSheet(QString::fromUtf8("color: rgb(8, 111, 208);"));
        Status->setAlignment(Qt::AlignmentFlag::AlignCenter);

        InforLayout->addWidget(Status);

        Check = new QPushButton(LibraryList);
        Check->setObjectName("Check");

        InforLayout->addWidget(Check);


        verticalLayout->addLayout(InforLayout);

        List = new QListWidget(LibraryList);
        List->setObjectName("List");

        verticalLayout->addWidget(List);

        ToolLayout = new QHBoxLayout();
        ToolLayout->setObjectName("ToolLayout");
        ToolSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        ToolLayout->addItem(ToolSpacer);

        ShowTasks = new QPushButton(LibraryList);
        ShowTasks->setObjectName("ShowTasks");
        ShowTasks->setEnabled(false);
        ShowTasks->setMinimumSize(QSize(0, 30));
        ShowTasks->setMaximumSize(QSize(16777215, 30));

        ToolLayout->addWidget(ShowTasks);

        DeleteLib = new QPushButton(LibraryList);
        DeleteLib->setObjectName("DeleteLib");
        DeleteLib->setEnabled(false);
        DeleteLib->setMinimumSize(QSize(0, 30));
        DeleteLib->setMaximumSize(QSize(16777215, 30));

        ToolLayout->addWidget(DeleteLib);

        AppedLib = new QPushButton(LibraryList);
        AppedLib->setObjectName("AppedLib");
        AppedLib->setEnabled(false);
        AppedLib->setMinimumSize(QSize(0, 30));
        AppedLib->setMaximumSize(QSize(16777215, 30));

        ToolLayout->addWidget(AppedLib);


        verticalLayout->addLayout(ToolLayout);


        retranslateUi(LibraryList);

        QMetaObject::connectSlotsByName(LibraryList);
    } // setupUi

    void retranslateUi(QWidget *LibraryList)
    {
        LibraryList->setWindowTitle(QCoreApplication::translate("LibraryList", "LibraryList", nullptr));
        WidgetTip->setText(QCoreApplication::translate("LibraryList", "\345\244\207\344\273\275\347\273\204\345\210\227\350\241\250", nullptr));
        Address->setText(QCoreApplication::translate("LibraryList", "192.168.56.133", nullptr));
        Address->setPlaceholderText(QCoreApplication::translate("LibraryList", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200", nullptr));
        Port->setText(QCoreApplication::translate("LibraryList", "8899", nullptr));
        Port->setPlaceholderText(QCoreApplication::translate("LibraryList", "\347\253\257\345\217\243\345\217\267", nullptr));
        Name->setText(QCoreApplication::translate("LibraryList", "test@email.com", nullptr));
        Name->setPlaceholderText(QCoreApplication::translate("LibraryList", "\347\224\250\346\210\267\345\220\215", nullptr));
        Password->setText(QCoreApplication::translate("LibraryList", "123456", nullptr));
        Password->setPlaceholderText(QCoreApplication::translate("LibraryList", "\345\217\243\344\273\244", nullptr));
        Status->setText(QCoreApplication::translate("LibraryList", "\346\234\252\351\252\214\350\257\201", nullptr));
        Check->setText(QCoreApplication::translate("LibraryList", "\351\252\214\350\257\201", nullptr));
        ShowTasks->setText(QCoreApplication::translate("LibraryList", "\346\237\245\347\234\213\344\273\273\345\212\241", nullptr));
        DeleteLib->setText(QCoreApplication::translate("LibraryList", "\345\210\240\351\231\244\345\244\207\344\273\275\345\272\223", nullptr));
        AppedLib->setText(QCoreApplication::translate("LibraryList", "\346\267\273\345\212\240\345\244\207\344\273\275\345\272\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibraryList: public Ui_LibraryList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYLIST_H
