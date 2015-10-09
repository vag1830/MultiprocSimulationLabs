/********************************************************************************
** Form generated from reading UI file 'paramwindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMWINDOW_H
#define UI_PARAMWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParamWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_defaults;
    QPushButton *btn_save;
    QPushButton *btn_close;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ParamWindow)
    {
        if (ParamWindow->objectName().isEmpty())
            ParamWindow->setObjectName(QString::fromUtf8("ParamWindow"));
        ParamWindow->resize(400, 400);
        ParamWindow->setMinimumSize(QSize(400, 200));
        ParamWindow->setMaximumSize(QSize(16777215, 1000000));
        ParamWindow->setDocumentMode(true);
        ParamWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(ParamWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 386, 320));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 1, 0, 1, 5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 0, 1, 1);

        btn_defaults = new QPushButton(centralwidget);
        btn_defaults->setObjectName(QString::fromUtf8("btn_defaults"));

        gridLayout_2->addWidget(btn_defaults, 2, 1, 1, 1);

        btn_save = new QPushButton(centralwidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        gridLayout_2->addWidget(btn_save, 2, 2, 1, 1);

        btn_close = new QPushButton(centralwidget);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        gridLayout_2->addWidget(btn_close, 2, 3, 1, 1);

        ParamWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ParamWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 20));
        ParamWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ParamWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ParamWindow->setStatusBar(statusbar);

        retranslateUi(ParamWindow);

        QMetaObject::connectSlotsByName(ParamWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ParamWindow)
    {
        ParamWindow->setWindowTitle(QApplication::translate("ParamWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        btn_defaults->setText(QApplication::translate("ParamWindow", "Defaults", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("ParamWindow", "Save", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("ParamWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ParamWindow: public Ui_ParamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMWINDOW_H
