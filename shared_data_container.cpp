#include "shared_data_container.h"
#include <QReadLocker>
#include <QWriteLocker>
#include <QDebug>
#include <QThread> //für msleep


Shared_Data_Container::Shared_Data_Container(QObject *parent) : QObject(parent)
{

}

Data Shared_Data_Container::readData()
{
    //Konstruktor von QReadLocker ruft automatisch lockForRead auf lock auf
    QReadLocker locker(&lock);
    qDebug() << "Lesezugriff auf Shared_Data.";
    return theData;
    // Ende der read-Methode -> Destruktor von locker -> unlock auf lock
}
void Shared_Data_Container::writeData(Data d)
{
    QWriteLocker locker(&lock);
    qDebug() << "Schreibzugriff auf Shared_Data. x = " << d.x << ", y = " << d.y;
    theData.x = d.x;
    QThread::msleep(100); // 100 ms Warten um längeren Schreibzugriff zu simulieren
    theData.y = d.y;
}
