#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>
#include <qcustomplot.h>
#include <QTime>
#include <QDateTime>

#include "Measurement.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString recievedText;
    ~MainWindow();

    int counter_ = 0;
    int delay_ = 1000U;
    int interval_ = -60*5U;

    bool liveGraph_ = false;

    double ymin_ = -1;
    double ymax_ = -1;
    double yminH_ = -1;
    double ymaxH_ = -1;
    double accH_ = 1;
    double acc_ = 1;

    //QDateTime now_ = QDateTime::currentDateTime().toLocalTime();

private slots:

    void disconnected                           (void);
    void readyRead                              (void);
    void connected                              (void);
    void on_btn_Clear_clicked                   ();
    void on_btn_Connect_clicked                 ();
    void on_btn_Send_clicked                    ();
    void t_updateGraph                          (void);

private:
    Ui::MainWindow *ui;
    QTcpSocket * socket;
};

#endif // MAINWINDOW_H
