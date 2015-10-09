#ifndef SIMULATION_H
#define SIMULATION_H

#include "mainwindow.h"
#include <QObject>
#include <QString>
#include "environment.h"
#include "program.h"
#include "configuration.h"

#include <QProcess>
class MainWindow;


class Simulation : public QObject
{
    Q_OBJECT

private:
    Environment* environment;
    Program* program;
    MainWindow* window;

    QString name;
    QString simulationCommand;

    Configuration* configuration;
    QString configurationPath;

    QVector<QWidget*> configuration_ui;

    QProcess *QPROC;

public:
    explicit Simulation(QObject *parent = 0);
    Simulation( QString, QString, Environment*, Program*, MainWindow*);

    QVector<QWidget*> getConfig_ui();

    Configuration* getConfiguration() const;
    QVector<Parameter*> getParameterList() const;
    Parameter* getParameter( const int );

    QString getConfigurationPath() const;


    QString getName() const;
    void setName( const QString );

    void setParameterValue( const QString, const QString );
    void setParameterValue( const int, const QString );
    QString getParameterValue( const int ) const;
    QString getParameterValue( const QString ) const;

    bool hasParameterWithName( const QString );
    QString getParameterType( const QString );

    Program* getProgram() const;
    void setProgram( Program* );

    Environment* getEnvironment() const;
    void setEnvironment( Environment* );

    void init();
    void start() const;
    void finalize();


    ~Simulation();
signals:

public slots:
    void cmb_param_changed( QString );
    void txt_param_changed( QString );

    void simulationStarted();
    void simulationFinished();

};

#endif // SIMULATION_H
