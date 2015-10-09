#ifndef WRIGHTER_H
#define WRIGHTER_H

#include <QObject>
#include <QVector>
#include <QString>

class Wrighter
{
public:
    Wrighter( const QString );

    void addline( const QString );
    void tofile() const;

    ~Wrighter();

private:
        QString filename;
        QVector<QString> myVector;
};

#endif // WRIGHTER_H
