#ifndef TRAINGUI_H
#define TRAINGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TrainGUI; }
QT_END_NAMESPACE

class TrainGUI : public QMainWindow
{
    Q_OBJECT

public:
    TrainGUI(QWidget *parent = nullptr);
    ~TrainGUI();

private:
    Ui::TrainGUI *ui;
};
#endif // TRAINGUI_H
