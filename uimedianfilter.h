#ifndef UIMEDIANFILTER_H
#define UIMEDIANFILTER_H

#include <QDialog>
#include <QWidget>
#include <opencv2/opencv.hpp>
using namespace cv;

namespace Ui {
class UiMedianFilter;
}

class UiMedianFilter : public QDialog
{
    Q_OBJECT

public:
    explicit UiMedianFilter(QWidget *parent = 0);
    ~UiMedianFilter();
    void DisplayImageFiltrada(Mat image);

private:
    Ui::UiMedianFilter *ui;
};

#endif // UIMEDIANFILTER_H
