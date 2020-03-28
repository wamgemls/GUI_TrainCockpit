#ifndef SHARED_DATA_CONTAINER_H
#define SHARED_DATA_CONTAINER_H

#include <QObject>
#include <QReadWriteLock>
#include "data.h"

class Shared_Data_Container : public QObject
{
    Q_OBJECT
public:
    explicit Shared_Data_Container(QObject *parent = nullptr);

    Data readData(void);
    void writeData(Data);

private:
    // Lock-Objekt, das Status der Zugriffe speichert:
    QReadWriteLock lock;
    // Das gemeinsame Datenobjekt, auf das MainWindow und Worker zugreifen wollen
    Data theData;
    // privat, damit Zugriff nur durch read- und write-Methode möglich
    // diese Methoden sorgen auch dafür das:
    // - der Lesezugriff (read) eines Threads nicht durch Schreiben eines anderen Threads bzw.
    // - der Schreibzugriff (write) eines Threads nicht durch Lesen eines anderen Threads unterbrochen wird
};

#endif // SHARED_DATA_CONTAINER_H
