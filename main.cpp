#include <QApplication>
#include <QSharedMemory>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    static QSharedMemory *shareMem = new QSharedMemory( "oneStock",&a);
    if ( !shareMem->create( 1 ) )
    {
        qApp->quit();
        return -1;
    }

    MainWindow *w = new MainWindow ;
    a.installEventFilter(w);
    w->showMaximized();
    return a.exec();
}
