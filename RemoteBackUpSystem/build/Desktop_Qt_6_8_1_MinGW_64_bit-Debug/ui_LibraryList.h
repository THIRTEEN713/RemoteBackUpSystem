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

        List = new QListWidget(LibraryList);
        List->setObjectName("List");

        verticalLayout->addWidget(List);

        ToolLayout = new QHBoxLayout();
        ToolLayout->setObjectName("ToolLayout");
        ToolSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        ToolLayout->addItem(ToolSpacer);

        ShowTasks = new QPushButton(LibraryList);
        ShowTasks->setObjectName("ShowTasks");
        ShowTasks->setMinimumSize(QSize(0, 30));
        ShowTasks->setMaximumSize(QSize(16777215, 30));

        ToolLayout->addWidget(ShowTasks);

        DeleteLib = new QPushButton(LibraryList);
        DeleteLib->setObjectName("DeleteLib");
        DeleteLib->setMinimumSize(QSize(0, 30));
        DeleteLib->setMaximumSize(QSize(16777215, 30));

        ToolLayout->addWidget(DeleteLib);

        AppedLib = new QPushButton(LibraryList);
        AppedLib->setObjectName("AppedLib");
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
        WidgetTip->setText(QCoreApplication::translate("LibraryList", "\345\244\207\344\273\275\345\272\223\345\210\227\350\241\250", nullptr));
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
