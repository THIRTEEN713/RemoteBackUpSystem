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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibListItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *LibraryName;
    QLineEdit *LibraryAddress;
    QLineEdit *LibraryPort;
    QPushButton *ChangePlane;
    QPushButton *ShowLibrary;

    void setupUi(QWidget *LibListItem)
    {
        if (LibListItem->objectName().isEmpty())
            LibListItem->setObjectName("LibListItem");
        LibListItem->resize(517, 52);
        horizontalLayout = new QHBoxLayout(LibListItem);
        horizontalLayout->setObjectName("horizontalLayout");
        LibraryName = new QLineEdit(LibListItem);
        LibraryName->setObjectName("LibraryName");
        LibraryName->setMinimumSize(QSize(0, 28));

        horizontalLayout->addWidget(LibraryName);

        LibraryAddress = new QLineEdit(LibListItem);
        LibraryAddress->setObjectName("LibraryAddress");
        LibraryAddress->setMinimumSize(QSize(100, 28));
        LibraryAddress->setMaximumSize(QSize(100, 16777215));
        LibraryAddress->setStyleSheet(QString::fromUtf8("border-radius:14px;\n"
"border:1px solid #c0c0c0;"));
        LibraryAddress->setAlignment(Qt::AlignmentFlag::AlignCenter);
        LibraryAddress->setReadOnly(true);

        horizontalLayout->addWidget(LibraryAddress);

        LibraryPort = new QLineEdit(LibListItem);
        LibraryPort->setObjectName("LibraryPort");
        LibraryPort->setMinimumSize(QSize(80, 28));
        LibraryPort->setMaximumSize(QSize(80, 16777215));
        LibraryPort->setStyleSheet(QString::fromUtf8("border-radius:14px;\n"
"border:1px solid #c0c0c0;"));
        LibraryPort->setAlignment(Qt::AlignmentFlag::AlignCenter);
        LibraryPort->setReadOnly(true);

        horizontalLayout->addWidget(LibraryPort);

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
        LibraryAddress->setPlaceholderText(QCoreApplication::translate("LibListItem", "\345\244\207\344\273\275\345\272\223\345\234\260\345\235\200", nullptr));
        LibraryPort->setPlaceholderText(QCoreApplication::translate("LibListItem", "\345\244\207\344\273\275\345\272\223\347\253\257\345\217\243", nullptr));
        ChangePlane->setText(QCoreApplication::translate("LibListItem", "\346\233\264\346\224\271\350\256\241\345\210\222", nullptr));
        ShowLibrary->setText(QCoreApplication::translate("LibListItem", "\346\237\245\347\234\213\345\272\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibListItem: public Ui_LibListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBLISTITEM_H
