#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getDataButton = new QPushButton("GetData", this);
    getDataButton->setGeometry(100, 100, 100, 50);

    startWorkerButton = new QPushButton("Start Worker Thread", this);
    startWorkerButton->setGeometry(400, 100, 200, 50);

    stopWorkerButton = new QPushButton("Stop Worker Thread", this);
    stopWorkerButton->setGeometry(400, 200, 200, 50);

    quitButton = new QPushButton("Quit", this);
    quitButton->setGeometry(400, 400, 200, 50);

    xDataLabel = new QLabel(this);
    xDataLabel->setGeometry(100, 200, 100, 50);

    yDataLabel = new QLabel(this);
    yDataLabel->setGeometry(100, 250, 100, 50);

    ThrottleSlider = new QSlider(this);
    ThrottleSlider->setGeometry(300,400,100,50);


    // dem Worker-Objekt den Zeiger auf das gemeinsame Shared_Data_Container-Objekt geben:
    worker.sdc_ptr = &theSharedDataContainer;

    // eigenes Worker-Objekt in gesonderten Thread verschieben:
    worker.moveToThread(&thread_for_worker);
    // Thread starten:
    thread_for_worker.start();
    // ggf. dem Thread eine geeigente relative Priorität geben (geht erst, wenn er gestartet wurde):
    thread_for_worker.setPriority(QThread::LowPriority);



    // Wenn Quit-Button geklickt, zuerst den zusätzlichen Thread beenden:
    connect(quitButton, SIGNAL(clicked()), &thread_for_worker, SLOT(quit()));

    // Wenn zusätzlicher Thread beendet wurde, dann die gesamte App beenden:
    connect(&thread_for_worker, SIGNAL(finished()), qApp, SLOT(quit()));

    // Starten des Workers (zugehöriger Thread läuft bereits)
    connect(startWorkerButton, SIGNAL(clicked()), &worker, SLOT(startWorking()));
    // Stoppen des Workers (Thread läuft aber weiter)
    connect(stopWorkerButton, SIGNAL(clicked()), &worker, SLOT(stopWorking()));

    connect(getDataButton, SIGNAL(clicked()), this, SLOT(getDataFromSharedDataObject()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getDataFromSharedDataObject()
{
    // Lese Daten aus gemeinsamen Shared_Data_Container
    Data d = theSharedDataContainer.readData();
    //qDebug() << "Gelesen: x = " << d.x << " , y = " << d.y;
    xDataLabel->setNum(d.x);
    yDataLabel->setNum(d.y);
}
