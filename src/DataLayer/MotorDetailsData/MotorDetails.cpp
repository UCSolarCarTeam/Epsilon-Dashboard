#include "MotorDetails.h"

MotorDetails::MotorDetails()
    : phaseCCurrent_(0)
    , phaseBCurrent_(0)
    , motorVoltageReal_(0)
    , motorVoltageImaginary_(0)
    , motorCurrentReal_(0)
    , motorCurrentImaginary_(0)
    , backEmf_(0)
    , voltageRail15VSupply_(0)
    , voltageRail3VSupply_(0)
    , voltageRail1VSupply_(0)
    , heatSinkTemp_(0)
    , motorTemp_(0)
    , dspBoardTemp_(0)
    , dcBusAmpHours_(0)
    , odometer_(0)
    , slipSpeed_(0)
{
}

double MotorDetails::phaseCCurrent() const
{
    return phaseCCurrent_;
}
double MotorDetails::phaseBCurrent() const
{
    return phaseBCurrent_;
}
double MotorDetails::motorVoltageReal() const
{
    return motorVoltageReal_;
}
double MotorDetails::motorVoltageImaginary() const
{
    return motorVoltageImaginary_;
}
double MotorDetails::motorCurrentReal() const
{
    return motorCurrentReal_;
}
double MotorDetails::motorCurrentImaginary() const
{
    return motorCurrentImaginary_;
}
double MotorDetails::backEmf() const
{
    return backEmf_;
}
double MotorDetails::voltageRail15VSupply() const
{
    return voltageRail15VSupply_;
}
double MotorDetails::voltageRail3VSupply() const
{
    return voltageRail3VSupply_;
}
double MotorDetails::voltageRail1VSupply() const
{
    return voltageRail1VSupply_;
}
double MotorDetails::heatSinkTemp() const
{
    return heatSinkTemp_;
}
double MotorDetails::motorTemp() const
{
    return motorTemp_;
}
double MotorDetails::dspBoardTemp() const
{
    return dspBoardTemp_;
}
double MotorDetails::dcBusAmpHours() const
{
    return dcBusAmpHours_;
}
double MotorDetails::odometer() const
{
    return odometer_;
}
double MotorDetails::slipSpeed() const
{
    return slipSpeed_;
}

void MotorDetails::setPhaseCCurrent(double phaseCCurrent)
{
    phaseCCurrent_ = phaseCCurrent;
}
void MotorDetails::setPhaseBCurrent(double phaseBCurrent)
{
    phaseBCurrent_ = phaseBCurrent;
}
void MotorDetails::setMotorVoltageReal(double motorVoltageReal)
{
    motorVoltageReal_ = motorVoltageReal;
}
void MotorDetails::setMotorVoltageImaginary(double motorVoltageImaginary)
{
    motorVoltageImaginary_ = motorVoltageImaginary;
}
void MotorDetails::setMotorCurrentReal(double motorCurrentReal)
{
    motorCurrentReal_ = motorCurrentReal;
}
void MotorDetails::setMotorCurrentImaginary(double motorCurrentImaginary)
{
    motorCurrentImaginary_ = motorCurrentImaginary;
}
void MotorDetails::setBackEmf(double backEmf)
{
    backEmf_ = backEmf;
}
void MotorDetails::setVoltageRail15VSupply(double voltageRail15VSupply)
{
    voltageRail15VSupply_ = voltageRail15VSupply;
}
void MotorDetails::setVoltageRail3VSupply(double voltageRail3VSupply)
{
    voltageRail3VSupply_ = voltageRail3VSupply;
}
void MotorDetails::setVoltageRail1VSupply(double voltageRail1VSupply)
{
    voltageRail1VSupply_ = voltageRail1VSupply;
}
void MotorDetails::setHeatSinkTemp(double heatSinkTemp)
{
    heatSinkTemp_ = heatSinkTemp;
}
void MotorDetails::setMotorTemp(double motorTemp)
{
    motorTemp_ = motorTemp;
}
void MotorDetails::setDspBoardTemp(double dspBoardTemp)
{
    dspBoardTemp_ = dspBoardTemp;
}
void MotorDetails::setDcBusAmpHours(double dcBusAmpHours)
{
    dcBusAmpHours_ = dcBusAmpHours;
}
void MotorDetails::setOdometer(double odometer)
{
    odometer_ = odometer;
}
void MotorDetails::setSlipSpeed(double slipSpeed)
{
    slipSpeed_ = slipSpeed;
}
