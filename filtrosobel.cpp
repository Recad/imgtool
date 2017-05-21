#include "filtrosobel.h"

FiltroSobel::FiltroSobel(){

}

Mat FiltroSobel::aplicarSobel(Mat imagen){

    imagenSalida = imagen.clone();
    imagenEntrada = imagen.clone();

    nucleoX[0][0] = 1; nucleoX[0][1] = 0; nucleoX[0][2] = -1;
    nucleoX[1][0] = 2; nucleoX[1][1] = 0; nucleoX[1][2] = -2;
    nucleoX[2][0] = 1; nucleoX[2][1] = 0; nucleoX[2][2] = -1;

    nucleoY[0][0] = 1; nucleoY[0][1] = 2; nucleoY[0][2] = 1;
    nucleoY[1][0] = 0; nucleoY[1][1] = 0; nucleoY[1][2] = 0;
    nucleoY[2][0] = -1; nucleoY[2][1] = -2; nucleoY[2][2] = -1;
    
    for(int i = 1; i < (imagen.rows - 1); i++){
        for(int j = 1; j < (imagen.cols - 1); j++){
            
            imagenSalida.at<uchar>(i, j) = aplicarNucleos(i, j);
        }
    }

    return imagenSalida;
}

int FiltroSobel::aplicarNucleos(int posicionX, int posicionY){

    int valorX = 0, valorY = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            valorX += (nucleoX[i][j] * imagenEntrada.at<uchar>(posicionX - 1 + i, posicionY - 1 + j));
            valorY += (nucleoY[i][j]  * imagenEntrada.at<uchar>(posicionX - 1 + i, posicionY - 1 + j));
        }
    }

    double resultado = sqrt((double)((valorX * valorX) + (valorY * valorY)));

    return (int)resultado;
}
