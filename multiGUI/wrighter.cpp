#include <QtDebug>
#include <QFile>
#include "wrighter.h"

Wrighter::Wrighter( QString fname )
{
    filename = fname;
}

void Wrighter::addline( const QString newline )
{
    myVector.push_back( newline );
}

void Wrighter::tofile() const
{
    QFile outFile( filename );
    if ( !outFile.open( QIODevice::ReadWrite | QIODevice::Text ) )
        qDebug( "%s","failed to open file" );
    else
    {
        QTextStream out( &outFile );
        for( int i = 0; i < myVector.size(); i++ )
            out << myVector[i].toStdString().c_str() << endl;
    }
    outFile.close();
}

Wrighter::~Wrighter(){}
