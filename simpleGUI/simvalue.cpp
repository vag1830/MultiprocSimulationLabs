#include "simvalue.h"

SimValue::SimValue(QObject *parent) :
    QObject(parent)
{
}

SimValue::SimValue( QString g_name,
                    QString g_type,
                    QString g_value,
                    QString g_descr,
                    QString g_smallDescr,
                    QObject *parent ):
    QObject(parent)
{
    name = g_name;
    value = g_value;
    type = g_type;
    descr = g_descr;
    smallDescr = g_smallDescr;
}

void SimValue::setname( QString g_name )
{
    name = g_name;
}
void SimValue::setvalue( QString g_value )
{
    value = g_value;
}
void SimValue::settype( QString g_type )
{
    type = g_type;
}
void SimValue::setdescr( QString g_descr )
{
    descr = g_descr;
}
void SimValue::setsmalldescr( QString g_smallDescr )
{
    smallDescr = g_smallDescr;
}
void SimValue::settypewidget( enum TYPE g_type )
{
    type_widget = g_type;
}

QString SimValue::getname() const
{
    return name;
}
QString SimValue::getvalue() const
{
    return value;
}
QString SimValue::gettype() const
{
    return type;
}
QString SimValue::getdescr() const
{
    return descr;
}
QString SimValue::getsmalldescr() const
{
    return smallDescr;
}
enum TYPE SimValue::gettypewidget() const
{
    return type_widget;
}

SimValue::~SimValue(){}

