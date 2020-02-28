#ifndef GENVTRACKING_H
#define GENVTRACKING_H
#include <QObject>
#include <QMainWindow>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core.hpp>
#include <ctime>
#include <qdatetime.h>
#include <opencv2/videoio.hpp>
#include <qtextstream.h>
#include <opencv2/face.hpp>
using namespace cv;


class GenvTracking : public QObject
{
    Q_OBJECT

private:
    cv::Mat img;
    cv::VideoCapture* cam;
    
    GenvTracking(QObject* parent = 0);
    //std::vector<std::string> models;
    static GenvTracking* instance;
    bool stream;
    bool rec;
    void openIfIsNot(const int dev = 0);
    bool GenvTracking::saveSnapshot();
    GenvTracking(GenvTracking const&) = delete;
    void operator=(GenvTracking const&) = delete;



public:
    ~GenvTracking();
    QImage Mat2QImage(cv::Mat* src);
    void chargerModels();
    void entrainementModel();
    static GenvTracking* getInstance();

signals:
    void sendStream();
    void sendImg(QImage output);
    void pushButtonChangeText(std::string txt);

public slots:
    void recupImg();
    void setStatut();
    void funcStream();
    void enregistrementModel();
};
#endif // GENVTRACKING_H
