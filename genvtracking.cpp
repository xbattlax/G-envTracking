#include "genvtracking.h"

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
}
void GenvTracking::recupImg(){
    (*cam) >> img;
    QImage output((const unsigned char *)img.data, img.cols, img.rows, QImage::Format_Indexed8);
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
