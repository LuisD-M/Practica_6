#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->setupUi(this);
    alto  = 975;      //457
    ancho = 457;      //975
    dt = 0.1;

    scene = new QGraphicsScene(this);
    scene->setSceneRect(-alto/2,-ancho/2,alto,ancho);

    setStyleSheet("MainWindow {background-image:url(:/Espacio.png)}");

    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Crear_planeta_clicked()
{

}


void MainWindow::on_Simular_clicked()
{

}

