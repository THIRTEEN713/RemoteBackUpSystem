/********************************************************************************
** Form generated from reading UI file 'FolderItem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOLDERITEM_H
#define UI_FOLDERITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FolderItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLabel *Name;
    QLabel *SrcName;
    QLabel *Type;
    QLabel *Size;
    QLabel *Time;

    void setupUi(QWidget *FolderItem)
    {
        if (FolderItem->objectName().isEmpty())
            FolderItem->setObjectName("FolderItem");
        FolderItem->resize(576, 37);
        horizontalLayout = new QHBoxLayout(FolderItem);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, -1, 5, -1);
        lineEdit = new QLineEdit(FolderItem);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(0, 20));

        horizontalLayout->addWidget(lineEdit);

        Name = new QLabel(FolderItem);
        Name->setObjectName("Name");
        Name->setMinimumSize(QSize(0, 20));
        Name->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setBold(true);
        Name->setFont(font);

        horizontalLayout->addWidget(Name);

        SrcName = new QLabel(FolderItem);
        SrcName->setObjectName("SrcName");
        SrcName->setMinimumSize(QSize(100, 20));
        SrcName->setMaximumSize(QSize(100, 20));
        QFont font1;
        font1.setBold(false);
        SrcName->setFont(font1);
        SrcName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(SrcName);

        Type = new QLabel(FolderItem);
        Type->setObjectName("Type");
        Type->setMinimumSize(QSize(50, 20));
        Type->setMaximumSize(QSize(50, 20));
        Type->setFont(font1);
        Type->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(Type);

        Size = new QLabel(FolderItem);
        Size->setObjectName("Size");
        Size->setMinimumSize(QSize(100, 20));
        Size->setMaximumSize(QSize(100, 20));
        Size->setFont(font1);
        Size->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(Size);

        Time = new QLabel(FolderItem);
        Time->setObjectName("Time");
        Time->setMinimumSize(QSize(110, 20));
        Time->setMaximumSize(QSize(110, 20));
        Time->setFont(font1);
        Time->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(Time);


        retranslateUi(FolderItem);

        QMetaObject::connectSlotsByName(FolderItem);
    } // setupUi

    void retranslateUi(QWidget *FolderItem)
    {
        FolderItem->setWindowTitle(QCoreApplication::translate("FolderItem", "Form", nullptr));
        Name->setText(QCoreApplication::translate("FolderItem", "1.cpp", nullptr));
        SrcName->setText(QCoreApplication::translate("FolderItem", "1.cpp", nullptr));
        Type->setText(QCoreApplication::translate("FolderItem", "C++", nullptr));
        Size->setText(QCoreApplication::translate("FolderItem", "55 kb", nullptr));
        Time->setText(QCoreApplication::translate("FolderItem", "yy mm dd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FolderItem: public Ui_FolderItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOLDERITEM_H
