#include "MotorView.h"

MotorView::MotorView(KeyMotorPresenter& keyMotorPresenter, MotorDetailsPresenter& motorDetailsPresenter,
                         I_MotorUi& ui)
    : keyMotorPresenter_(keyMotorPresenter)
    , motorDetailsPresenter_(motorDetailsPresenter)
    , ui_(ui)
{
    connectMotor(keyMotorPresenter_, motorDetailsPresenter_ );
}

MotorView::~MotorView()
{
}

void MotorView::connectMotor(KeyMotorPresenter& keyMotorPresenter, MotorDetailsPresenter& motorDetailsPresenter)
{
    connect(&keyMotorPresenter, SIGNAL(motorZeroReceived(KeyMotor)),
            this, SIGNAL(motorZeroReceived(KeyMotor)));
    connect(&keyMotorPresenter, SIGNAL(motorOneReceived(KeyMotor)),
            this, SIGNAL(motorOneReceived(KeyMotor)));
    connect(&keyMotorPresenter, SIGNAL(motorSetCurrentReceived(double setCurrent)),
            this, SIGNAL(motorSetCurrentReceived(double setCurrent)));
    connect(&keyMotorPresenter, SIGNAL(motorActualSpeedReceived(double actualSpeed)),
            this, SIGNAL(motorActualSpeedReceived(double actualSpeed)));
    connect(&keyMotorPresenter, SIGNAL(motorBusVoltageReceived(double busVoltage)),
            this, SIGNAL(motorBusVoltageReceived(double busVoltage)));
    connect(&keyMotorPresenter, SIGNAL(motorBusCurrentReceived(double busCurrent)),
            this, SIGNAL(motorBusCurrentReceived(double busCurrent)));

    connect(&motorDetailsPresenter, SIGNAL(motorZeroDetailsReceived(MotorDetails)),
            this, SIGNAL(motorZeroDetailsReceived(MotorDetails)));
    connect(&motorDetailsPresenter, SIGNAL(motorOneDetailsReceived(MotorDetails)),
            this, SIGNAL(motorOneDetailsReceived(MotorDetails)));
}


void MotorView::setCurrentLeftReceived(double setCurrentLeft)
{
    ui_.setCurrentLeftLabel().setNum(setCurrentLeft);
}

void MotorView::setCurrentRightReceived(double setCurrentRight)
{
    ui_.setCurrentRightLabel().setNum(setCurrentRight);
}

void MotorView::setCurrentAvg(double setCurrentLeft, double setCurrentRight)
{
    double setCurrentAvg = (setCurrentLeft + setCurrentRight)/2;
    ui_.setCurrentAvgLabel().setNum(setCurrentAvg);
}

void MotorView::setVelocityLeftReceived(double setVelocityLeft)
{
    ui_.setVelocityLeftLabel().setNum(setVelocityLeft);
}

void MotorView::setVelocityRightReceived(double setVelocityRight)
{
    ui_.setVelocityRightLabel().setNum(setVelocityRight);
}

void MotorView::setVelocityAvg(double setVelocityLeft, double setVelocityRight)
{
    double setVelocityAvg = (setVelocityLeft + setVelocityRight)/2;
    ui_.setVelocityAvgLabel().setNum(setVelocityAvg);
}

void MotorView::busCurrentLeftReceived(double busCurrentLeft)
{
    ui_.busCurrentLeftLabel().setNum(busCurrentLeft);
}

void MotorView::busCurrentRightReceived(double busCurrentRight)
{
    ui_.busCurrentRightLabel().setNum(busCurrentRight);
}

void MotorView::busCurrentAvg(double busCurrentLeft, double busCurrentRight)
{
    double busCurrentAvg = (busCurrentLeft + busCurrentRight)/2;
    ui_.busCurrentAvgLabel().setNum(busCurrentAvg);
}

void MotorView::busVoltageLeftReceived(double busVoltageLeft)
{
    ui_.busVoltageLeftLabel().setNum(busVoltageLeft);
}

void MotorView::busVoltageRightReceived(double busVoltageRight)
{
    ui_.busVoltageRightLabel().setNum(busVoltageRight);
}

