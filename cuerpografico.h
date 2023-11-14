#ifndef CUERPOGRAFICO_H
#define CUERPOGRAFICO_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "cuerpo.h"

class cuerpografico : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    cuerpografico(float x, float y, float vx, float vy, float m, float r);

    QRectF boundingRect() const;                           //delimitador del cuerpo en la escena

    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget); //  dibujar el cuerpo
    void setEscala(float s);                                               // establece la escala del cuerpo
    void actualizar(float dt);                                             // actualizar el tiempo y posicion

    cuerpo* getEsf();                                                      // Puntero al cuerpo.


private:
    cuerpo *esf;                     // puntero a un objeto de la clase "cuerpo"
    float escala;                    //almacena la escala del cuerpo gráfico.

};

#endif // CUERPOGRAFICO_H
