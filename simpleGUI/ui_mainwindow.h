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
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_exit;
    QAction *action_open_c_file;
    QAction *action_help;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btn_edit;
    QTextEdit *txt_c_file;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lbl_c_file;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QComboBox *cmb_simulators;
    QPushButton *btn_edit_params;
    QTextEdit *txt_simulator;
    QPushButton *btn_run;
    QGridLayout *gridLayout_3;
    QLabel *lblLogoEU;
    QLabel *lblLogoDigiGr;
    QLabel *lblLogoEspa;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QMenu *menuHelp;
    QMenu *menuFile;
    QMenu *menuOpen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(408, 523);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(240, 360));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_open_c_file = new QAction(MainWindow);
        action_open_c_file->setObjectName(QString::fromUtf8("action_open_c_file"));
        action_help = new QAction(MainWindow);
        action_help->setObjectName(QString::fromUtf8("action_help"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(240, 360));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        gridLayoutWidget = new QWidget(splitter);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_edit = new QPushButton(gridLayoutWidget);
        btn_edit->setObjectName(QString::fromUtf8("btn_edit"));

        gridLayout->addWidget(btn_edit, 0, 3, 1, 1);

        txt_c_file = new QTextEdit(gridLayoutWidget);
        txt_c_file->setObjectName(QString::fromUtf8("txt_c_file"));
        txt_c_file->setSizeIncrement(QSize(0, 0));
        txt_c_file->setBaseSize(QSize(0, 0));
        txt_c_file->setContextMenuPolicy(Qt::DefaultContextMenu);
        txt_c_file->setReadOnly(true);

        gridLayout->addWidget(txt_c_file, 1, 0, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        lbl_c_file = new QLabel(gridLayoutWidget);
        lbl_c_file->setObjectName(QString::fromUtf8("lbl_c_file"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_c_file->sizePolicy().hasHeightForWidth());
        lbl_c_file->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lbl_c_file, 0, 0, 1, 1);

        splitter->addWidget(gridLayoutWidget);
        gridLayoutWidget_2 = new QWidget(splitter);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        cmb_simulators = new QComboBox(gridLayoutWidget_2);
        cmb_simulators->setObjectName(QString::fromUtf8("cmb_simulators"));

        gridLayout_2->addWidget(cmb_simulators, 0, 2, 1, 1);

        btn_edit_params = new QPushButton(gridLayoutWidget_2);
        btn_edit_params->setObjectName(QString::fromUtf8("btn_edit_params"));

        gridLayout_2->addWidget(btn_edit_params, 0, 3, 1, 1);

        txt_simulator = new QTextEdit(gridLayoutWidget_2);
        txt_simulator->setObjectName(QString::fromUtf8("txt_simulator"));
        txt_simulator->setReadOnly(true);

        gridLayout_2->addWidget(txt_simulator, 1, 0, 1, 4);

        btn_run = new QPushButton(gridLayoutWidget_2);
        btn_run->setObjectName(QString::fromUtf8("btn_run"));

        gridLayout_2->addWidget(btn_run, 2, 3, 1, 1);

        splitter->addWidget(gridLayoutWidget_2);

        verticalLayout_2->addWidget(splitter);

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
        sizePolicy.setHeightForWidth(lblLogoDigiGr->sizePolicy().hasHeightForWidth());
        lblLogoDigiGr->setSizePolicy(sizePolicy);
        lblLogoDigiGr->setMinimumSize(QSize(66, 0));
        lblLogoDigiGr->setMaximumSize(QSize(66, 16777215));
        lblLogoDigiGr->setAlignment(Qt::AlignCenter);
        lblLogoDigiGr->setOpenExternalLinks(true);

        gridLayout_3->addWidget(lblLogoDigiGr, 0, 1, 1, 1);

        lblLogoEspa = new QLabel(centralWidget);
        lblLogoEspa->setObjectName(QString::fromUtf8("lblLogoEspa"));
        lblLogoEspa->setOpenExternalLinks(true);

        gridLayout_3->addWidget(lblLogoEspa, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 408, 20));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setTearOffEnabled(false);
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(action_help);
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(action_exit);
        menuOpen->addAction(action_open_c_file);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SimpleGUI", 0, QApplication::UnicodeUTF8));
        action_exit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        action_exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_open_c_file->setText(QApplication::translate("MainWindow", ".c file", 0, QApplication::UnicodeUTF8));
        action_open_c_file->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        action_help->setText(QApplication::translate("MainWindow", "parameter <config>", 0, QApplication::UnicodeUTF8));
        action_help->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        btn_edit->setText(QApplication::translate("MainWindow", "edit", 0, QApplication::UnicodeUTF8));
        lbl_c_file->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Choose Simulator", 0, QApplication::UnicodeUTF8));
        btn_edit_params->setText(QApplication::translate("MainWindow", "Edit Parameters", 0, QApplication::UnicodeUTF8));
        btn_run->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        lblLogoEU->setText(QApplication::translate("MainWindow", "<a href='http://www.google.com'></a>", 0, QApplication::UnicodeUTF8));
        lblLogoDigiGr->setText(QApplication::translate("MainWindow", "<a href='http://www.google.com'></a>", 0, QApplication::UnicodeUTF8));
        lblLogoEspa->setText(QApplication::translate("MainWindow", "<a href='http://www.google.com'></a>", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuOpen->setTitle(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
