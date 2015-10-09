#include "simulation.h"
#include "wrighter.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include "outputwindow.h"

#include <QtConcurrentRun>

#include <QStringList>

Simulation::Simulation(QObject *parent) :
    QObject(parent)
{
}
Simulation::Simulation( QString gName, QString gConfigPath, Environment* env, Program* pr, MainWindow* win ) {
    name = gName;
    environment = env;
    program = pr;
    window = win;

    QStringList list;
    configurationPath = gConfigPath;

    configuration = new Configuration( configurationPath, name + "_conf" );




    for ( int i = 0; i < configuration->getParametersList().size(); i++ )
    {
        if ( configuration->getParameterType(i) == "bool" )
        {
            configuration_ui.push_back( new QComboBox );
            static_cast<QComboBox*>(configuration_ui.last())->
                    addItem( configuration->getParametersList()[i]->getDValue() );
            if ( configuration->getParametersList()[i]->getDValue() == "true" )
                static_cast<QComboBox*>(configuration_ui.last())->addItem( "false" );
            else
                static_cast<QComboBox*>(configuration_ui.last())->addItem( "true" );

            configuration_ui.last()->setToolTip( configuration->getParametersList()[i]->getDesc() );
            configuration_ui.last()->setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Fixed );
            connect( static_cast<QComboBox*>( configuration_ui.last() ),
                     SIGNAL( currentIndexChanged( QString ) ), this,
                     SLOT( cmb_param_changed( QString ) ) );
        }
        else
            if ( configuration->getParameterType(i) == "list" )
            {

                list = configuration->getParametersList()[i]->getValue().split( QChar(',') );
                configuration_ui.push_back( new QComboBox );
                for ( int j = 0; j < list.size(); j++  )
                    static_cast<QComboBox*>(configuration_ui.last())->
                            addItem( list.value(j).trimmed() );

                configuration_ui.last()->setToolTip( configuration->getParametersList()[i]->getDesc() );
                configuration_ui.last()->setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Fixed );
                connect( static_cast<QComboBox*>( configuration_ui.last() ),
                         SIGNAL( currentIndexChanged( QString ) ), this,
                         SLOT( cmb_param_changed( QString ) ) );
            }
            else
            {
                configuration_ui.push_back( new QLineEdit );
                static_cast<QLineEdit*>(configuration_ui.last())->
                        setText( configuration->getParametersList()[i]->getValue() );
                configuration_ui.last()->setToolTip( configuration->getParametersList()[i]->getDesc() );
                configuration_ui.last()->setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Fixed );
                connect( static_cast<QLineEdit*>( configuration_ui.last() ),
                         SIGNAL( textChanged( QString ) ), this,
                         SLOT( txt_param_changed( QString ) ) );
            }
    }



    QPROC = new QProcess();

    connect( QPROC, SIGNAL( started() ), this, SLOT( simulationStarted() ) );
    connect( QPROC, SIGNAL( finished( int ) ), this, SLOT( simulationFinished() ) );
}


// ------------------ SLOTS ------------------------ //
void Simulation::cmb_param_changed( QString value ) {
    QObject *cmb = QObject::sender();
    for ( int i = 0; i < configuration_ui.size(); i++ )
        if ( cmb == configuration_ui[i] )
        {
            configuration->getParametersList()[i]->setValue( value );
            //qDebug("%s %s",configuration->getParametersList()[i]->getName().toAscii().data(),
                   //configuration->getParametersList()[i]->getValue().toAscii().data() );
        }
}
void Simulation::txt_param_changed( QString value ) {
    QObject *txt = QObject::sender();
    for ( int i = 0; i < configuration_ui.size(); i++ )
        if ( txt == configuration_ui[i] )
        {
            configuration->getParametersList()[i]->setValue( value );
            //qDebug("%s %s",configuration->getParametersList()[i]->getName().toAscii().data(),
                   //configuration->getParametersList()[i]->getValue().toAscii().data() );
        }
}

Configuration* Simulation::getConfiguration() const {
    return configuration;
}
QVector<QWidget*> Simulation::getConfig_ui() {
    return configuration_ui;
}

