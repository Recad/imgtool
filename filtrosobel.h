#ifndef FILTROSOBEL_H
#define FILTROSOBEL_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <cmath>

using namespace cv;
using namespace std;

class FiltroSobel {

public:
    FiltroSobel();
    Mat aplicarSobel(Mat imagen);
    int aplicarNucleos(int posicionX, int posicionY);

private:
    Mat imagenSalida;
    Mat imagenEntrada;
    int nucleoX[3][3];
    int nucleoY[3][3];
};

#endif
