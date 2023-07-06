#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Measurement.h"
#include "FileMeasurements.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    dateTimeTickerTemp_(new QCPAxisTickerDateTime),
    dateTimeTickerHumid_(new QCPAxisTickerDateTime),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = NULL;

    this->setWindowTitle("Weather Station App");

    ui->graph_Temp->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    ui->graph_Temp->xAxis->setTicker(dateTimeTickerTemp_);
    dateTimeTickerTemp_->setDateTimeFormat("hh:mm");
    ui->graph_Temp->xAxis->setLabel("Time");
    ui->graph_Temp->yAxis->setLabel("Temperature");
    ui->graph_Temp->addGraph();

    ui->graph_Humid->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    ui->graph_Humid->xAxis->setTicker(dateTimeTickerHumid_);
    dateTimeTickerHumid_->setDateTimeFormat("hh:mm");
    ui->graph_Humid->xAxis->setLabel("Time");
    ui->graph_Humid->yAxis->setLabel("Humidity");
    ui->graph_Humid->addGraph();

    ui->cb_Monitor->setCurrentIndex(0);
    ui->btn_Load->setDisabled(true);
    ui->label_Error2->setStyleSheet("QLabel { color : red; }");
    ui->label_Error2->setText("Switch monitor to database");

    ui->btn_Download->setDisabled(true);
    ui->line_Filename->setDisabled(true);
    ui->label_Error->setStyleSheet("QLabel { color : red; }");
    ui->label_Error->setText("Please establish connection");

    ui->dateEdit_End->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_Start->setDateTime(QDateTime::currentDateTime().addDays(-7));
    ui->btn_Filter->setDisabled(true);
    ui->dateEdit_End->setDisabled(true);
    ui->dateEdit_Start->setDisabled(true);
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

    ui->btn_Download->setDisabled(false);
    ui->line_Filename->setDisabled(false);
    ui->label_Error->setStyleSheet("QLineEdit { color: red }");
    ui->label_Error->setText(" ");
    //ui->label_Error->setVisible(false);
}

void MainWindow::disconnected()
{
    socket->close();
    socket = NULL;

    ui->btn_Download->setDisabled(true);
    ui->line_Filename->setDisabled(true);
    ui->label_Error->setStyleSheet("QLabel { color : red; }");
    ui->label_Error->setText("Please establish connection");
    //ui->label_Error->setVisible(true);
}

void MainWindow::updateGraph (QDateTime timestamp, double t, double h)
{

    if (refresh_)
    {
        yminT_ = t - acc_;
        ymaxT_ = t + acc_;
        yminH_ = h - accH_;
        ymaxH_ = h + accH_;
        refresh_ = false;
    }

    else
    {
        if (t < yminT_)
        {
            yminT_ = t - acc_;
        }

        if (t > ymaxT_)
        {
            ymaxT_ = t + acc_;
        }

        if (h < yminH_)
        {
            yminH_ = h - accH_;
        }

        if (h > ymaxH_)
        {
            ymaxH_ = h + accH_;
        }
    }

    ui->graph_Temp->yAxis->setRange(yminT_, ymaxT_);
    ui->graph_Temp->graph(0)->addData(timestamp.toSecsSinceEpoch(), t);
    ui->graph_Temp->replot();

    ui->graph_Humid->yAxis->setRange(yminH_, ymaxH_);
    ui->graph_Humid->graph(0)->addData(timestamp.toSecsSinceEpoch(), h);
    ui->graph_Humid->replot();
}

void MainWindow::readyRead()
{
    recievedText = socket->read(socket->bytesAvailable());

    if (recievedText.length() < 30 && live_)
    {
        ui->text_Recieve->appendPlainText(recievedText);
        Measurement m(recievedText);
        updateGraph(m.getTimestamp(),m.getTemperature(),m.getHumidity());
        ui->graph_Temp->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(m.getTimestamp().addSecs(interval_)), QCPAxisTickerDateTime::dateTimeToKey(m.getTimestamp()));
        ui->graph_Humid->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(m.getTimestamp().addSecs(interval_)), QCPAxisTickerDateTime::dateTimeToKey(m.getTimestamp()));
    }

    else if (recievedText.length() > 30)
    {
        FileMeasurements f(ui->line_Filename->text());
        QList<QString> list = recievedText.split('\n');

        for (int var = 0; var < list.length(); var++)
        {
            f.println(list[var]);
        }
        ui->label_Error->setStyleSheet("QLabel { color : green; }");
        ui->label_Error->setText("Download Done!");
    }
}

void MainWindow::on_btn_Clear_clicked()
{
    ui->text_Recieve->clear();
}

void MainWindow::on_btn_Refresh_clicked()
{
    refresh_ = true;
}

