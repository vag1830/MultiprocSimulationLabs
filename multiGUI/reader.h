#ifndef READER_H
#define READER_H

#include <QObject>
#include <QVector>
#include <QString>

class Reader : public QObject
{
    Q_OBJECT
public:
    explicit Reader(QObject *parent = 0);
    Reader( const QString );
    QVector<QString> & getOutput();
    ~Reader();

private:
        QVector<QString> myVector;
signals:

public slots:

};

#endif // READER_H
