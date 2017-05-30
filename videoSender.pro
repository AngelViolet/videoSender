#-------------------------------------------------
#
# Project created by QtCreator 2016-07-06T15:46:57
#
#-------------------------------------------------

QT       += core gui
QT      += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = videoSender
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


INCLUDEPATH += D:\Qt\opencv\build\include\opencv \
                        D:\Qt\opencv\build\include\opencv2 \
                        D:\Qt\opencv\build\include

#  LIBS+=D:\Qt\opencv\MinGW\lib\libopencv_*
LIBS+=D:\Qt\opencv\MinGW\lib\libopencv_calib3d2410.dll.a	\
  D:\Qt\opencv\MinGW\lib\libopencv_contrib2410.dll.a	\
  D:\Qt\opencv\MinGW\lib\libopencv_core2410.dll.a	\
  D:\Qt\opencv\MinGW\lib\libopencv_features2d2410.dll.a	\
  D:\Qt\opencv\MinGW\lib\libopencv_flann2410.dll.a	\
  D:\Qt\opencv\MinGW\lib\libopencv_gpu2410.dll.a	\
  D:\Qt\opencv\MinGW\lib\libopencv_highgui2410.dll.a	\
  D:\Qt\opencv\MinGW\lib\libopencv_imgproc2410.dll.a	\
  D:\Qt\opencv\MinGW\lib\libopencv_legacy2410.dll.a	\
  D:\Qt\opencv\MinGW\lib\libopencv_ml2410.dll.a	\
  D:\Qt\opencv\MinGW\lib\libopencv_objdetect2410.dll.a	\
  D:\Qt\opencv\MinGW\lib\libopencv_video2410.dll.a
