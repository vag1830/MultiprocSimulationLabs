#ifndef OUTPUTWINDOW_H
#define OUTPUTWINDOW_H

#include <QMainWindow>

namespace Ui {
    class OutputWindow;
}

class OutputWindow : public QMainWindow
{
    Q_OBJECT

signals:

public slots:
    void btn_close_clicked();
public:
    explicit OutputWindow(QWidget *parent = 0);
    void init( QString );
    ~OutputWindow();

private:
    Ui::OutputWindow *ui;
};

#endif // OUTPUTWINDOW_H
