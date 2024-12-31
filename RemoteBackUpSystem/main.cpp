#include "LibraryList.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LibraryList w;
    w.show();
    return a.exec();
}
