#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void receiveImg(QImage frame);
    void on_pushButton_clicked();
signals:
    void sendSetup(int dev);
private:
    Ui::MainWindow *ui;
    bool cam;
};
#endif // MAINWINDOW_H
