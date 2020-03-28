#include "worker.h"
#include <QTimerEvent>
#include <QDebug>
#include "data.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
    seconds = 0;
}

void Worker::startWorking()
{
    qDebug() << "Worker started";
     timerid = startTimer(1000); // 1000 ms
    // alle 1000 ms wird einer TimerEvent erzeugt
}

void Worker::stopWorking()
{
    qDebug() << "Worker stopped";
    killTimer(timerid);
}

// Überschreiben der von QObject geerbten timerEvent-Methode
void Worker::timerEvent(QTimerEvent *event)
{
    seconds++;
    qDebug() << "TimerEvent mit TimerId " << event->timerId() << endl;
    qDebug() << "Seconds: " << seconds << endl;

    Data d;
    d.x = 1 * seconds;
    d.y = 2 * seconds;

    // Schreiben der neuen Daten in das gemeinsame Shared-Data_Objekt
    sdc_ptr->writeData(d);
}
