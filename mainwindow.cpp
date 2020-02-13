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
    QImage imgIn= QImage((uchar*) img.data, img.cols, img.rows, img.step, QImage::Format_Indexed8);
    ui->opencv->setPixmap(QPixmap::fromImage(imgIn));

}
void MainWindow::receiveImg(QImage frame)
{
    ui->opencv->setPixmap(QPixmap::fromImage(frame));
}

