#include "paramwindow.h"
#include "ui_paramwindow.h"

#include "wrighter.h"

#include <QPushButton>
#include <QComboBox>
#include <QToolButton>
#include <QToolTip>
#include <QLabel>
#include <QLineEdit>
#include <QTabWidget>
#include <QDebug>


ParamWindow::ParamWindow( Program* prog, MainWindow* win, QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ParamWindow)
{
    ui->setupUi(this);

    connect( ui->btnClose, SIGNAL( clicked() ), this, SLOT( btn_close_clicked() ) );
    //connect( ui->btnSave, SIGNAL( clicked() ), this, SLOT( btn_save_clicked() ) );
    connect( ui->btnDefaults, SIGNAL( clicked() ), this, SLOT( btn_defaults_clicked() ) );

    window = win;
    window->setEnabled( false );
    this->setEnabled( true );
    program = prog;
    //ui->btnSave->setEnabled( false );
    calledFor = "program";

    this->setWindowTitle( program->getName() );
    ui->gridLayout_2->addWidget( new QLabel( "desc" ),
                                  0, 0, 1, 1, Qt::AlignTop );
//    ui->gridLayout_2->addWidget( new QLabel( "option" ),
//                              0, 0, 1, 1, Qt::AlignTop );
//    ui->gridLayout_2->addWidget( new QLabel( "type" ),
//                              0, 1, 1, 1, Qt::AlignTop );
    ui->gridLayout_2->addWidget( new QLabel( "value" ),
                              0, 1, 1, 1, Qt::AlignTop );
//    ui->gridLayout_2->addWidget( new QLabel( "default value" ),
//                              0, 3, 1, 1, Qt::AlignTop );
//    ui->gridLayout_2->addWidget( new QLabel( "desrcription" ),
//                              0, 4, 1, 1, Qt::AlignTop );

    int i;
    //QToolButton* tool;
    for( i = 0; i < program->getParameterList().size(); i++ )
    {
        ui->gridLayout_2->addWidget( new QLabel( program->getParameterList()[i]->getSmallDesc() ),
                                   i + 1, 0, 1, 1, Qt::AlignRight );
//        ui->gridLayout_2->addWidget( new QLabel( program->getParameterList()[i]->getName() ),
//                                   i + 1, 0, 1, 1, Qt::AlignTop );
//        ui->gridLayout_2->addWidget( new QLabel( program->getParameterList()[i]->getType() ),
//                                   i + 1, 1, 1, 1, Qt::AlignTop );

        ui->gridLayout_2->addWidget( program->getConfig_ui()[i],
                                   i + 1, 1, 1, 1, Qt::AlignVCenter );
//        ui->gridLayout_2->addWidget( new QLabel( program->getParameterList()[i]->getDValue() ),
//                                   i + 1, 3, 1, 1, Qt::AlignTop );
//        tool = new QToolButton;
//        tool->setToolTip( program->getParameterList()[i]->getDesc() );
//        ui->gridLayout_2->addWidget ( tool ,
//                                   i + 1, 4, 1, 1, Qt::AlignTop );
    }
}


