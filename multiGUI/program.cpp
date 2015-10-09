#include "program.h"
#include <QComboBox>
#include <QLineEdit>
#include <QDebug>
#include <QStringList>

Program::Program( QString gExecPath, QString gName, QString gConfigPath, QObject *parent ) :
    QObject( parent )
{
    executable = gExecPath;
    name = gName;
    configurationPath = gConfigPath;
    defaultConf = true;

    QStringList list;

    if ( configurationPath != "null" )
    {
        hasConf = true;

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
    }
    else
    {
        hasConf = false;
    }
}

// ------------------ SLOTS ------------------------ //
void Program::cmb_param_changed( QString value ) {
    QObject *cmb = QObject::sender();
    for ( int i = 0; i < configuration_ui.size(); i++ )
        if ( cmb == configuration_ui[i] )
        {
            configuration->getParametersList()[i]->setValue( value );
            qDebug("%s %s",configuration->getParametersList()[i]->getName().toAscii().data(),
                   configuration->getParametersList()[i]->getValue().toAscii().data() );
        }
    defaultConf = false;
}
void Program::txt_param_changed( QString value ) {
    QObject *txt = QObject::sender();
    for ( int i = 0; i < configuration_ui.size(); i++ )
        if ( txt == configuration_ui[i] )
        {
            configuration->getParametersList()[i]->setValue( value );
            qDebug("%s %s",configuration->getParametersList()[i]->getName().toAscii().data(),
                   configuration->getParametersList()[i]->getValue().toAscii().data() );
        }
    defaultConf = false;
}

Configuration* Program::getConfiguration() const {
    return configuration;
}
QVector<QWidget*> Program::getConfig_ui() {
    return configuration_ui;
}

QVector<Parameter*> Program::getParameterList() const {
    return configuration->getParametersList();
}
Parameter* Program::getParameter( const int index ) {
    return configuration->getParametersList()[index];
}


QString Program::getName() const {
    return name;
}
QString Program::getExecutable() const {
    return executable;
}
QString Program::getConfigurationPath() const {
    return configurationPath;
}
bool Program::hasConfiguration() const {
    return hasConf;
}
void Program::hasConfiguration( bool hc ) {
    hasConf = hc;
}
bool Program::configurationChanged() const {
    return !defaultConf;
}
void Program::configurationChanged( bool df ) {
    defaultConf = df;
}


void Program::setName( const QString gName ) {
    name = gName;
}
void Program::setExecutable( const QString gExecPath ) {
    executable = gExecPath;
}

void Program::setParameterValue( const QString gName, const QString gValue ) {

}
void Program::setParameterValue( const int index, const QString gValue ) {

}
QString Program::getParameterValue( const int index ) const {

}
QString Program::getParameterValue( const QString gName ) const {

}

bool Program::hasParameterWithName( const QString gName ) {
    return configuration->hasParameterWithName( gName );
}
QString Program::getParameterType( const QString gName ) {
    return configuration->getParameterType( gName );
}

//void Program::setParameterValue( const QString gName, const int gValue ) {
//    configuration->getParameterByName( gName )->setValue( gValue );
//}
//void Program::setParameterValue( const QString gName, const bool gValue ) {
//    configuration->getParameterByName( gName )->setValue( gValue );
//}
//void Program::setParameterValue( const QString gName, const QString gValue ) {
//    configuration->getParameterByName( gName )->setValue( gValue );
//}
//int Program::getParameterIntValue( const QString gName ) const {
//    return configuration->getParameterByName( gName )->getIntValue();
//}
//bool Program::getParameterBoolValue( const QString gName ) const {
//    return configuration->getParameterByName( gName )->getBoolValue();
//}
//QString Program::getParameterStringValue( const QString gName ) const {
//    return configuration->getParameterByName( gName )->getStringValue();
//}

Program::~Program() {}
