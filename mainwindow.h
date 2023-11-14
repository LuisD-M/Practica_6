#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QImage>
#include <QPixmap>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <QImage>
#include <QPixmap>

#include "cuerpo.h"
#include "cuerpografico.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Crear_planeta_clicked();
    void on_Simular_clicked();
    void actualizar();


private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;

    // almacenar las dimensiones de la escena gráfica.
    float dt;
    int alto;
    int ancho;
    QList<cuerpografico*>cuerpos;
};
#endif // MAINWINDOW_H
