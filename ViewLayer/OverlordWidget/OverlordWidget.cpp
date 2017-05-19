#include <QVBoxLayout>
#include "OverlordWidget.h"
#include "BatteryUi/I_BatteryUi.h"
#include "ControlUi/I_ControlUi.h"
#include "HomePageUi/I_HomePageUi.h"
#include "MotorFaultUi/I_MotorFaultUi.h"
#include "MotorUi/I_MotorUi.h"
#include "MPPTUi/I_MpptUi.h"
#include "TabUi/I_TabUi.h"
OverlordWidget::OverlordWidget(I_BatteryUi& batteryUi
                               , I_ControlUi& controlUi
                               , I_HomePageUi& homepageUi
                               , I_MotorFaultUi& motorFaultUi
                               , I_MotorUi& motorUi
                               , I_MpptUi& mpptUi
                               , I_TabUi& tabUi
                              )
    : batteryUi_(batteryUi)
    , controlUi_(controlUi)
    , homepageUi_(homepageUi)
    , motorFaultUi_(motorFaultUi)
    , motorUi_(motorUi)
    , mpptUi_(mpptUi)
    , tabUi_(tabUi)
{
    menu_ = new QStackedWidget();
    menu_->addWidget(&homepageUi_);
    menu_->addWidget(&motorUi_);
    menu_->addWidget(&batteryUi_);
    menu_->addWidget(&controlUi_);
    menu_->addWidget(&motorFaultUi_);
    menu_->addWidget(&mpptUi_);
    connect(&homepageUi_.batteryButton(), SIGNAL(clicked()),
            this, SLOT(handleBatteryButtonClicked()));
    connect(&homepageUi_.controlButton(), SIGNAL(clicked()),
            this, SLOT(handleControlButtonClicked()));
    connect(&homepageUi_.motorFaultButton(), SIGNAL(clicked()),
            this, SLOT(handleMotorFaultButtonClicked()));
    connect(&homepageUi_.motorButton(), SIGNAL(clicked()),
            this, SLOT(handleMotorButtonClicked()));
    connect(&homepageUi_.mpptButton(), SIGNAL(clicked()),
            this, SLOT(handleMPPTButtonClicked()));
    connect(&tabUi_.homepageButton(), SIGNAL(clicked()),
            this, SLOT(handleHomepageButtonClicked()));
    connect(&tabUi_.homepageButton(), SIGNAL(clicked()),
            this, SLOT(handleHomepageButtonClicked()));
    connect(&tabUi_.homepageButton(), SIGNAL(clicked()),
            this, SLOT(handleHomepageButtonClicked()));
    connect(&tabUi_.homepageButton(), SIGNAL(clicked()),
            this, SLOT(handleHomepageButtonClicked()));
    connect(&tabUi_.batteryButton(), SIGNAL(clicked()),
            this, SLOT(handleBatteryButtonClicked()));
    connect(&tabUi_.controlButton(), SIGNAL(clicked()),
            this, SLOT(handleControlButtonClicked()));
    connect(&tabUi_.motorButton(), SIGNAL(clicked()),
            this, SLOT(handleMotorButtonClicked()));
    connect(&tabUi_.motorFaultButton(), SIGNAL(clicked()),
            this, SLOT(handleMotorFaultButtonClicked()));
    connect(&tabUi_.mpptButton(), SIGNAL(clicked()),
            this, SLOT(handleMPPTButtonClicked()));
    resize(683, 768);
    QVBoxLayout    *overlordLayout = new QVBoxLayout;
    overlordLayout->setContentsMargins(0,0,0,0);
    overlordLayout->addWidget(&tabUi_);
    overlordLayout->addWidget(menu_);
    tabUi_.hide();
    setLayout(overlordLayout);
    overlordLayout->setSizeConstraint(QLayout::SetNoConstraint);

    show();
}

OverlordWidget::~OverlordWidget()
{

}

void OverlordWidget::handleBatteryButtonClicked()
{
    if(!tabUi_.isVisible())
    {
        tabUi_.show();
    }
    menu_->setCurrentWidget(&batteryUi_);
}
void OverlordWidget::handleControlButtonClicked()
{
    if(!tabUi_.isVisible())
    {
        tabUi_.show();
    }
    menu_->setCurrentWidget(&controlUi_);
}
void OverlordWidget::handleHomepageButtonClicked()
{
    menu_->setCurrentWidget(&homepageUi_);
    if(tabUi_.isVisible())
    {
        tabUi_.hide();
    }
}

void OverlordWidget::handleMotorFaultButtonClicked()
{
    if(!tabUi_.isVisible())
    {
        tabUi_.show();
    }

    menu_->setCurrentWidget(&motorFaultUi_);
}
void OverlordWidget::handleMotorButtonClicked()
{
    if(!tabUi_.isVisible())
    {
        tabUi_.show();
    }
    menu_->setCurrentWidget(&motorUi_);
}
void OverlordWidget::handleMPPTButtonClicked()
{
    if(!tabUi_.isVisible())
    {
        tabUi_.show();
    }
    menu_->setCurrentWidget(&mpptUi_);
}

