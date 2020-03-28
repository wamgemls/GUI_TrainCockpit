#include "traingui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrainGUI w;
    w.show();
    return a.exec();
}
