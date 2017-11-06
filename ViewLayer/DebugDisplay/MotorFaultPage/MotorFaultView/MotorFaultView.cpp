#include "MotorFaultView.h"


namespace {
    int height = 25;
    QString errorStyleSheet = "font: 20px 'Arial';\nfont-weight:500;color:red; margin-left: 10px;";
    QString limitStyleSheet = "font: 20px 'Arial';\nfont-weight:500;color:yellow; margin-left: 10px;";
    int labelResizeLimit = 5;
}
MotorFaultView::MotorFaultView(MotorFaultsPresenter& motorFaultsPresenter,
                               BatteryFaultsPresenter& batteryFaultsPresenter,
                               I_MotorFaultUi& ui)
    : motorFaultsPresenter_(motorFaultsPresenter)
    , batteryFaultsPresenter_(batteryFaultsPresenter)
    , ui_(ui)
    , badMotorPositionHallSequence0Fault_(new QLabel())
    , configReadError0Fault_(new QLabel())
    , dcBusOverVoltage0Fault_(new QLabel())
    , desaturationFault0Fault_(new QLabel())
    , motorOverSpeed0Fault_(new QLabel())
    , railUnderVoltageLockOut0Fault_(new QLabel())
    , watchdogCausedLastReset0Fault_(new QLabel())
    , softwareOverCurrent0Fault_(new QLabel())
    , busCurrentLimit0Fault_(new QLabel())
    , busVoltageUpperLimit0Fault_(new QLabel())
    , busVoltageLowerLimit0Fault_ (new QLabel())
    , ipmOrMotorTelemetryLimit0Fault_ (new QLabel())
    , motorCurrentLimit0Fault_ (new QLabel())
    , outputVoltagePwmLimit0Fault_ (new QLabel())
    , velocityLimit0Fault_ (new QLabel())
    , label0Count_(0)
    , badMotorPositionHallSequence1Fault_(new QLabel())
    , configReadError1Fault_(new QLabel())
    , dcBusOverVoltage1Fault_(new QLabel())
    , desaturationFault1Fault_(new QLabel())
    , motorOverSpeed1Fault_(new QLabel())
    , railUnderVoltageLockOut1Fault_(new QLabel())
    , watchdogCausedLastReset1Fault_(new QLabel())
    , softwareOverCurrent1Fault_(new QLabel())
    , busCurrentLimit1Fault_(new QLabel())
    , busVoltageUpperLimit1Fault_(new QLabel())
    , busVoltageLowerLimit1Fault_ (new QLabel())
    , ipmOrMotorTelemetryLimit1Fault_ (new QLabel())
    , motorCurrentLimit1Fault_ (new QLabel())
    , outputVoltagePwmLimit1Fault_ (new QLabel())
    , velocityLimit1Fault_ (new QLabel())
    , label1Count_(0)
{

    QLayout *layout0 = ui_.motor0ContentsWidget().layout();
    int current_width0 = ui_.motor0ContentsWidget().size().width();

    QLayout *layout1 = ui_.motor1ContentsWidget().layout();
    int current_width1 = ui_.motor1ContentsWidget().size().width();

    // Motor 0
    badMotorPositionHallSequence0Fault_.resize(current_width0, height );
    badMotorPositionHallSequence0Fault_.setText("Bad Motor Position Hall Sequence");
    badMotorPositionHallSequence0Fault_.setStyleSheet(errorStyleSheet);
    badMotorPositionHallSequence0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&badMotorPositionHallSequence0Fault_);
    badMotorPositionHallSequence0Fault_.hide();

    configReadError0Fault_.resize(current_width0, height);
    configReadError0Fault_.setText("Config Read Error");
    configReadError0Fault_.setStyleSheet(errorStyleSheet);
    configReadError0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&configReadError0Fault_);
    configReadError0Fault_.hide();

    dcBusOverVoltage0Fault_.resize(current_width0, height);
    dcBusOverVoltage0Fault_.setText("DC Bus Over Voltage");
    dcBusOverVoltage0Fault_.setStyleSheet(errorStyleSheet);
    dcBusOverVoltage0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&dcBusOverVoltage0Fault_);
    dcBusOverVoltage0Fault_.hide();

    desaturationFault0Fault_.resize(current_width0, height);
    desaturationFault0Fault_.setText("Desaturation Fault");
    desaturationFault0Fault_.setStyleSheet(errorStyleSheet);
    desaturationFault0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&desaturationFault0Fault_);
    desaturationFault0Fault_.hide();

    motorOverSpeed0Fault_.resize(current_width0, height);
    motorOverSpeed0Fault_.setText("Motor Over Speed");
    motorOverSpeed0Fault_.setStyleSheet(errorStyleSheet);
    motorOverSpeed0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&motorOverSpeed0Fault_);
    motorOverSpeed0Fault_.hide();

    railUnderVoltageLockOut0Fault_.resize(current_width0, height);
    railUnderVoltageLockOut0Fault_.setText("Rail Under Voltage Lockout");
    railUnderVoltageLockOut0Fault_.setStyleSheet(errorStyleSheet);
    railUnderVoltageLockOut0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&railUnderVoltageLockOut0Fault_);
    railUnderVoltageLockOut0Fault_.hide();

    watchdogCausedLastReset0Fault_.resize(current_width0, height);
    watchdogCausedLastReset0Fault_.setText("Watchdog Caused Last Reset");
    watchdogCausedLastReset0Fault_.setStyleSheet(errorStyleSheet);
    watchdogCausedLastReset0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&watchdogCausedLastReset0Fault_);
    watchdogCausedLastReset0Fault_.hide();

    softwareOverCurrent0Fault_.resize(current_width0, height);
    softwareOverCurrent0Fault_.setText("Software Over Current");
    softwareOverCurrent0Fault_.setStyleSheet(errorStyleSheet);
    softwareOverCurrent0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&softwareOverCurrent0Fault_);
    softwareOverCurrent0Fault_.hide();

    busCurrentLimit0Fault_.resize(current_width0, height);
    busCurrentLimit0Fault_.setText("Bus Current Limit");
    busCurrentLimit0Fault_.setStyleSheet(limitStyleSheet);
    busCurrentLimit0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&busCurrentLimit0Fault_);
    busCurrentLimit0Fault_.hide();

    busVoltageLowerLimit0Fault_.resize(current_width0, height);
    busVoltageLowerLimit0Fault_.setText("Bus Voltage Lower Limit");
    busVoltageLowerLimit0Fault_.setStyleSheet(limitStyleSheet);
    busVoltageLowerLimit0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&busVoltageLowerLimit0Fault_);
    busVoltageLowerLimit0Fault_.hide();

    busVoltageUpperLimit0Fault_.resize(current_width0, height);
    busVoltageUpperLimit0Fault_.setText("Bus Voltage Upper Limit");
    busVoltageUpperLimit0Fault_.setStyleSheet(limitStyleSheet);
    busVoltageUpperLimit0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&busVoltageUpperLimit0Fault_);
    busVoltageUpperLimit0Fault_.hide();

    ipmOrMotorTelemetryLimit0Fault_.resize(current_width0, height);
    ipmOrMotorTelemetryLimit0Fault_.setText("IPM or Motor Telemetry Limit");
    ipmOrMotorTelemetryLimit0Fault_.setStyleSheet(limitStyleSheet);
    ipmOrMotorTelemetryLimit0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&ipmOrMotorTelemetryLimit0Fault_);
    ipmOrMotorTelemetryLimit0Fault_.hide();

    motorCurrentLimit0Fault_.resize(current_width0, height);
    motorCurrentLimit0Fault_.setText("Motor Current Limit");
    motorCurrentLimit0Fault_.setStyleSheet(limitStyleSheet);
    motorCurrentLimit0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&motorCurrentLimit0Fault_);
    motorCurrentLimit0Fault_.hide();

    outputVoltagePwmLimit0Fault_.resize(current_width0, height);
    outputVoltagePwmLimit0Fault_.setText("Output Voltage PWM Limit");
    outputVoltagePwmLimit0Fault_.setStyleSheet(limitStyleSheet);
    outputVoltagePwmLimit0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&outputVoltagePwmLimit0Fault_);
    outputVoltagePwmLimit0Fault_.hide();

    velocityLimit0Fault_.resize(current_width0, height);
    velocityLimit0Fault_.setText("Velocity Limit");
    velocityLimit0Fault_.setStyleSheet(limitStyleSheet);
    velocityLimit0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&velocityLimit0Fault_);
    velocityLimit0Fault_.hide();

    // Motor 1
    badMotorPositionHallSequence1Fault_.resize(current_width1, height );
    badMotorPositionHallSequence1Fault_.setText("Bad Motor Position Hall Sequence");
    badMotorPositionHallSequence1Fault_.setStyleSheet(errorStyleSheet);
    badMotorPositionHallSequence1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&badMotorPositionHallSequence1Fault_);
    badMotorPositionHallSequence1Fault_.hide();

    configReadError1Fault_.resize(current_width1, height);
    configReadError1Fault_.setText("Config Read Error");
    configReadError1Fault_.setStyleSheet(errorStyleSheet);
    configReadError1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&configReadError1Fault_);
    configReadError1Fault_.hide();

    dcBusOverVoltage1Fault_.resize(current_width1, height);
    dcBusOverVoltage1Fault_.setText("DC Bus Over Voltage");
    dcBusOverVoltage1Fault_.setStyleSheet(errorStyleSheet);
    dcBusOverVoltage1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&dcBusOverVoltage1Fault_);
    dcBusOverVoltage1Fault_.hide();

    desaturationFault1Fault_.resize(current_width1, height);
    desaturationFault1Fault_.setText("Desaturation Fault");
    desaturationFault1Fault_.setStyleSheet(errorStyleSheet);
    desaturationFault1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&desaturationFault1Fault_);
    desaturationFault1Fault_.hide();

    motorOverSpeed1Fault_.resize(current_width1, height);
    motorOverSpeed1Fault_.setText("Motor Over Speed");
    motorOverSpeed1Fault_.setStyleSheet(errorStyleSheet);
    motorOverSpeed1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&motorOverSpeed1Fault_);
    motorOverSpeed1Fault_.hide();

    railUnderVoltageLockOut1Fault_.resize(current_width1, height);
    railUnderVoltageLockOut1Fault_.setText("Rail Under Voltage Lockout");
    railUnderVoltageLockOut1Fault_.setStyleSheet(errorStyleSheet);
    railUnderVoltageLockOut1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&railUnderVoltageLockOut1Fault_);
    railUnderVoltageLockOut1Fault_.hide();

    watchdogCausedLastReset1Fault_.resize(current_width1, height);
    watchdogCausedLastReset1Fault_.setText("Watchdog Caused Last Reset");
    watchdogCausedLastReset1Fault_.setStyleSheet(errorStyleSheet);
    watchdogCausedLastReset1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&watchdogCausedLastReset1Fault_);
    watchdogCausedLastReset1Fault_.hide();

    softwareOverCurrent1Fault_.resize(current_width1, height);
    softwareOverCurrent1Fault_.setText("Software Over Current");
    softwareOverCurrent1Fault_.setStyleSheet(errorStyleSheet);
    softwareOverCurrent1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&softwareOverCurrent1Fault_);
    softwareOverCurrent1Fault_.hide();

    busCurrentLimit1Fault_.resize(current_width1, height);
    busCurrentLimit1Fault_.setText("Bus Current Limit");
    busCurrentLimit1Fault_.setStyleSheet(limitStyleSheet);
    busCurrentLimit1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&busCurrentLimit1Fault_);
    busCurrentLimit1Fault_.hide();

    busVoltageLowerLimit1Fault_.resize(current_width1, height);
    busVoltageLowerLimit1Fault_.setText("Bus Voltage Lower Limit");
    busVoltageLowerLimit1Fault_.setStyleSheet(limitStyleSheet);
    busVoltageLowerLimit1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&busVoltageLowerLimit1Fault_);
    busVoltageLowerLimit1Fault_.hide();

    busVoltageUpperLimit1Fault_.resize(current_width1, height);
    busVoltageUpperLimit1Fault_.setText("Bus Voltage Upper Limit");
    busVoltageUpperLimit1Fault_.setStyleSheet(limitStyleSheet);
    busVoltageUpperLimit1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&busVoltageUpperLimit1Fault_);
    busVoltageUpperLimit1Fault_.hide();

    ipmOrMotorTelemetryLimit1Fault_.resize(current_width1, height);
    ipmOrMotorTelemetryLimit1Fault_.setText("IPM or Motor Telemetry Limit");
    ipmOrMotorTelemetryLimit1Fault_.setStyleSheet(limitStyleSheet);
    ipmOrMotorTelemetryLimit1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&ipmOrMotorTelemetryLimit1Fault_);
    ipmOrMotorTelemetryLimit1Fault_.hide();

    motorCurrentLimit1Fault_.resize(current_width1, height);
    motorCurrentLimit1Fault_.setText("Motor Current Limit");
    motorCurrentLimit1Fault_.setStyleSheet(limitStyleSheet);
    motorCurrentLimit1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&motorCurrentLimit1Fault_);
    motorCurrentLimit1Fault_.hide();

    outputVoltagePwmLimit1Fault_.resize(current_width1, height);
    outputVoltagePwmLimit1Fault_.setText("Output Voltage PWM Limit");
    outputVoltagePwmLimit1Fault_.setStyleSheet(limitStyleSheet);
    outputVoltagePwmLimit1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&outputVoltagePwmLimit1Fault_);
    outputVoltagePwmLimit1Fault_.hide();

    velocityLimit1Fault_.resize(current_width1, height);
    velocityLimit1Fault_.setText("Velocity Limit");
    velocityLimit1Fault_.setStyleSheet(limitStyleSheet);
    velocityLimit1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&velocityLimit1Fault_);
    velocityLimit1Fault_.hide();

    ui_.motor0ContentsWidget().setLayout(layout0);
    ui_.motor1ContentsWidget().setLayout(layout1);


    connectMotorFaults(motorFaultsPresenter_);
    connectBatteryFaults(batteryFaultsPresenter_);


    // Testing
    ErrorFlags errorflags0; ErrorFlags errorflags1;
    errorflags0.setBadMotorPositionHallSequence(true);
    errorflags0.setConfigReadError(true);
    errorflags0.setDcBusOverVoltage(true);
    errorflags0.setDesaturationFault(true);
    errorflags0.setMotorOverSpeed(true);
    errorflags0.setRailUnderVoltageLockOut(true);
    errorflags0.setSoftwareOverCurrent(true);
    errorflags0.setWatchdogCausedLastReset(true);
    motorZeroErrorFlagsReceived(errorflags0);

    errorflags1.setBadMotorPositionHallSequence(true);
    errorflags1.setConfigReadError(true);
    errorflags1.setDcBusOverVoltage(true);
    errorflags1.setDesaturationFault(true);
    errorflags1.setMotorOverSpeed(true);
    errorflags1.setRailUnderVoltageLockOut(true);
    errorflags1.setSoftwareOverCurrent(true);
    errorflags1.setWatchdogCausedLastReset(true);
    motorOneErrorFlagsReceived(errorflags1);

    LimitFlags limitflags0; LimitFlags limitflags1;
    limitflags0.setBusCurrentLimit(true);
    limitflags0.setBusVoltageLowerLimit(true);
    limitflags0.setBusVoltageUpperLimit(true);
    limitflags0.setIpmOrMotorTelemetryLimit(true);
    limitflags0.setMotorCurrentLimit(true);
    limitflags0.setOutputVoltagePwmLimit(true);
    limitflags0.setVelocityLimit(true);
    motorZeroLimitFlagsReceived(limitflags0);

    limitflags1.setBusCurrentLimit(true);
    limitflags1.setBusVoltageLowerLimit(true);
    limitflags1.setBusVoltageUpperLimit(true);
    limitflags1.setIpmOrMotorTelemetryLimit(true);
    limitflags1.setMotorCurrentLimit(true);
    limitflags1.setOutputVoltagePwmLimit(true);
    limitflags1.setVelocityLimit(true);
    motorOneLimitFlagsReceived(limitflags1);

    qDebug()<<ui_.motor0ContentsWidget().size();
    qDebug() << ui_.motor1ContentsWidget().size();
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
    static bool softwareOverCurrent = false;
    static bool watchdogCausedLastReset = false;

    int current_width = ui_.motor0ContentsWidget().size().width();
    int current_height = ui_.motor0ContentsWidget().size().height();

    if(motorZeroErrorFlags.badMotorPositionHallSequence())
    {
        if (!badMotorPositionHallSequenceOn)
        {
            label0Count_++;
            badMotorPositionHallSequenceOn = true;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            badMotorPositionHallSequence0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.badMotorPositionHallSequence())
    {
        if (badMotorPositionHallSequenceOn)
        {

            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            badMotorPositionHallSequenceOn = false;
            badMotorPositionHallSequence0Fault_.hide();
        }
    }

    if (motorZeroErrorFlags.configReadError())
    {
        if (!configReadErrorOn)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            configReadErrorOn = true;
            configReadError0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.configReadError())
    {
        if (configReadErrorOn)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            configReadErrorOn = false;
            configReadError0Fault_.hide();
        }
    }

    if (motorZeroErrorFlags.dcBusOverVoltage())
    {
        if (!dcBusOverVoltageOn)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            dcBusOverVoltageOn = true;
            dcBusOverVoltage0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.dcBusOverVoltage())
    {
        if (dcBusOverVoltageOn)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            dcBusOverVoltageOn = false;
            dcBusOverVoltage0Fault_.hide();
        }
    }

    if (motorZeroErrorFlags.desaturationFault())
    {
        if (!desaturationFaultOn)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            desaturationFaultOn = true;
            desaturationFault0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.desaturationFault())
    {
        if (desaturationFaultOn)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            desaturationFaultOn = false;
            desaturationFault0Fault_.hide();
        }
    }

    if (motorZeroErrorFlags.motorOverSpeed())
    {
        if (!motorOverSpeedOn)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            motorOverSpeedOn = true;
            motorOverSpeed0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.motorOverSpeed())
    {
        if (motorOverSpeedOn)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            motorOverSpeedOn = false;
            motorOverSpeed0Fault_.hide();
        }
    }

    if (motorZeroErrorFlags.railUnderVoltageLockOut())
    {
        if (!railUnderVoltageLockOutOn)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            railUnderVoltageLockOutOn = true;
            railUnderVoltageLockOut0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.railUnderVoltageLockOut())
    {
        if (railUnderVoltageLockOutOn)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            railUnderVoltageLockOutOn = false;
            railUnderVoltageLockOut0Fault_.hide();
        }
    }

    if (motorZeroErrorFlags.watchdogCausedLastReset())
    {
        if (!watchdogCausedLastReset)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            watchdogCausedLastReset = true;
            watchdogCausedLastReset0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.watchdogCausedLastReset())
    {
        if (watchdogCausedLastReset)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            watchdogCausedLastReset = false;
            watchdogCausedLastReset0Fault_.hide();
        }
    }

    if (motorZeroErrorFlags.softwareOverCurrent())
    {
        if (!softwareOverCurrent)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            softwareOverCurrent = true;
            softwareOverCurrent0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.softwareOverCurrent())
    {
        if (softwareOverCurrent)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            softwareOverCurrent = false;
            softwareOverCurrent0Fault_.hide();
        }
    }
}


