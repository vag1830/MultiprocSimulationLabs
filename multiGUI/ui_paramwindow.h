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
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *btnClose;
    QPushButton *btnDefaults;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ParamWindow)
    {
        if (ParamWindow->objectName().isEmpty())
            ParamWindow->setObjectName(QString::fromUtf8("ParamWindow"));
        ParamWindow->resize(520, 365);
        ParamWindow->setMinimumSize(QSize(520, 0));
        centralwidget = new QWidget(ParamWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 506, 285));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 3);

        btnClose = new QPushButton(centralwidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        gridLayout->addWidget(btnClose, 2, 2, 1, 1);

        btnDefaults = new QPushButton(centralwidget);
        btnDefaults->setObjectName(QString::fromUtf8("btnDefaults"));

        gridLayout->addWidget(btnDefaults, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        ParamWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ParamWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 520, 20));
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
        btnClose->setText(QApplication::translate("ParamWindow", "Close", 0, QApplication::UnicodeUTF8));
        btnDefaults->setText(QApplication::translate("ParamWindow", "Defaults", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ParamWindow: public Ui_ParamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMWINDOW_H
