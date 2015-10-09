#include "environment.h"
#include <QtDebug>
#include <QComboBox>
#include <QLineEdit>
#include <QStringList>

Environment::Environment(QObject *parent) :
    QObject(parent)
{
}

Environment::Environment( QString gConfigPath, QString gName ) {
    name = gName;
    configurationPath = gConfigPath;

    QStringList list;

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

                    configuration->getParametersList()[i]->setValue( configuration->getParametersList()[i]->getDValue() );
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

// ------------------ SLOTS ------------------------ //
void Environment::cmb_param_changed( QString value ) {
    QObject *cmb = QObject::sender();
    for ( int i = 0; i < configuration_ui.size(); i++ )
        if ( cmb == configuration_ui[i] )
        {
            configuration->getParametersList()[i]->setValue( value );
            //qDebug() << configuration->getParametersList()[i]->getValue();
        }
}
void Environment::txt_param_changed( QString value ) {
    QObject *txt = QObject::sender();
    for ( int i = 0; i < configuration_ui.size(); i++ )
        if ( txt == configuration_ui[i] )
        {
            configuration->getParametersList()[i]->setValue( value );
            //qDebug("%s %s",configuration->getParametersList()[i]->getName().toAscii().data(),
                   //configuration->getParametersList()[i]->getValue().toAscii().data() );
        }
}

Configuration* Environment::getConfiguration() const {
    return configuration;
}
QVector<QWidget*> Environment::getConfig_ui() {
    return configuration_ui;
}

QVector<Parameter*> Environment::getParameterList() const {
    return configuration->getParametersList();
}
Parameter* Environment::getParameter( const int index ) {
    return configuration->getParametersList()[index];
}

QString Environment::getConfigurationPath() const {
    return configurationPath;
}
QString Environment::getName() const {
    return name;
}

void Environment::setName( const QString gName ) {
    name = gName;
}

void Environment::setParameterValue( const QString gName, const QString gValue ) {

}
void Environment::setParameterValue( const int index, const QString gValue ) {

}
QString Environment::getParameterValue( const int index ) const {

}
QString Environment::getParameterValue( const QString gName ) const {

}


bool Environment::hasParameterWithName( const QString gName ) {
    return configuration->hasParameterWithName( gName );
}
QString Environment::getParameterType( const QString gName ) {
    return configuration->getParameterType( gName );
}

//void Environment::setParameterValue( const QString gName, const int gValue ) {
//    configuration->getParameterByName( gName )->setValue( gValue );
//}
//void Environment::setParameterValue( const QString gName, const bool gValue ) {
//    configuration->getParameterByName( gName )->setValue( gValue );
//}
//void Environment::setParameterValue( const QString gName, const QString gValue ) {
//    configuration->getParameterByName( gName )->setValue( gValue );
//}
//int Environment::getParameterIntValue( const QString gName ) const {
//    return configuration->getParameterByName( gName )->getIntValue();
//}
//bool Environment::getParameterBoolValue( const QString gName ) const {
//    return configuration->getParameterByName( gName )->getBoolValue();
//}
//QString Environment::getParameterStringValue( const QString gName ) const {
//    return configuration->getParameterByName( gName )->getStringValue();
//}

Environment::~Environment() {}
