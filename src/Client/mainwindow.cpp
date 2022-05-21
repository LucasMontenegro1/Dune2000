#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtMultimedia/QMediaPlayer>
#include <QErrorMessage>

MainWindow::MainWindow(std::string& host, std::string& port, QWidget *parent)
        : QMainWindow(parent)
        ,host(host)
        ,port(port)
        , ui(new Ui::MainWindow)
        , playing(true)
{
    ui->setupUi(this);
    this->music = new QMediaPlayer(this);
    music->setMedia(QUrl::fromLocalFile("/home/lucas/Desktop/Dune 2000 - Attack on Arrakis.mp3"));
    music->setVolume(50);
    music->play();
    ui->lineEdit->setStyleSheet("QLineEdit {background-color: white;}");
    ui->lineEdit_2->setStyleSheet("QLineEdit {background-color: white;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{

}

void MainWindow::on_Background_linkActivated(const QString &link)
{

}


void MainWindow::on_radioButton_clicked()
{
    music->pause();
}


void MainWindow::on_pushButton_clicked(bool checked)
{
    if(playing){
        music->pause();
        playing = false;
    }else{
        music->play();
        playing = true;
    }

}


void MainWindow::on_frame_customContextMenuRequested(const QPoint &pos)
{

}


void MainWindow::on_StartButton_clicked()
{
    QString first(ui->lineEdit->text());
    QString second(ui->lineEdit_2->text());
    if (first.isEmpty() || second.isEmpty() ){
        QErrorMessage msg;
        msg.showMessage("FILL HOST AND PORT");
        msg.exec();
    }else{
        host = first.toStdString();
        port = second.toStdString();
        this->close();
    }

}