void MotorFaultView::motorZeroLimitFlagsReceived(LimitFlags motorZeroLimitFlags)
{
    static bool busCurrentLimit = false;
    static bool busVoltageLowerLimit = false;
    static bool busVoltageUpperLimit = false;
    static bool ipmOrMotorTelemetryLimit = false;
    static bool motorCurrentLimit = false;
    static bool outputVoltagePwmLimit = false;
    static bool velocityLimit = false;

    int current_width = ui_.motor0ContentsWidget().size().width();
    int current_height = ui_.motor0ContentsWidget().size().height();

    if (motorZeroLimitFlags.busCurrentLimit())
    {
        if (!busCurrentLimit)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            busCurrentLimit = true;
            busCurrentLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.busCurrentLimit())
    {
        if (busCurrentLimit)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            busCurrentLimit = false;
            busCurrentLimit0Fault_.hide();
        }
    }

    if (motorZeroLimitFlags.busVoltageLowerLimit())
    {
        if (!busVoltageLowerLimit)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            busVoltageLowerLimit = true;
            busVoltageLowerLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.busVoltageLowerLimit())
    {
        if (busVoltageLowerLimit)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            busVoltageLowerLimit = false;
            busVoltageLowerLimit0Fault_.hide();
        }
    }

    if (motorZeroLimitFlags.busVoltageUpperLimit())
    {
        if (!busVoltageUpperLimit)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            busVoltageUpperLimit = true;
            busVoltageUpperLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.busVoltageUpperLimit())
    {
        if (busVoltageUpperLimit)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            busVoltageUpperLimit = false;
            busVoltageUpperLimit0Fault_.hide();
        }
    }

    if (motorZeroLimitFlags.ipmOrMotorTelemetryLimit())
    {
        if (!ipmOrMotorTelemetryLimit)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            ipmOrMotorTelemetryLimit = true;
            ipmOrMotorTelemetryLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.ipmOrMotorTelemetryLimit())
    {
        if (ipmOrMotorTelemetryLimit)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            ipmOrMotorTelemetryLimit = false;
            ipmOrMotorTelemetryLimit0Fault_.hide();
        }
    }

    if (motorZeroLimitFlags.motorCurrentLimit())
    {
        if (!motorCurrentLimit)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            motorCurrentLimit = true;
            motorCurrentLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.motorCurrentLimit())
    {
        if (motorCurrentLimit)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            motorCurrentLimit = false;
            motorCurrentLimit0Fault_.hide();
        }
    }

    if (motorZeroLimitFlags.outputVoltagePwmLimit())
    {
        if (!outputVoltagePwmLimit)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            outputVoltagePwmLimit = true;
            outputVoltagePwmLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.outputVoltagePwmLimit())
    {
        if (outputVoltagePwmLimit)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            outputVoltagePwmLimit = false;
            outputVoltagePwmLimit0Fault_.hide();
        }
    }

    if (motorZeroLimitFlags.velocityLimit())
    {
        if (!velocityLimit)
        {
            label0Count_++;
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
            velocityLimit = true;
            velocityLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.velocityLimit())
    {
        if (velocityLimit)
        {
            if (label0Count_ >= labelResizeLimit)
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
            label0Count_--;
            velocityLimit = false;
            velocityLimit0Fault_.hide();
        }
    }
}

