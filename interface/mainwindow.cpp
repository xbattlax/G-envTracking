#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    while(true){
        cap >> img;
        imshow("cam",img);
    }

}