ParamWindow::ParamWindow( Environment* env, MainWindow* win, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParamWindow)
{
    ui->setupUi(this);

    connect( ui->btnClose, SIGNAL( clicked() ), this, SLOT( btn_close_clicked() ) );
    //connect( ui->btnSave, SIGNAL( clicked() ), this, SLOT( btn_save_clicked() ) );
    connect( ui->btnDefaults, SIGNAL( clicked() ), this, SLOT( btn_defaults_clicked() ) );

    window = win;
    window->setEnabled( false );
    this->setEnabled( true );
    //ui->btnSave->setEnabled( false );
    environment = env;
    calledFor = "environment";

    vector<QString> groupList;

    this->setWindowTitle( environment->getName() );

//    for( int  i = 0; i < environment->getParameterList().size(); i++ )
//    {
//        bool exists = false;
//        for ( int j = 0; j < groupList.size(); j++ )
//            if ( environment->getParameterList()[i]->getGroup() == groupList[j] )
//            {
//                exists = true;
//                break;
//            }
//        if ( !exists )
//        {
//            groupList.push_back( environment->getParameterList()[i]->getGroup() );
//            ui->gridLayout->addWidget( new QTabWidget( this ) );


//        }

//    }


    ui->gridLayout_2->addWidget( new QLabel( "desc" ),
                              0, 0, 1, 1, Qt::AlignTop );
//    ui->gridLayout_2->addWidget( new QLabel( "option" ),
//                              0, 0, 1, 1, Qt::AlignTop );
//    ui->gridLayout_2->addWidget( new QLabel( "type" ),
//                              0, 1, 1, 1, Qt::AlignTop );
    ui->gridLayout_2->addWidget( new QLabel( "value" ),
                              0, 1, 1, 1, Qt::AlignTop );
//    ui->gridLayout_2->addWidget( new QLabel( "default value" ),
//                              0, 3, 1, 1, Qt::AlignTop );


    int i;
    //QToolButton* tool;
    for( i = 0; i < environment->getParameterList().size(); i++ )
    {
        ui->gridLayout_2->addWidget( new QLabel( environment->getParameterList()[i]->getSmallDesc() ),
                                   i + 1, 0, 1, 1, Qt::AlignRight );
//        ui->gridLayout_2->addWidget( new QLabel( environment->getParameterList()[i]->getName() ),
//                                   i + 1, 0, 1, 1, Qt::AlignTop );
//        ui->gridLayout_2->addWidget( new QLabel( environment->getParameterList()[i]->getType() ),
//                                   i + 1, 1, 1, 1, Qt::AlignTop );

        ui->gridLayout_2->addWidget( environment->getConfig_ui()[i],
                                   i + 1, 1, 1, 1, Qt::AlignTop );
//        ui->gridLayout_2->addWidget( new QLabel( environment->getParameterList()[i]->getDValue() ),
//                                   i + 1, 3, 1, 1, Qt::AlignTop );
        //tool = new QToolButton;
        //tool->setToolTip( environment->getParameterList()[i]->getDesc() );
        //ui->gridLayout_2->addWidget ( tool ,
        //                           i + 1, 4, 1, 1, Qt::AlignTop );
    }


}
ParamWindow::ParamWindow( Simulation* sim, MainWindow* win, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParamWindow)
{
    ui->setupUi(this);

    connect( ui->btnClose, SIGNAL( clicked() ), this, SLOT( btn_close_clicked() ) );
    //connect( ui->btnSave, SIGNAL( clicked() ), this, SLOT( btn_save_clicked() ) );
    connect( ui->btnDefaults, SIGNAL( clicked() ), this, SLOT( btn_defaults_clicked() ) );

    window = win;
    window->setEnabled( false );
    this->setEnabled( true );
    //ui->btnSave->setEnabled( false );
    simulation = sim;
    calledFor = "simulation";

    this->setWindowTitle( simulation->getName() );
    ui->gridLayout_2->addWidget( new QLabel( "option" ),
                              0, 0, 1, 1, Qt::AlignTop );
    ui->gridLayout_2->addWidget( new QLabel( "type" ),
                              0, 1, 1, 1, Qt::AlignTop );
    ui->gridLayout_2->addWidget( new QLabel( "value" ),
                              0, 2, 1, 1, Qt::AlignTop );
    ui->gridLayout_2->addWidget( new QLabel( "default value" ),
                              0, 3, 1, 1, Qt::AlignTop );
//    ui->gridLayout_2->addWidget( new QLabel( "desrcription" ),
//                              0, 4, 1, 1, Qt::AlignTop );

    int i;
    //QToolButton* tool;
    for( i = 0; i < simulation->getParameterList().size(); i++ )
    {
        ui->gridLayout_2->addWidget( new QLabel( simulation->getParameterList()[i]->getName() ),
                                   i + 1, 0, 1, 1, Qt::AlignTop );
        ui->gridLayout_2->addWidget( new QLabel( simulation->getParameterList()[i]->getType() ),
                                   i + 1, 1, 1, 1, Qt::AlignTop );

        ui->gridLayout_2->addWidget( simulation->getConfig_ui()[i],
                                   i + 1, 2, 1, 1, Qt::AlignTop );
        ui->gridLayout_2->addWidget( new QLabel( simulation->getParameterList()[i]->getDValue() ),
                                   i + 1, 3, 1, 1, Qt::AlignTop );
        //tool = new QToolButton;
        //tool->setToolTip( environment->getParameterList()[i]->getDesc() );
        //ui->gridLayout_2->addWidget ( tool ,
        //                           i + 1, 4, 1, 1, Qt::AlignTop );
    }


}

