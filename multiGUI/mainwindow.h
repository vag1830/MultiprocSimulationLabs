#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "paramwindow.h"
#include "program.h"
#include "environment.h"
#include "simulation.h"

class ParamWindow;
class Simulation;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);

    Program* getProgramByName( const QString );
    Environment* getEnvironmentByName( const QString );

    bool hasProgramWithName ( const QString ) const;
    bool hasEnvironmentWithName ( const QString ) const;

    Ui::MainWindow* getUi();


    Ui::MainWindow *ui;

    ~MainWindow();

public slots:
    void programChanged();
    void configureProgramClicked();
    void environmentChanged();
    void createEnvironmentClicked();
    void configureEnvironmentClicked();
    void configureSimulationClicked();

    void exitClicked();
    void runClicked();


private:


    QVector<Program*> programs;
    QVector<Environment*> environments;

    Simulation* simulation;
    ParamWindow *pwindow;

};

#endif // MAINWINDOW_H
