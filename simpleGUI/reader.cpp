#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QFile>
#include "reader.h"

Reader::Reader(QObject *parent) :
    QObject(parent)
{
}

Reader::Reader( const QString filename )
{
    QFile inFile( filename );
    if ( !inFile.open( QIODevice::ReadOnly | QIODevice::Text ) )
        qDebug( "%s","failed to open file" );
    else
    {
        QTextStream in( &inFile );
        QString line = in.readLine();
        while ( !line.isNull() )
        {
            myVector.push_back( line );
            line = in.readLine();
        }
        //for ( int i = 0; i < myVector.size(); i++ )
            //qDebug( "%s",myVector[i].toAscii().data() );
    }
    inFile.close();
}

QVector<QString> & Reader::getOutput()
{
    return myVector;
}

Reader::~Reader(){}