void ParamWindow::btn_defaults_clicked()
{
    if ( calledFor == "program" )
    {
        int i;
        //qDebug(" %d", simulator->getconfig_ui().size()  );
        for( i = 0; i < program->getConfig_ui().size(); i++ )
        {
            if ( program->getParameter(i)->getType() == "bool" )
            {
                static_cast<QComboBox*>( program->getConfig_ui()[i] )->
                        setCurrentIndex( 0 );
            }
            else
            {
                static_cast<QLineEdit*>( program->getConfig_ui()[i] )->
                        setText( program->getParameter(i)->getDValue() );
            }
        }
        program->configurationChanged( true );
    }
    if ( calledFor == "environment" )
    {
        int i;
        //qDebug(" %d", simulator->getconfig_ui().size()  );
        for( i = 0; i < environment->getConfig_ui().size(); i++ )
        {
            if ( environment->getParameter(i)->getType() == "bool" )
            {
                static_cast<QComboBox*>( environment->getConfig_ui()[i] )->
                        setCurrentIndex( 0 );
            }
            else
                if ( environment->getParameter(i)->getType() == "list" )
                {
                    static_cast<QComboBox*>( environment->getConfig_ui()[i] )->
                            setCurrentIndex( 0 );
                }
                else
                {
                    static_cast<QLineEdit*>( environment->getConfig_ui()[i] )->
                            setText( environment->getParameter(i)->getDValue() );
                }
        }
    }
    if ( calledFor == "simulation" )
    {
        int i;
        //qDebug(" %d", simulator->getconfig_ui().size()  );
        for( i = 0; i < simulation->getConfig_ui().size(); i++ )
        {
            if ( simulation->getParameter(i)->getType() == "bool" )
            {
                static_cast<QComboBox*>( simulation->getConfig_ui()[i] )->
                        setCurrentIndex( 0 );
            }
            else
            {
                static_cast<QLineEdit*>( simulation->getConfig_ui()[i] )->
                        setText( simulation->getParameter(i)->getDValue() );
            }
        }
    }
}
void ParamWindow::btn_save_clicked()
{
    if ( calledFor == "environment" )
    {
//        QString path = "../multiGUI/configurations/environments/" + environment->getName();
//        QString dirPath = "mkdir " + path;
//        QString fileName = environment->getName() + "_conf";
//        system( dirPath.toStdString().c_str() );
//        qDebug() << dirPath;
//        Wrighter write( path + "/" + fileName );

//        for( int i = 0; i < environment->getParameterList().size(); i++ )
//        {
//            if ( environment->getParameterList()[i]->getValue() != environment->getParameterList()[i]->getDValue() )
//                if ( environment->getParameterList()[i]->getType() == "bool"  )
//                    write.addline( environment->getParameterList()[i]->getName() );
//                else
//                    write.addline( environment->getParameterList()[i]->getName() + " " +
//                                   environment->getParameterList()[i]->getValue() );
//        }
//        write.addline( "STOPCONFIG 1" );
//        write.tofile();
    }
}

void ParamWindow::btn_close_clicked()
{
    window->setEnabled( true );
    this->close();
}

void ParamWindow::closeEvent(QCloseEvent *event) {
    window->setEnabled( true );
    this->close();
}

ParamWindow::~ParamWindow()
{
    delete ui;
}
