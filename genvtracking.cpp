#include "genvtracking.h"
#include "mainwindow.h"


/*
Constructeur :
    cam : VideoCapture -> Capture de la webcam
    rec : bool -> true si en cours d'enregistrement
*/
GenvTracking::GenvTracking(QObject *parent):
    QObject(parent),
    rec(false)
{
    cam = new cv::VideoCapture();
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
    cam->open(dev); //release automatique
}

/*
change l'�tat de rec et ferme le flux vers la webcam s'il passe � false
*/
void GenvTracking::setStatut() {
    std::string txt = "stopper l'enregistrement";
    rec = (!rec);
    if (rec == false) {
        cam->release();
        txt = "d�marrer l'enregistrement";
    }
    emit pushButtonChangeText(txt);
}

/*
V�rfie que le flux de la webcam est ouvert puis lis ton contenu
Renvoie un signal sendImg(QImage)
*/
void GenvTracking::recupImg() {
    if (rec) {
        openIfIsNot();
        cam->read(img);
        QImage output(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
        emit sendImg(output.rgbSwapped()); //rgbSwapped rectifie la colorim�trie de l'image (erreur provenant du format QImage::Format_RGB888
    }
}