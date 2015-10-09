#include "outputwindow.h"
#include "ui_outputwindow.h"
#include "reader.h"

OutputWindow::OutputWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OutputWindow)
{
    ui->setupUi(this);

    connect( ui->btn_close, SIGNAL( clicked() ), this, SLOT( btn_close_clicked() ) );
}

void OutputWindow::init( QString fpath )
{
    Reader prog_reader( fpath + "prog-output");
    Reader sim_reader( fpath + "sim-output");
    QString remove_prog_file = "rm " + fpath + "prog-output";
    QString remove_sim_file = "rm " + fpath + "sim-output";
    QString remove_exec_file = "rm " + fpath + "sim-exec";
    QString remove_current_configuration_file = "rm ../simpleGUI/conf/current.conf";

    ui->txt_prog_output->clear();
    for( int i = 0; i < prog_reader.getOutput().size(); i++ )
        ui->txt_prog_output->append( prog_reader.getOutput()[i] );

    ui->txt_sim_output->clear();
    for( int i = 0; i < sim_reader.getOutput().size(); i++ )
        ui->txt_sim_output->append( sim_reader.getOutput()[i] );

    system( remove_prog_file.toStdString().c_str() );
    system( remove_sim_file.toStdString().c_str() );
    system( remove_exec_file.toStdString().c_str() );
    system( remove_current_configuration_file.toStdString().c_str() );
}

void OutputWindow::btn_close_clicked()
{
    this->close();
}

OutputWindow::~OutputWindow()
{
    delete ui;
}
