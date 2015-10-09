#include <QtGui/QApplication>
#include "mainwindow.h"
#include "paramwindow.h"
#include "parameter.h"
#include "configuration.h"
#include "program.h"
#include "environment.h"
#include "simulation.h"

#include <QtDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Program pr( "/home/vaggelis/RSIM/apps/QS/execs/quicksort.out", "QS", "../multiGUI/configurations/programs/QS_parameters" );
    //Environment env( "../multiGUI/configurations/environments/env_parameters", "test" );

    //Configuration conf(file, "skata sta moutra sou");

    //conf.getParameterByName("-p")->getType()

    //Program pr("vaggelis", "skata sta moutra sou" , "sdgjb" );
    //bool str = conf.getParameterByName("-B")->getBoolDValue();

    //qDebug() << pr.getName();
    //qDebug() << env.getConfiguration()->getParametersSize();
    //for ( int i = 0; i < pr.getConfiguration()->getParametersSize(); i++ )
    //{
//        QString pName, pType;
//        int iValue;
//        bool bValue;
//        QString sValue;

//        pName = pr.getConfiguration()->getParametersList()[i]->getName();
//        pType = pr.getConfiguration()->getParametersList()[i]->getType();

//        if ( !pType.compare( "int" ) ) {
//            qDebug() << "name = " << pName.toAscii().data() << ", "
//                     << "type = " << pType << ", "
//                     << "value = " << pr.getParameterIntValue( pName ) << ", ";
//        }
//        if ( !pType.compare( "bool" ) ) {
//            qDebug() << "name = " << pName << ", "
//                     << "type = " << pType << ", "
//                     << "value = " << pr.getParameterBoolValue( pName ) << ", ";
//        }
//        if ( !pType.compare( "string" ) ) {
//            qDebug() << "name = " << pName << ", "
//                     << "type = " << pType << ", "
//                     << "value = " << pr.getParameterStringValue( pName ) << ", ";
//        }
    //}

    //Simulation sim( "an_other_simulation", &env, &pr );
    //sim.init();
   // sim.start();


    return a.exec();
}
