#include <QString>
#include "configuration.h"
#include "parameter.h"

#ifndef PROGRAM_H
#define PROGRAM_H

class Program : public QObject
{
    Q_OBJECT

private:
    Configuration* configuration;
    QString configurationPath;

    QString name;
    QString executable;
    QVector<QWidget*> configuration_ui;

    bool hasConf;
    bool defaultConf;


public slots:
    void cmb_param_changed( QString );
    void txt_param_changed( QString );

public:

    explicit Program( QString, QString = "null", QString = "null", QObject *parent = 0 );

    Configuration* getConfiguration() const;
    QVector<Parameter*> getParameterList() const;
    Parameter* getParameter( const int );

    QVector<QWidget*> getConfig_ui();

    QString getName() const;
    QString getExecutable() const;
    QString getConfigurationPath() const;
    bool hasConfiguration() const;
    void hasConfiguration( bool );

    bool configurationChanged() const;
    void configurationChanged( bool );

    void setName( const QString );
    void setExecutable( const QString );

    void setParameterValue( const QString, const QString );
    void setParameterValue( const int, const QString );
    QString getParameterValue( const int ) const;
    QString getParameterValue( const QString ) const;

    bool hasParameterWithName( const QString );
    QString getParameterType( const QString );

//    void setParameterValue( const QString, const int );
//    void setParameterValue( const QString, const bool );
//    void setParameterValue( const QString, const QString );
//    int getParameterIntValue( const QString ) const;
//    bool getParameterBoolValue( const QString ) const;
//    QString getParameterStringValue( const QString ) const;

    ~Program();
};

#endif // PROGRAM_H
