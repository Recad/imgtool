#ifndef SOBELFILTER_H
#define SOBELFILTER_H

#include <QDialog>
#include <QWidget>
#include <opencv2/opencv.hpp>
using namespace cv;

namespace Ui {
class SobelFilter;
}

class SobelFilter : public QDialog
{
    Q_OBJECT

public:
    explicit SobelFilter(QWidget *parent = 0);
    ~SobelFilter();
    void DisplayImageFiltrada(Mat image);

private:
    Ui::SobelFilter *ui;
};

#endif // SOBELFILTER_H
