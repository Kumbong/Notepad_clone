#include "mainwindow/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationName("Textpad");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);


    MainWindow w;
    w.show();

    return app.exec();
}
