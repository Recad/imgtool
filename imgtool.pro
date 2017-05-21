QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = imgtool
TEMPLATE = app

SOURCES += main.cpp\
           mainwindow.cpp \
           filtromedianas.cpp \
           medianfilter.cpp \
           filtrosobel.cpp \
           sobelfiler.cpp

HEADERS  += mainwindow.h \
            filtromedianas.h \
            medianfilter.h \
            filtrosobel.h \
            sobelfilter.h

FORMS    += mainwindow.ui \
            medianfilter.ui \
            sobelfilter.ui

INCLUDEPATH += C:\opencv\build\install\include
LIBS += -LC:\opencv\build\install\x86\mingw\lib\
    -lopencv_core320.dll \
    -lopencv_highgui320.dll \
    -lopencv_imgcodecs320.dll \
    -lopencv_imgproc320.dll \
    -lopencv_features2d320.dll \
    -lopencv_calib3d320.dll
