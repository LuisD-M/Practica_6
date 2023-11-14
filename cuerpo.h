#ifndef CUERPO_H
#define CUERPO_H

#include <QObject>

class cuerpo : public QObject
{
    Q_OBJECT
public:
    explicit cuerpo(QObject *parent = nullptr);

signals:

};

#endif // CUERPO_H
