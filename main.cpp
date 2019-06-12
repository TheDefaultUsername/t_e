#include "mainwindow.h"
#include "textcolorprovider.h"
#include "textworkprovider.h"
#include "fileworkprovider.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
