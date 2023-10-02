#include "colordialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    colorDialog w;
    w.show();
    return a.exec();
}
