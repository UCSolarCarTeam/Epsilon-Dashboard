#include "AuxBmsUi.h"
#include "ui_AuxBmsUi.h"

AuxBmsUi::AuxBmsUi() :
    ui_(new Ui::AuxBmsUi)
{
    ui_->setupUi(this);
    QPixmap bkgnd(":/Resources/Background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette background;
    background.setBrush(QPalette::Background, bkgnd);
    this->setPalette(background);
}

AuxBmsUi::~AuxBmsUi()
{
    delete ui_;
}

QWidget& AuxBmsUi::alive()
{
    return *ui_->auxBmsAliveIcon;
}

QLabel& AuxBmsUi::voltage()
{
    return *ui_->auxVoltage;
}

QLabel& AuxBmsUi::prechargeState()
{
    return *ui_->prechargeState;
}

QLabel& AuxBmsUi::allowCharge()
{
    return *ui_->allowCharge;
}

QLabel& AuxBmsUi::strobeBms()
{
    return *ui_->strobeBms;
}

QLabel& AuxBmsUi::chargeTripHighTemperatureCurrent()
{
    return *ui_->chargeTripHighTemperatureCurrent;
}

QLabel& AuxBmsUi::chargeTripHighVoltage()
{
    return *ui_->chargeTripHighVoltage;
}

QLabel& AuxBmsUi::chargeTripPackCurrent()
{
    return *ui_->chargeTripPackCurrent;
}

QLabel& AuxBmsUi::dischargeTripPackCurrent()
{
    return *ui_->dischargeTripPackCurrent;
}

QLabel& AuxBmsUi::dischargeTripHighTemperatureCurrent()
{
    return *ui_->dischargeTripHighTemperatureCurrent;
}

QLabel& AuxBmsUi::dischargeTripLowVoltage()
{
    return *ui_->dischargeTripLowVoltage;
}

QLabel& AuxBmsUi::protectionTrip()
{
    return *ui_->protectionTrip;
}

QLabel& AuxBmsUi::highVoltageEnableState()
{
    return *ui_->highVoltageEnableState;
}

QLabel& AuxBmsUi::allowDischarge()
{
    return *ui_->allowDischarge;
}

QLabel& AuxBmsUi::orionCanReceivedRecently()
{
    return *ui_->orionCanReceivedRecently;
}

QLabel& AuxBmsUi::chargeContactorError()
{
    return *ui_->chargeContactorError;
}

QLabel& AuxBmsUi::dischargeContactorError()
{
    return *ui_->dischargeContactorError;
}

QLabel& AuxBmsUi::commonContactorError()
{
    return *ui_->commonContactorError;
}

QLabel& AuxBmsUi::dischargeShouldTrip()
{
    return *ui_->dischargeShouldTrip;
}

QLabel& AuxBmsUi::chargeShouldTrip()
{
    return *ui_->chargeShouldTrip;
}

QLabel& AuxBmsUi::chargeOpenButShouldBeClosed()
{
    return *ui_->chargeOpenButShouldBeClosed;
}

QLabel& AuxBmsUi::dischargeOpenButShouldBeClosed()
{
    return *ui_->dischargeOpenButShouldBeClosed;
}

QLabel& AuxBmsUi::tripContactorDisconnectedUnexpectedly()
{
    return *ui_->tripContactorDisconnectedUnexpectedly;
}

QLabel& AuxBmsUi::tripOrionMessageTimeout()
{
    return *ui_->tripOrionMessageTimeout;
}

QLabel& AuxBmsUi::dischargeNotClosedHighCurrent()
{
    return *ui_->dischargeNotClosedHighCurrent;
}

QLabel& AuxBmsUi::chargeNotClosedHighCurrent()
{
    return *ui_->chargeNotClosedHighCurrent;
}
