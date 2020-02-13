#include "genvtracking.h"
#include <opencv2/imgproc.hpp>

GenvTracking::GenvTracking(QObject *parent):
    QObject(parent),
    rec(false)
{
    cam=new cv::VideoCapture();
}
GenvTracking::~GenvTracking()
{
    if(cam->isOpened()) cam->release();
    delete cam;
}
bool GenvTracking::isOpen( int device)
{
    if(cam->isOpened()) cam->release();
    cam->open(device);
    if(cam->isOpened()) return true;
    else return false;
    recupImg();
}
void GenvTracking::recupImg(){
    (*cam) >> img;
    //imshow("cam",img);
    QImage output((const unsigned char *)img.data, img.cols, img.rows, QImage::Format_RGBX64);
    emit sendImg(output);
}

void GenvTracking::setStatus(int dev){
    isOpen(dev);
    if(!cam->isOpened()) {
        rec = false;
            return;
        }
        rec = true;
}
QImage Mat2QImage(cv::Mat *src)
{
     cv::Mat temp; // make the same cv::Mat
     cv::cvtColor(*src, temp,cv::COLOR_BGR2RGB); // cvtColor Makes a copt, that what i need
     QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     dest.bits(); // enforce deep copy, see documentation
     // of QImage::QImage ( const uchar * data, int width, int height, Format format )
     return dest;
}
