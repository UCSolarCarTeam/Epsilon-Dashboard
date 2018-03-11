#pragma once

#include <QString>

class MotorDetails
{
public:
    MotorDetails();

    double phaseCCurrent() const;
    double phaseBCurrent() const;
    double motorVoltageReal() const;
    double motorVoltageImaginary() const;
    double motorCurrentReal() const;
    double motorCurrentImaginary() const;
    double backEmf() const;
    double voltageRail15VSupply() const;
    double voltageRail3VSupply() const;
    double voltageRail1VSupply() const;
    double heatSinkTemp() const;
    double motorTemp() const;
    double dspBoardTemp() const;
    double dcBusAmpHours() const;
    double odometer() const;
    double slipSpeed() const;

    void setPhaseCCurrent(double phaseCCurrent);
    void setPhaseBCurrent(double phaseBCurrent);
    void setMotorVoltageReal(double motorVoltageReal);
    void setMotorVoltageImaginary(double motorVoltageImaginary);
    void setMotorCurrentReal(double motorCurrentReal);
    void setMotorCurrentImaginary(double motorCurrentImaginary);
    void setBackEmf(double backEmf);
    void setVoltageRail15VSupply(double voltageRail15VSupply);
    void setVoltageRail3VSupply(double voltageRail3VSupply);
    void setVoltageRail1VSupply(double voltageRail1VSupply);
    void setHeatSinkTemp(double heatSinkTemp);
    void setMotorTemp(double motorTemp);
    void setDspBoardTemp(double dspBoardTemp);
    void setDcBusAmpHours(double dcBusAmpHours);
    void setOdometer(double odometer);
    void setSlipSpeed(double slipSpeed);

private:
    double phaseCCurrent_;
    double phaseBCurrent_;
    double motorVoltageReal_;
    double motorVoltageImaginary_;
    double motorCurrentReal_;
    double motorCurrentImaginary_;
    double backEmf_;
    double voltageRail15VSupply_;
    double voltageRail3VSupply_;
    double voltageRail1VSupply_;
    double heatSinkTemp_;
    double motorTemp_;
    double dspBoardTemp_;
    double dcBusAmpHours_;
    double odometer_;
    double slipSpeed_;
};
