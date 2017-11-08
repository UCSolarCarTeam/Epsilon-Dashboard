#include "ControlUi.h"
#include "ui_ControlUi.h"
ControlUi::ControlUi() :
    ui_(new Ui::ControlUi)
{
    ui_->setupUi(this);
}

ControlUi::~ControlUi()
{
    delete ui_;
}

QLabel& ControlUi::titleLabel()
{
    return *ui_->title;
}
