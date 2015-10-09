#include <QtDebug>


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reader.h"
#include "helpwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QImage EU(":/logos/eu.jpg");
    QImage digiGR(":/logos/digiGr.jpg");
    QImage ESPA(":/logos/espa.jpg");

    ui->lblLogoEU->setPixmap(QPixmap::fromImage(EU));
    ui->lblLogoDigiGr->setPixmap(QPixmap::fromImage(digiGR));
    ui->lblLogoEspa->setPixmap(QPixmap::fromImage(ESPA));

    ui->lblLogoEU->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->lblLogoEU->setOpenExternalLinks(true);
    ui->lblLogoEU->setText("<a href=\"http://europa.eu/index_el.htm\"><img src=\":/logos/eu.jpg\"/></a>");

    ui->lblLogoDigiGr->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->lblLogoDigiGr->setOpenExternalLinks(true);
    ui->lblLogoDigiGr->setText("<a href=\"http://www.digitalplan.gov.gr/portal\"><img src=\":/logos/digiGr.jpg\"/></a>");

    ui->lblLogoEspa->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->lblLogoEspa->setOpenExternalLinks(true);
    ui->lblLogoEspa->setText("<a href=\"http://www.espa.gr/el/Pages/Default.aspx\"><img src=\":/logos/espa.jpg\"/></a>");

    ui->cmb_simulators->addItem("sim-safe");
    ui->cmb_simulators->addItem("sim-fast");
    ui->cmb_simulators->addItem("sim-profile");
    ui->cmb_simulators->addItem("sim-cache");
    ui->cmb_simulators->addItem("sim-bpred");
    ui->cmb_simulators->addItem("sim-cheetah");
    ui->cmb_simulators->addItem("sim-outorder");

    ev = new EventHandler( this, parent );
    simulator = new Simulator ( ui->cmb_simulators->currentText() );
    pwindow = new ParamWindow( simulator, this, this );
    pwindow->move( this->x() + this->width(), this->y() );
    ui->btn_run->setEnabled( false );
    ui->btn_edit_params->setEnabled( false );

    QString hpath = "../simpleGUI/help/" + simulator->getname() + ".hlp";
    Reader reader( hpath );

    ui->txt_simulator->clear();
    for ( int i = 0; i < reader.getOutput().size(); i++ )
        ui->txt_simulator->append( reader.getOutput()[i] );

    connect( ui->action_open_c_file, SIGNAL( triggered() ), ev,
             SLOT( menu_open_clicked() ) );
    connect( ui->action_exit, SIGNAL( triggered() ), ev,
             SLOT( menu_exit_clicked() ) );
    connect( ui->btn_run, SIGNAL( clicked() ), ev,
             SLOT( btn_run_clicked() ) );
    connect( ui->btn_edit, SIGNAL( clicked() ), this,
             SLOT( btn_edit_clicked() ) );
    connect( ui->btn_edit_params, SIGNAL( clicked() ), this,
             SLOT( btn_edit_params_clicked() ) );
    connect( ui->cmb_simulators, SIGNAL( currentIndexChanged( QString ) ), this,
             SLOT( simulator_changed() ));
    connect( ui->action_help, SIGNAL( triggered() ), this,
             SLOT( menu_help_clicked() ) );
}

QString MainWindow::getfpath() const
{
    return fpath;
}
void MainWindow::setfpath( QString path )
{
    fpath = path;
}
QString MainWindow::getfname() const
{
    return fname;
}
void MainWindow::setfname( QString name )
{
    fname = name;
}
Simulator* MainWindow::getsimulator() const
{
    return simulator;
}

void MainWindow::btn_edit_clicked()
{
    QString kwrite = "kwrite " + fpath + fname;
    system( kwrite.toStdString().c_str() );
}
void MainWindow::diplayfile( const QString path ) const
{
    Reader rdr( path );
    ui->lbl_c_file->setText( fname );
    ui->txt_c_file->clear();
    for (int i = 0; i < rdr.getOutput().size(); i++ )
        ui->txt_c_file->append( rdr.getOutput()[i] );

    ui->btn_run->setEnabled( true );
    ui->btn_edit_params->setEnabled( true );
}
void MainWindow::simulator_changed()
{
    delete simulator;
    simulator = new Simulator( ui->cmb_simulators->currentText() );
    if ( pwindow->isVisible() )
    {
        delete pwindow;
        pwindow = new ParamWindow( simulator,  this, this );
        pwindow->move( this->x() + this->width(), this->y() );
        pwindow->show();
    }
    else
    {
        delete pwindow;
        pwindow = new ParamWindow( simulator,  this, this );
        pwindow->move( this->x() + this->width(), this->y() );
    }

    QString hpath = "../simpleGUI/help/" + simulator->getname() + ".hlp";
    Reader reader( hpath );

    ui->txt_simulator->clear();
    for ( int i = 0; i < reader.getOutput().size(); i++ )
        ui->txt_simulator->append( reader.getOutput()[i] );
}
void MainWindow::btn_edit_params_clicked()
{
    pwindow->show();
}
void MainWindow::menu_help_clicked()
{
    HelpWindow *hlp = new HelpWindow( this );
    hlp->setWindowTitle( "Help" );
    hlp->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}

