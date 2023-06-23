#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = NULL;

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::t_updateGraph);
    timer->start(delay_);

    ui->graph_Temp->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    ui->graph_Temp->xAxis->setTicker(dateTimeTicker);
    dateTimeTicker->setDateTimeFormat("hh:mm");
    ui->graph_Temp->xAxis->setLabel("Time");
    ui->graph_Temp->yAxis->setLabel("Temperature");
    ui->graph_Temp->addGraph();

    ui->graph_Humid->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker2(new QCPAxisTickerDateTime);
    ui->graph_Humid->xAxis->setTicker(dateTimeTicker2);
    dateTimeTicker2->setDateTimeFormat("hh:mm");
    ui->graph_Humid->xAxis->setLabel("Time");
    ui->graph_Humid->yAxis->setLabel("Humidity");
    ui->graph_Humid->addGraph();
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

void MainWindow::t_updateGraph(void)
{

}

void MainWindow::connected()
{
     ui->btn_Connect->setText("Conectado");
     ui->btn_Connect->setStyleSheet("background-color: rgb(0,255,0);");
}

void MainWindow::readyRead()
{
     recievedText = socket->read(socket->bytesAvailable());
     ui->text_Recieve->appendPlainText(recievedText);

     QList<QString> temp = recievedText.split(';');

     QDate date(temp[2].toInt(), temp[1].toInt(), temp[0].toInt());
     QTime time(temp[3].toInt(), temp[4].toInt(), temp[5].toInt(), 0);
     QDateTime dateTime(date, time);
     //now_ = now_.addMSecs(delay_);

     Measurement m(temp[6].toFloat(), temp[7].toFloat(), dateTime);

     ui->graph_Temp->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(dateTime.addSecs(interval_)), QCPAxisTickerDateTime::dateTimeToKey(dateTime));
     ui->graph_Humid->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(dateTime.addSecs(interval_)), QCPAxisTickerDateTime::dateTimeToKey(dateTime));

     double x = 0, t = 0, h = 0;

     x = (double) dateTime.toSecsSinceEpoch();
     t = m.getTemperature();
     h = m.getHumidity();

     if (!liveGraph_)
     {
         ymin_ = t - acc_;
         ymax_ = t + acc_;
         yminH_ = h - accH_;
         ymaxH_ = h + accH_;
         liveGraph_ = true;
     }

     if (t < ymin_)
     {
         ymin_ = t - acc_;
     }

     if (t > ymax_)
     {
         ymax_ = t + acc_;
     }

     if (h < yminH_)
     {
         yminH_ = h - accH_;
     }

     if (h > ymaxH_)
     {
         ymaxH_ = h + accH_;
     }

     ui->graph_Temp->yAxis->setRange(ymin_, ymax_);
     ui->graph_Temp->graph(0)->addData(x, t);
     ui->graph_Temp->replot();

     ui->graph_Humid->yAxis->setRange(yminH_, ymaxH_);
     ui->graph_Humid->graph(0)->addData(x, h);
     ui->graph_Humid->replot();

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
