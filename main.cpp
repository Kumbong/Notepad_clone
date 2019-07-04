#include "mainwindow/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Notepad--");
    QCoreApplication::setApplicationName("Notepad--");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);


    MainWindow w;
    w.show();

    return app.exec();
}
