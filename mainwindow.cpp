#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    alto  = 975;      //457
    ancho = 457;      //975
    dt = 0.1;

    scene = new QGraphicsScene(this);
    scene->setSceneRect(-alto/2,-ancho/2,alto,ancho);

    setStyleSheet("MainWindow {background-image:url(:/Espacio.png)}");

    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();

    timer = new QTimer(this);

    timer->stop();
    connect(timer,SIGNAL(timeout()),this, SLOT(actualizar()));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete scene;
}

void MainWindow::on_Crear_planeta_clicked()
{
    float posx = ui->Posicionx->text().toFloat();                          //Se toman los valores de la interfaz
    float posy = ui->Posiciony->text().toFloat();
    float masa = ui->Masa->text().toFloat();
    float radio = ui->Radio->text().toFloat();
    float velx = ui->Velocidadx->text().toFloat();
    float vely = ui->Velocidady->text().toFloat();

    cuerpos.append(new cuerpografico(posx,posy,velx,vely,masa,radio));                // crea nuevo objeto con los datos
    scene->addItem(cuerpos.back());
    cuerpos.back()->actualizar(dt);                                                // Al ultimo ingresado lo actualiza

    ui->Posicionx->clear();                                                     //Limpiar los datos para nuevo ingreso
    ui->Posiciony->clear();
    ui->Masa->clear();
    ui->Radio->clear();
    ui->Velocidadx->clear();
    ui->Velocidady->clear();
}


void MainWindow::on_Simular_clicked()
{
    timer->start(dt);
}

void MainWindow::actualizar()
{
    for (int i = 0 ; i < cuerpos.size() ; i++  ) {      //Recorre lista para calcular aceleracion de los cuerpos
        for (int j = 0 ; j < cuerpos.size() ; j++ ) {
            if (i != j){
                cuerpos.at(i)->getEsf()->acelerar(cuerpos.at(j)->getEsf()->getPX(),cuerpos.at(j)->getEsf()->getPY(),cuerpos.at(j)->getEsf()->getMasa());
                cuerpos.at(i)->actualizar(dt);          //aqui
            }
        }
    }
}


