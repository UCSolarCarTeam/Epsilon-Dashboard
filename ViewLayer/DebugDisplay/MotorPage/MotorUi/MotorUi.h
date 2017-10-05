#pragma once
#include "I_MotorUi.h"

namespace Ui
{
    class MotorUi;
}
class MotorUi : public I_MotorUi
{
    Q_OBJECT
public:
    explicit MotorUi();
    ~MotorUi();
    QLabel& setCurrentLeftLabel();
    QLabel& setCurrenttAvgLabel();
    QLabel& setCurrentRightLabel();
    QLabel& setVelocityLeftLabel();
    QLabel& setVelocityAvgLabel();
    QLabel& setVelocityRightLabel();
    QLabel& busCurrentLeftLabel();
    QLabel& busCurrentAvgLabel();
    QLabel& busCurrentRightLabel();
    QLabel& busVelocityLeftLabel();
    QLabel& busVelocityAvgLabel();
    QLabel& busVelocityRightLabel();
    QLabel& vehicleVelocityLeftLabel();
    QLabel& vehicleVelocityAvgLabel();
    QLabel& vehicleVelocityRightLabel();
    QLabel& phaseCCurrentLeftLabe();
    QLabel& phaseCCurrentAvgLabel();
    QLabel& phaseCCurrentRightLabel();
    QLabel& phaseBCurrentLeftLabel();
    QLabel& phaseBCurrentAvgLabel();
    QLabel& phaseBCurrentRIghtLabel();
    QLabel& motorVoltageRealLeftLabel();
    QLabel& motorVoltageRealAvgLabel();
    QLabel& motorVoltageRealRightLabel();
    QLabel& motorVoltageImaginaryLeftLabel();
    QLabel& motorVolategImaginaryAvgLabel();
    QLabel& motorVoltageImaginarRightLabel();
    QLabel& motorCurrentRealLeftLabel();
    QLabel& motorCurrentRealAvgLabel();
    QLabel& motorCurrentRealLeftLabel();
    QLabel& motorCurrentRealRightLabel();
    QLabel& motorCurrentImaginaryLeftLabel();
    QLabel& motorCurrentImaginaryAvgLabel();
    QLabel& motorCurrentImaginaryRightLabel();
    QLabel& backEmfRealLeftLabel();
    QLabel& backEmfRealAvgLabel();
    QLabel& backEmfRealRightLabel();
    QLabel& voltageRail15VSupplyLeftLabel();
    QLabel& voltageRail15VSupplyAvgLabel();
    QLabel& voltageRail15VSupplyRightLabel();
	QLabel& voltageRail3VSupplyLeftLabel();
    QLabel& voltageRail3VSupplyLeftLabel();
    QLabel& voltageRail3VSupplyLeftLabel();
	QLabel& voltageRail1VSupplyLeftLabel();
    QLabel& voltageRail1VSupplyLeftLabel();
    QLabel& voltageRail1VSupplyLeftLabel();
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

