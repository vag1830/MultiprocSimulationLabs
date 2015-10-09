#include "tools.cpp"
#include "configuration.h"
#include "parameter.cpp"
#include <QtDebug>
#include <QStringList>

Configuration::Configuration(QObject *parent) :
    QObject(parent)
{
}

Configuration::Configuration( const QString gFilename, const QString gName ) {
    filename = gFilename;
    name= gName;

    Reader reader( filename );
    QStringList list;

    int tempSize = reader.getOutput().size();
    for ( int i = 2; i < tempSize; i++ )
    {

        list = reader.getOutput()[i].split( QChar('#') );
        parameters.push_back( new Parameter( list.value(1).trimmed(),
                                                        list.value(2).trimmed(),
                                                        list.value(5).trimmed(),
                                                        list.value(6).trimmed(),
                                                        list.value(3).trimmed(),
                                                        list.value(4).trimmed(),
                                                        list.value(7).trimmed() ) );

    }
    parametersSize = tempSize - 2;

}
Configuration::Configuration( const QString gFilename ) {
    filename = gFilename;
    Reader reader( filename );
}

QVector<Parameter*> Configuration::getParametersList() const {
    return parameters;
}

QString Configuration::getFileName() const {
    return filename;
}
QString Configuration::getName() const {
    return name;
}
short int Configuration::getParametersSize() const {
    return parametersSize;
}
Parameter* Configuration::getParameterByName( const QString gName ) const
{
    for ( int i = 0; i < parametersSize; i++ )
    {
        if ( parameters[i]->getName() == gName ) { return parameters[i]; }
    }

}
Parameter* Configuration::getParameterByType( const QString gType ) const
{
    for ( int i = 0; i < parametersSize; i++ )
    {
        if ( parameters[i]->getType() == gType) { return parameters[i]; }
    }
}
QVector<Parameter*> Configuration::getParameterByGroup() const {

}

bool Configuration::hasParameterWithName( const QString gName ) {
    for ( int i = 0; i < parametersSize; i++ )
    {
        if ( parameters[i]->getName() == gName )
            return true;
    }
    return false;
}

QString Configuration::getParameterType( const QString gName ) {
    for ( int i = 0; i < parametersSize; i++ )
    {
        if ( parameters[i]->getName() == gName )
            return parameters[i]->getType();
    }
}

bool Configuration::isDefault () const {
    bool changed = true;
    for ( int i = 0; i < parameters.size(); i++ )
    {
        if ( !parameters[i]->isDefault() ) {
            //qDebug() << parameters[i]->getName() << " - " << parameters[i]->getValue() << " - " << parameters[i]->getDValue();
            changed = false;
            break;
        }
    }
    return changed;
}
QString Configuration::getParameterType( const int index ) {
    return parameters[index]->getType();
}








