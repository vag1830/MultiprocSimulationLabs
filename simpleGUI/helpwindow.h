#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>

namespace Ui {
    class HelpWindow;
}

class HelpWindow : public QDialog
{
    Q_OBJECT

public slots:
    void btn_close_clicked();

public:
    explicit HelpWindow(QWidget *parent = 0);
    ~HelpWindow();

private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
