# pragma once

#include <QObject>

class I_AuxBmsData;

class AuxBmsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit AuxBmsPresenter(const I_AuxBmsData& auxBmsData);

private:
    void relayAuxBmsData();

    const I_AuxBmsData& auxBmsData_;

signals:
    void prechargeStateReceived(const QString&);
    void auxVoltageReceived(const int&);
    void auxBmsAliveReceived(const bool&);
    void strobeBmsLightReceived(const bool&);
    void allowChargeReceieved(const bool&);
    void contactorErrorReceieved(const bool&);
};
