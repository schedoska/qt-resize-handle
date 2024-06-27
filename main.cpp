#include "okno.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OKno okno;
    okno.show();
    return a.exec();
}
