#ifndef SIMVALUE_H
#define SIMVALUE_H

#include <QObject>


using namespace std;

enum TYPE { str = 1, cmb };

class SimValue : public QObject
{
    Q_OBJECT
public:
    explicit SimValue(QObject *parent = 0);
    explicit SimValue( QString, QString, QString, QString, QString, QObject *parent = 0 );

    void setname( QString );
    void setvalue( QString );
    void settype( QString );
    void setdescr( QString );
    void setsmalldescr( QString );
    void settypewidget( enum TYPE );

    QString getname() const;
    QString getvalue() const;
    QString gettype() const;
    QString getdescr() const;
    QString getsmalldescr() const;
    enum TYPE gettypewidget() const;
    ~SimValue();

signals:

public slots:

private:
    QString name;
    QString value;
    QString type;
    QString descr;
    QString smallDescr;
    enum TYPE type_widget;
};

#endif // SIMVALUE_H
