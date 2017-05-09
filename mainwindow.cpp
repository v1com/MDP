#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scene.h"
#include "view.h"
#include <QSplitter>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{

    QSplitter *h1Splitter = new QSplitter;
    QSplitter *h2Splitter = new QSplitter;

    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Horizontal);
    vSplitter->addWidget(h1Splitter);
    vSplitter->addWidget(h2Splitter);

    Scene * leftScene = new Scene(1);
    View * leftView = new View(leftScene, 1);
    leftView->setRenderHint(QPainter::Antialiasing);
    leftView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    leftView->setBackgroundBrush(QColor(255, 255, 255));
    leftView->setWindowTitle("Workspace");

    Scene * rightScene = new Scene(2);
    View * rightView = new View(rightScene, 2);
    rightView->setRenderHint(QPainter::Antialiasing);
    rightView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    rightView->setBackgroundBrush(QColor(255, 255, 255));
    rightView->setWindowTitle("Tools");

    h1Splitter->addWidget(leftView);
    h2Splitter->addWidget(rightView);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(vSplitter);
    setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
