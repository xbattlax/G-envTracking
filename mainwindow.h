#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QThread>
#include "genvtracking.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage Mat2QImage(cv::Mat *src);

private slots:
    void receiveImg(QImage frame);
    //void on_pushButton_clicked();
signals:
    void sendSetup(int dev);
private:
    Ui::MainWindow *ui;
    QThread *thread;
    void init();
public slots:
    void pushButtonChangeText(std::string txt);
};
#endif // MAINWINDOW_H