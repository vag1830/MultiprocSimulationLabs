#ifndef PARAMWINDOW_H
#define PARAMWINDOW_H

#include <QMainWindow>
#include "program.h"
#include "environment.h"
#include "simulation.h"
//#include "mainwindow.h"
class Simulation;
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
    explicit ParamWindow( Program*, MainWindow*, QWidget *parent = 0);
    explicit ParamWindow( Environment*, MainWindow*, QWidget *parent = 0);
    explicit ParamWindow( Simulation*, MainWindow*, QWidget *parent = 0);
//    void setui( Program* );
//    void setui( Environment* );
//    void setui( Simulation* );

    ~ParamWindow();

private:
    Ui::ParamWindow *ui;
    Program* program;
    Environment* environment;
    Simulation* simulation;
    MainWindow *window;
    QString calledFor;

protected:
    void closeEvent(QCloseEvent *event);


};

#endif // PARAMWINDOW_H
