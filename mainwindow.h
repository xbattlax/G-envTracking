#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage Mat2QImage(cv::Mat const& src);
    static void pushButtonChangeText(std::string txt);

private slots:
    void receiveImg(QImage frame);
    //void on_pushButton_clicked();
signals:
    void sendSetup(int dev);
private:
    Ui::MainWindow *ui;
    QThread *thread;
    static Ui::MainWindow* UI;
    void init()
};
#endif // MAINWINDOW_H