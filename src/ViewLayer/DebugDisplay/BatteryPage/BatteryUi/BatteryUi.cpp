#include "BatteryUi.h"
#include "ui_BatteryUi.h"
BatteryUi::BatteryUi() :
    ui_(new Ui::BatteryUi)
{
    ui_->setupUi(this);
}

BatteryUi::~BatteryUi()
{
    delete ui_;
}

QLabel& BatteryUi::titleLabel()
{
    return *ui_->title;
}
