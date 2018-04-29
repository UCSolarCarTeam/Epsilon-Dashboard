#pragma once
#include "I_MotorUi.h"

namespace Ui
{
    class MotorUi;
}
class MotorUi: public I_MotorUi
{
    Q_OBJECT
public:
    explicit MotorUi();
    ~MotorUi();
    QLabel& setCurrentLeftLabel();
    QLabel& setCurrentAvgLabel();
    QLabel& setCurrentRightLabel();
    QLabel& setVelocityLeftLabel();
    QLabel& setVelocityAvgLabel();
    QLabel& setVelocityRightLabel();
    QLabel& busCurrentLeftLabel();
    QLabel& busCurrentAvgLabel();
    QLabel& busCurrentRightLabel();
    QLabel& busVoltageLeftLabel();
    QLabel& busVoltageAvgLabel();
    QLabel& busVoltageRightLabel();
    QLabel& vehicleVelocityLeftLabel();
    QLabel& vehicleVelocityAvgLabel();
    QLabel& vehicleVelocityRightLabel();
    QLabel& phaseCCurrentLeftLabel();
    QLabel& phaseCCurrentAvgLabel();
    QLabel& phaseCCurrentRightLabel();
    QLabel& phaseBCurrentLeftLabel();
    QLabel& phaseBCurrentAvgLabel();
    QLabel& phaseBCurrentRightLabel();
    QLabel& motorVoltageRealLeftLabel();
    QLabel& motorVoltageRealAvgLabel();
    QLabel& motorVoltageRealRightLabel();
    QLabel& motorVoltageImaginaryLeftLabel();
    QLabel& motorVoltageImaginaryAvgLabel();
    QLabel& motorVoltageImaginaryRightLabel();
    QLabel& motorCurrentRealLeftLabel();
    QLabel& motorCurrentRealAvgLabel();
    QLabel& motorCurrentRealRightLabel();
    QLabel& motorCurrentImaginaryLeftLabel();
    QLabel& motorCurrentImaginaryAvgLabel();
    QLabel& motorCurrentImaginaryRightLabel();
    QLabel& backEmfLeftLabel();
    QLabel& backEmfAvgLabel();
    QLabel& backEmfRightLabel();
    QLabel& voltageRail15VSupplyLeftLabel();
    QLabel& voltageRail15VSupplyAvgLabel();
    QLabel& voltageRail15VSupplyRightLabel();
    QLabel& voltageRail3VSupplyLeftLabel();
    QLabel& voltageRail3VSupplyAvgLabel();
    QLabel& voltageRail3VSupplyRightLabel();
    QLabel& voltageRail1VSupplyLeftLabel();
    QLabel& voltageRail1VSupplyAvgLabel();
    QLabel& voltageRail1VSupplyRightLabel();
    QLabel& heatSinkTempLeftLabel();
    QLabel& heatSinkTempAvgLabel();
    QLabel& heatSinkTempRightLabel();
    QLabel& motorTempLeftLabel();
    QLabel& motorTempAvgLabel();
    QLabel& motorTempRightLabel();
    QLabel& dspBoardTempLeftLabel();
    QLabel& dspBoardTempAvgLabel();
    QLabel& dspBoardTempRightLabel();
    QLabel& dcBusAmpHoursLeftLabel();
    QLabel& dcBusAmpHoursAvgLabel();
    QLabel& dcBusAmpHoursRightLabel();
    QLabel& odometerLeftLabel();
    QLabel& odometerAvgLabel();
    QLabel& odometerRightLabel();
    QLabel& slipSpeedLeftLabel();
    QLabel& slipSpeedAvgLabel();
    QLabel& slipSpeedRightLabel();
private:
    Ui::MotorUi* ui_;
};

