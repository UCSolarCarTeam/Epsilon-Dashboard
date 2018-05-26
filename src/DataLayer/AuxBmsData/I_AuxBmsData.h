#pragma once

#include <QObject>
#include <QString>

class I_AuxBmsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_AuxBmsData() {}

    /* Data "Gets" */
    virtual QString prechargeState() const = 0;
    virtual int auxVoltage() const = 0;
    virtual bool auxBmsAlive() const = 0;
    virtual bool strobeBmsLight() const = 0;
    virtual bool allowCharge() const = 0;
    virtual bool contactorError() const = 0;
    virtual bool highVoltageEnable() const = 0;

    /* Data "Sets" */
    virtual void setPrechargeState(const QString&) = 0;
    virtual void setAuxVoltage(const int&) = 0;
    virtual void setAuxBmsAlive(const bool&) = 0;
    virtual void setStrobeBmsLight(const bool&) = 0;
    virtual void setAllowCharge(const bool&) = 0;
    virtual void setContactorError(const bool&) = 0;
    virtual void setHighVoltageEnable(const bool&) = 0;

signals:
    void prechargeStateReceived(const QString&);
    void auxVoltageReceived(const int&);
    void auxBmsAliveReceived(const bool&);
    void strobeBmsLightRecieved(const bool&);
    void allowChargeRecieved(const bool&);
    void contactorErrorRecieved(const bool&);
    void highVoltageEnableRecieved(const bool&);
};
