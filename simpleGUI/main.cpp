#include <QtGui/QApplication>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "eventhandler.h"
#include "simulator.h"

//#include "wrighter.h"

int main(int argc, char *argv[])
{
    //Wrighter write( "/home/vaggelis/Documents/testfile" );
    //write.addline( "vaggelis" );
    //write.tofile();

    QApplication a(argc, argv);
    MainWindow w;
    w.move( ( a.desktop()->width() - w.width() ) / 2,
            ( a.desktop()->height() - w.height() ) / 2 );

    w.show();

    return a.exec();
}
