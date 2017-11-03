#include "MotorFaultView.h"

MotorFaultView::MotorFaultView(MotorFaultsPresenter& motorFaultsPresenter,
                               BatteryFaultsPresenter& batteryFaultsPresenter,
                               I_MotorFaultUi& ui)
    : motorFaultsPresenter_(motorFaultsPresenter)
    , batteryFaultsPresenter_(batteryFaultsPresenter)
    , ui_(ui)
    , badMotorPositionHallSequenceFault_(new QLabel())
    , configReadErrorFault_(new QLabel())
    , dcBusOverVoltageFault_(new QLabel())
    , desaturationFaultFault_(new QLabel())
    , motorOverSpeedFault_(new QLabel())
    , railUnderVoltageLockOutFault_(new QLabel())
    , watchdogCausedLastResetFault_(new QLabel())
{
    QLayout *layout = ui_.motor0ContentsWidget().layout();
    int current_width = ui_.motor0ContentsWidget().size().width();
//    int current_height = ui_.motor0ContentsWidget().size().height();
//    ui_.motor0ContentsWidget().resize(current_width, current_height + 25 * );

    badMotorPositionHallSequenceFault_.resize(current_width, 25);
    badMotorPositionHallSequenceFault_.setText("Bad Motor Posision Hall Sequence");
    badMotorPositionHallSequenceFault_.setStyleSheet("font: 14px 'Arial';\nfont-weight:500;color:red;");
    configReadErrorFault_.setFixedSize(current_width, 25);
    layout->addWidget(&badMotorPositionHallSequenceFault_);
    badMotorPositionHallSequenceFault_.hide();

    configReadErrorFault_.resize(current_width, 25);
    configReadErrorFault_.setText("Config Read Error");
    configReadErrorFault_.setStyleSheet("font: 14px 'Arial';\nfont-weight:500;color:red;");
    configReadErrorFault_.setFixedSize(current_width, 25);
    layout->addWidget(&configReadErrorFault_);
    configReadErrorFault_.hide();

    dcBusOverVoltageFault_.resize(current_width, 25);
    dcBusOverVoltageFault_.setText("DC Bus Over Voltage");
    dcBusOverVoltageFault_.setStyleSheet("font: 14px 'Arial';\nfont-weight:500;color:red;");
    dcBusOverVoltageFault_.setFixedSize(current_width, 25);
    layout->addWidget(&dcBusOverVoltageFault_);
    dcBusOverVoltageFault_.hide();

    desaturationFaultFault_.resize(current_width, 25);
    desaturationFaultFault_.setText("Desaturation Fault");
    desaturationFaultFault_.setStyleSheet("font: 14px 'Arial';\nfont-weight:500;color:red;");
    desaturationFaultFault_.setFixedSize(current_width, 25);
    layout->addWidget(&desaturationFaultFault_);
    desaturationFaultFault_.hide();

    motorOverSpeedFault_.resize(current_width, 25);
    motorOverSpeedFault_.setText("Motor Over Speed");
    motorOverSpeedFault_.setStyleSheet("font: 14px 'Arial';\nfont-weight:500;color:red;");
    motorOverSpeedFault_.setFixedSize(current_width, 25);
    layout->addWidget(&motorOverSpeedFault_);
    motorOverSpeedFault_.hide();

    railUnderVoltageLockOutFault_.resize(current_width, 25);
    railUnderVoltageLockOutFault_.setText("Rail Under Voltage Lockout");
    railUnderVoltageLockOutFault_.setStyleSheet("font: 14px 'Arial';\nfont-weight:500;color:red;");
    railUnderVoltageLockOutFault_.setFixedSize(current_width, 25);
    layout->addWidget(&railUnderVoltageLockOutFault_);
    railUnderVoltageLockOutFault_.hide();

    watchdogCausedLastResetFault_.resize(current_width, 25);
    watchdogCausedLastResetFault_.setText("Watchdog Caused Last Reset");
    watchdogCausedLastResetFault_.setStyleSheet("font: 14px 'Arial';\nfont-weight:500;color:red;");
    watchdogCausedLastResetFault_.setFixedSize(current_width, 25);
    layout->addWidget(&watchdogCausedLastResetFault_);
    watchdogCausedLastResetFault_.hide();

    ui_.motor0ContentsWidget().setLayout(layout);

    connectMotorFaults(motorFaultsPresenter_);
    connectBatteryFaults(batteryFaultsPresenter_);

    ErrorFlags errorflags;
    errorflags.setBadMotorPositionHallSequence(true);
    errorflags.setConfigReadError(true);
    errorflags.setDcBusOverVoltage(true);
    errorflags.setDesaturationFault(true);
    errorflags.setMotorOverSpeed(true);
    errorflags.setRailUnderVoltageLockOut(true);
    errorflags.setSoftwareOverCurrent(true);
    errorflags.setWatchdogCausedLastReset(true);

    motorZeroErrorFlagsReceived(errorflags);
}

MotorFaultView::~MotorFaultView()
{
}

