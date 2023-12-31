#include "cuerpo.h"
#include <cmath>

cuerpo::cuerpo(float px_, float py_, float vx_, float vy_, float masa_, float R_)
{
    PX = px_;
    PY = py_;
    VX = vx_;
    VY = vy_;
    masa = masa_;
    R = R_;
    AX = 0;
    AY = 0;
    //G = 6.67384*(pow(10,-11));
    G=1;
    teta = 0;
    radio=0;

}

float cuerpo::getPX() const
{
    return PX;
}

float cuerpo::getPY() const
{
    return PY;
}

float cuerpo::getMasa() const
{
    return masa;
}

float cuerpo::getR() const
{
    return R;
}

void cuerpo::acelerar(float px2_, float py2_, float masa2)
{

    float y = py2_ - PY;
    float x = px2_ - PX;


    teta = atan2(y,x);

    float co = cos(teta);
    float si = sin(teta);

    //radio = pow( (pow((x),2 ) + pow( (y),2) ),1/2);      //aceleracion de un planeta con respecto a distancia

    radio = pow((x*x)+(y*y), 0.5);


    AX = (G*masa2*co)/pow(radio,2);
    AY = (G*masa2*si)/pow(radio,2);

    //AX = G*masa2*(px2_-PX)/pow(radio,2);
    //AY = G*masa2*(py2_-PY)/pow(radio,2);
}

void cuerpo::actualizar(float dt, float sumX, float sumY)
{

    VX = VX + (sumX*dt);                                  // vx = vx + ax*t
    VY = VY + (sumY*dt);                                  // vy = vy + ay*t
    PX = PX + (VX*dt) + ((sumX*dt*dt)/2);                 // x = xo + vx*t + (ax/2)*t^2
    PY = PY + (VY*dt) + ((sumY*dt*dt)/2);                 // y = yo + vy*t + (ay/2)*t^2

    // VX = VX + (sumX*dt);                                  // vx = vx + ax*t
    //VY = VY + (sumY*dt);                                  // vy = vy + ay*t
}

float cuerpo::aceleX()
{
    return AX;
}

float cuerpo::aceleY()
{
    return AY;
}

float cuerpo::angulo()
{
    return teta;
}



