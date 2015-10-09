#include "outputwindow.h"
#include "ui_outputwindow.h"
#include <QDebug>

#include "reader.h"

OutputWindow::OutputWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OutputWindow)
{
    ui->setupUi(this);
}


OutputWindow::OutputWindow( Simulation* sim, MainWindow* win, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OutputWindow)
{
    ui->setupUi(this);

    connect( ui->btnClose, SIGNAL( clicked() ), this, SLOT( btn_close_clicked() ) );

    window = win;
    simulation = sim;

    this->setWindowTitle( simulation->getName() );

    ui->tabsContainer->setTabText( 0, simulation->getName() + "_err" );
    ui->tabsContainer->setTabText( 1, simulation->getName() + "_stat" );
    ui->tabsContainer->setTabText( 2, simulation->getName() + "_out" );
    ui->tabsContainer->setTabText( 3, simulation->getName() + "_pstats" );
    ui->tabsContainer->setTabText( 4, simulation->getName() + "_stats_miss" );

    Reader reader_err( "../multiGUI/simulations/" + simulation->getName() + "/" + simulation->getName() + "_err" );
    for ( int i = 0; i < reader_err.getOutput().size(); i++ )
        ui->txtErr->append( reader_err.getOutput()[i] );

    Reader reader_stat( "../multiGUI/simulations/" + simulation->getName() + "/" + simulation->getName() + "_stat" );
    for ( int i = 0; i < reader_stat.getOutput().size(); i++ )
        ui->txtStat->append( reader_stat.getOutput()[i] );

    Reader reader_out( "../multiGUI/simulations/" + simulation->getName() + "/" + simulation->getName() + "_out" );
    for ( int i = 0; i < reader_out.getOutput().size(); i++ )
        ui->txtOut->append( reader_out.getOutput()[i] );

    Reader reader_pstats( "../multiGUI/simulations/" + simulation->getName() + "/" + simulation->getName() + "_pstats" );
    for ( int i = 0; i < reader_pstats.getOutput().size(); i++ )
        ui->txt_pstats->append( reader_pstats.getOutput()[i] );

    Reader reader_stats_miss( "../multiGUI/simulations/" + simulation->getName() + "/" + simulation->getName() + "_stats_miss" );
    for ( int i = 0; i < reader_stats_miss.getOutput().size(); i++ )
        ui->txt_stats_miss->append( reader_stats_miss.getOutput()[i] );

    //qDebug() << simulation->getName();
}






void OutputWindow::btn_close_clicked()
{
    this->close();
}

OutputWindow::~OutputWindow()
{
    delete ui;
}