void MotorFaultView::motorOneErrorFlagsReceived(ErrorFlags motorOneErrorFlags)
{
    static bool badMotorPositionHallSequenceOn = false;
    static bool configReadErrorOn = false;
    static bool dcBusOverVoltageOn = false;
    static bool desaturationFaultOn = false;
    static bool motorOverSpeedOn = false;
    static bool railUnderVoltageLockOutOn = false;
    static bool softwareOverCurrent = false;
    static bool watchdogCausedLastReset = false;

    int current_width = ui_.motor1ContentsWidget().size().width();
    int current_height = ui_.motor1ContentsWidget().size().height();

    if(motorOneErrorFlags.badMotorPositionHallSequence())
    {
        if (!badMotorPositionHallSequenceOn)
        {
            label1Count_++;
            badMotorPositionHallSequenceOn = true;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            badMotorPositionHallSequence1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.badMotorPositionHallSequence())
    {
        if (badMotorPositionHallSequenceOn)
        {

            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            badMotorPositionHallSequenceOn = false;
            badMotorPositionHallSequence1Fault_.hide();
        }
    }

    if (motorOneErrorFlags.configReadError())
    {
        if (!configReadErrorOn)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            configReadErrorOn = true;
            configReadError1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.configReadError())
    {
        if (configReadErrorOn)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            configReadErrorOn = false;
            configReadError1Fault_.hide();
        }
    }

    if (motorOneErrorFlags.dcBusOverVoltage())
    {
        if (!dcBusOverVoltageOn)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            dcBusOverVoltageOn = true;
            dcBusOverVoltage1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.dcBusOverVoltage())
    {
        if (dcBusOverVoltageOn)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            dcBusOverVoltageOn = false;
            dcBusOverVoltage1Fault_.hide();
        }
    }

    if (motorOneErrorFlags.desaturationFault())
    {
        if (!desaturationFaultOn)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            desaturationFaultOn = true;
            desaturationFault1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.desaturationFault())
    {
        if (desaturationFaultOn)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            desaturationFaultOn = false;
            desaturationFault1Fault_.hide();
        }
    }

    if (motorOneErrorFlags.motorOverSpeed())
    {
        if (!motorOverSpeedOn)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            motorOverSpeedOn = true;
            motorOverSpeed1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.motorOverSpeed())
    {
        if (motorOverSpeedOn)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            motorOverSpeedOn = false;
            motorOverSpeed1Fault_.hide();
        }
    }

    if (motorOneErrorFlags.railUnderVoltageLockOut())
    {
        if (!railUnderVoltageLockOutOn)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            railUnderVoltageLockOutOn = true;
            railUnderVoltageLockOut1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.railUnderVoltageLockOut())
    {
        if (railUnderVoltageLockOutOn)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            railUnderVoltageLockOutOn = false;
            railUnderVoltageLockOut1Fault_.hide();
        }
    }

    if (motorOneErrorFlags.watchdogCausedLastReset())
    {
        if (!watchdogCausedLastReset)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            watchdogCausedLastReset = true;
            watchdogCausedLastReset1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.watchdogCausedLastReset())
    {
        if (watchdogCausedLastReset)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            watchdogCausedLastReset = false;
            watchdogCausedLastReset1Fault_.hide();
        }
    }

    if (motorOneErrorFlags.softwareOverCurrent())
    {
        if (!softwareOverCurrent)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            softwareOverCurrent = true;
            softwareOverCurrent1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.softwareOverCurrent())
    {
        if (softwareOverCurrent)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            softwareOverCurrent = false;
            softwareOverCurrent1Fault_.hide();
        }
    }
}

