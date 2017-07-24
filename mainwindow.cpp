#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"

#include <QThreadPool>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    worker = new Worker;
    QThreadPool::globalInstance()->start(worker);
}

MainWindow::~MainWindow()
{
    worker->close();
    delete ui;
}

#include <iostream>
void MainWindow::on_send_clicked()
{
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    socket.connect ("tcp://localhost:5555");
    std::cout << ">> server connected" << std::endl;

    zmq::message_t request (5);
    memcpy (request.data (), "Hello", 5);
    std::cout << ">> sending hello" << std::endl;
    socket.send (request);

    zmq::message_t reply;
    socket.recv (&reply);
    std::cout << ">> received world " << std::endl;
}
