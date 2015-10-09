#ifndef PARAMWINDOW_H
#define PARAMWINDOW_H

#include <QMainWindow>
#include "simulator.h"
#include "eventhandler.h"
#include "mainwindow.h"

class EventHandler;
class MainWindow;

namespace Ui {
    class ParamWindow;
}

class ParamWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void btn_defaults_clicked();
    void btn_save_clicked();
    void btn_close_clicked();

public:
    explicit ParamWindow( Simulator *, MainWindow *, QWidget *parent = 0);
    void setui( Simulator* );
    ~ParamWindow();

private:
    Ui::ParamWindow *ui;
    Simulator *simulator;
    MainWindow *window;

};

#endif // PARAMWINDOW_H
