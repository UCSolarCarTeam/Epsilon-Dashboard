#pragma once

#include <QWidget>

class QLabel;

class I_AuxBmsUi : public QWidget
{
    Q_OBJECT
public:
    virtual ~I_AuxBmsUi() {}
    virtual QWidget& alive() = 0;
    //Info
    virtual QLabel& voltage() = 0;
    virtual QLabel& prechargeState() = 0;
    //Statuses
    virtual QLabel& allowCharge() = 0;
    virtual QLabel& strobeBms() = 0;
    virtual QLabel& chargeTripHighTemperatureCurrent() = 0;
    virtual QLabel& chargeTripHighVoltage() = 0;
    virtual QLabel& chargeTripPackCurrent() = 0;
    virtual QLabel& dischargeTripPackCurrent() = 0;
    virtual QLabel& dischargeTripHighTemperatureCurrent() = 0;
    virtual QLabel& dischargeTripLowVoltage() = 0;
    virtual QLabel& protectionTrip() = 0;
    virtual QLabel& highVoltageEnableState() = 0;
    virtual QLabel& allowDischarge() = 0;
    virtual QLabel& orionCanReceivedRecently() = 0;
    virtual QLabel& chargeContactorError() = 0;
    virtual QLabel& dischargeContactorError() = 0;
    virtual QLabel& commonContactorError() = 0;
    virtual QLabel& dischargeShouldTrip() = 0;
    virtual QLabel& chargeShouldTrip() = 0;
    virtual QLabel& chargeOpenButShouldBeClosed() = 0;
    virtual QLabel& dischargeOpenButShouldBeClosed() = 0;
};
