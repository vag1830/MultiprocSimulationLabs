/********************************************************************************
** Form generated from reading UI file 'outputwindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTWINDOW_H
#define UI_OUTPUTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutputWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabsContainer;
    QWidget *tabErr;
    QGridLayout *gridLayout_2;
    QTextEdit *txtErr;
    QWidget *tabStat;
    QGridLayout *gridLayout_3;
    QTextEdit *txtStat;
    QWidget *tabOut;
    QGridLayout *gridLayout_4;
    QTextEdit *txtOut;
    QWidget *tab_stats;
    QGridLayout *gridLayout_5;
    QTextEdit *txt_pstats;
    QWidget *tab_stats_miss;
    QGridLayout *gridLayout_6;
    QTextEdit *txt_stats_miss;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OutputWindow)
    {
        if (OutputWindow->objectName().isEmpty())
            OutputWindow->setObjectName(QString::fromUtf8("OutputWindow"));
        OutputWindow->resize(454, 410);
        centralwidget = new QWidget(OutputWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnClose = new QPushButton(centralwidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        gridLayout->addWidget(btnClose, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        tabsContainer = new QTabWidget(centralwidget);
        tabsContainer->setObjectName(QString::fromUtf8("tabsContainer"));
        tabErr = new QWidget();
        tabErr->setObjectName(QString::fromUtf8("tabErr"));
        gridLayout_2 = new QGridLayout(tabErr);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        txtErr = new QTextEdit(tabErr);
        txtErr->setObjectName(QString::fromUtf8("txtErr"));

        gridLayout_2->addWidget(txtErr, 0, 0, 1, 1);

        tabsContainer->addTab(tabErr, QString());
        tabStat = new QWidget();
        tabStat->setObjectName(QString::fromUtf8("tabStat"));
        gridLayout_3 = new QGridLayout(tabStat);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        txtStat = new QTextEdit(tabStat);
        txtStat->setObjectName(QString::fromUtf8("txtStat"));

        gridLayout_3->addWidget(txtStat, 1, 0, 1, 1);

        tabsContainer->addTab(tabStat, QString());
        tabOut = new QWidget();
        tabOut->setObjectName(QString::fromUtf8("tabOut"));
        gridLayout_4 = new QGridLayout(tabOut);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        txtOut = new QTextEdit(tabOut);
        txtOut->setObjectName(QString::fromUtf8("txtOut"));

        gridLayout_4->addWidget(txtOut, 0, 0, 1, 1);

        tabsContainer->addTab(tabOut, QString());
        tab_stats = new QWidget();
        tab_stats->setObjectName(QString::fromUtf8("tab_stats"));
        gridLayout_5 = new QGridLayout(tab_stats);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        txt_pstats = new QTextEdit(tab_stats);
        txt_pstats->setObjectName(QString::fromUtf8("txt_pstats"));

        gridLayout_5->addWidget(txt_pstats, 0, 0, 1, 1);

        tabsContainer->addTab(tab_stats, QString());
        tab_stats_miss = new QWidget();
        tab_stats_miss->setObjectName(QString::fromUtf8("tab_stats_miss"));
        gridLayout_6 = new QGridLayout(tab_stats_miss);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        txt_stats_miss = new QTextEdit(tab_stats_miss);
        txt_stats_miss->setObjectName(QString::fromUtf8("txt_stats_miss"));

        gridLayout_6->addWidget(txt_stats_miss, 0, 0, 1, 1);

        tabsContainer->addTab(tab_stats_miss, QString());

        gridLayout->addWidget(tabsContainer, 1, 0, 1, 2);

        OutputWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OutputWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 454, 20));
        OutputWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(OutputWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        OutputWindow->setStatusBar(statusbar);

        retranslateUi(OutputWindow);

        tabsContainer->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OutputWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OutputWindow)
    {
        OutputWindow->setWindowTitle(QApplication::translate("OutputWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("OutputWindow", "Close", 0, QApplication::UnicodeUTF8));
        tabsContainer->setTabText(tabsContainer->indexOf(tabErr), QApplication::translate("OutputWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
        tabsContainer->setTabText(tabsContainer->indexOf(tabStat), QApplication::translate("OutputWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
        tabsContainer->setTabText(tabsContainer->indexOf(tabOut), QApplication::translate("OutputWindow", "Page", 0, QApplication::UnicodeUTF8));
        tabsContainer->setTabText(tabsContainer->indexOf(tab_stats), QApplication::translate("OutputWindow", "Page", 0, QApplication::UnicodeUTF8));
        tabsContainer->setTabText(tabsContainer->indexOf(tab_stats_miss), QApplication::translate("OutputWindow", "Page", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OutputWindow: public Ui_OutputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTWINDOW_H
