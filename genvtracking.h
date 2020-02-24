#ifndef GENVTRACKING_H
#define GENVTRACKING_H
#include <QObject>
#include <QMainWindow>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/core.hpp"
#include <opencv2/face.hpp>
/*#include <opencv2/face.hpp>
#include "boost/filesystem.hpp"
using namespace cv;
=======
#include <opencv2/face.hpp>
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"*/


class GenvTracking : public QObject
{
    Q_OBJECT

private:
    cv::Mat img;
    cv::VideoCapture* cam;
    /*std::vector<std::string> models;
    std::vector<Ptr<cv::face::FisherFaceRecognizer>> modelsObj;*/
    bool stream;
    bool rec;
    void openIfIsNot(const int dev = 0);


public:
    explicit GenvTracking(QObject* parent = 0);
    ~GenvTracking();
    QImage Mat2QImage(cv::Mat* src);
    void enregistrementModel();
    void chargerModels();


signals:
    void sendStream();
    void sendImg(QImage output);
    void pushButtonChangeText(std::string txt);
   

public slots:
    void recupImg();
    void setStatut();
    void funcStream();
};
#endif // GENVTRACKING_H
