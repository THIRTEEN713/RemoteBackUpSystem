/********************************************************************************
** Form generated from reading UI file 'RemoteFolder.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTEFOLDER_H
#define UI_REMOTEFOLDER_H

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

class Ui_RemoteFolder
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *FolderTip;
    QHBoxLayout *ToolLayout;
    QPushButton *Backup;
    QPushButton *Updata;
    QSpacerItem *ToolSpacer;
    QHBoxLayout *InforLayout;
    QLabel *AddrTip;
    QLabel *Address;
    QLabel *CurPath;
    QLabel *Path;
    QPushButton *PrevPath;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QListWidget *List;

    void setupUi(QWidget *RemoteFolder)
    {
        if (RemoteFolder->objectName().isEmpty())
            RemoteFolder->setObjectName("RemoteFolder");
        RemoteFolder->resize(600, 600);
        RemoteFolder->setMinimumSize(QSize(600, 600));
        RemoteFolder->setMaximumSize(QSize(600, 600));
        verticalLayout = new QVBoxLayout(RemoteFolder);
        verticalLayout->setObjectName("verticalLayout");
        FolderTip = new QLabel(RemoteFolder);
        FolderTip->setObjectName("FolderTip");
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        FolderTip->setFont(font);

        verticalLayout->addWidget(FolderTip);

        ToolLayout = new QHBoxLayout();
        ToolLayout->setObjectName("ToolLayout");
        Backup = new QPushButton(RemoteFolder);
        Backup->setObjectName("Backup");

        ToolLayout->addWidget(Backup);

        Updata = new QPushButton(RemoteFolder);
        Updata->setObjectName("Updata");

        ToolLayout->addWidget(Updata);

        ToolSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        ToolLayout->addItem(ToolSpacer);


        verticalLayout->addLayout(ToolLayout);

        InforLayout = new QHBoxLayout();
        InforLayout->setObjectName("InforLayout");
        AddrTip = new QLabel(RemoteFolder);
        AddrTip->setObjectName("AddrTip");
        QFont font1;
        font1.setBold(true);
        AddrTip->setFont(font1);

        InforLayout->addWidget(AddrTip);

        Address = new QLabel(RemoteFolder);
        Address->setObjectName("Address");

        InforLayout->addWidget(Address);

        CurPath = new QLabel(RemoteFolder);
        CurPath->setObjectName("CurPath");
        CurPath->setFont(font1);

        InforLayout->addWidget(CurPath);

        Path = new QLabel(RemoteFolder);
        Path->setObjectName("Path");

        InforLayout->addWidget(Path);

        PrevPath = new QPushButton(RemoteFolder);
        PrevPath->setObjectName("PrevPath");

        InforLayout->addWidget(PrevPath);


        verticalLayout->addLayout(InforLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 20, 10, -1);
        label = new QLabel(RemoteFolder);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(RemoteFolder);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(RemoteFolder);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(50, 16777215));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(RemoteFolder);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(100, 0));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(RemoteFolder);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(110, 0));
        label_5->setMaximumSize(QSize(110, 16777215));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout);

        List = new QListWidget(RemoteFolder);
        List->setObjectName("List");
        List->setFont(font1);

        verticalLayout->addWidget(List);


        retranslateUi(RemoteFolder);

        QMetaObject::connectSlotsByName(RemoteFolder);
    } // setupUi

    void retranslateUi(QWidget *RemoteFolder)
    {
        RemoteFolder->setWindowTitle(QCoreApplication::translate("RemoteFolder", "Form", nullptr));
        FolderTip->setText(QCoreApplication::translate("RemoteFolder", "\345\244\207\344\273\275\345\272\223-1", nullptr));
        Backup->setText(QCoreApplication::translate("RemoteFolder", "\345\244\207\344\273\275", nullptr));
        Updata->setText(QCoreApplication::translate("RemoteFolder", "\345\210\267\346\226\260", nullptr));
        AddrTip->setText(QCoreApplication::translate("RemoteFolder", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        Address->setText(QCoreApplication::translate("RemoteFolder", "TextLabel", nullptr));
        CurPath->setText(QCoreApplication::translate("RemoteFolder", "\345\275\223\345\211\215\350\267\257\345\276\204\357\274\232", nullptr));
        Path->setText(QCoreApplication::translate("RemoteFolder", "TextLabel", nullptr));
        PrevPath->setText(QCoreApplication::translate("RemoteFolder", "\344\270\212\347\272\247\347\233\256\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("RemoteFolder", "\346\226\207\344\273\266\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("RemoteFolder", "\345\216\237\346\226\207\344\273\266\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("RemoteFolder", "\347\261\273\345\236\213", nullptr));
        label_4->setText(QCoreApplication::translate("RemoteFolder", "\345\244\247\345\260\217", nullptr));
        label_5->setText(QCoreApplication::translate("RemoteFolder", "\345\244\207\344\273\275\346\227\245\346\234\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoteFolder: public Ui_RemoteFolder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTEFOLDER_H
