#include <QString>

#ifndef PARAMETER_H
#define PARAMETER_H

using namespace std;

class Parameter {

private:

    QString name;
    QString type;
    QString desc;
    QString group;
    QString value;
    QString dValue;
    QString smallDesc;

public:

    Parameter( const QString, const QString, const QString, const QString, const QString, const QString, const QString );

    bool isDefault() const;

    QString getName() const;
    QString getType() const;
    QString getDesc() const;
    QString getGroup() const;
    QString getSmallDesc() const;


    void setName( const QString );
    void setType( const QString );
    void setDesc( const QString );
    void setGroup(const QString );
    void setSmallDesc(const QString );

    QString getValue() const;
    QString getDValue() const;
    void setValue( const QString );
    void setDValue( const QString );


    ~Parameter();
};

#endif // PARAMETER_H


