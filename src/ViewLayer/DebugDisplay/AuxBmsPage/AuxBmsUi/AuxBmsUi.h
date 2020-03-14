#pragma once
#include "I_AuxBmsUi.h"

namespace Ui
{
    class AuxBmsUi;
}

class AuxBmsUi : public I_AuxBmsUi
{
    Q_OBJECT
public:
    explicit AuxBmsUi();
    ~AuxBmsUi();

private:
    Ui::AuxBmsUi* ui_;

    // I_AuxBmsUi interface
public:
    QWidget& alive() override;
    QLabel& voltage() override;
    QLabel& prechargeState() override;
    QLabel& allowCharge() override;
    QLabel& strobeBms() override;
    QLabel& chargeTripHighTemperatureCurrent() override;
    QLabel& chargeTripHighVoltage() override;
    QLabel& chargeTripPackCurrent() override;
    QLabel& dischargeTripPackCurrent() override;
    QLabel& dischargeTripHighTemperatureCurrent() override;
    QLabel& dischargeTripLowVoltage() override;
    QLabel& protectionTrip() override;
    QLabel& highVoltageEnableState() override;
    QLabel& allowDischarge() override;
    QLabel& orionCanReceivedRecently() override;
    QLabel& chargeContactorError() override;
    QLabel& dischargeContactorError() override;
    QLabel& commonContactorError() override;
    QLabel& dischargeShouldTrip() override;
    QLabel& chargeShouldTrip() override;
    QLabel& chargeOpenButShouldBeClosed() override;
    QLabel& dischargeOpenButShouldBeClosed() override;
};
