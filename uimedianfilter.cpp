#include "uimedianfilter.h"
#include "ui_uimedianfilter.h"
#include "medianfilter.h"

UiMedianFilter::UiMedianFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UiMedianFilter)
{
    ui->setupUi(this);
}

UiMedianFilter::~UiMedianFilter()
{
    delete ui;
}

void UiMedianFilter::DisplayImageFiltrada(Mat image){
    Mat imageForFMediana = image.clone();
    MedianFilter *medianfilter = new MedianFilter();
    Mat imagenFiltrada = medianfilter->aplicarFiltroMediana(imageForFMediana, 3, 3);
    QImage imdisplay_ori((uchar*)image.data, image.cols, image.rows, image.step, QImage::Format_Indexed8);
    QImage imdisplay_fil((uchar*)imagenFiltrada.data, imagenFiltrada.cols, imagenFiltrada.rows, imagenFiltrada.step, QImage::Format_Indexed8);

    ui->display_image_ori->setPixmap(QPixmap::fromImage(imdisplay_ori));
    ui->display_image_fil->setPixmap(QPixmap::fromImage(imdisplay_fil));
}
