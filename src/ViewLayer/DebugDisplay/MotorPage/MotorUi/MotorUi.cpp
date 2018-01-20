#include "MotorUi.h"
#include "ui_MotorUi.h"
MotorUi::MotorUi():
    ui_(new Ui::MotorUi)
{
    ui_->setupUi(this);
}

MotorUi::~MotorUi()
{
    delete ui_;
}

QLabel& MotorUi::titleLabel()
{
    return *ui_->title;
}