QVector<Parameter*> Simulation::getParameterList() const {
    return configuration->getParametersList();
}
Parameter* Simulation::getParameter( const int index ) {
    return configuration->getParametersList()[index];
}

QString Simulation::getConfigurationPath() const {
    return configurationPath;
}

QString Simulation::getName() const {
    return name;
}
void Simulation::setName( const QString gName ) {
    name = gName;
}

void Simulation::setParameterValue( const QString gName, const QString gValue ) {

}
void Simulation::setParameterValue( const int index, const QString gValue ) {

}
QString Simulation::getParameterValue( const int index ) const {

}
QString Simulation::getParameterValue( const QString gName ) const {

}


bool Simulation::hasParameterWithName( const QString gName ) {
    return configuration->hasParameterWithName( gName );
}
QString Simulation::getParameterType( const QString gName ) {
    return configuration->getParameterType( gName );
}

Program* Simulation::getProgram() const {
    return program;
}
void Simulation::setProgram( Program* pr ) {
    program = pr;
}

Environment* Simulation::getEnvironment() const {
    return environment;
}
void Simulation::setEnvironment( Environment* env ) {
    environment = env;
}

void Simulation::init() {

    window->getUi()->txtConsole->clear();
    window->getUi()->txtConsole->append("Initializing the Simulation...");
    // initialize the simulation here

    // create simulation output files
    // creating simulation folder
    QString outputDirectory = "../multiGUI/simulations/" + name;        // -D
    QString createSimulationDir = "mkdir " + outputDirectory;
    system ( createSimulationDir.toStdString().c_str() );

    // creating program executable file path
    QString exeFilePath = program->getExecutable().remove(".out");      // -f
    //qDebug() << exeFilePath;

    // create simulation input files
    // creating environment configuration file
    QString envConfFilePath;
    QString createEnvConfFile; // -z

    if ( environment->getConfiguration()->isDefault() )
    {
        envConfFilePath = "/dev/null";
    }
    else
    {
        envConfFilePath = outputDirectory + "/" + environment->getName() + "_conf";
        createEnvConfFile = "touch " + envConfFilePath;
        system ( createEnvConfFile.toStdString().c_str() );

        Wrighter wrighter( envConfFilePath );
        QString confFileLine;

        for ( int i = 0; i < environment->getConfiguration()->getParametersSize(); i++ )
        {
            if ( !environment->getConfiguration()->getParametersList()[i]->isDefault() )
            {
                if (environment->getConfiguration()->getParametersList()[i]->getType() == "list") {
                    confFileLine = environment->getConfiguration()->getParametersList()[i]->getName()
                         + " " +  environment->getConfiguration()->getParametersList()[i]->getDValue();
                }
                else {
                    confFileLine = environment->getConfiguration()->getParametersList()[i]->getName()
                        + " " +  environment->getConfiguration()->getParametersList()[i]->getValue();
                }

                wrighter.addline( confFileLine );
            }

        }
        wrighter.addline( "STOPCONFIG 1" );
        wrighter.tofile();
    }

    // creating the simulation command

    QString executionTitle = name;                     // -S
    QString progInputFilePath = "/dev/null";           // -0 option
    QString envCLOptions = "";                       // extra environment command line options

    for ( int i = 0; i < this->getParameterList().size(); i++ )
    {
        if ( this->getParameterList()[i]->getType() == "bool" )
        {

            if ( this->getParameterList()[i]->getValue() == "true" )
                envCLOptions = envCLOptions + this->getParameterList()[i]->getName()+ " ";
        }
        else
        {
            if ( !this->getParameterList()[i]->isDefault() )
                envCLOptions = envCLOptions + this->getParameterList()[i]->getName() + " " +
                        this->getParameterList()[i]->getValue() + " ";
        }
    }

    QString progCLoptions = "";                        // program options after --

    if ( program->configurationChanged() )
        for ( int i = 0; i < program->getParameterList().size(); i++ )
        {
            qDebug() << ( program->getName() == "mularray" );
            if ( program->getName() == "mularray" || program->getName() == "jacobi" )
            {
                progCLoptions = progCLoptions + program->getParameter(i)->getValue() + " ";
            }
            else
            {
                if ( program->getParameter(i)->getType() == "bool" )
                {
                    if ( program->getParameter(i)->getValue() == "true" )
                        progCLoptions = progCLoptions + program->getParameter(i)->getName()+ " ";
                }
                else
                {
                    if ( !program->getParameter(i)->isDefault() )
                        progCLoptions = progCLoptions + program->getParameter(i)->getName() +
                                program->getParameter(i)->getValue() + " ";
                }
            }
        }


    executionTitle = name; // the output file will have the simulation name as prefix
    //outputDirectory = ;
    //progInputFilePath = ;
    //envConfFilePath = environment->getConfigurationPath();
    //envCLOptions = ;

//    envConfFilePath = "/dev/null";

    simulationCommand = "rsim -f " + exeFilePath +
            " -S " + executionTitle +
            " -D " + outputDirectory +
            " -0 " + progInputFilePath +
            " -z " + envConfFilePath +
            " " + envCLOptions +
            " -- " + progCLoptions;

    qDebug() << simulationCommand;
    //qDebug() << simulationCommand.toStdString().c_str();

    window->getUi()->txtConsole->append("Done.");

}
void Simulation::simulationStarted() {
    window->getUi()->txtConsole->append("Starting the Simulation...");
}
void Simulation::simulationFinished() {
    window->getUi()->txtConsole->append("Done.");
}
void Simulation::start() const {

    //QFuture<int> future = QtConcurrent::run( system( simulationCommand.toStdString().c_str() ) );


    QPROC->execute(simulationCommand);

}

