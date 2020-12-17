#include "mainwindow.h"

#include <QApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    // std::cout << "lasgna" << '\n';
    QTextStream(stdout) << "Hello!" << '\n';
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
