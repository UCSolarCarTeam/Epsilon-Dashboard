#pragma once

#include <QObject>

class I_LightsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_LightsData() {}

    virtual bool lowBeams() const = 0;
    virtual bool highBeams() const = 0;
    virtual bool brakes() const = 0;
    virtual bool leftSignal() const = 0;
    virtual bool rightSignal() const = 0;
    virtual bool bmsStrobeLight() const = 0;
    virtual bool alive() const = 0;

    virtual void setlowBeams(bool lowBeams) = 0;
    virtual void sethighBeams(bool highBeams) = 0;
    virtual void setbrakes(bool brakes) = 0;
    virtual void setleftSignal(bool leftSignal) = 0;
    virtual void setrightSignal(bool rightSignal) = 0;
    virtual void setBmsStrobeLight(bool bmsStrobeLight) = 0;
    virtual void setAlive(bool alive) = 0;

signals:
    void lowBeamsReceived(bool lowBeams);
    void highBeamsReceived(bool highBeams);
    void brakesReceived(bool brakes);
    void leftSignalReceived(bool leftSignal);
    void rightSignalReceived(bool rightSignal);
    void bmsStrobeLightReceived(bool bmsStrobeLight);
    void aliveReceived(bool alive);
};
