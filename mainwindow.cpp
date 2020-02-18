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

QImage MainWindow::putImage(const Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if (mat.type() == CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i = 0; i < 256; i++)
            colorTable.push_back(qRgb(i, i, i));
        // Copy input Mat
        const uchar* qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if (mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar* qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        cout << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

void MainWindow::on_pushButton_clicked()
{
    //ui->mdiArea_2->hide();
    VideoCapture cap;
    cap.open(0);
    Mat img;
    cap >> img;
    imshow("camera", img);
    QImage((uchar*) img.data, img.cols, img.rows, img.step, QImage::Format_Indexed8);
    QPixmap pixmap = QPixmap::fromImage(imgIn);
   /* QPixmap resized_pixmap = pixmap.scaled(1920, 1920, Qt::AspectRatioMode::KeepAspectRatio);*/
    ui->opencv->setPixmap(pixmap);

}
void MainWindow::receiveImg(QImage frame)
{
    ui->opencv->setPixmap(QPixmap::fromImage(frame));
}

