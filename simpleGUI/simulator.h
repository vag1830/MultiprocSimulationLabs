#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QObject>
#include <QVector>

#include "simvalue.h"

class Simulator : public QObject
{
    Q_OBJECT
public:
    explicit Simulator( QObject *parent = 0);
    explicit Simulator( QString, QObject *parent = 0);
    QVector <SimValue*> getconfig() const;
    QVector <SimValue*> getcurconfig() const;
    QVector <QWidget*> getconfig_ui();
    void setdconf( const bool );
    bool getdconf() const;
    QString getname() const;
    ~Simulator();

signals:

public slots:
    void cmb_param_changed( QString );
    void txt_param_changed( QString );

private:
   QString name;
   QVector <SimValue*> configuration;
   QVector <SimValue*> current_configuration;
   QVector <QWidget*> configuration_ui;
   bool default_configuration;
};

#endif // SIMULATOR_H
