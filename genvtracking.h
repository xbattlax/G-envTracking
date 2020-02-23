#ifndef GENVTRACKING_H
#define GENVTRACKING_H
#include <QObject>
#include <QMainWindow>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


class GenvTracking : public QObject
{
    Q_OBJECT

private:
    cv::Mat img;
    cv::VideoCapture *cam;
    bool rec;
    void openIfIsNot(const int dev = 0);


public:
    explicit GenvTracking(QObject *parent = 0);
    ~GenvTracking();

signals:
    void pushButtonChangeText(std::string txt);
    void sendImg(QImage img);

public slots:
    void recupImg();
    void setStatut();
};

#endif // GENVTRACKING_H