void MotorFaultView::motorOneLimitFlagsReceived(LimitFlags motorOneLimitFlags)
{
    static bool busCurrentLimit = false;
    static bool busVoltageLowerLimit = false;
    static bool busVoltageUpperLimit = false;
    static bool ipmOrMotorTelemetryLimit = false;
    static bool motorCurrentLimit = false;
    static bool outputVoltagePwmLimit = false;
    static bool velocityLimit = false;

    int current_width = ui_.motor1ContentsWidget().size().width();
    int current_height = ui_.motor1ContentsWidget().size().height();

    if (motorOneLimitFlags.busCurrentLimit())
    {
        if (!busCurrentLimit)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            busCurrentLimit = true;
            busCurrentLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.busCurrentLimit())
    {
        if (busCurrentLimit)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            busCurrentLimit = false;
            busCurrentLimit1Fault_.hide();
        }
    }

    if (motorOneLimitFlags.busVoltageLowerLimit())
    {
        if (!busVoltageLowerLimit)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            busVoltageLowerLimit = true;
            busVoltageLowerLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.busVoltageLowerLimit())
    {
        if (busVoltageLowerLimit)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            busVoltageLowerLimit = false;
            busVoltageLowerLimit1Fault_.hide();
        }
    }

    if (motorOneLimitFlags.busVoltageUpperLimit())
    {
        if (!busVoltageUpperLimit)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            busVoltageUpperLimit = true;
            busVoltageUpperLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.busVoltageUpperLimit())
    {
        if (busVoltageUpperLimit)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            busVoltageUpperLimit = false;
            busVoltageUpperLimit1Fault_.hide();
        }
    }

    if (motorOneLimitFlags.ipmOrMotorTelemetryLimit())
    {
        if (!ipmOrMotorTelemetryLimit)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            ipmOrMotorTelemetryLimit = true;
            ipmOrMotorTelemetryLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.ipmOrMotorTelemetryLimit())
    {
        if (ipmOrMotorTelemetryLimit)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            ipmOrMotorTelemetryLimit = false;
            ipmOrMotorTelemetryLimit1Fault_.hide();
        }
    }

    if (motorOneLimitFlags.motorCurrentLimit())
    {
        if (!motorCurrentLimit)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            motorCurrentLimit = true;
            motorCurrentLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.motorCurrentLimit())
    {
        if (motorCurrentLimit)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            motorCurrentLimit = false;
            motorCurrentLimit1Fault_.hide();
        }
    }

    if (motorOneLimitFlags.outputVoltagePwmLimit())
    {
        if (!outputVoltagePwmLimit)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            outputVoltagePwmLimit = true;
            outputVoltagePwmLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.outputVoltagePwmLimit())
    {
        if (outputVoltagePwmLimit)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            outputVoltagePwmLimit = false;
            outputVoltagePwmLimit1Fault_.hide();
        }
    }

    if (motorOneLimitFlags.velocityLimit())
    {
        if (!velocityLimit)
        {
            label1Count_++;
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
            velocityLimit = true;
            velocityLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.velocityLimit())
    {
        if (velocityLimit)
        {
            if (label1Count_ >= labelResizeLimit)
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
            label1Count_--;
            velocityLimit = false;
            velocityLimit1Fault_.hide();
        }
    }
}

void MotorFaultView::errorFlagsReceived(BatteryErrorFlags batteryErrorFlags)
{
}

void MotorFaultView::limitFlagsReceived(BatteryLimitFlags batteryLimitFlags)
{
}
