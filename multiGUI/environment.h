#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QObject>
#include <QString>
#include "configuration.h"

class Environment : public QObject
{
    Q_OBJECT

private:
    Configuration* configuration;
    QString configurationPath;
    QString name;

    QVector<QWidget*> configuration_ui;

public slots:
    void cmb_param_changed( QString );
    void txt_param_changed( QString );

public:

    explicit Environment(QObject *parent = 0);
    Environment( QString, QString = "null" );


    QVector<QWidget*> getConfig_ui();

    Configuration* getConfiguration() const;
    QVector<Parameter*> getParameterList() const;
    Parameter* getParameter( const int );

    QString getConfigurationPath() const;
    QString getName() const;

    void setName( const QString );
    //void setCongigurationPath( const QString );

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

    ~Environment();
signals:

public slots:

};

#endif // ENVIRONMENT_H
