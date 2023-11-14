#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QImage>
#include <QPixmap>
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

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    // almacenar las dimensiones de la escena gráfica.
    float dt;
    int alto;
    int ancho;
};
#endif // MAINWINDOW_H
