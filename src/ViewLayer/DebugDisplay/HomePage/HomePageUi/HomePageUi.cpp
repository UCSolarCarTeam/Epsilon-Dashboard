#include "ui_HomePageUi.h"
#include "HomePageUi.h"
HomePageUi::HomePageUi() :
    ui_(new Ui::HomePageUi)
{
    ui_->setupUi(this);
}

HomePageUi::~HomePageUi()
{
    delete ui_;
}

QPushButton& HomePageUi::batteryButton()
{
    return *ui_->batteryButton;
}

QPushButton& HomePageUi::controlButton()
{
    return *ui_->controlButton;
}

QPushButton& HomePageUi::motorFaultButton()
{
    return *ui_->motorFaultButton;
}

QPushButton& HomePageUi::motorButton()
{
    return *ui_->motorButton;
}

QPushButton& HomePageUi::mpptButton()
{
    return *ui_->MPPT;
}
