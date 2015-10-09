#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include <QVector>
#include <QString>
#include "parameter.h"
#include "reader.h"

class Configuration : public QObject
{
    Q_OBJECT

private:
    QVector<Parameter*> parameters;
    short int parametersSize;
    QString name;
    QString filename;
public:

    explicit Configuration(QObject *parent = 0);
    Configuration( const QString, const QString );
    Configuration( const QString );

    QVector<Parameter*> getParametersList() const;

    QString getFileName() const;
    QString getName() const;
    short int getParametersSize() const;
    Parameter* getParameterByName( const QString ) const;
    Parameter* getParameterByType( const QString ) const;
    QVector<Parameter*> getParameterByGroup() const;

    bool hasParameterWithName( const QString );
    QString getParameterType( const QString );
    QString getParameterType( const int );

    bool isDefault () const;

signals:

public slots:

};

#endif // CONFIGURATION_H
