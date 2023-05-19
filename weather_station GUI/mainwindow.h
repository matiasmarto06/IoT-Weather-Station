#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

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

    void disconnected(void);
    void readyRead(void);
    void connected(void);

    void on_btn_Clear_clicked();

    void on_btn_Connect_clicked();

    void on_btn_Send_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket * socket;
};

#endif // MAINWINDOW_H