void MotorView::busVoltageAvg(double busVoltageLeft, double busVoltageRight)
{
    double busVoltageAvg = (busVoltageLeft + busVoltageRight)/2;
    ui_.busVoltageAvgLabel().setNum(busVoltageAvg);
}

void MotorView::vehicleVelocityLeftReceived(double vehicleVelocityLeft)
{
    ui_.vehicleVelocityLeftLabel().setNum(vehicleVelocityLeft);
}

void MotorView::vehicleVelocityRightReceived(double vehicleVelocityRight)
{
    ui_.vehicleVelocityRightLabel().setNum(vehicleVelocityRight);
}

void MotorView::vehicleVelocityAvg(double vehicleVelocityLeft, double vehicleVelocityRight)
{
    double vehicleVelocityAvg = (vehicleVelocityLeft + vehicleVelocityRight)/2;
    ui_.vehicleVelocityAvgLabel().setNum(vehicleVelocityAvg);
}

void MotorView::phaseCCurrentLeftReceived(double phaseCCurrentLeft)
{
    ui_.phaseCCurrentLeftLabel().setNum(phaseCCurrentLeft);
}

void MotorView::phaseCCurrentRightReceived(double phaseCCurrentRight)
{
    ui_.phaseCCurrentRightLabel().setNum(phaseCCurrentRight);
}

void MotorView::phaseCCurrentAvg(double phaseCCurrentLeft, double phaseCCurrentRight)
{
    double phaseCCurrentAvg = (phaseCCurrentLeft + phaseCCurrentRight)/2;
    ui_.phaseCCurrentAvgLabel().setNum(phaseCCurrentAvg);
}

void MotorView::phaseBCurrentLeftReceived(double phaseBCurrentLeft)
{
    ui_.phaseBCurrentLeftLabel().setNum(phaseBCurrentLeft);
}

void MotorView::phaseBCurrentRightReceived(double phaseBCurrentRight)
{
    ui_.phaseBCurrentRightLabel().setNum(phaseBCurrentRight);
}

void MotorView::phaseBCurrentAvg(double phaseBCurrentLeft, double phaseBCurrentRight)
{
    double phaseBCurrentAvg = (phaseBCurrentLeft + phaseBCurrentRight)/2;
    ui_.phaseBCurrentAvgLabel().setNum(phaseBCurrentAvg);
}

void MotorView::motorVoltageRealLeftReceived(double motorVoltageRealLeft)
{
    ui_.motorVoltageRealLeftLabel().setNum(motorVoltageRealLeft);
}

void MotorView::motorVoltageRealRightReceived(double motorVoltageRealRight)
{
    ui_.motorVoltageRealRightLabel().setNum(motorVoltageRealRight);
}

void MotorView::motorVoltageRealAvg(double motorVoltageRealLeft, double motorVoltageRealRight)
{
    double motorVoltageRealAvg = (motorVoltageRealLeft + motorVoltageRealRight)/2;
    ui_.motorVoltageRealAvgLabel().setNum(motorVoltageRealAvg);
}

void MotorView::motorVoltageImaginaryLeftReceived(double motorVoltageImaginaryLeft)
{
    ui_.motorVoltageImaginaryLeftLabel().setNum(motorVoltageImaginaryLeft);
}

void MotorView::motorVoltageImaginaryRightReceived(double motorVoltageImaginaryRight)
{
    ui_.motorVoltageImaginaryRightLabel().setNum(motorVoltageImaginaryRight);
}

void MotorView::motorVoltageImaginaryAvg(double motorVoltageImaginaryLeft, double motorVoltageImaginaryRight)
{
    double motorVoltageImaginaryAvg = (motorVoltageImaginaryLeft + motorVoltageImaginaryRight)/2;
    ui_.motorVoltageImaginaryAvgLabel().setNum(motorVoltageImaginaryAvg);
}

void MotorView::motorCurrentRealLeftReceived(double motorCurrentRealLeft)
{
    ui_.motorCurrentRealLeftLabel().setNum(motorCurrentRealLeft);
}

