#include "genvtracking.h"
#include <opencv2/imgproc.hpp>


GenvTracking::GenvTracking(QObject *parent):
    QObject(parent),
    rec(false),
    stream(false)
{
    cam=new cv::VideoCapture();
    models = *new std::vector<std::string>;
    modelsObj= *new std::vector<Ptr<cv::face::FisherFaceRecognizer>>;
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
QImage GenvTracking::Mat2QImage(cv::Mat *src)
{
     cv::Mat temp; // make the same cv::Mat
     cv::cvtColor(*src, temp,cv::COLOR_BGR2RGB); // cvtColor Makes a copt, that what i need
     QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     dest.bits(); // enforce deep copy, see documentation
     // of QImage::QImage ( const uchar * data, int width, int height, Format format )
     return dest;
}
void GenvTracking::funcStream(){
    stream=!stream;
    emit sendStream();
}

void GenvTracking::enregistrementModel(){
    std::vector<int> YesOrNot;
    std::vector<Mat> images;
    Ptr<cv::face::FisherFaceRecognizer> model = cv::face::FisherFaceRecognizer::create();
    int i=0;
    while (i<5000){
        cv::Mat img;
        *cam>>img;
        images.push_back( img);
        YesOrNot.push_back( 1);
    }
    model->train(images, YesOrNot);
    model->save("test.yml");
}

void GenvTracking::chargerModels(){
    boost::filesystem::path p("..");
    for (auto i = boost::filesystem::directory_iterator(p); i != boost::filesystem::directory_iterator(); i++)
        {
            if (!is_directory(i->path()))
            {
                models.push_back(i->path().filename().string());
                Ptr<cv::face::FisherFaceRecognizer> m=cv::face::FisherFaceRecognizer::create();
                m->read(i->path().filename().string());
                modelsObj.push_back( m);

            }
            else
                continue;
        }
}




