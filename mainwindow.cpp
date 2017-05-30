#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv.hpp>
using namespace cv;
#include <QFile>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sender = new QUdpSocket(this);
    //ip = QHostAddress(ui->lineEdit->text());
    //port = ui->lineEdit_2->text().toInt();
    dstip = QHostAddress("192.168.254.0");
    dstport = 5555;
    srcip = QHostAddress::Any;
    srcport = 6666;
    sender->bind(srcip, srcport);
}

MainWindow::~MainWindow()
{
    delete sender;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    camera.open(0);
    connect(&timer, SIGNAL(timeout()),
            this, SLOT(timer_slot())
            );
    timer.start(33);
}
void MainWindow::on_pushButton_2_clicked()
{
    timer.stop();
    camera.release();
}
void MainWindow::timer_slot()
{
    Mat cvImage;    //定义矩阵，用来存放图像
    camera.read(cvImage); // 从摄像头采集图像
    QImage qtImage; // 把opencv的图像转换为qt的图像
    qtImage = QImage(cvImage.data,
             cvImage.size().width,
             cvImage.size().height,
             QImage::Format_RGB888);
    // 显示图像
    ui->label->setPixmap(
           QPixmap::fromImage(qtImage.rgbSwapped())
                );
    ui->label->resize(QSize(qtImage.width(),
                            qtImage.height()));
// #include <QFile>
    // 保存图像
    qtImage.save("test.jpg", "JPEG");
    //打开图像
    QFile file("test.jpg");
    file.open(QIODevice::ReadOnly);
    // 把图像读到 buffer
    QByteArray buffer;
    buffer = file.readAll();
       //发送图像
    sender->writeDatagram(
                buffer, buffer.size(),
                dstip, dstport
                );
    file.close();
}



