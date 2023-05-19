#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = NULL;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_Send_clicked()
{
    if(socket)
    {
         socket->write(ui->text_Send->toPlainText().toUtf8());
    }
}

void MainWindow::on_btn_Connect_clicked()
{
     if( !socket )
     {
        socket = new QTcpSocket;
        QHostAddress addr(ui->line_IP->text());
        socket->connectToHost(addr,ui->line_Port->text().toUInt());
        connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
        connect(socket,SIGNAL(connected()), this, SLOT(connected()));
     }
     else
     {
         socket->close();
         delete socket;
         socket = NULL;
         ui->btn_Connect->setText("Desconectado");
         ui->btn_Connect->setStyleSheet("background-color: rgb(255,0,0);");
     }
}

void MainWindow::connected()
{
    ui->btn_Connect->setText("Conectado");
    ui->btn_Connect->setStyleSheet("background-color: rgb(0,255,0);");
}

void MainWindow::readyRead()
{

    ui->text_Recieve->appendPlainText( socket->read(socket->bytesAvailable()) );
}

void MainWindow::disconnected()
{
    socket->close();
    socket = NULL;
}

void MainWindow::on_btn_Clear_clicked()
{
    ui->text_Recieve->clear();
}
