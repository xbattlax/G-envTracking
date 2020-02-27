#include "genvtracking.h"
#include <opencv2/imgproc.hpp>

#include <opencv2/videoio.hpp>

#include "opencv2/face.hpp"
#include <string>
#include <fstream>
#include <iostream>

using namespace cv;
using namespace std;




cv::CascadeClassifier faceCascade;
/*
Constructeur :
    cam : VideoCapture -> Capture de la webcam
    rec : bool -> true si en cours d'enregistrement
*/
GenvTracking::GenvTracking(QObject *parent):
    QObject(parent),
    rec(false),
    stream(false)
{
    /*if(capture.)*/
    cam = new cv::VideoCapture();
    //models = *new std::vector<std::string>;
    modelsObj= *new std::vector<cv::Ptr<cv::face::FisherFaceRecognizer>>;
}

/*
Destructeur
*/
GenvTracking::~GenvTracking()
{
    delete cam; //appelle automatiquement cam->release();
}

/*
Ouvre le flux vers la webcam s'il ne l'est pas d�j�
*/
void GenvTracking::openIfIsNot(const int dev)
{
    if(!cam->isOpened()) cam->open(dev); //release automatique
}

/*
change l'�tat de rec et ferme le flux vers la webcam s'il passe � false
*/
void GenvTracking::setStatut() {
    std::string txt = "stopper l'enregistrement";
    rec = (!rec);
    if (rec == false) {
        cam->release();
        txt = "demarrer l'enregistrement";
    }
    emit pushButtonChangeText(txt);
}

QImage GenvTracking::Mat2QImage(cv::Mat *src)
{
     cv::Mat temp; // make the same cv::Mat
     cv::cvtColor(*src, temp,cv::COLOR_BGR2RGB); // cvtColor Makes a copt, that what i need
     QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     dest.bits(); // enforce deep copy, see documentation
     // of QImage::QImage ( const uchar * data, int width, int height, Format format )
     return dest;
}
void GenvTracking::funcStream(){
    stream=!stream;
    emit sendStream();
}

void GenvTracking::enregistrementModel(){
    recupImg();
    std::vector<int> nom;
    std::vector<cv::Mat> images;
    cv::Ptr<cv::face::FisherFaceRecognizer> model = cv::face::FisherFaceRecognizer::create();
    int i=0;
    while (i<500){
        QString s = QString::number(i);
        //qInfo("progression :", s);
        cv::Mat img;
        *cam>>img;
        cv::Mat imageGris;
        cvtColor( img, imageGris, cv::COLOR_BGR2GRAY );
        images.push_back( imageGris);
        nom.push_back( 0);
    }
    model->train(images, nom);
    model->save("test.yml");
}

void GenvTracking::entrainementModel(){

}

void GenvTracking::chargerModels(){

    std::ifstream fichier("strtok /Users/nathanmetzger/untitled2/models.txt");
    if(fichier){
        std::string ligne;
        while ( std::getline( fichier, ligne )){
            cv::Ptr<cv::face::FisherFaceRecognizer> m=cv::face::FisherFaceRecognizer::create();
            m->read(ligne);
            modelsObj.push_back(m);
        }
    }
}

/*
V�rfie que le flux de la webcam est ouvert puis lis ton contenu
Renvoie un signal sendImg(QImage)
*/
void GenvTracking::recupImg() {
    if (rec) {

        openIfIsNot();
        cam->read(img);
        cv::Mat imageGris;
        cvtColor( img, imageGris, cv::COLOR_BGR2GRAY );
        faceCascade.load( "/Users/nathanmetzger/untitled2/haarcascade_frontalface_default.xml" );
        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(imageGris, faces);
        for ( size_t i = 0; i < faces.size(); i++ )
        {
          cv::Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
          cv::ellipse( img, center, cv::Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, cv::Scalar( 255, 255, 100 ), 4 );
        }
        QImage output(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
        emit sendImg(output.rgbSwapped()); //rgbSwapped rectifie la colorim�trie de l'image (erreur provenant du format QImage::Format_RGB888
    }
}


bool GenvTracking::saveSnapshot() {
    openIfIsNot();
    // Default resolution of the frame is obtained.The default resolution is system dependent. 
    int frame_width = cam->get(CAP_PROP_FRAME_WIDTH);
    int frame_height = cam->get(CAP_PROP_FRAME_HEIGHT);

    //Création du nom de la vidéo
    QString* fileName(0); //initialisation du pointeur à 0
    fileName = new QString();
    QString date(""), hour("");
    QTextStream(&date) << QDate::currentDate().year() << '-' << QDate::currentDate().month() << '-' << QDate::currentDate().day();
    QTextStream(&hour) << QTime::currentTime().hour() << '-' << QTime::currentTime().minute();
    *fileName = date + '_' + hour + ".mp4";
    // Define the codec and create VideoWriter object.
    const int framerate(20);
    VideoWriter video(fileName->toStdString(), CV_WRAP('M', 'J', 'P', 'G'), framerate, Size(frame_width, frame_height));
    const int time(10); //temps d'enregistrement en secondes
    int nbImages(0);
    while (1)
    {

        Mat img;
        // Capture frame-by-frame 
        *cam >> img;
        nbImages++;
        // If the frame is empty, break immediately
        if (img.empty()) break;
        // Write the frame into the file 'outcpp.avi'
        video.write(img);
        // Display the resulting frame    
        //imshow("Frame", img);

        // Press  ESC on keyboard to  exit
        /*char c = (char)waitKey(1);
        if (c == 27)
            break;*/
        if (nbImages == time * framerate) break;
    }

    // When everything done, release the video capture and write object
    cam->release();
    video.release();

    // Closes all the windows
    /*destroyAllWindows();*/
    return true;
}