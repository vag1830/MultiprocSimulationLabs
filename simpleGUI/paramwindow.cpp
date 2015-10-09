#include "paramwindow.h"
#include "ui_paramwindow.h"

#include "wrighter.h"

#include <QPushButton>
#include <QComboBox>
#include <QToolButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

ParamWindow::ParamWindow( Simulator *sim, MainWindow* win, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParamWindow)
{
    ui->setupUi(this);

    connect( ui->btn_close, SIGNAL( clicked() ), this, SLOT( btn_close_clicked() ) );
    connect( ui->btn_save, SIGNAL( clicked() ), this, SLOT( btn_save_clicked() ) );
    connect( ui->btn_defaults, SIGNAL( clicked() ), this, SLOT( btn_defaults_clicked() ) );

    simulator = sim;
    window = win;

    this->setWindowTitle( sim->getname() );
    ui->gridLayout->addWidget( new QLabel( "description" ),
                              0, 0, 1, 1, Qt::AlignTop );
//    ui->gridLayout->addWidget( new QLabel( "option" ),
//                              0, 0, 1, 1, Qt::AlignTop );
//    ui->gridLayout->addWidget( new QLabel( "type" ),
//                              0, 1, 1, 1, Qt::AlignTop );
    ui->gridLayout->addWidget( new QLabel( "value" ),
                              0, 1, 1, 1, Qt::AlignTop );
//    ui->gridLayout->addWidget( new QLabel( "desrcription" ),
//                              0, 3, 1, 1, Qt::AlignTop );
    int i;
    for( i = 0; i < sim->getconfig().size(); i++ )
    {
        ui->gridLayout->addWidget( new QLabel( sim->getconfig()[i]->getsmalldescr() ),
                                   i + 1, 0, 1, 1, Qt::AlignRight );
//        ui->gridLayout->addWidget( new QLabel( sim->getconfig()[i]->getname() ),
//                                   i + 1, 0, 1, 1, Qt::AlignTop );
//        ui->gridLayout->addWidget( new QLabel( sim->getconfig()[i]->gettype() ),
//                                   i + 1, 1, 1, 1, Qt::AlignTop );
        ui->gridLayout->addWidget( sim->getconfig_ui()[i],
                                   i + 1, 1, 1, 1, Qt::AlignVCenter );
//        ui->gridLayout->addWidget( new QToolButton,
//                                   i + 1, 3, 1, 1, Qt::AlignTop );
//        static_cast<QToolButton*>( ui->gridLayout->itemAtPosition( i + 1, 3 )->widget() )->
//                setToolTip( sim->getconfig()[i]->getdescr() );

    }
}

void ParamWindow::btn_defaults_clicked()
{
    int i;
    //qDebug(" %d", simulator->getconfig_ui().size()  );
    for( i = 0; i < simulator->getconfig_ui().size(); i++ )
    {
        if ( !qstrcmp( simulator->getconfig()[i]->gettype().toStdString().c_str(), "<true|false> " ) )
        {
            static_cast<QComboBox*>(simulator->getconfig_ui()[i])->
                    setCurrentIndex( 0 );
        }
        else
        {
            static_cast<QLineEdit*>(simulator->getconfig_ui()[i])->
                    setText( simulator->getconfig()[i]->getvalue() );
        }
    }
}
void ParamWindow::btn_save_clicked()
{
    Wrighter write( "../simpleGUI/conf/current.conf" );
    write.addline( "-redir:sim "  + window->getfpath() + "sim-output"  );
    write.addline( "-redir:prog " + window->getfpath() + "prog-output" );

    for( int i = 0; i < simulator->getcurconfig().size(); i++ )
    {
        if ( !qstrcmp( simulator->getcurconfig()[i]->gettype().toStdString().c_str(),
                       "<true|false> " ) )
        {
            if ( static_cast<QComboBox*>(simulator->getconfig_ui()[i])->
                 currentIndex() == 1 )
                write.addline( simulator->getcurconfig()[i]->getname() );
        }
        else
            if ( simulator->getcurconfig()[i]->getvalue() !=
                           simulator->getconfig()[i]->getvalue() )
                write.addline( simulator->getcurconfig()[i]->getname()
                               + " " + simulator->getcurconfig()[i]->getvalue() );
    }
    simulator->setdconf( false );
    write.tofile();
}

void ParamWindow::btn_close_clicked()
{
    this->close();
}

ParamWindow::~ParamWindow()
{
    delete ui;
}
