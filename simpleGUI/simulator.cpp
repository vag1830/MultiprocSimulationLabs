#include "simulator.h"
#include "reader.h"
#include "eventhandler.h"
#include <QDebug>
#include <QStringList>
#include <QComboBox>
#include <QLineEdit>

Simulator::Simulator(QObject *parent) :
    QObject(parent){}

Simulator::Simulator( QString g_name, QObject *parent):
    QObject(parent)
{  
//  FIX THIS-----------------*
    QString cpath = "../simpleGUI/conf/" + g_name + "-default.conf";
    Reader reader( cpath );
    QStringList list;
    for ( int i = 0; i < reader.getOutput().size(); i++ )
    {
        list = reader.getOutput()[i].simplified().split( QChar('#') );
        configuration.push_back( new SimValue( list.value(0),
                                               list.value(1),
                                               list.value(2),
                                               list.value(3),
                                               list.value(4) ) );
        current_configuration.push_back( new SimValue( list.value(0),
                                               list.value(1),
                                               list.value(2),
                                               list.value(3),
                                               list.value(3) ) );

        if ( !qstrcmp( configuration[i]->gettype().toStdString().c_str(), "<true|false> " ) )
        {
            configuration_ui.push_back( new QComboBox );
            static_cast<QComboBox*>(configuration_ui.last())->addItem( "False" );
            static_cast<QComboBox*>(configuration_ui.last())->addItem( "True" );

            static_cast<QComboBox*>(configuration_ui.last())->setToolTip( configuration[i]->getdescr() );
            static_cast<QComboBox*>(configuration_ui.last())->setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Fixed );

            connect( static_cast<QComboBox*>( configuration_ui.last() ),
                     SIGNAL( currentIndexChanged( QString ) ), this,
                     SLOT( cmb_param_changed( QString ) ) );
        }
        else
        {
            configuration_ui.push_back( new QLineEdit );
            static_cast<QLineEdit*>(configuration_ui.last())->
                    setText( configuration[i]->getvalue() );

            static_cast<QLineEdit*>(configuration_ui.last())->setToolTip( configuration[i]->getdescr() );
            static_cast<QLineEdit*>(configuration_ui.last())->setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Fixed );

            connect( static_cast<QLineEdit*>( configuration_ui.last() ),
                     SIGNAL( textChanged( QString ) ), this,
                     SLOT( txt_param_changed( QString ) ) );
        }
    }
    //qDebug("%s", cpath.toAscii().data() );
    name = g_name;
    default_configuration = true;
}

void Simulator::cmb_param_changed( QString value )
{
    QObject *cmb = QObject::sender();
    for ( int i = 0; i < configuration_ui.size(); i++ )
        if ( cmb == configuration_ui[i] )
        {
            current_configuration[i]->setvalue( value );
            qDebug("%s %s",current_configuration[i]->getname().toAscii().data(),
                   current_configuration[i]->getvalue().toAscii().data() );
        }
}

void Simulator::txt_param_changed( QString value )
{
    QObject *txt = QObject::sender();
    for ( int i = 0; i < configuration_ui.size(); i++ )
        if ( txt == configuration_ui[i] )
        {
            current_configuration[i]->setvalue( value );
            qDebug("%s %s",current_configuration[i]->getname().toAscii().data(),
                   current_configuration[i]->getvalue().toAscii().data() );
        }
}


QVector <SimValue*> Simulator::getconfig() const
{
    return configuration;
}
QVector <SimValue*> Simulator::getcurconfig() const
{
    return current_configuration;
}
QVector <QWidget*> Simulator::getconfig_ui()
{
    return configuration_ui;
}
QString Simulator::getname() const
{
    return name;
}
void Simulator::setdconf( const bool a )
{
    default_configuration = a;
}
bool Simulator::getdconf() const
{
    return default_configuration;
}

Simulator::~Simulator()
{
    for ( int i = 0; i < configuration.size(); i++ )
    {
          delete configuration[i];
          delete configuration_ui[i];
          delete current_configuration[i];
    }
}