void Simulation::finalize()  {
    window->getUi()->txtConsole->append("Finalizing...");


    // need to copy files from ~/RSIM/rsim-2.2-2/bin to ~/bin
    QString runPstats = "pstats ../multiGUI/simulations/" + name + "/"
            + name + "_err 0 > ../multiGUI/simulations/" + name + "/" + name + "_pstats";
    system ( runPstats.toStdString().c_str() );

    runPstats = "pstats ../multiGUI/simulations/" + name + "/"
            + name + "_err 1 >> ../multiGUI/simulations/" + name + "/" + name + "_pstats";
    system ( runPstats.toStdString().c_str() );

    runPstats = "pstats ../multiGUI/simulations/" + name + "/"
            + name + "_err 2 >> ../multiGUI/simulations/" + name + "/" + name + "_pstats";
    system ( runPstats.toStdString().c_str() );

    QString runStatsMiss = "stats_miss -cache  1 ../multiGUI/simulations/" + name + "/"
            + name + " 0 > ../multiGUI/simulations/" + name + "/" + name + "_stats_miss";
    system ( runStatsMiss.toStdString().c_str() );

    runStatsMiss = "stats_miss -cache  1 ../multiGUI/simulations/" + name + "/"
            + name + " 1 >> ../multiGUI/simulations/" + name + "/" + name + "_stats_miss";
    system ( runStatsMiss.toStdString().c_str() );

    runStatsMiss = "stats_miss -cache  1 ../multiGUI/simulations/" + name + "/"
            + name + " 2 >> ../multiGUI/simulations/" + name + "/" + name + "_stats_miss";
    system ( runStatsMiss.toStdString().c_str() );

    runStatsMiss = "stats_miss -cache  0 ../multiGUI/simulations/" + name + "/"
                + name + " 0 > ../multiGUI/simulations/" + name + "/" + name + "_stats_miss";
    system ( runStatsMiss.toStdString().c_str() );

    runStatsMiss = "stats_miss -cache  0 ../multiGUI/simulations/" + name + "/"
            + name + " 1 >> ../multiGUI/simulations/" + name + "/" + name + "_stats_miss";
    system ( runStatsMiss.toStdString().c_str() );

    runStatsMiss = "stats_miss -cache  0 ../multiGUI/simulations/" + name + "/"
            + name + " 2 >> ../multiGUI/simulations/" + name + "/" + name + "_stats_miss";
    system ( runStatsMiss.toStdString().c_str() );




    OutputWindow* outWin = new OutputWindow( this, window );
    outWin->show();

    //qDebug() << "DONE !";
    // collect simulation stistics
    // create simulation stats files

    window->getUi()->txtConsole->append("Done.");
}

Simulation::~Simulation() {}
