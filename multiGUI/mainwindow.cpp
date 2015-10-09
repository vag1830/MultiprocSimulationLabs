#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

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


    programs.push_back( new Program( "../multiGUI/apps/QS/execs/quicksort.out",
                                     "QS",
                                     "../multiGUI/configurations/programs/QS_parameters" ) );
    programs.push_back( new Program( "../multiGUI/apps/SOR/execs/sor.out",
                                     "SOR",
                                     "../multiGUI/configurations/programs/SOR_parameters" ) );
    programs.push_back( new Program( "../multiGUI/apps/jacobi/execs/jacobi_rc.out",
                                     "jacobi",
                                     "../multiGUI/configurations/programs/jacobi_parameters" ) );
    //programs.last()->hasConfiguration( false );
    //qDebug() << programs.last()->hasConfiguration();
    programs.push_back( new Program( "../multiGUI/apps/mularray/execs/mularray_rc.out",
                                     "mularray",
                                     "../multiGUI/configurations/programs/mularray_parameters" ) );
    //programs.last()->hasConfiguration( false );
//    programs.push_back( new Program( "../multiGUI/executables/mularray_rc.out",
//                                     "mularray double",
//                                     "../multiGUI/configurations/programs/mularray_double_parameters" ) );
//    programs.last()->hasConfiguration( false );
    environments.push_back( new Environment ( "../multiGUI/configurations/environments/env_parameters",
                                              "RSIM default") );

    ui->cmbEnvironment->addItem( environments[0]->getName() );

    for ( int i = 0; i < programs.size(); i++ )
    {
        ui->cmbPrograms->addItem( programs[i]->getName() );
    }

    if ( this->getProgramByName( ui->cmbPrograms->currentText() )->hasConfiguration() )
        ui->btnProgParameters->setEnabled( true );
    else
        ui->btnProgParameters->setEnabled( false );

    ui->btnEnvParams->setEnabled( false );

    connect( ui->cmbPrograms, SIGNAL( currentIndexChanged( QString ) ), this, SLOT( programChanged() ) );
    connect( ui->btnProgParameters, SIGNAL( clicked() ), this, SLOT( configureProgramClicked() ) );
    connect( ui->cmbEnvironment, SIGNAL( currentIndexChanged(QString) ), this, SLOT( environmentChanged() ) );
    connect( ui->btnCreateEnvironment, SIGNAL( clicked() ), this, SLOT( createEnvironmentClicked() ) );
    connect( ui->btnExit, SIGNAL( clicked() ), this, SLOT( exitClicked() ) );
    connect( ui->btnEnvParams, SIGNAL( clicked() ), this, SLOT( configureEnvironmentClicked() ) );
    connect( ui->btnSimParams, SIGNAL( clicked() ), this, SLOT( configureSimulationClicked() ) );
    connect( ui->btnRun, SIGNAL( clicked() ), this, SLOT( runClicked() ) );

    simulation = new Simulation( ui->txtSimulationName->text().simplified(),
                                 "../multiGUI/configurations/simulations/sim_parameters",
                                 this->getEnvironmentByName( ui->cmbEnvironment->currentText() ),
                                 this->getProgramByName( ui->cmbPrograms->currentText() ), this );
}


Program* MainWindow::getProgramByName( const QString gName ) {
    for ( int i = 0; i < programs.size(); i ++ )
        if ( programs[i]->getName() == gName )
            return programs[i];
}
Environment* MainWindow::getEnvironmentByName( const QString gName ) {
    for ( int i = 0; i < environments.size(); i ++ )
        if ( environments[i]->getName() == gName )
            return environments[i];
}
bool MainWindow::hasProgramWithName ( const QString gName ) const {
    for ( int i = 0; i < programs.size(); i++ )
        if ( programs[i]->getName() == gName )
            return true;
    return false;
}
bool MainWindow::hasEnvironmentWithName ( const QString gName ) const {
    for ( int i = 0; i < environments.size(); i++ )
        if ( environments[i]->getName() ==  gName  )
            return true;
    return false;
}

/* -------------------------- SLOTS ----------------------*/
void MainWindow::programChanged() {
    if ( this->getProgramByName( ui->cmbPrograms->currentText() )->hasConfiguration() )
    {
        ui->btnProgParameters->setEnabled( true );
    }
    else
    {
        ui->btnProgParameters->setEnabled( false );
    }

    simulation->setProgram( this->getProgramByName( ui->cmbPrograms->currentText() ) );
}
void MainWindow::configureProgramClicked() {
    pwindow = new ParamWindow( this->getProgramByName( ui->cmbPrograms->currentText() ), this, this );
    pwindow->show();
}
void MainWindow::environmentChanged() {
    if ( ui->cmbEnvironment->currentText() == "RSIM default" )
        ui->btnEnvParams->setEnabled( false );
    else
        ui->btnEnvParams->setEnabled( true );

    simulation->setEnvironment( this->getEnvironmentByName( ui->cmbEnvironment->currentText() ) );
}
void MainWindow::createEnvironmentClicked() {
    bool isValid = true;

    if ( ui->txtEnvName->text() == "" )
    {
        ui->txtConsole->append( "Please provide a valid name for the new Environment!" );
        isValid = false;
    }
    if ( this->hasEnvironmentWithName( ui->txtEnvName->text().simplified() ) )
    {
        ui->txtConsole->append( "Environment already exists!" );
        isValid = false;
    }

    if ( isValid )
    {
        environments.push_back(new Environment ( "../multiGUI/configurations/environments/env_parameters",
                                                 ui->txtEnvName->text().simplified() ) );
        ui->cmbEnvironment->addItem( ui->txtEnvName->text().simplified() );
        ui->txtEnvName->setText( "" );
        ui->txtConsole->append("New Environment added successfully");
    }
}
void MainWindow::configureEnvironmentClicked() {
    pwindow = new ParamWindow( this->getEnvironmentByName( ui->cmbEnvironment->currentText() ), this, this );
    pwindow->show();
}
void MainWindow::configureSimulationClicked() {
    bool isValid = true;

    if ( ui->txtSimulationName->text() == "" )
    {
        ui->txtConsole->append( "Please provide a valid name for the new Simulation!" );
        isValid = false;
    }
    else {
        simulation->setName( ui->txtSimulationName->text().simplified() );
    }

    if ( isValid )
    {
        pwindow = new ParamWindow( simulation, this, this );
        pwindow->show();
    }
}

void MainWindow::runClicked() {
    bool isValid = true;

    if ( ui->txtSimulationName->text() == "" )
    {
        ui->txtConsole->append( "Please provide a valid name for the new Simulation!" );
        isValid = false;
    }
    else {
        simulation->setName( ui->txtSimulationName->text().simplified() );
    }
//    if ( this->hasEnvironmentWithName( ui->txtEnvName->text().simplified() ) )
//    {
//        ui->txtConsole->append( "Environment already exists!" );
//        isValid = false;
//    }

    if ( isValid )
    {

        simulation->init();

        simulation->start();

        simulation->finalize();

    }
}

void MainWindow::exitClicked() {
    // clean simulation folder
    QString delDir = "rm -rf ../multiGUI/simulations";
    QString mkDir = "mkdir ../multiGUI/simulations";
    system ( delDir.toStdString().c_str() );
    system ( mkDir.toStdString().c_str() );
    this->close();
}

Ui::MainWindow* MainWindow::getUi() {
    return ui;
}

MainWindow::~MainWindow()
{
    delete ui;
}