void MainWindow::on_cb_Monitor_activated(int index)
{
    switch (index)
    {
    case GRAPH_LIVE_:
        live_ = true;
        ui->btn_Load->setDisabled(true);
        ui->btn_Refresh->setDisabled(false);
        ui->btn_Filter->setDisabled(true);
        ui->dateEdit_End->setDisabled(true);
        ui->dateEdit_Start->setDisabled(true);
        ui->label_Error2->setText("Switch monitor to database");
        dateTimeTickerHumid_->setDateTimeFormat("hh:mm");
        dateTimeTickerTemp_->setDateTimeFormat("hh:mm");
        ui->graph_Humid->graph(0)->data().clear();
        ui->graph_Humid->replot();
        ui->graph_Humid->update();
        ui->graph_Temp->graph(0)->data().clear();
        ui->graph_Temp->replot();
        ui->graph_Temp->update();
        ui->line_Database->clear();
        break;

    case GRAPH_DATABASE_:
        live_ = false;
        ui->btn_Refresh->setDisabled(true);
        ui->btn_Load->setDisabled(false);
        ui->label_Error2->setText("Load a database");
        dateTimeTickerTemp_->setDateTimeFormat("dd MMM hh:mm");
        dateTimeTickerHumid_->setDateTimeFormat("dd MMM hh:mm");
        ui->graph_Humid->graph(0)->data().clear();
        ui->graph_Humid->replot();
        ui->graph_Humid->update();
        ui->graph_Temp->graph(0)->data().clear();
        ui->graph_Temp->replot();
        ui->graph_Temp->update();
        break;
    }
}

void MainWindow::on_btn_Download_clicked()
{
    if (ui->line_Filename->text().isEmpty())
    {
        ui->label_Error->setStyleSheet("QLabel { color : red; }");
        ui->label_Error->setText("Filename can't be empty");
    }
    else
    {
        ui->label_Error->setStyleSheet("QLabel { color : red; }");
        ui->label_Error->setText(" ");
        socket->write(QString("download request").toUtf8());
    }
}

void MainWindow::on_btn_Load_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", ".csv(*.csv)");
    QFile p(path);
    if (!p.open(QIODevice::ReadOnly))
    {
        ui->label_Error2->setText("File can't be opened");
        return;
    }

    ui->line_Database->setText(p.fileName());
    ui->label_Error2->setText(" ");

    int i = 0;
    while (!p.atEnd())
    {
        Measurement m(p.readLine());

        if (m.getTimestamp().isValid() && !(m.getTimestamp().toSecsSinceEpoch() > QDateTime::currentDateTime().toSecsSinceEpoch()))
        {
            if (m.getTimestamp().toSecsSinceEpoch() < start_.toSecsSinceEpoch() || i == 0)
            {
                start_ = m.getTimestamp();
            }

            if (m.getTimestamp().toSecsSinceEpoch() > end_.toSecsSinceEpoch() || i == 0)
            {
                end_ = m.getTimestamp();
            }

            updateGraph(m.getTimestamp(), m.getTemperature(), m.getHumidity());
        }

        ui->graph_Temp->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(start_), QCPAxisTickerDateTime::dateTimeToKey(end_));
        ui->graph_Humid->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(start_), QCPAxisTickerDateTime::dateTimeToKey(end_));

        ui->dateEdit_End->setDateTime(end_);
        ui->dateEdit_Start->setDateTime(start_);
        ui->dateEdit_End->setDisabled(false);
        ui->dateEdit_Start->setDisabled(false);
        ui->btn_Filter->setDisabled(false);

        i++;
    }



    ui->label_Error2->setText(" ");

    p.close();
}


void MainWindow::on_btn_Filter_clicked()
{
    filter_ = !filter_;

    if (filter_)
    {
        ui->btn_Filter->setText("Clear");
        ui->graph_Temp->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(ui->dateEdit_Start->dateTime()), QCPAxisTickerDateTime::dateTimeToKey(ui->dateEdit_End->dateTime()));
        ui->graph_Temp->replot();
        ui->graph_Temp->update();
        ui->graph_Humid->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(ui->dateEdit_Start->dateTime()), QCPAxisTickerDateTime::dateTimeToKey(ui->dateEdit_End->dateTime()));
        ui->graph_Humid->replot();
        ui->graph_Temp->update();
        ui->dateEdit_End->setDisabled(true);
        ui->dateEdit_Start->setDisabled(true);
    }
    else
    {
        ui->btn_Filter->setText("Filter");
        ui->graph_Temp->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(start_), QCPAxisTickerDateTime::dateTimeToKey(end_));
        ui->graph_Temp->replot();
        ui->graph_Temp->update();
        ui->graph_Humid->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(start_), QCPAxisTickerDateTime::dateTimeToKey(end_));
        ui->graph_Humid->replot();
        ui->graph_Temp->update();
        ui->dateEdit_End->setDisabled(false);
        ui->dateEdit_Start->setDisabled(false);
    }
}


void MainWindow::on_dateEdit_End_dateTimeChanged(const QDateTime &dateTime)
{
    if (dateTime.toSecsSinceEpoch() > QDateTime::currentDateTime().toSecsSinceEpoch())
    {
        ui->dateEdit_End->setDateTime(QDateTime::currentDateTime());
    }
}


void MainWindow::on_dateEdit_Start_dateTimeChanged(const QDateTime &dateTime)
{
    if (dateTime.toSecsSinceEpoch() > ui->dateEdit_End->dateTime().toSecsSinceEpoch())
    {
        ui->dateEdit_Start->setDateTime(QDateTime::currentDateTime().addSecs(-1));
    }
}

