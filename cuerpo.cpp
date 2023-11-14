#include "cuerpo.h"

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
    G = 6.67384*(pow(10,-11));
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
    //float teta = atan((py2_ - PY)/(px2_ - PX));
    //teta = teta*0.01745;

    radio = pow( (pow((px2_- PX),2 ) + pow( (py2_ - PY),2) ),1/2);      //aceleracion de un planeta con respecto a distancia

    //AX = G*masa2(pow(radio,2) * sin(teta));
    //AY = (G*masa2*sin(teta))/pow(radio,2);

    AX = G*masa2*(px2_-PX)/pow(radio,2);
    AY = G*masa2*(py2_-PY)/pow(radio,2);


}

void cuerpo::actualizar(float dt)
{
    PX = PX + (VX*dt) + ((AX*dt*dt)/2);                 // x = xo + vx*t + (ax/2)*t^2
    PY = PY + (VY*dt) + ((AY*dt*dt)/2);                 // y = yo + vy*t + (ay/2)*t^2
    VX = VX + (AX*dt);                                  // vx = vx + ax*t
    VY = VY + (AY*dt);                                  // vy = vy + ay*t
}
