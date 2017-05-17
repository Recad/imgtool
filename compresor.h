#ifndef COMPRESOR_H
#define COMPRESOR_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "QtCore"
class Compresor : public QThread
{
public:
    Compresor();
    Compresor(int , cv::Mat);
    void run();
    cv::Mat ComprimirImagen();

    cv::Mat getMatriz() const;
    void setMatriz(const cv::Mat &value);

    int getPorcentaje() const;
    void setPorcentaje(int value);

    cv::Mat getResultado() const;
    void setResultado(const cv::Mat &value);

private:
    cv::Mat matriz;
    cv::Mat resultado;
    int porcentaje;

};

#endif // COMPRESOR_H
