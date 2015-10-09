#ifndef OUTPUTWINDOW_H
#define OUTPUTWINDOW_H

#include <QMainWindow>
#include "simulation.h"

class MainWindow;

namespace Ui {
    class OutputWindow;
}

class OutputWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void btn_close_clicked();

public:
    explicit OutputWindow(QWidget *parent = 0);
    explicit OutputWindow( Simulation*, MainWindow*, QWidget *parent = 0);

    ~OutputWindow();

private:
    Ui::OutputWindow *ui;
    MainWindow* window;
    Simulation* simulation;

};

#endif // OUTPUTWINDOW_H
