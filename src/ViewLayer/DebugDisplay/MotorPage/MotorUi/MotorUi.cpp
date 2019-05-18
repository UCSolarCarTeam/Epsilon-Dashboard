#include "MotorUi.h"
#include "ui_MotorUi.h"
MotorUi::MotorUi():
    ui_(new Ui::MotorUi),
    fontLoader_(new FontLoader)
{
    ui_->setupUi(this);
    QPixmap bkgnd(":/Resources/Background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette background;
    background.setBrush(QPalette::Background, bkgnd);
    this->setPalette(background);
}

MotorUi::~MotorUi()
{
    delete ui_;
}

QLabel& MotorUi::setCurrentLeftLabel()
{
    return *ui_->setCurrentLeftLabel;
}

QLabel& MotorUi::setCurrentAvgLabel()
{
    return *ui_->setCurrentAvgLabel;
}

QLabel& MotorUi::setCurrentRightLabel()
{
    return *ui_->setCurrentRightLabel;
}

QLabel& MotorUi::setVelocityLeftLabel()
{
    return *ui_->setVelocityLeftLabel;
}

QLabel& MotorUi::setVelocityAvgLabel()
{
    return *ui_->setVelocityAvgLabel;
}

QLabel& MotorUi::setVelocityRightLabel()
{
    return *ui_->setVelocityRightLabel;
}

QLabel& MotorUi::busCurrentLeftLabel()
{
    return *ui_->busCurrentLeftLabel;
}

QLabel& MotorUi::busCurrentAvgLabel()
{
    return *ui_->busCurrentAvgLabel;
}

QLabel& MotorUi::busCurrentRightLabel()
{
    return *ui_->busCurrentRightLabel;
}

QLabel& MotorUi::busVoltageLeftLabel()
{
    return *ui_->busVoltageLeftLabel;
}

QLabel& MotorUi::busVoltageAvgLabel()
{
    return *ui_->busVoltageAvgLabel;
}

QLabel& MotorUi::busVoltageRightLabel()
{
    return *ui_->busVoltageRightLabel;
}

QLabel& MotorUi::vehicleVelocityLeftLabel()
{
    return *ui_->vehicleVelocityLeftLabel;
}

QLabel& MotorUi::vehicleVelocityAvgLabel()
{
    return *ui_->vehicleVelocityAvgLabel;
}

QLabel& MotorUi::vehicleVelocityRightLabel()
{
    return *ui_->vehicleVelocityRightLabel;
}

QLabel& MotorUi::phaseCCurrentLeftLabel()
{
    return *ui_->phaseCCurrentLeftLabel;
}

QLabel& MotorUi::phaseCCurrentAvgLabel()
{
    return *ui_->phaseCCurrentAvgLabel;
}

QLabel& MotorUi::phaseCCurrentRightLabel()
{
    return *ui_->phaseCCurrentRightLabel;
}

QLabel& MotorUi::phaseBCurrentLeftLabel()
{
    return *ui_->phaseBCurrentLeftLabel;
}

QLabel& MotorUi::phaseBCurrentAvgLabel()
{
    return *ui_->phaseBCurrentAvgLabel;
}

QLabel& MotorUi::phaseBCurrentRightLabel()
{
    return *ui_->phaseBCurrentRightLabel;
}

QLabel& MotorUi::motorVoltageRealLeftLabel()
{
    return *ui_->motorVoltageRealLeftLabel;
}

QLabel& MotorUi::motorVoltageRealAvgLabel()
{
    return *ui_->motorVoltageRealAvgLabel;
}

QLabel& MotorUi::motorVoltageRealRightLabel()
{
    return *ui_->motorVoltageRealRightLabel;
}

QLabel& MotorUi::motorVoltageImaginaryLeftLabel()
{
    return *ui_->motorVoltageImaginaryLeftLabel;
}

QLabel& MotorUi::motorVoltageImaginaryAvgLabel()
{
    return *ui_->motorVoltageImaginaryAvgLabel;
}

QLabel& MotorUi::motorVoltageImaginaryRightLabel()
{
    return *ui_->motorVoltageImaginaryRightLabel;
}

QLabel& MotorUi::motorCurrentRealLeftLabel()
{
    return *ui_->motorCurrentRealLeftLabel;
}

QLabel& MotorUi::motorCurrentRealAvgLabel()
{
    return *ui_->motorCurrentRealAvgLabel;
}

QLabel& MotorUi::motorCurrentRealRightLabel()
{
    return *ui_->motorCurrentRealRightLabel;
}

QLabel& MotorUi::motorCurrentImaginaryLeftLabel()
{
    return *ui_->motorCurrentImaginaryLeftLabel;
}

QLabel& MotorUi::motorCurrentImaginaryAvgLabel()
{
    return *ui_->motorCurrentImaginaryAvgLabel;
}

QLabel& MotorUi::motorCurrentImaginaryRightLabel()
{
    return *ui_->motorCurrentImaginaryRightLabel;
}

QLabel& MotorUi::backEmfLeftLabel()
{
    return *ui_->backEmfLeftLabel;
}

QLabel& MotorUi::backEmfAvgLabel()
{
    return *ui_->backEmfAvgLabel;
}

QLabel& MotorUi::backEmfRightLabel()
{
    return *ui_->backEmfRightLabel;
}

QLabel& MotorUi::voltageRail15VSupplyLeftLabel()
{
    return *ui_->voltageRail15VSupplyLeftLabel;
}

QLabel& MotorUi::voltageRail15VSupplyAvgLabel()
{
    return *ui_->voltageRail15VSupplyAvgLabel;
}

QLabel& MotorUi::voltageRail15VSupplyRightLabel()
{
    return *ui_->voltageRail15VSupplyRightLabel;
}

QLabel& MotorUi::voltageRail3VSupplyLeftLabel()
{
    return *ui_->voltageRail3VSupplyLeftLabel;
}

QLabel& MotorUi::voltageRail3VSupplyAvgLabel()
{
    return *ui_->voltageRail3VSupplyAvgLabel;
}

QLabel& MotorUi::voltageRail3VSupplyRightLabel()
{
    return *ui_->voltageRail3VSupplyRightLabel;
}

QLabel& MotorUi::voltageRail1VSupplyLeftLabel()
{
    return *ui_->voltageRail1VSupplyLeftLabel;
}

QLabel& MotorUi::voltageRail1VSupplyAvgLabel()
{
    return *ui_->voltageRail1VSupplyAvgLabel;
}

QLabel& MotorUi::voltageRail1VSupplyRightLabel()
{
    return *ui_->voltageRail1VSupplyRightLabel;
}

QLabel& MotorUi::heatSinkTempLeftLabel()
{
    return *ui_->heatSinkTempLeftLabel;
}

QLabel& MotorUi::heatSinkTempAvgLabel()
{
    return *ui_->heatSinkTempAvgLabel;
}

QLabel& MotorUi::heatSinkTempRightLabel()
{
    return *ui_->heatSinkTempRightLabel;
}

QLabel& MotorUi::motorTempLeftLabel()
{
    return *ui_->motorTempLeftLabel;
}

QLabel& MotorUi::motorTempAvgLabel()
{
    return *ui_->motorTempAvgLabel;
}

QLabel& MotorUi::motorTempRightLabel()
{
    return *ui_->motorTempRightLabel;
}

QLabel& MotorUi::dspBoardTempLeftLabel()
{
    return *ui_->dspBoardTempLeftLabel;
}

QLabel& MotorUi::dspBoardTempAvgLabel()
{
    return *ui_->dspBoardTempAvgLabel;
}

QLabel& MotorUi::dspBoardTempRightLabel()
{
    return *ui_->dspBoardTempRightLabel;
}

QLabel& MotorUi::dcBusAmpHoursLeftLabel()
{
    return *ui_->dcBusAmpHoursLeftLabel;
}

QLabel& MotorUi::dcBusAmpHoursAvgLabel()
{
    return *ui_->dcBusAmpHoursAvgLabel;
}

QLabel& MotorUi::dcBusAmpHoursRightLabel()
{
    return *ui_->dcBusAmpHoursRightLabel;
}

QLabel& MotorUi::odometerLeftLabel()
{
    return *ui_->odometerLeftLabel;
}

QLabel& MotorUi::odometerAvgLabel()
{
    return *ui_->odometerAvgLabel;
}

QLabel& MotorUi::odometerRightLabel()
{
    return *ui_->odometerRightLabel;
}

QLabel& MotorUi::slipSpeedLeftLabel()
{
    return *ui_->slipSpeedLeftLabel;
}

QLabel& MotorUi::slipSpeedAvgLabel()
{
    return *ui_->slipSpeedAvgLabel;
}

QLabel& MotorUi::slipSpeedRightLabel()
{
    return *ui_->slipSpeedRightLabel;
}
