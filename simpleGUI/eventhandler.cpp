#include "eventhandler.h"

#include "outputwindow.h"

#include <QString>

#include <QtDebug>

EventHandler::EventHandler( QWidget *parent ):
    QWidget( parent ){}

EventHandler::EventHandler( MainWindow* w, QWidget *parent):
    QWidget( parent )
{
    window = w;
}

void EventHandler::menu_open_clicked()
{
    QFileDialog *qfd = new QFileDialog();
    qfd->setNameFilter("All *.c files (*.c)");
    qfd->setDirectory("/home/vaggelis/");
    qfd->exec();
    QStringList path = qfd->selectedFiles();
    QString only_path;

    window->setfname( path.toVector()[0].split( QChar('/') ).last() );
    window->diplayfile( path.toVector()[0] );

    for (int i = 0; i < path.toVector()[0].split( QChar('/') ).size() - 1; i++ )
        only_path.append( path.toVector()[0].split( QChar('/') ).value(i) + "/" );

    window->setfpath( only_path );
    //qDebug("%s", only_path.toAscii().data() );
    delete qfd;
}

void EventHandler::btn_run_clicked()
{
    window->diplayfile( window->getfpath() + window->getfname() );
    QString compilation = "~/Simplescalar/bin/sslittle-na-sstrix-gcc "
            + window->getfpath() + window->getfname()
            + " -o " + window->getfpath() + "sim-exec";
    // qDebug("%s", compilation.toAscii().data() );
    system( compilation.toStdString().c_str() );
    if ( !window->getsimulator()->getdconf() )
    {
        QString simplescalar = "~/Simplescalar/simplesim-3.0/"
                + window->getsimulator()->getname()
                + " -config ../simpleGUI/conf/current.conf "
                + window->getfpath() + "sim-exec";

        //qDebug("%s", simplescalar.toAscii().data() );
        system( simplescalar.toStdString().c_str() );
        window->getsimulator()->setdconf( true );
    }
    else
    {
        QString simplescalar = "~/Simplescalar/simplesim-3.0/"
                + window->getsimulator()->getname() + " -redir:sim "
                + window->getfpath() + "sim-output -redir:prog "
                + window->getfpath() + "prog-output "
                + window->getfpath() + "sim-exec";
        qDebug("%s", simplescalar.toAscii().data() );
        system( simplescalar.toStdString().c_str() );
        window->getsimulator()->setdconf( true );


    }

    OutputWindow *opwin = new OutputWindow( window );
    opwin->move( window->x(), window->y() );
    opwin->init( window->getfpath() );
    opwin->show();
}

void EventHandler::menu_exit_clicked()
{
    window->close();
}
