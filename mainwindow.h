#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "worker.h"
#include <QThread>
#include "shared_data_container.h"
#include <QSlider>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    void addPoint(double x, double y);
    void cleardata();
    void plot();

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *getDataButton;
    QPushButton *startWorkerButton;
    QPushButton *stopWorkerButton;
    QPushButton *quitButton;
    QLabel *xDataLabel;
    QLabel *yDataLabel;
    QSlider *ThrottleSlider;

    QVector<double> qv_x,qv_y;



    Worker worker; //Objekt der eigenen Klasse
    QThread thread_for_worker; // QThread-Objekt
    Shared_Data_Container theSharedDataContainer;

private slots:
    void getDataFromSharedDataObject();



    void on_pushButton_Add_clicked();
    void on_pushButton_Clear_clicked();
};
#endif // MAINWINDOW_H
