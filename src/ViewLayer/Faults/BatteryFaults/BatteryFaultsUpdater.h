#pragma once

#include <QObject>
#include "../DataLayer/BatteryFaultsData/BatteryErrorFlags.h"
#include "../DataLayer/BatteryFaultsData/BatteryLimitFlags.h"

class I_BatteryFaultList;
class BatteryFaultsPresenter;
class AuxBmsPresenter;

class BatteryFaultsUpdater : public QObject
{
    Q_OBJECT
public:
    BatteryFaultsUpdater(const BatteryFaultsPresenter& batteryFaultsPresenter,
                         const AuxBmsPresenter& auxBmsPresenter,
                         I_BatteryFaultList& faultList);

private slots:
    void errorFlagsReceived(BatteryErrorFlags);
    void limitFlagsReceived(BatteryLimitFlags);

    void chargeContactorErrorReceived(const bool chargeContactorError);
    void dischargeContactorErrorReceived(const bool dischargeContactorError);
    void commonContactorErrorReceived(const bool commonContactorError);
    void chargeTripHighTemperatureCurrentReceived(const bool chargeTripHighTemperatureCurrent);
    void chargeTripHighVoltageReceived(const bool chargeTripHighVoltage);
    void chargeTripPackCurrentReceived(const bool chargeTripPackCurrent);
    void dischargeTripPackCurrentReceived(const bool dischargeTripPackCurrent);
    void dischargeTripHighTemperatureCurrentReceived(const bool dischargeTripHighTemperatureCurrent);
    void dischargeTripLowVoltageReceived(const bool dischargeTripLowVoltage);
    void protectionTripReceived(const bool protectionTrip);
    void tripContactorDisconnectedUnexpectedlyReceived(const bool tripContactorDisconnectedUnexpectedly);
    void tripOrionMessageTimeoutReceived(const bool tripOrionMessageTimeout);
    void dischargeNotClosedHighCurrentReceived(const bool dischargeNotClosedHighCurrent);
    void chargeNotClosedHighCurrentReceived(const bool chargeNotClosedHighCurrent);

private:
    void connectAuxBmsTrips(const AuxBmsPresenter& auxBmsPresenter);
    const BatteryFaultsPresenter& batteryFaultsPresenter_;
    const AuxBmsPresenter& auxBmsPresenter_;
    I_BatteryFaultList& faultList_;

};
