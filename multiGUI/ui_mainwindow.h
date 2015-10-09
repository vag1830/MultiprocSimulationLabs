/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *lblChooseProgram;
    QComboBox *cmbPrograms;
    QPushButton *btnProgParameters;
    QLabel *lblNewEnvironment;
    QLineEdit *txtEnvName;
    QPushButton *btnCreateEnvironment;
    QLabel *lblChooseEnvironment;
    QComboBox *cmbEnvironment;
    QPushButton *btnEnvParams;
    QPushButton *btnSimParams;
    QPushButton *btnRun;
    QPushButton *btnExit;
    QLabel *lblSimulation;
    QLineEdit *txtSimulationName;
    QTextEdit *txtConsole;
    QGridLayout *gridLayout_3;
    QLabel *lblLogoEU;
    QLabel *lblLogoDigiGr;
    QLabel *lblLogoEspa;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(460, 374);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(460, 200));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblChooseProgram = new QLabel(centralWidget);
        lblChooseProgram->setObjectName(QString::fromUtf8("lblChooseProgram"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblChooseProgram->sizePolicy().hasHeightForWidth());
        lblChooseProgram->setSizePolicy(sizePolicy2);
        lblChooseProgram->setMinimumSize(QSize(0, 0));
        lblChooseProgram->setMaximumSize(QSize(16777215, 16777215));
        lblChooseProgram->setLayoutDirection(Qt::LeftToRight);
        lblChooseProgram->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblChooseProgram, 0, 0, 1, 1);

        cmbPrograms = new QComboBox(centralWidget);
        cmbPrograms->setObjectName(QString::fromUtf8("cmbPrograms"));
        sizePolicy2.setHeightForWidth(cmbPrograms->sizePolicy().hasHeightForWidth());
        cmbPrograms->setSizePolicy(sizePolicy2);
        cmbPrograms->setMinimumSize(QSize(0, 0));
        cmbPrograms->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(cmbPrograms, 0, 1, 1, 1);

        btnProgParameters = new QPushButton(centralWidget);
        btnProgParameters->setObjectName(QString::fromUtf8("btnProgParameters"));
        sizePolicy2.setHeightForWidth(btnProgParameters->sizePolicy().hasHeightForWidth());
        btnProgParameters->setSizePolicy(sizePolicy2);
        btnProgParameters->setMinimumSize(QSize(0, 0));
        btnProgParameters->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(btnProgParameters, 0, 2, 1, 1);

        lblNewEnvironment = new QLabel(centralWidget);
        lblNewEnvironment->setObjectName(QString::fromUtf8("lblNewEnvironment"));
        sizePolicy2.setHeightForWidth(lblNewEnvironment->sizePolicy().hasHeightForWidth());
        lblNewEnvironment->setSizePolicy(sizePolicy2);
        lblNewEnvironment->setMinimumSize(QSize(0, 0));
        lblNewEnvironment->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lblNewEnvironment, 1, 0, 1, 1);

        txtEnvName = new QLineEdit(centralWidget);
        txtEnvName->setObjectName(QString::fromUtf8("txtEnvName"));
        sizePolicy2.setHeightForWidth(txtEnvName->sizePolicy().hasHeightForWidth());
        txtEnvName->setSizePolicy(sizePolicy2);
        txtEnvName->setMinimumSize(QSize(0, 0));
        txtEnvName->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(txtEnvName, 1, 1, 1, 1);

        btnCreateEnvironment = new QPushButton(centralWidget);
        btnCreateEnvironment->setObjectName(QString::fromUtf8("btnCreateEnvironment"));
        sizePolicy2.setHeightForWidth(btnCreateEnvironment->sizePolicy().hasHeightForWidth());
        btnCreateEnvironment->setSizePolicy(sizePolicy2);
        btnCreateEnvironment->setMinimumSize(QSize(0, 0));
        btnCreateEnvironment->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(btnCreateEnvironment, 1, 2, 1, 1);

        lblChooseEnvironment = new QLabel(centralWidget);
        lblChooseEnvironment->setObjectName(QString::fromUtf8("lblChooseEnvironment"));
        sizePolicy2.setHeightForWidth(lblChooseEnvironment->sizePolicy().hasHeightForWidth());
        lblChooseEnvironment->setSizePolicy(sizePolicy2);
        lblChooseEnvironment->setMinimumSize(QSize(0, 0));
        lblChooseEnvironment->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lblChooseEnvironment, 2, 0, 1, 1);

        cmbEnvironment = new QComboBox(centralWidget);
        cmbEnvironment->setObjectName(QString::fromUtf8("cmbEnvironment"));
        sizePolicy2.setHeightForWidth(cmbEnvironment->sizePolicy().hasHeightForWidth());
        cmbEnvironment->setSizePolicy(sizePolicy2);
        cmbEnvironment->setMinimumSize(QSize(0, 0));
        cmbEnvironment->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(cmbEnvironment, 2, 1, 1, 1);

        btnEnvParams = new QPushButton(centralWidget);
        btnEnvParams->setObjectName(QString::fromUtf8("btnEnvParams"));
        sizePolicy2.setHeightForWidth(btnEnvParams->sizePolicy().hasHeightForWidth());
        btnEnvParams->setSizePolicy(sizePolicy2);
        btnEnvParams->setMinimumSize(QSize(0, 0));
        btnEnvParams->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(btnEnvParams, 2, 2, 1, 1);

        btnSimParams = new QPushButton(centralWidget);
        btnSimParams->setObjectName(QString::fromUtf8("btnSimParams"));
        sizePolicy2.setHeightForWidth(btnSimParams->sizePolicy().hasHeightForWidth());
        btnSimParams->setSizePolicy(sizePolicy2);
        btnSimParams->setMinimumSize(QSize(0, 0));
        btnSimParams->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(btnSimParams, 3, 2, 1, 1);

        btnRun = new QPushButton(centralWidget);
        btnRun->setObjectName(QString::fromUtf8("btnRun"));
        sizePolicy2.setHeightForWidth(btnRun->sizePolicy().hasHeightForWidth());
        btnRun->setSizePolicy(sizePolicy2);
        btnRun->setMinimumSize(QSize(0, 0));
        btnRun->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(btnRun, 4, 2, 1, 1);

        btnExit = new QPushButton(centralWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        sizePolicy2.setHeightForWidth(btnExit->sizePolicy().hasHeightForWidth());
        btnExit->setSizePolicy(sizePolicy2);
        btnExit->setMinimumSize(QSize(0, 0));
        btnExit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(btnExit, 6, 2, 1, 1);

        lblSimulation = new QLabel(centralWidget);
        lblSimulation->setObjectName(QString::fromUtf8("lblSimulation"));

        gridLayout->addWidget(lblSimulation, 3, 0, 1, 1);

        txtSimulationName = new QLineEdit(centralWidget);
        txtSimulationName->setObjectName(QString::fromUtf8("txtSimulationName"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(txtSimulationName->sizePolicy().hasHeightForWidth());
        txtSimulationName->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(txtSimulationName, 3, 1, 1, 1);

        txtConsole = new QTextEdit(centralWidget);
        txtConsole->setObjectName(QString::fromUtf8("txtConsole"));
        txtConsole->setTabChangesFocus(true);
        txtConsole->setReadOnly(true);

        gridLayout->addWidget(txtConsole, 5, 0, 1, 3);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lblLogoEU = new QLabel(centralWidget);
        lblLogoEU->setObjectName(QString::fromUtf8("lblLogoEU"));
        lblLogoEU->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblLogoEU->setOpenExternalLinks(true);

        gridLayout_3->addWidget(lblLogoEU, 0, 0, 1, 1);

        lblLogoDigiGr = new QLabel(centralWidget);
        lblLogoDigiGr->setObjectName(QString::fromUtf8("lblLogoDigiGr"));
        lblLogoDigiGr->setMinimumSize(QSize(66, 0));
        lblLogoDigiGr->setMaximumSize(QSize(66, 16777215));
        lblLogoDigiGr->setAlignment(Qt::AlignCenter);
        lblLogoDigiGr->setOpenExternalLinks(true);

        gridLayout_3->addWidget(lblLogoDigiGr, 0, 1, 1, 1);

        lblLogoEspa = new QLabel(centralWidget);
        lblLogoEspa->setObjectName(QString::fromUtf8("lblLogoEspa"));
        lblLogoEspa->setOpenExternalLinks(true);

        gridLayout_3->addWidget(lblLogoEspa, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 460, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        cmbPrograms->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MultiGUI", 0, QApplication::UnicodeUTF8));
        lblChooseProgram->setText(QApplication::translate("MainWindow", "Choose Program:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmbPrograms->setToolTip(QApplication::translate("MainWindow", "Choose one of the available Programs", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        cmbPrograms->setStatusTip(QApplication::translate("MainWindow", "Choose one of the available Programs", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        cmbPrograms->setWhatsThis(QApplication::translate("MainWindow", "Choose one of the available Programs", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        btnProgParameters->setToolTip(QApplication::translate("MainWindow", "Edit program Parameters", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnProgParameters->setStatusTip(QApplication::translate("MainWindow", "Edit program Parameters", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnProgParameters->setWhatsThis(QApplication::translate("MainWindow", "Edit program Parameters", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        btnProgParameters->setText(QApplication::translate("MainWindow", "Configure Program", 0, QApplication::UnicodeUTF8));
        lblNewEnvironment->setText(QApplication::translate("MainWindow", "Environment Name:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtEnvName->setToolTip(QApplication::translate("MainWindow", "Provide a name for a new Environment and the output files.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        txtEnvName->setStatusTip(QApplication::translate("MainWindow", "Provide a name for a new Environment and the output files.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        txtEnvName->setWhatsThis(QApplication::translate("MainWindow", "Provide a name for a new Environment and the output files.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        btnCreateEnvironment->setToolTip(QApplication::translate("MainWindow", "Create a new Environment", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnCreateEnvironment->setStatusTip(QApplication::translate("MainWindow", "Create a new Environment", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnCreateEnvironment->setWhatsThis(QApplication::translate("MainWindow", "Create a new Environment", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        btnCreateEnvironment->setText(QApplication::translate("MainWindow", "Create", 0, QApplication::UnicodeUTF8));
        lblChooseEnvironment->setText(QApplication::translate("MainWindow", "Choose Environment:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmbEnvironment->setToolTip(QApplication::translate("MainWindow", "Choose one of the available Environments", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        cmbEnvironment->setStatusTip(QApplication::translate("MainWindow", "Choose one of the available Environments", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        cmbEnvironment->setWhatsThis(QApplication::translate("MainWindow", "Choose one of the available Environments", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        btnEnvParams->setToolTip(QApplication::translate("MainWindow", "Edit the Configuration File", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnEnvParams->setStatusTip(QApplication::translate("MainWindow", "Edit the Configuration File", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnEnvParams->setWhatsThis(QApplication::translate("MainWindow", "Edit the Configuration File", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        btnEnvParams->setText(QApplication::translate("MainWindow", "Configure Environment", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnSimParams->setToolTip(QApplication::translate("MainWindow", "Edit command line Parameters", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnSimParams->setStatusTip(QApplication::translate("MainWindow", "Edit command line Parameters", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnSimParams->setWhatsThis(QApplication::translate("MainWindow", "Edit command line Parameters", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        btnSimParams->setText(QApplication::translate("MainWindow", "Configure Simulation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnRun->setToolTip(QApplication::translate("MainWindow", "Run the Simulation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnRun->setStatusTip(QApplication::translate("MainWindow", "Run the Simulation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnRun->setWhatsThis(QApplication::translate("MainWindow", "Run the Simulation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        btnRun->setText(QApplication::translate("MainWindow", "Run Simulation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnExit->setToolTip(QApplication::translate("MainWindow", "Exit MultiGUI", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnExit->setStatusTip(QApplication::translate("MainWindow", "Exit MultiGUI", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        btnExit->setWhatsThis(QApplication::translate("MainWindow", "Exit MultiGUI", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        btnExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        lblSimulation->setText(QApplication::translate("MainWindow", "Simulation Name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtSimulationName->setToolTip(QApplication::translate("MainWindow", "Provide a name for the Simulation and the output directory.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        txtSimulationName->setStatusTip(QApplication::translate("MainWindow", "Provide a name for the Simulation and the output directory.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        txtSimulationName->setWhatsThis(QApplication::translate("MainWindow", "Provide a name for the Simulation and the output directory.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        txtConsole->setToolTip(QApplication::translate("MainWindow", "Console", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        txtConsole->setStatusTip(QApplication::translate("MainWindow", "Console", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        txtConsole->setWhatsThis(QApplication::translate("MainWindow", "Console", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        lblLogoEU->setText(QString());
        lblLogoDigiGr->setText(QString());
        lblLogoEspa->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