void MotorView::motorCurrentRealRightReceived(double motorCurrentRealRight)
{
    ui_.motorCurrentRealRightLabel().setNum(motorCurrentRealRight);
}

void MotorView::motorCurrentRealAvg(double motorCurrentRealLeft, double motorCurrentRealRight)
{
    double motorCurrentRealAvg = (motorCurrentRealLeft + motorCurrentRealRight)/2;
    ui_.motorCurrentRealAvgLabel().setNum(motorCurrentRealAvg);
}

void MotorView::motorCurrentImaginaryLeftReceived(double motorCurrentImaginaryLeft)
{
    ui_.motorCurrentImaginaryLeftLabel().setNum(motorCurrentImaginaryLeft);
}

void MotorView::motorCurrentImaginaryRightReceived(double motorCurrentImaginaryRight)
{
    ui_.motorCurrentImaginaryRightLabel().setNum(motorCurrentImaginaryRight);
}

void MotorView::motorCurrentImaginaryAvg(double motorCurrentImaginaryLeft, double motorCurrentImaginaryRight)
{
    double motorCurrentImaginaryAvg = (motorCurrentImaginaryLeft + motorCurrentImaginaryRight)/2;
    ui_.motorCurrentImaginaryAvgLabel().setNum(motorCurrentImaginaryAvg);
}

void MotorView::backEmfRealLeftReceived(double backEmfRealLeft)
{
    ui_.backEmfRealLeftLabel().setNum(backEmfRealLeft);
}

void MotorView::backEmfRealRightReceived(double backEmfRealRight)
{
    ui_.backEmfRealRightLabel().setNum(backEmfRealRight);
}

void MotorView::backEmfRealAvg(double backEmfRealLeft, double backEmfRealRight)
{
    double backEmfRealAvg = (backEmfRealLeft + backEmfRealRight)/2;
    ui_.backEmfRealAvgLabel().setNum(backEmfRealAvg);
}

void MotorView::voltageRail15VSupplyLeftReceived(double voltageRail15VSupplyLeft)
{
    ui_.voltageRail15VSupplyLeftLabel().setNum(voltageRail15VSupplyLeft);
}

void MotorView::voltageRail15VSupplyRightReceived(double voltageRail15VSupplyRight)
{
    ui_.voltageRail15VSupplyRightLabel().setNum(voltageRail15VSupplyRight);
}

void MotorView::voltageRail15VSupplyAvg(double voltageRail15VSupplyLeft, double voltageRail15VSupplyRight)
{
    double voltageRail15VSupplyAvg = (voltageRail15VSupplyLeft + voltageRail15VSupplyRight)/2;
    ui_.voltageRail15VSupplyAvgLabel().setNum(voltageRail15VSupplyAvg);
}

void MotorView::voltageRail3VSupplyLeftReceived(double voltageRail3VSupplyLeft)
{
    ui_.voltageRail3VSupplyLeftLabel().setNum(voltageRail3VSupplyLeft);
}

void MotorView::voltageRail3VSupplyRightReceived(double voltageRail3VSupplyRight)
{
    ui_.voltageRail3VSupplyRightLabel().setNum(voltageRail3VSupplyRight);
}

void MotorView::voltageRail3VSupplyAvg(double voltageRail3VSupplyLeft, double voltageRail3VSupplyRight)
{
    double voltageRail3VSupplyAvg = (voltageRail3VSupplyLeft + voltageRail3VSupplyRight)/2;
    ui_.voltageRail3VSupplyAvgLabel().setNum(voltageRail3VSupplyAvg);
}

void MotorView::voltageRail1VSupplyLeftReceived(double voltageRail1VSupplyLeft)
{
    ui_.voltageRail1VSupplyLeftLabel().setNum(voltageRail1VSupplyLeft);
}

void MotorView::voltageRail1VSupplyRightReceived(double voltageRail1VSupplyRight)
{
    ui_.voltageRail1VSupplyRightLabel().setNum(voltageRail1VSupplyRight);
}

