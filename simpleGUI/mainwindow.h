#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simulator.h"
#include <QString>
#include "eventhandler.h"
#include "paramwindow.h"

class EventHandler;
class ParamWindow;

namespace Ui {
    class MainWindow;
    enum TYPE { str = 1, cmb };
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:

public slots:
    void simulator_changed();
    void btn_edit_params_clicked();
    void btn_edit_clicked();
    void menu_help_clicked();

public:
    explicit MainWindow(QWidget *parent = 0);
    void setfpath( QString );
    QString getfpath() const;
    void setfname( QString );
    QString getfname() const;
    void diplayfile( const QString ) const;
    Simulator* getsimulator() const;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    EventHandler *ev;
    QString fpath;
    QString fname;
    Simulator *simulator;
    ParamWindow *pwindow;
};

#endif // MAINWINDOW_H
