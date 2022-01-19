#include "scanner.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scanner w;
    w.show();

    return a.exec();
}
