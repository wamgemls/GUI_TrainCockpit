#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Q_INIT_RESOURCE(qmlsources);

    //QNetworkProxyFactory::setUseSystemConfiguration(true);

    MainWindow mainwidget;
    mainwidget.show();
    return a.exec();
}//Olli hat gar keine eier und ein stinkt hart
