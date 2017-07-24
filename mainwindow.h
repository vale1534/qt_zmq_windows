#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "worker.h"

#include <QMainWindow>
#include <zmq.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_send_clicked();

private:
    Worker *worker;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
