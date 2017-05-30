#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv.hpp>
using namespace cv;
#include <QTimer>
#include <QtNetwork/QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void timer_slot();
private:
    Ui::MainWindow *ui;
    VideoCapture camera;
    QTimer timer;
    QUdpSocket *sender;
    QHostAddress dstip;
    QHostAddress srcip; // 可以不写
    quint16  dstport;
    quint16  srcport;
};

#endif // MAINWINDOW_H
