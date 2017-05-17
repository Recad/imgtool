#include "compresor.h"
#include "QtCore"
#include "QDebug"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;


Compresor::Compresor()
{

}
Compresor::Compresor(int porcentaje ,Mat matriz)
{
    this->matriz = matriz;
    this->porcentaje = porcentaje;
}

void Compresor::run(){

    qDebug()<<"Corriendo";
    this->resultado = ComprimirImagen();
    qDebug()<<"a terminado de correr";
}

cv::Mat Compresor::ComprimirImagen(){
    matriz.convertTo(matriz, CV_32F, 1.0/255);
    SVD svdimagencita(matriz);
    float porcentajeu = 1.0;
    int valoresSingulares = 1 ;



    if (porcentaje >0 and this->porcentaje <=100){

        porcentajeu = (this->porcentaje / 100.0);

        valoresSingulares=floor(porcentajeu*svdimagencita.w.rows);
    }

    Mat v ;
    transpose(svdimagencita.vt,v);


    Mat Umenor = svdimagencita.u.colRange(0 ,valoresSingulares);
    Mat vmenor = v.colRange(0,valoresSingulares);

    Mat singula = svdimagencita.w.rowRange(0,valoresSingulares);

    Mat vt ;
    transpose(vmenor,vt);

    //Construimos la imagen con esos valores singulares

    Mat result = Umenor * Mat::diag(singula) * vt;
    this->resultado = result;
    cv::imshow("imagen comprimida",result);
    return result;

}

cv::Mat Compresor::getMatriz() const
{
    return matriz;
}

void Compresor::setMatriz(const cv::Mat &value)
{
    matriz = value;
}

int Compresor::getPorcentaje() const
{
    return porcentaje;
}

void Compresor::setPorcentaje(int value)
{
    porcentaje = value;
}

cv::Mat Compresor::getResultado() const
{
    return resultado;
}

void Compresor::setResultado(const cv::Mat &value)
{
    resultado = value;
}
