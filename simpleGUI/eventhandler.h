#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QWidget>
#include <QFileDialog>
#include "mainwindow.h"
#include "paramwindow.h"

class MainWindow;
class ParamWindow;

class EventHandler : public QWidget
{
    Q_OBJECT
public:
    explicit EventHandler( QWidget *parent = 0 );
    explicit EventHandler( MainWindow *, QWidget *parent = 0 );
signals:

public slots:
    void menu_open_clicked();
    void menu_exit_clicked();
    void btn_run_clicked();



private:
    MainWindow *window;
    ParamWindow *pwindow;

};

#endif // EVENTHANDLER_H