void MotorFaultView::connectMotorFaults(MotorFaultsPresenter& motorFaultsPresenter)
{
    connect(&motorFaultsPresenter, SIGNAL(motorZeroErrorFlagsReceived(ErrorFlags)),
            this, SLOT(motorZeroErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorZeroLimitFlagsReceived(LimitFlags)),
            this, SLOT(motorZeroLimitFlagsReceived(LimitFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorOneErrorFlagsReceived(ErrorFlags)),
            this, SLOT(motorOneErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)),
            this, SLOT(motorOneLimitFlagsReceived(LimitFlags)));
}

void MotorFaultView::connectBatteryFaults(BatteryFaultsPresenter& batteryFaultsPresenter)
{
    connect(&batteryFaultsPresenter, SIGNAL(errorFlagsReceived(BatteryErrorFlags)),
            this, SLOT(errorFlagsReceived(BatteryErrorFlags)));
    connect(&batteryFaultsPresenter, SIGNAL(limitFlagsReceived(BatteryLimitFlags)),
            this, SLOT(limitFlagsReceived(BatteryLimitFlags)));
}

void MotorFaultView::motorZeroErrorFlagsReceived(ErrorFlags motorZeroErrorFlags)
{
    static bool badMotorPositionHallSequenceOn = false;
    static bool configReadErrorOn = false;
    static bool dcBusOverVoltageOn = false;
    static bool desaturationFaultOn = false;
    static bool motorOverSpeedOn = false;
    static bool railUnderVoltageLockOutOn = false;
    static bool watchdogCausedLastReset = false;


    if(motorZeroErrorFlags.badMotorPositionHallSequence())
    {
        if (!badMotorPositionHallSequenceOn)
        {
            badMotorPositionHallSequenceOn = true;
            badMotorPositionHallSequenceFault_.show();
        }
    }
    else if (!motorZeroErrorFlags.badMotorPositionHallSequence())
    {
        if (badMotorPositionHallSequenceOn)
        {
            badMotorPositionHallSequenceOn = false;
            badMotorPositionHallSequenceFault_.hide();
        }
    }

    if (motorZeroErrorFlags.configReadError())
    {
        if (!configReadErrorOn)
        {
            configReadErrorOn = true;
            configReadErrorFault_.show();
        }
    }
    else if (!motorZeroErrorFlags.configReadError())
    {
        if (configReadErrorOn)
        {
            configReadErrorOn = false;
            configReadErrorFault_.hide();
        }
    }

    if (motorZeroErrorFlags.dcBusOverVoltage())
    {
        if (!dcBusOverVoltageOn)
        {
            dcBusOverVoltageOn = true;
            dcBusOverVoltageFault_.show();
        }
    }
    else if (!motorZeroErrorFlags.dcBusOverVoltage())
    {
        if (dcBusOverVoltageOn)
        {
            dcBusOverVoltageOn = false;
            dcBusOverVoltageFault_.hide();
        }
    }

    if (motorZeroErrorFlags.desaturationFault())
    {
        if (!desaturationFaultOn)
        {
            desaturationFaultOn = true;
            desaturationFaultFault_.show();
        }
    }
    else if (!motorZeroErrorFlags.desaturationFault())
    {
        if (desaturationFaultOn)
        {
            desaturationFaultOn = false;
            desaturationFaultFault_.hide();
        }
    }

    if (motorZeroErrorFlags.motorOverSpeed())
    {
        if (!motorOverSpeedOn)
        {
            motorOverSpeedOn = true;
            motorOverSpeedFault_.show();
        }
    }
    else if (!motorZeroErrorFlags.motorOverSpeed())
    {
        if (motorOverSpeedOn)
        {
            motorOverSpeedOn = false;
            motorOverSpeedFault_.hide();
        }
    }

    if (motorZeroErrorFlags.railUnderVoltageLockOut())
    {
        if (!railUnderVoltageLockOutOn)
        {
            railUnderVoltageLockOutOn = true;
            railUnderVoltageLockOutFault_.show();
        }
    }
    else if (!motorZeroErrorFlags.railUnderVoltageLockOut())
    {
        if (railUnderVoltageLockOutOn)
        {
            railUnderVoltageLockOutOn = false;
            railUnderVoltageLockOutFault_.hide();
        }
    }

    if (motorZeroErrorFlags.watchdogCausedLastReset())
    {
        if (!watchdogCausedLastReset)
        {
            watchdogCausedLastReset = true;
            watchdogCausedLastResetFault_.show();
        }
    }
    else if (!motorZeroErrorFlags.watchdogCausedLastReset())
    {
        if (watchdogCausedLastReset)
        {
            railUnderVoltageLockOutOn = false;
            watchdogCausedLastResetFault_.hide();
        }
    }
}


void MotorFaultView::motorZeroLimitFlagsReceived(LimitFlags motorZeroLimitFlags)
{
}

void MotorFaultView::motorOneErrorFlagsReceived(ErrorFlags motorOneErrorFlags)
{
}

void MotorFaultView::motorOneLimitFlagsReceived(LimitFlags motorOneLimitFlags)
{
}

void MotorFaultView::errorFlagsReceived(BatteryErrorFlags batteryErrorFlags)
{
}

void MotorFaultView::limitFlagsReceived(BatteryLimitFlags batteryLimitFlags)
{
}
