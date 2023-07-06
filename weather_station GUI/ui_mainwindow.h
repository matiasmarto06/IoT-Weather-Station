/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab_graphs;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *v_liveGraph;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *v_layout_Filter;
    QHBoxLayout *h_layout_Start;
    QLabel *label_dateStart;
    QDateTimeEdit *dateEdit_Start;
    QHBoxLayout *h_layout_End;
    QLabel *label_dateEnd;
    QDateTimeEdit *dateEdit_End;
    QHBoxLayout *h_layout_FilterBtn;
    QSpacerItem *spacer_Filter;
    QPushButton *btn_Filter;
    QVBoxLayout *v_layout_Database;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_Database;
    QLineEdit *line_Database;
    QHBoxLayout *h_layout_Load;
    QSpacerItem *spacer_Load;
    QPushButton *btn_Load;
    QHBoxLayout *h_layout_Error_2;
    QLabel *label_Error2;
    QVBoxLayout *v_layout_Monitor;
    QHBoxLayout *h_layout_Monitor;
    QLabel *label_Monitor;
    QComboBox *cb_Monitor;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *spacer_Refresh;
    QPushButton *btn_Refresh;
    QHBoxLayout *h_layout_Refresh;
    QLabel *label_empty;
    QCustomPlot *graph_Temp;
    QCustomPlot *graph_Humid;
    QWidget *tab_connect;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *h_layout_IPConnectPort;
    QSpacerItem *h_spacer_IPConnectPort;
    QVBoxLayout *v_layout_Download;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_Filename;
    QLineEdit *line_Filename;
    QHBoxLayout *h_layout_Download;
    QSpacerItem *h_spacer_Donwload;
    QPushButton *btn_Download;
    QHBoxLayout *h_layout_Error;
    QLabel *label_Error;
    QVBoxLayout *v_layout_IPConnectPort;
    QHBoxLayout *h_layout_IP;
    QLabel *label_IP;
    QLineEdit *line_IP;
    QHBoxLayout *h_layout_Port;
    QLabel *label_Port;
    QLineEdit *line_Port;
    QHBoxLayout *h_layout_Connect;
    QSpacerItem *h_spacer_Connect;
    QPushButton *btn_Connect;
    QVBoxLayout *v_layout_SendRecieve;
    QPlainTextEdit *text_Send;
    QHBoxLayout *h_layout_Send;
    QSpacerItem *h_spacer_Send;
    QPushButton *btn_Send;
    QPlainTextEdit *text_Recieve;
    QHBoxLayout *h_layout_Clear;
    QSpacerItem *h_spacer_Clear;
    QPushButton *btn_Clear;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(571, 768);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setMinimumSize(QSize(553, 750));
        tab_graphs = new QWidget();
        tab_graphs->setObjectName("tab_graphs");
        verticalLayout_3 = new QVBoxLayout(tab_graphs);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        v_liveGraph = new QVBoxLayout();
        v_liveGraph->setSpacing(6);
        v_liveGraph->setObjectName("v_liveGraph");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        v_layout_Filter = new QVBoxLayout();
        v_layout_Filter->setSpacing(6);
        v_layout_Filter->setObjectName("v_layout_Filter");
        h_layout_Start = new QHBoxLayout();
        h_layout_Start->setSpacing(6);
        h_layout_Start->setObjectName("h_layout_Start");
        label_dateStart = new QLabel(tab_graphs);
        label_dateStart->setObjectName("label_dateStart");
        label_dateStart->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        h_layout_Start->addWidget(label_dateStart);

        dateEdit_Start = new QDateTimeEdit(tab_graphs);
        dateEdit_Start->setObjectName("dateEdit_Start");

        h_layout_Start->addWidget(dateEdit_Start);


        v_layout_Filter->addLayout(h_layout_Start);

        h_layout_End = new QHBoxLayout();
        h_layout_End->setSpacing(6);
        h_layout_End->setObjectName("h_layout_End");
        label_dateEnd = new QLabel(tab_graphs);
        label_dateEnd->setObjectName("label_dateEnd");
        label_dateEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        h_layout_End->addWidget(label_dateEnd);

        dateEdit_End = new QDateTimeEdit(tab_graphs);
        dateEdit_End->setObjectName("dateEdit_End");

        h_layout_End->addWidget(dateEdit_End);


        v_layout_Filter->addLayout(h_layout_End);

        h_layout_FilterBtn = new QHBoxLayout();
        h_layout_FilterBtn->setSpacing(6);
        h_layout_FilterBtn->setObjectName("h_layout_FilterBtn");
        spacer_Filter = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        h_layout_FilterBtn->addItem(spacer_Filter);

        btn_Filter = new QPushButton(tab_graphs);
        btn_Filter->setObjectName("btn_Filter");

        h_layout_FilterBtn->addWidget(btn_Filter);


        v_layout_Filter->addLayout(h_layout_FilterBtn);


        horizontalLayout->addLayout(v_layout_Filter);

        v_layout_Database = new QVBoxLayout();
        v_layout_Database->setSpacing(6);
        v_layout_Database->setObjectName("v_layout_Database");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_Database = new QLabel(tab_graphs);
        label_Database->setObjectName("label_Database");
        label_Database->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_Database);

        line_Database = new QLineEdit(tab_graphs);
        line_Database->setObjectName("line_Database");
        line_Database->setEnabled(false);
        line_Database->setMinimumSize(QSize(100, 20));
        line_Database->setMaximumSize(QSize(250, 20));
        line_Database->setReadOnly(true);

        horizontalLayout_7->addWidget(line_Database);


        v_layout_Database->addLayout(horizontalLayout_7);

        h_layout_Load = new QHBoxLayout();
        h_layout_Load->setSpacing(6);
        h_layout_Load->setObjectName("h_layout_Load");
        spacer_Load = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        h_layout_Load->addItem(spacer_Load);

        btn_Load = new QPushButton(tab_graphs);
        btn_Load->setObjectName("btn_Load");

        h_layout_Load->addWidget(btn_Load);


        v_layout_Database->addLayout(h_layout_Load);

        h_layout_Error_2 = new QHBoxLayout();
        h_layout_Error_2->setSpacing(6);
        h_layout_Error_2->setObjectName("h_layout_Error_2");
        label_Error2 = new QLabel(tab_graphs);
        label_Error2->setObjectName("label_Error2");
        label_Error2->setMinimumSize(QSize(0, 20));
        QFont font;
        font.setItalic(true);
        label_Error2->setFont(font);
        label_Error2->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        label_Error2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        h_layout_Error_2->addWidget(label_Error2);


        v_layout_Database->addLayout(h_layout_Error_2);


        horizontalLayout->addLayout(v_layout_Database);

        v_layout_Monitor = new QVBoxLayout();
        v_layout_Monitor->setSpacing(6);
        v_layout_Monitor->setObjectName("v_layout_Monitor");
        h_layout_Monitor = new QHBoxLayout();
        h_layout_Monitor->setSpacing(6);
        h_layout_Monitor->setObjectName("h_layout_Monitor");
        label_Monitor = new QLabel(tab_graphs);
        label_Monitor->setObjectName("label_Monitor");
        label_Monitor->setMinimumSize(QSize(0, 0));
        label_Monitor->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        h_layout_Monitor->addWidget(label_Monitor);

        cb_Monitor = new QComboBox(tab_graphs);
        cb_Monitor->addItem(QString());
        cb_Monitor->addItem(QString());
        cb_Monitor->setObjectName("cb_Monitor");
        cb_Monitor->setMinimumSize(QSize(85, 20));
        cb_Monitor->setMaximumSize(QSize(16777215, 20));
        cb_Monitor->setLayoutDirection(Qt::LeftToRight);

        h_layout_Monitor->addWidget(cb_Monitor);


        v_layout_Monitor->addLayout(h_layout_Monitor);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        spacer_Refresh = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(spacer_Refresh);

        btn_Refresh = new QPushButton(tab_graphs);
        btn_Refresh->setObjectName("btn_Refresh");

        horizontalLayout_2->addWidget(btn_Refresh);


        v_layout_Monitor->addLayout(horizontalLayout_2);

        h_layout_Refresh = new QHBoxLayout();
        h_layout_Refresh->setSpacing(6);
        h_layout_Refresh->setObjectName("h_layout_Refresh");
        label_empty = new QLabel(tab_graphs);
        label_empty->setObjectName("label_empty");

        h_layout_Refresh->addWidget(label_empty);


        v_layout_Monitor->addLayout(h_layout_Refresh);


        horizontalLayout->addLayout(v_layout_Monitor);


        v_liveGraph->addLayout(horizontalLayout);

        graph_Temp = new QCustomPlot(tab_graphs);
        graph_Temp->setObjectName("graph_Temp");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graph_Temp->sizePolicy().hasHeightForWidth());
        graph_Temp->setSizePolicy(sizePolicy);

        v_liveGraph->addWidget(graph_Temp);

        graph_Humid = new QCustomPlot(tab_graphs);
        graph_Humid->setObjectName("graph_Humid");
        sizePolicy.setHeightForWidth(graph_Humid->sizePolicy().hasHeightForWidth());
        graph_Humid->setSizePolicy(sizePolicy);

        v_liveGraph->addWidget(graph_Humid);


        verticalLayout_3->addLayout(v_liveGraph);

        tabWidget->addTab(tab_graphs, QString());
        tab_connect = new QWidget();
        tab_connect->setObjectName("tab_connect");
        verticalLayout = new QVBoxLayout(tab_connect);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        h_layout_IPConnectPort = new QHBoxLayout();
        h_layout_IPConnectPort->setSpacing(6);
        h_layout_IPConnectPort->setObjectName("h_layout_IPConnectPort");
        h_spacer_IPConnectPort = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        h_layout_IPConnectPort->addItem(h_spacer_IPConnectPort);

        v_layout_Download = new QVBoxLayout();
        v_layout_Download->setSpacing(6);
        v_layout_Download->setObjectName("v_layout_Download");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_Filename = new QLabel(tab_connect);
        label_Filename->setObjectName("label_Filename");
        label_Filename->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_Filename);

        line_Filename = new QLineEdit(tab_connect);
        line_Filename->setObjectName("line_Filename");
        line_Filename->setMinimumSize(QSize(100, 20));
        line_Filename->setMaximumSize(QSize(250, 20));

        horizontalLayout_8->addWidget(line_Filename);


        v_layout_Download->addLayout(horizontalLayout_8);

        h_layout_Download = new QHBoxLayout();
        h_layout_Download->setSpacing(6);
        h_layout_Download->setObjectName("h_layout_Download");
        h_spacer_Donwload = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        h_layout_Download->addItem(h_spacer_Donwload);

        btn_Download = new QPushButton(tab_connect);
        btn_Download->setObjectName("btn_Download");

        h_layout_Download->addWidget(btn_Download);


        v_layout_Download->addLayout(h_layout_Download);

        h_layout_Error = new QHBoxLayout();
        h_layout_Error->setSpacing(6);
        h_layout_Error->setObjectName("h_layout_Error");
        label_Error = new QLabel(tab_connect);
        label_Error->setObjectName("label_Error");
        QFont font1;
        font1.setBold(false);
        font1.setItalic(true);
        label_Error->setFont(font1);
        label_Error->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        label_Error->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        h_layout_Error->addWidget(label_Error);


        v_layout_Download->addLayout(h_layout_Error);


        h_layout_IPConnectPort->addLayout(v_layout_Download);

        v_layout_IPConnectPort = new QVBoxLayout();
        v_layout_IPConnectPort->setSpacing(6);
        v_layout_IPConnectPort->setObjectName("v_layout_IPConnectPort");
        h_layout_IP = new QHBoxLayout();
        h_layout_IP->setSpacing(6);
        h_layout_IP->setObjectName("h_layout_IP");
        label_IP = new QLabel(tab_connect);
        label_IP->setObjectName("label_IP");
        label_IP->setMinimumSize(QSize(30, 0));
        label_IP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        h_layout_IP->addWidget(label_IP);

        line_IP = new QLineEdit(tab_connect);
        line_IP->setObjectName("line_IP");
        line_IP->setMinimumSize(QSize(100, 20));
        line_IP->setMaximumSize(QSize(250, 20));

        h_layout_IP->addWidget(line_IP);


        v_layout_IPConnectPort->addLayout(h_layout_IP);

        h_layout_Port = new QHBoxLayout();
        h_layout_Port->setSpacing(6);
        h_layout_Port->setObjectName("h_layout_Port");
        label_Port = new QLabel(tab_connect);
        label_Port->setObjectName("label_Port");
        label_Port->setMinimumSize(QSize(30, 0));
        label_Port->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        h_layout_Port->addWidget(label_Port);

        line_Port = new QLineEdit(tab_connect);
        line_Port->setObjectName("line_Port");
        line_Port->setMinimumSize(QSize(100, 20));
        line_Port->setMaximumSize(QSize(250, 20));

        h_layout_Port->addWidget(line_Port);


        v_layout_IPConnectPort->addLayout(h_layout_Port);

        h_layout_Connect = new QHBoxLayout();
        h_layout_Connect->setSpacing(6);
        h_layout_Connect->setObjectName("h_layout_Connect");
        h_spacer_Connect = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        h_layout_Connect->addItem(h_spacer_Connect);

        btn_Connect = new QPushButton(tab_connect);
        btn_Connect->setObjectName("btn_Connect");

        h_layout_Connect->addWidget(btn_Connect);


        v_layout_IPConnectPort->addLayout(h_layout_Connect);


        h_layout_IPConnectPort->addLayout(v_layout_IPConnectPort);


        verticalLayout->addLayout(h_layout_IPConnectPort);

        v_layout_SendRecieve = new QVBoxLayout();
        v_layout_SendRecieve->setSpacing(6);
        v_layout_SendRecieve->setObjectName("v_layout_SendRecieve");
        text_Send = new QPlainTextEdit(tab_connect);
        text_Send->setObjectName("text_Send");

        v_layout_SendRecieve->addWidget(text_Send);

        h_layout_Send = new QHBoxLayout();
        h_layout_Send->setSpacing(6);
        h_layout_Send->setObjectName("h_layout_Send");
        h_spacer_Send = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        h_layout_Send->addItem(h_spacer_Send);

        btn_Send = new QPushButton(tab_connect);
        btn_Send->setObjectName("btn_Send");

        h_layout_Send->addWidget(btn_Send);


        v_layout_SendRecieve->addLayout(h_layout_Send);

        text_Recieve = new QPlainTextEdit(tab_connect);
        text_Recieve->setObjectName("text_Recieve");
        text_Recieve->setLineWidth(0);
        text_Recieve->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_Recieve->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_Recieve->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        text_Recieve->setReadOnly(true);

        v_layout_SendRecieve->addWidget(text_Recieve);

        h_layout_Clear = new QHBoxLayout();
        h_layout_Clear->setSpacing(6);
        h_layout_Clear->setObjectName("h_layout_Clear");
        h_spacer_Clear = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        h_layout_Clear->addItem(h_spacer_Clear);

        btn_Clear = new QPushButton(tab_connect);
        btn_Clear->setObjectName("btn_Clear");

        h_layout_Clear->addWidget(btn_Clear);


        v_layout_SendRecieve->addLayout(h_layout_Clear);


        verticalLayout->addLayout(v_layout_SendRecieve);

        tabWidget->addTab(tab_connect, QString());

        verticalLayout_4->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Cliente", nullptr));
        label_dateStart->setText(QCoreApplication::translate("MainWindow", "Start:", nullptr));
        label_dateEnd->setText(QCoreApplication::translate("MainWindow", "End:", nullptr));
        btn_Filter->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        label_Database->setText(QCoreApplication::translate("MainWindow", "Database: ", nullptr));
        btn_Load->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        label_Error2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#aa0000;\">Switch monitor to database</span></p></body></html>", nullptr));
        label_Monitor->setText(QCoreApplication::translate("MainWindow", "Monitor:", nullptr));
        cb_Monitor->setItemText(0, QCoreApplication::translate("MainWindow", "Live", nullptr));
        cb_Monitor->setItemText(1, QCoreApplication::translate("MainWindow", "Database", nullptr));

        btn_Refresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        label_empty->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_graphs), QCoreApplication::translate("MainWindow", "Monitor", nullptr));
        label_Filename->setText(QCoreApplication::translate("MainWindow", "File name: ", nullptr));
        btn_Download->setText(QCoreApplication::translate("MainWindow", "Download", nullptr));
        label_Error->setText(QCoreApplication::translate("MainWindow", "Please establish connection", nullptr));
        label_IP->setText(QCoreApplication::translate("MainWindow", "IP:", nullptr));
        line_IP->setText(QCoreApplication::translate("MainWindow", "192.168.0.x", nullptr));
        label_Port->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        btn_Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        btn_Send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        text_Recieve->setPlainText(QString());
        text_Recieve->setPlaceholderText(QString());
        btn_Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_connect), QCoreApplication::translate("MainWindow", "Connection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
