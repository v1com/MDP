#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Test 4
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
