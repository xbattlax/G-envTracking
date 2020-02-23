#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <QTimer>
#include <iostream>
#include "genvtracking.h"
#include "qdebug.h"
using namespace cv;
using namespace std;

/*
Constructeur :
    ui -> fenetre graphique
    opencv -> QLabel d'affichage de la cam�ra
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->opencv->setScaledContents(true);
    init();
}

/*
Destructeur 
*/
MainWindow::~MainWindow() {
    thread->quit();
    while (!thread->isFinished());
    delete thread;
    delete ui;
}

/*
Initie les connexions entre signaux
*/
void MainWindow::init() {
    thread = new QThread(); //Cr�ation d'un thread
    GenvTracking* webcam = new GenvTracking(); //objet qui g�re les images OpenCV
    QTimer* timer = new QTimer(); //objet qui g�re la cadence des threads
    timer->setInterval(1); //cadence du Qtimer

    connect(timer, SIGNAL(timeout()), webcam, SLOT(recupImg())); //lorsque le timer envoie le signal timeOut -> une image est r�cup�rer sur la webcam
    connect(thread, SIGNAL(finished()), webcam, SLOT(deleteLater())); //supprimer l'objet webcam quand le thread se termine
    connect(thread, SIGNAL(finished()), timer, SLOT(deleteLater())); //supprimer l'objet timer quand le thread se termine
    connect(ui->pushButton, SIGNAL(clicked()), webcam, SLOT(setStatut())); //change l'�tat de rec dans l'objet webcam
    connect(webcam, SIGNAL(sendImg(QImage)), this, SLOT(receiveImg(QImage))); //lorsque le signal sendImg(QImage) est �mis, la fenetre le r�cup�re pour l'afficher
    /*connect(webcam, SIGNAL(pushButtonChangeText(string)), this, SLOT(pushButtonChangeText(string)));*/

    timer->start();
    webcam->moveToThread(thread);
    timer->moveToThread(thread);

    thread->start();
}




/*
Affiche img dans le Qlabel ui->opencv
*/
void MainWindow::receiveImg(QImage img)
{      
    QPixmap pixmap = QPixmap::fromImage(img);
    ui->opencv->setPixmap(pixmap);
}

void MainWindow::pushButtonChangeText(string txt) {
    qInfo() << QString::fromStdString(txt);
    ui->pushButton->setText(QString::fromStdString(txt));
}

QImage MainWindow::Mat2QImage(cv::Mat* src)
{
    cv::Mat temp; // make the same cv::Mat
    cv::cvtColor(*src, temp, cv::COLOR_BGR2RGB); // cvtColor Makes a copt, that what i need
    QImage dest((const uchar*)temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    dest.bits(); // enforce deep copy, see documentation
    // of QImage::QImage ( const uchar * data, int width, int height, Format format )
    return dest;
}