void MotorView::voltageRail1VSupplyAvg(double voltageRail1VSupplyLeft, double voltageRail1VSupplyRight)
{
    double voltageRail1VSupplyAvg = (voltageRail1VSupplyLeft + voltageRail1VSupplyRight)/2;
    ui_.voltageRail1VSupplyAvgLabel().setNum(voltageRail1VSupplyAvg);
}


void MotorView::heatSinkTempLeftReceived(double heatSinkTempLeft)
{
    ui_.heatSinkTempLeftLabel().setNum(heatSinkTempLeft);
}

void MotorView::heatSinkTempRightReceived(double heatSinkTempRight)
{
    ui_.heatSinkTempRightLabel().setNum(heatSinkTempRight);
}

void MotorView::heatSinkTempAvg(double heatSinkTempLeft, double heatSinkTempRight)
{
    double heatSinkTempAvg = (heatSinkTempLeft + heatSinkTempRight)/2;
    ui_.heatSinkTempAvgLabel().setNum(heatSinkTempAvg);
}

void MotorView::motorTempLeftReceived(double motorTempLeft)
{
    ui_.motorTempLeftLabel().setNum(motorTempLeft);
}

void MotorView::motorTempRightReceived(double motorTempRight)
{
    ui_.motorTempRightLabel().setNum(motorTempRight);
}

void MotorView::motorTempAvg(double motorTempLeft, double motorTempRight)
{
    double motorTempAvg = (motorTempLeft + motorTempRight)/2;
    ui_.motorTempAvgLabel().setNum(motorTempAvg);
}

void MotorView::dspBoardTempLeftReceived(double dspBoardTempLeft)
{
    ui_.dspBoardTempLeftLabel().setNum(dspBoardTempLeft);
}

void MotorView::dspBoardTempRightReceived(double dspBoardTempRight)
{
    ui_.dspBoardTempRightLabel().setNum(dspBoardTempRight);
}

void MotorView::dspBoardTempAvg(double dspBoardTempLeft, double dspBoardTempRight)
{
    double dspBoardTempAvg = (dspBoardTempLeft + dspBoardTempRight)/2;
    ui_.dspBoardTempAvgLabel().setNum(dspBoardTempAvg);
}

void MotorView::dcBusAmpHoursLeftReceived(double dcBusAmpHoursLeft)
{
    ui_.dcBusAmpHoursLeftLabel().setNum(dcBusAmpHoursLeft);
}

void MotorView::dcBusAmpHoursRightReceived(double dcBusAmpHoursRight)
{
    ui_.dcBusAmpHoursRightLabel().setNum(dcBusAmpHoursRight);
}

void MotorView::dcBusAmpHoursAvg(double dcBusAmpHoursLeft, double dcBusAmpHoursRight)
{
    double dcBusAmpHoursAvg = (dcBusAmpHoursLeft + dcBusAmpHoursRight)/2;
    ui_.dcBusAmpHoursAvgLabel().setNum(dcBusAmpHoursAvg);
}

void MotorView::odometerLeftReceived(double odometerLeft)
{
    ui_.odometerLeftLabel().setNum(odometerLeft);
}

void MotorView::odometerRightReceived(double odometerRight)
{
    ui_.odometerRightLabel().setNum(odometerRight);
}

void MotorView::odometerAvg(double odometerLeft, double odometerRight)
{
    double odometerAvg = (odometerLeft + odometerRight)/2;
    ui_.odometerAvgLabel().setNum(odometerAvg);
}

void MotorView::slipSpeedLeftReceived(double slipSpeedLeft)
{
    ui_.slipSpeedLeftLabel().setNum(slipSpeedLeft);
}

void MotorView::slipSpeedRightReceived(double slipSpeedRight)
{
    ui_.slipSpeedRightLabel().setNum(slipSpeedRight);
}

void MotorView::slipSpeedAvg(double slipSpeedLeft, double slipSpeedRight)
{
    double slipSpeedAvg = (slipSpeedLeft + slipSpeedRight)/2;
    ui_.slipSpeedAvgLabel().setNum(slipSpeedAvg);
}

