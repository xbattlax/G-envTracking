#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include "genvtracking.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GenvTracking *track = new GenvTracking(this);
    track->setStatus(0);
    connect(this, SIGNAL(sendSetup(int)), track, SLOT(setStatus(int)));
    connect(track, SIGNAL(sendImg(QImage)), this, SLOT(receiveImg(QImage)));
}


MainWindow::~MainWindow()
{
    //this->camView(false);
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

    //ui->mdiArea_2->hide();
    VideoCapture cap;
    cap.open(0);
    Mat img;
    cap >> img;

    ui->opencv->setPixmap(QPixmap::fromImage(Mat2QImage(&img)));


}
void MainWindow::receiveImg(QImage frame)
{

    ui->opencv->setPixmap(QPixmap::fromImage(frame));
}
QImage MainWindow::Mat2QImage(cv::Mat *src)
{
     cv::Mat temp; // make the same cv::Mat
     cv::cvtColor(*src, temp,cv::COLOR_BGR2RGB); // cvtColor Makes a copt, that what i need
     QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     dest.bits(); // enforce deep copy, see documentation
     // of QImage::QImage ( const uchar * data, int width, int height, Format format )
     return dest;
}

