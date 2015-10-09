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
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutputWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *lbl_prog_output;
    QSpacerItem *horizontalSpacer_4;
    QTextEdit *txt_prog_output;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *lbl_sim_output;
    QTextEdit *txt_sim_output;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_close;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OutputWindow)
    {
        if (OutputWindow->objectName().isEmpty())
            OutputWindow->setObjectName(QString::fromUtf8("OutputWindow"));
        OutputWindow->resize(640, 480);
        centralwidget = new QWidget(OutputWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        gridLayoutWidget = new QWidget(splitter);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        lbl_prog_output = new QLabel(gridLayoutWidget);
        lbl_prog_output->setObjectName(QString::fromUtf8("lbl_prog_output"));
        lbl_prog_output->setMaximumSize(QSize(16777215, 20));

        gridLayout_3->addWidget(lbl_prog_output, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        txt_prog_output = new QTextEdit(gridLayoutWidget);
        txt_prog_output->setObjectName(QString::fromUtf8("txt_prog_output"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txt_prog_output->sizePolicy().hasHeightForWidth());
        txt_prog_output->setSizePolicy(sizePolicy);
        txt_prog_output->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier"));
        txt_prog_output->setFont(font);
        txt_prog_output->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(txt_prog_output, 2, 0, 1, 3);

        splitter->addWidget(gridLayoutWidget);
        gridLayoutWidget_2 = new QWidget(splitter);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lbl_sim_output = new QLabel(gridLayoutWidget_2);
        lbl_sim_output->setObjectName(QString::fromUtf8("lbl_sim_output"));

        gridLayout_2->addWidget(lbl_sim_output, 0, 0, 1, 1);

        txt_sim_output = new QTextEdit(gridLayoutWidget_2);
        txt_sim_output->setObjectName(QString::fromUtf8("txt_sim_output"));
        txt_sim_output->setFont(font);
        txt_sim_output->setReadOnly(true);

        gridLayout_2->addWidget(txt_sim_output, 1, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 1, 1, 1);

        btn_close = new QPushButton(gridLayoutWidget_2);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        gridLayout_2->addWidget(btn_close, 2, 2, 1, 1);

        splitter->addWidget(gridLayoutWidget_2);

        verticalLayout->addWidget(splitter);

        OutputWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OutputWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 20));
        OutputWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(OutputWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        OutputWindow->setStatusBar(statusbar);

        retranslateUi(OutputWindow);

        QMetaObject::connectSlotsByName(OutputWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OutputWindow)
    {
        OutputWindow->setWindowTitle(QApplication::translate("OutputWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        lbl_prog_output->setText(QApplication::translate("OutputWindow", "Program Output", 0, QApplication::UnicodeUTF8));
        lbl_sim_output->setText(QApplication::translate("OutputWindow", "Simulator Output", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("OutputWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OutputWindow: public Ui_OutputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTWINDOW_H
