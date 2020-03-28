#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "shared_data_container.h"

class Worker : public QObject
{
    Q_OBJECT
private:
    int timerid;
    int seconds;

public:
    explicit Worker(QObject *parent = nullptr);
    // Der Worker braucht einen Zeiger auf das gemeinsame Shared_Data_Objekt
    // der Zeiger wird vom Mainwindow auf das dort erzeugte Shared_Data_Objekt übergeben
    Shared_Data_Container *sdc_ptr = nullptr;

public slots:
    void stopWorking();
    void startWorking();

protected:
    void timerEvent(QTimerEvent *event) override;
signals:

};

#endif // WORKER_H
