#include "MotorFaultUi.h"
#include "ui_MotorFaultUi.h"
MotorFaultUi::MotorFaultUi():
    ui_(new Ui::MotorFaultUi)
{
    ui_->setupUi(this);
}

MotorFaultUi::~MotorFaultUi()
{
    delete ui_;
}

QLabel& MotorFaultUi::titleLabel()
{
    return *ui_->title;
}
