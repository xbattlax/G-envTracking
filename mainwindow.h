#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "genvtracking.h"
using namespace cv;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage Mat2QImage(cv::Mat *src);

private slots:
    void receiveImg(QImage frame);
    //void on_pushButton_clicked();
signals:
    void sendSetup(int dev);
private:
    Ui::MainWindow *ui;
    bool cam;
};
#endif // MAINWINDOW_H
