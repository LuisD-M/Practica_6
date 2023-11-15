#ifndef CUERPO_H
#define CUERPO_H

#include <QObject>
#include <cmath>

class cuerpo : public QObject
{
    Q_OBJECT

public:
    cuerpo(float px_, float py_, float vx_, float vy_, float masa_, float R_);   //Constructor para inicializar las variables

    float getPX() const;                                        //Metodos para obtener valores
    float getPY() const;
    float getMasa() const;
    float getR() const;

    void acelerar(float px2_, float py2_, float masa2);                 // aceleración
    void actualizar(float dt, float sumX, float sumY); // actualiza la posición y velocidad
    float aceleX();
    float aceleY();


private:
    float PX;                   // posición eje x
    float PY;                   // posicion eje y
    float VX;                   // velocidad eje x
    float VY;                   // velocidad eje y
    float radio;                // distancia entre dos planetas
    float masa;                 // masa
    float AX;                   // aceleración eje x
    float AY;                   // aceleración eje y
    float G;                    // constante de gravedad.
    float R;                    // radio del planeta

};

#endif // CUERPO_H
