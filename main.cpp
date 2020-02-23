#include "mainwindow.h"
//#include "opencv2/opencv.hpp"
#include <QApplication>

//using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //w.camView(true);
    return a.exec();
}
