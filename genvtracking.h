#ifndef GENVTRACKING_H
#define GENVTRACKING_H
#include <QObject>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/core.hpp"
#include <opencv2/face.hpp>
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
using namespace cv;

class GenvTracking : public QObject
{
    Q_OBJECT

private:
    cv::Mat img;
    cv::VideoCapture *cam;

    std::vector<std::string> models;
    std::vector<Ptr<cv::face::FisherFaceRecognizer>> modelsObj;

    bool rec;
    bool stream;

    bool isOpen(int dev);


public:
    explicit GenvTracking(QObject *parent);
    ~GenvTracking();
    QImage Mat2QImage(cv::Mat *src);
    void enregistrementModel();
    void chargerModels();


signals:
    void sendImg(QImage output);
    void sendStream();

public slots:
    void recupImg();
    void setStatus(int dev);
    void funcStream();
};

#endif // GENVTRACKING_H
