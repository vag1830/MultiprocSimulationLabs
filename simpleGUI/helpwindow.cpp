#include "helpwindow.h"
#include "ui_helpwindow.h"
#include "reader.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    Reader reader( "help/general.hlp");
    ui->setupUi(this);

    for(int i = 0; i < reader.getOutput().size(); i++ )
        ui->lbl_help->setText( ui->lbl_help->text() + reader.getOutput()[i] + "\n" );
    connect( ui->btn_close, SIGNAL( clicked() ), this, SLOT( btn_close_clicked() ) );
}

void HelpWindow::btn_close_clicked()
{
    this->close();
}



HelpWindow::~HelpWindow()
{
    delete ui;
}
