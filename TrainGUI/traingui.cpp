#include "traingui.h"
#include "ui_traingui.h"

TrainGUI::TrainGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TrainGUI)
{
    ui->setupUi(this);
}

TrainGUI::~TrainGUI()
{
    delete ui;
}

