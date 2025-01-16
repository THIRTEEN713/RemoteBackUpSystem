/********************************************************************************
** Form generated from reading UI file 'LibListItem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBLISTITEM_H
#define UI_LIBLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibListItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *LibraryName;
    QLabel *LibraryTime;
    QPushButton *ChangePlane;
    QPushButton *ShowLibrary;

    void setupUi(QWidget *LibListItem)
    {
        if (LibListItem->objectName().isEmpty())
            LibListItem->setObjectName("LibListItem");
        LibListItem->resize(601, 52);
        horizontalLayout = new QHBoxLayout(LibListItem);
        horizontalLayout->setObjectName("horizontalLayout");
        LibraryName = new QLineEdit(LibListItem);
        LibraryName->setObjectName("LibraryName");
        LibraryName->setMinimumSize(QSize(0, 28));
        LibraryName->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(LibraryName);

        LibraryTime = new QLabel(LibListItem);
        LibraryTime->setObjectName("LibraryTime");
        LibraryTime->setMinimumSize(QSize(150, 0));
        LibraryTime->setMaximumSize(QSize(150, 16777215));
        QFont font;
        font.setBold(true);
        LibraryTime->setFont(font);
        LibraryTime->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(LibraryTime);

        ChangePlane = new QPushButton(LibListItem);
        ChangePlane->setObjectName("ChangePlane");
        ChangePlane->setMinimumSize(QSize(60, 30));
        ChangePlane->setMaximumSize(QSize(60, 30));

        horizontalLayout->addWidget(ChangePlane);

        ShowLibrary = new QPushButton(LibListItem);
        ShowLibrary->setObjectName("ShowLibrary");
        ShowLibrary->setMinimumSize(QSize(60, 30));
        ShowLibrary->setMaximumSize(QSize(60, 30));

        horizontalLayout->addWidget(ShowLibrary);


        retranslateUi(LibListItem);

        QMetaObject::connectSlotsByName(LibListItem);
    } // setupUi

    void retranslateUi(QWidget *LibListItem)
    {
        LibListItem->setWindowTitle(QCoreApplication::translate("LibListItem", "Form", nullptr));
        LibraryTime->setText(QCoreApplication::translate("LibListItem", "TextLabel", nullptr));
        ChangePlane->setText(QCoreApplication::translate("LibListItem", "\346\233\264\346\224\271\350\256\241\345\210\222", nullptr));
        ShowLibrary->setText(QCoreApplication::translate("LibListItem", "\346\237\245\347\234\213\345\272\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibListItem: public Ui_LibListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBLISTITEM_H
