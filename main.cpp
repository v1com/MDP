#include <QApplication>
#include "mainwindow.h"
#include "dialog.h"

int main(int argc, char * argv[])
{
    QApplication app(argc,argv);

    Dialog *myDialog = new Dialog();
    myDialog->exec();

    return app.exec();
}
