#include "cuerpografico.h"
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "cuerpo.h"

cuerpografico::cuerpografico(float x, float y, float vx, float vy, float m, float r) : escala(0.05)
{
    esf = new cuerpo(x,y,vx,vy,m,r);
}

QRectF cuerpografico::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(), -1*escala*esf->getR(), 2*escala*esf->getR(), 2*escala*esf->getR());
}

void cuerpografico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void cuerpografico::setEscala(float s)
{
    escala = s;
}

void cuerpografico::actualizar(float dt, float sumX, float sumY)
{
    esf->actualizar(dt, sumX, sumY);                                                                // Actualiza el cuerpo en la escena
    setPos( esf->getPX()*escala, esf->getPY()*escala);                                  // asigna el cuerpo a la escena
}

cuerpo *cuerpografico::getEsf()
{
    return esf;                                                                         //Retorna el cuerpo
}
