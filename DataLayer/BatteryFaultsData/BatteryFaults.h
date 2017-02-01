#pragma once

#include <QString>

class BatteryFaults
{
public:
    BatteryFaults();

    virtual ~BatteryFaults();

    bool cellOverVoltage() const;
    bool cellUnderVoltage() const;
    bool cellOverTemperature() const;
    bool measurementUntrusted() const;
    bool CMUCOMMTIMEOUT() const;
    bool vehicleCommTimeout() const;
    bool bmuIsInSetupMode() const;
    bool cmuCanBusPowerStatus() const;
    bool packIsolationTestFailure() const;
    bool softwareOverCurrentMeasured() const;
    bool canSupplyIsLow() const;
    bool contactorIsStuck() const;
    bool cmuDetectedExtraCellPresent() const;

    void setCellOverVoltage(bool cellOverVoltage);
    void setCellUnderVoltage(bool cellUnderVoltage);
    void setCellOverTemperature(bool cellOverTemperature);
    void setMeasurementUntrusted(bool measurementUntrusted);
    void setCMUCOMMTIMEOUT(bool CMUCOMMTIMEOUT);
    void setVehicleCommTimeout(bool vehicleCommTimeout);
    void setBmuIsInSetupMode(bool bmuIsInSetupMode);
    void setCmuCanBusPowerStatus(bool cmuCanBusPowerStatus);
    void setPackIsolationTestFailure(bool packIsolationTestFailure);
    void setSoftwareOverCurrentMeasured(bool softwareOverCurrentMeasured);
    void setCanSupplyIsLow(bool canSupplyIsLow);
    void setContactorIsStuck(bool contactorIsStuck);
    void setCmuDetectedExtraCellPresent(bool cmuDetectedExtraCellPresent);

private:
    bool cellOverVoltage_;
    bool cellUnderVoltage_;
    bool cellOverTemperature_;
    bool measurementUntrusted_;
    bool CMUCOMMTIMEOUT_;
    bool vehicleCommTimeout_;
    bool bmuIsInSetupMode_;
    bool cmuCanBusPowerStatus_;
    bool packIsolationTestFailure_;
    bool softwareOverCurrentMeasured_;
    bool canSupplyIsLow_;
    bool contactorIsStuck_;
    bool cmuDetectedExtraCellPresent_;
};
