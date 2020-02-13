#ifndef GENVTRACKING_H
#define GENVTRACKING_H
#include <QObject>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/core.hpp"
class GenvTracking : public QObject
{
    Q_OBJECT

private:
    cv::Mat img;
    cv::VideoCapture *cam;

    bool rec;


    bool isOpen(int dev);


public:
    explicit GenvTracking(QObject *parent);
    ~GenvTracking();
    QImage Mat2QImage(cv::Mat *src);


signals:
    void sendImg(QImage output);

public slots:
    void recupImg();
    void setStatus(int dev);
};

#endif // GENVTRACKING_H
