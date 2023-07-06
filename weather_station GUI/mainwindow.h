#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QFileDialog>
//#include <QMessageBox>
#include <iostream>
#include <qcustomplot.h>
#include <QHostAddress>


#define GRAPH_LIVE_     0
#define GRAPH_DATABASE_ 1

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString recievedText;

    QSharedPointer<QCPAxisTickerDateTime> dateTimeTickerTemp_;
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTickerHumid_;
    QDateTime start_;
    QDateTime end_;

    ~MainWindow();
    int counter_    = 0;
    int delay_      = 1000U;
    int interval_   = -60*5U;

    bool filter_    = false;
    bool refresh_   = true;
    bool live_      = true;

    double yminT_    = -1;
    double ymaxT_    = -1;
    double yminH_   = -1;
    double ymaxH_   = -1;
    double accH_    = 1;
    double acc_     = 1;

private slots:

    void disconnected                           (void);
    void readyRead                              (void);
    void connected                              (void);
    void on_btn_Clear_clicked                   ();
    void on_btn_Connect_clicked                 ();
    void on_btn_Send_clicked                    ();
    void updateGraph                            (QDateTime, double, double);
    void on_btn_Refresh_clicked                 ();
    void on_cb_Monitor_activated                (int index);
    void on_btn_Download_clicked                ();
    void on_btn_Load_clicked                    ();
    void on_btn_Filter_clicked                  ();
    void on_dateEdit_End_dateTimeChanged        (const QDateTime &dateTime);

    void on_dateEdit_Start_dateTimeChanged(const QDateTime &dateTime);

private:
    Ui::MainWindow *ui;
    QTcpSocket * socket;
};

#endif // MAINWINDOW_H
