#include "sobelfilter.h"
#include "ui_sobelfilter.h"
#include "filtrosobel.h"
using namespace std;

SobelFilter::SobelFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SobelFilter)
{
    ui->setupUi(this);
}

SobelFilter::~SobelFilter()
{
    delete ui;
}

void SobelFilter::DisplayImageFiltrada(Mat image){
    Mat imageForFSobel = image.clone();
    FiltroSobel *filtrosobel = new FiltroSobel();
    Mat imagenFiltrada = filtrosobel->aplicarSobel(imageForFSobel);
    QImage imdisplay_ori((uchar*)image.data, image.cols, image.rows, image.step, QImage::Format_Indexed8);
    QImage imdisplay_fil((uchar*)imagenFiltrada.data, imagenFiltrada.cols, imagenFiltrada.rows, imagenFiltrada.step, QImage::Format_Indexed8);

    ui->display_image_ori->setPixmap(QPixmap::fromImage(imdisplay_ori));
    ui->display_image_fil->setPixmap(QPixmap::fromImage(imdisplay_fil));
}
