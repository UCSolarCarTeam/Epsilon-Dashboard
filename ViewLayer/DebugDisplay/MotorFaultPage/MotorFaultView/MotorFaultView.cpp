#include "MotorFaultView.h"

namespace
{
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
    , alwaysOnSupplyFault_ (new QLabel())
    , canbusCommunicationsFault_ (new QLabel())
    , chargeLimitEnforcementFault_ (new QLabel())
    , chargerSafetyRelayFault_ (new QLabel())
    , currentSensorFault_ (new QLabel())
    , dischargeLimitEnforcementFault_ (new QLabel())
    , fanMonitorFault_ (new QLabel())
    , highVoltageIsolationFault_ (new QLabel())
    , internalCommununicationFault_ (new QLabel())
    , internalConversionFault_ (new QLabel())
    , internalLogicFault_ (new QLabel())
    , internalMemoryFault_ (new QLabel())
    , internalThermistorFault_ (new QLabel())
    , lowCellVoltageFault_ (new QLabel())
    , openWiringFault_ (new QLabel())
    , packVoltageSensorFault_ (new QLabel())
    , powerSupplyFault12V_ (new QLabel())
    , thermistorFault_ (new QLabel())
    , voltageRedundancyFault_ (new QLabel())
    , weakCellFault_ (new QLabel())
    , weakPackFault_ (new QLabel())
    , cclReducedDueToAlternateCurrentLimit_ (new QLabel())
    , cclReducedDueToChargerLatch_ (new QLabel())
    , cclReducedDueToHighCellResistance_ (new QLabel())
    , cclReducedDueToHighCellVoltage_ (new QLabel())
    , cclReducedDueToHighPackVoltage_ (new QLabel())
    , cclReducedDueToHighSoc_ (new QLabel())
    , cclReducedDueToTemperature_ (new QLabel())
    , dclandCclReducedDueToCommunicationFailsafe_ (new QLabel())
    , dclandCclReducedDueToVoltageFailsafe_ (new QLabel())
    , dclReducedDueToHighCellResistance_ (new QLabel())
    , dclReducedDueToLowCellVoltage_ (new QLabel())
    , dclReducedDueToLowPackVoltage_ (new QLabel())
    , dclReducedDueToLowSoc_ (new QLabel())
    , dclReducedDueToTemperature_ (new QLabel())
    , labelBcount_ (0)
{

    // Setting up Vertical bar (wasn't letting me setup in namespace)
    QScrollBar* verticalBar = new QScrollBar;
    verticalBar->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {"
                               "    background:rgba(83, 83, 84);"
                               "    width:10px;    "
                               "    margin: 0px 0px 0px 0px;"
                               "}"
                               "QScrollBar::handle:vertical {"
                               "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                               "    stop: 0 rgb(255, 192, 33), stop: 0.5 rgb(255, 192, 33), stop:1 rgb(255, 192, 33));"
                               "    min-height: 0px;"
                               "    border-radius: 5px;"
                               "}"
                               "QScrollBar::add-line:vertical {"
                               "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                               "    stop: 0 rgb(255, 192, 33), stop: 0.5 rgb(255, 192, 33),  stop:1 rgb(255, 192, 33));"
                               "    height: 0px;"
                               "    subcontrol-position: bottom;"
                               "    subcontrol-origin: margin;"
                               "}"
                               "QScrollBar::sub-line:vertical {"
                               "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                               "    stop: 0  rgb(255, 192, 33), stop: 0.5 rgb(255, 192, 33),  stop:1 rgb(255, 192, 33));"
                               "    height: 0 px;"
                               "    subcontrol-position: top;"
                               "    subcontrol-origin: margin;"
                               "}"
                                                ));

    ui_.motor0ScrollArea().setVerticalScrollBar(verticalBar);
    ui_.motor1ScrollArea().setVerticalScrollBar(verticalBar);
    ui_.batteryScrollArea().setVerticalScrollBar(verticalBar);

    QLayout* layout0 = ui_.motor0ContentsWidget().layout();
    int current_width0 = ui_.motor0ContentsWidget().size().width();

    QLayout* layout1 = ui_.motor1ContentsWidget().layout();
    int current_width1 = ui_.motor1ContentsWidget().size().width();

    QLayout* layoutB = ui_.batteryContentsWidget().layout();
    int current_widthB = ui_.batteryContentsWidget().size().width();

    // Motor 0
    badMotorPositionHallSequence0Fault_.resize(current_width0, height );
    badMotorPositionHallSequence0Fault_.setText("Bad Motor Position Hall Sequence Error");
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
    dcBusOverVoltage0Fault_.setText("DC Bus Over Voltage Error");
    dcBusOverVoltage0Fault_.setStyleSheet(errorStyleSheet);
    dcBusOverVoltage0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&dcBusOverVoltage0Fault_);
    dcBusOverVoltage0Fault_.hide();

    desaturationFault0Fault_.resize(current_width0, height);
    desaturationFault0Fault_.setText("Desaturation Fault Error");
    desaturationFault0Fault_.setStyleSheet(errorStyleSheet);
    desaturationFault0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&desaturationFault0Fault_);
    desaturationFault0Fault_.hide();

    motorOverSpeed0Fault_.resize(current_width0, height);
    motorOverSpeed0Fault_.setText("Motor Over Speed Error");
    motorOverSpeed0Fault_.setStyleSheet(errorStyleSheet);
    motorOverSpeed0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&motorOverSpeed0Fault_);
    motorOverSpeed0Fault_.hide();

    railUnderVoltageLockOut0Fault_.resize(current_width0, height);
    railUnderVoltageLockOut0Fault_.setText("Rail Under Voltage Lockout Error");
    railUnderVoltageLockOut0Fault_.setStyleSheet(errorStyleSheet);
    railUnderVoltageLockOut0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&railUnderVoltageLockOut0Fault_);
    railUnderVoltageLockOut0Fault_.hide();

    watchdogCausedLastReset0Fault_.resize(current_width0, height);
    watchdogCausedLastReset0Fault_.setText("Watchdog Caused Last Reset Error");
    watchdogCausedLastReset0Fault_.setStyleSheet(errorStyleSheet);
    watchdogCausedLastReset0Fault_.setFixedSize(current_width0, height);
    layout0->addWidget(&watchdogCausedLastReset0Fault_);
    watchdogCausedLastReset0Fault_.hide();

    softwareOverCurrent0Fault_.resize(current_width0, height);
    softwareOverCurrent0Fault_.setText("Software Over Current Error");
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
    badMotorPositionHallSequence1Fault_.setText("Bad Motor Position Hall Sequence Error");
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
    dcBusOverVoltage1Fault_.setText("DC Bus Over Voltage Error");
    dcBusOverVoltage1Fault_.setStyleSheet(errorStyleSheet);
    dcBusOverVoltage1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&dcBusOverVoltage1Fault_);
    dcBusOverVoltage1Fault_.hide();

    desaturationFault1Fault_.resize(current_width1, height);
    desaturationFault1Fault_.setText("Desaturation Fault Error");
    desaturationFault1Fault_.setStyleSheet(errorStyleSheet);
    desaturationFault1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&desaturationFault1Fault_);
    desaturationFault1Fault_.hide();

    motorOverSpeed1Fault_.resize(current_width1, height);
    motorOverSpeed1Fault_.setText("Motor Over Speed Error");
    motorOverSpeed1Fault_.setStyleSheet(errorStyleSheet);
    motorOverSpeed1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&motorOverSpeed1Fault_);
    motorOverSpeed1Fault_.hide();

    railUnderVoltageLockOut1Fault_.resize(current_width1, height);
    railUnderVoltageLockOut1Fault_.setText("Rail Under Voltage Lockout Error");
    railUnderVoltageLockOut1Fault_.setStyleSheet(errorStyleSheet);
    railUnderVoltageLockOut1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&railUnderVoltageLockOut1Fault_);
    railUnderVoltageLockOut1Fault_.hide();

    watchdogCausedLastReset1Fault_.resize(current_width1, height);
    watchdogCausedLastReset1Fault_.setText("Watchdog Caused Last Reset Error");
    watchdogCausedLastReset1Fault_.setStyleSheet(errorStyleSheet);
    watchdogCausedLastReset1Fault_.setFixedSize(current_width1, height);
    layout1->addWidget(&watchdogCausedLastReset1Fault_);
    watchdogCausedLastReset1Fault_.hide();

    softwareOverCurrent1Fault_.resize(current_width1, height);
    softwareOverCurrent1Fault_.setText("Software Over Current Error");
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

    // Battery
    alwaysOnSupplyFault_.resize(current_widthB, height);
    alwaysOnSupplyFault_.setText("Always On Supply Fault");
    alwaysOnSupplyFault_.setStyleSheet(errorStyleSheet);
    alwaysOnSupplyFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&alwaysOnSupplyFault_);
    alwaysOnSupplyFault_.hide();

    canbusCommunicationsFault_.resize(current_widthB, height);
    canbusCommunicationsFault_.setText("CAN Bus Communications Fault");
    canbusCommunicationsFault_.setStyleSheet(errorStyleSheet);
    canbusCommunicationsFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&canbusCommunicationsFault_);
    canbusCommunicationsFault_.hide();

    chargeLimitEnforcementFault_.resize(current_widthB, height);
    chargeLimitEnforcementFault_.setText("Charge Limit Enforcement Fault");
    chargeLimitEnforcementFault_.setStyleSheet(errorStyleSheet);
    chargeLimitEnforcementFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&chargeLimitEnforcementFault_);
    chargeLimitEnforcementFault_.hide();

    chargerSafetyRelayFault_.resize(current_widthB, height);
    chargerSafetyRelayFault_.setText("Charger Safety Relay Fault");
    chargerSafetyRelayFault_.setStyleSheet(errorStyleSheet);
    chargerSafetyRelayFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&chargerSafetyRelayFault_);
    chargerSafetyRelayFault_.hide();

    currentSensorFault_.resize(current_widthB, height);
    currentSensorFault_.setText("Current Sensor Fault");
    currentSensorFault_.setStyleSheet(errorStyleSheet);
    currentSensorFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&currentSensorFault_);
    currentSensorFault_.hide();

    dischargeLimitEnforcementFault_.resize(current_widthB, height);
    dischargeLimitEnforcementFault_.setText("Discharge Limit Enforcement Fault");
    dischargeLimitEnforcementFault_.setStyleSheet(errorStyleSheet);
    dischargeLimitEnforcementFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&dischargeLimitEnforcementFault_);
    dischargeLimitEnforcementFault_.hide();

    fanMonitorFault_.resize(current_widthB, height);
    fanMonitorFault_.setText("Fan Monitor Fault");
    fanMonitorFault_.setStyleSheet(errorStyleSheet);
    fanMonitorFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&fanMonitorFault_);
    fanMonitorFault_.hide();

    highVoltageIsolationFault_.resize(current_widthB, height);
    highVoltageIsolationFault_.setText("High Voltage Isolation Fault");
    highVoltageIsolationFault_.setStyleSheet(errorStyleSheet);
    highVoltageIsolationFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&highVoltageIsolationFault_);
    highVoltageIsolationFault_.hide();

    internalCommununicationFault_.resize(current_widthB, height);
    internalCommununicationFault_.setText("Internal Communication Fault");
    internalCommununicationFault_.setStyleSheet(errorStyleSheet);
    internalCommununicationFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&internalCommununicationFault_);
    internalCommununicationFault_.hide();

    internalConversionFault_.resize(current_widthB, height);
    internalConversionFault_.setText("Internal Conversion Fault");
    internalConversionFault_.setStyleSheet(errorStyleSheet);
    internalConversionFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&internalConversionFault_);
    internalConversionFault_.hide();

    internalLogicFault_.resize(current_widthB, height);
    internalLogicFault_.setText("Internal Logic Fault");
    internalLogicFault_.setStyleSheet(errorStyleSheet);
    internalLogicFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&internalLogicFault_);
    internalLogicFault_.hide();

    internalMemoryFault_.resize(current_widthB, height);
    internalMemoryFault_.setText("Internal Memory Fault");
    internalMemoryFault_.setStyleSheet(errorStyleSheet);
    internalMemoryFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&internalMemoryFault_);
    internalMemoryFault_.hide();

    internalThermistorFault_.resize(current_widthB, height);
    internalThermistorFault_.setText("Internal Thermistor Fault");
    internalThermistorFault_.setStyleSheet(errorStyleSheet);
    internalThermistorFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&internalThermistorFault_);
    internalThermistorFault_.hide();

    lowCellVoltageFault_.resize(current_widthB, height);
    lowCellVoltageFault_.setText("Low Cell Voltage Fault");
    lowCellVoltageFault_.setStyleSheet(errorStyleSheet);
    lowCellVoltageFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&lowCellVoltageFault_);
    lowCellVoltageFault_.hide();

    openWiringFault_.resize(current_widthB, height);
    openWiringFault_.setText("Open Wiring Fault");
    openWiringFault_.setStyleSheet(errorStyleSheet);
    openWiringFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&openWiringFault_);
    openWiringFault_.hide();

    packVoltageSensorFault_.resize(current_widthB, height);
    packVoltageSensorFault_.setText("Pack Voltage Sensor Fault");
    packVoltageSensorFault_.setStyleSheet(errorStyleSheet);
    packVoltageSensorFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&packVoltageSensorFault_);
    packVoltageSensorFault_.hide();

    powerSupplyFault12V_.resize(current_widthB, height);
    powerSupplyFault12V_.setText("12V Power Supply Fault");
    powerSupplyFault12V_.setStyleSheet(errorStyleSheet);
    powerSupplyFault12V_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&powerSupplyFault12V_);
    powerSupplyFault12V_.hide();

    thermistorFault_.resize(current_widthB, height);
    thermistorFault_.setText("Thermistor Fault");
    thermistorFault_.setStyleSheet(errorStyleSheet);
    thermistorFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&thermistorFault_);
    thermistorFault_.hide();

    voltageRedundancyFault_.resize(current_widthB, height);
    voltageRedundancyFault_.setText("Voltage Redundancy Fault");
    voltageRedundancyFault_.setStyleSheet(errorStyleSheet);
    voltageRedundancyFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&voltageRedundancyFault_);
    voltageRedundancyFault_.hide();

    weakCellFault_.resize(current_widthB, height);
    weakCellFault_.setText("Weak Cell Fault");
    weakCellFault_.setStyleSheet(errorStyleSheet);
    weakCellFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&weakCellFault_);
    weakCellFault_.hide();

    weakPackFault_.resize(current_widthB, height);
    weakPackFault_.setText("Weak Pack Fault");
    weakPackFault_.setStyleSheet(errorStyleSheet);
    weakPackFault_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&weakPackFault_);
    weakPackFault_.hide();

    cclReducedDueToAlternateCurrentLimit_.resize(current_widthB, height);
    cclReducedDueToAlternateCurrentLimit_.setText("CCL Reduced Due To Alternate Current");
    cclReducedDueToAlternateCurrentLimit_.setStyleSheet(limitStyleSheet);
    cclReducedDueToAlternateCurrentLimit_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&cclReducedDueToAlternateCurrentLimit_);
    cclReducedDueToAlternateCurrentLimit_.hide();

    cclReducedDueToChargerLatch_.resize(current_widthB, height);
    cclReducedDueToChargerLatch_.setText("CCL Reduced Due To Charger Latch");
    cclReducedDueToChargerLatch_.setStyleSheet(limitStyleSheet);
    cclReducedDueToChargerLatch_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&cclReducedDueToChargerLatch_);
    cclReducedDueToChargerLatch_.hide();

    cclReducedDueToHighCellResistance_.resize(current_widthB, height);
    cclReducedDueToHighCellResistance_.setText("CCL Reduced Due To High Cell Resistance");
    cclReducedDueToHighCellResistance_.setStyleSheet(limitStyleSheet);
    cclReducedDueToHighCellResistance_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&cclReducedDueToHighCellResistance_);
    cclReducedDueToHighCellResistance_.hide();

    cclReducedDueToHighCellVoltage_.resize(current_widthB, height);
    cclReducedDueToHighCellVoltage_.setText("CCL Reduced Due To High Cell Voltage");
    cclReducedDueToHighCellVoltage_.setStyleSheet(limitStyleSheet);
    cclReducedDueToHighCellVoltage_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&cclReducedDueToHighCellVoltage_);
    cclReducedDueToHighCellVoltage_.hide();

    cclReducedDueToHighPackVoltage_.resize(current_widthB, height);
    cclReducedDueToHighPackVoltage_.setText("CCL Reduced Due To High Pack Voltage");
    cclReducedDueToHighPackVoltage_.setStyleSheet(limitStyleSheet);
    cclReducedDueToHighPackVoltage_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&cclReducedDueToHighPackVoltage_);
    cclReducedDueToHighPackVoltage_.hide();

    cclReducedDueToHighSoc_.resize(current_widthB, height);
    cclReducedDueToHighSoc_.setText("CCL Reduced Due To High SOC");
    cclReducedDueToHighSoc_.setStyleSheet(limitStyleSheet);
    cclReducedDueToHighSoc_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&cclReducedDueToHighSoc_);
    cclReducedDueToHighSoc_.hide();

    cclReducedDueToTemperature_.resize(current_widthB, height);
    cclReducedDueToTemperature_.setText("CCL Reduced Due To Temperature");
    cclReducedDueToTemperature_.setStyleSheet(limitStyleSheet);
    cclReducedDueToTemperature_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&cclReducedDueToTemperature_);
    cclReducedDueToTemperature_.hide();

    dclandCclReducedDueToCommunicationFailsafe_.resize(current_widthB, height);
    dclandCclReducedDueToCommunicationFailsafe_.setText("DCL and CCL Reduced Due To Communication Fail Safe");
    dclandCclReducedDueToCommunicationFailsafe_.setStyleSheet(limitStyleSheet);
    dclandCclReducedDueToCommunicationFailsafe_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&dclandCclReducedDueToCommunicationFailsafe_);
    dclandCclReducedDueToCommunicationFailsafe_.hide();

    dclandCclReducedDueToVoltageFailsafe_.resize(current_widthB, height);
    dclandCclReducedDueToVoltageFailsafe_.setText("DCL and CCL Reduced Due To Voltage Fail Safe");
    dclandCclReducedDueToVoltageFailsafe_.setStyleSheet(limitStyleSheet);
    dclandCclReducedDueToVoltageFailsafe_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&dclandCclReducedDueToVoltageFailsafe_);
    dclandCclReducedDueToVoltageFailsafe_.hide();

    dclReducedDueToHighCellResistance_.resize(current_widthB, height);
    dclReducedDueToHighCellResistance_.setText("DCL Reduced Due To High Cell Resistance");
    dclReducedDueToHighCellResistance_.setStyleSheet(limitStyleSheet);
    dclReducedDueToHighCellResistance_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&dclReducedDueToHighCellResistance_);
    dclReducedDueToHighCellResistance_.hide();

    dclReducedDueToLowCellVoltage_.resize(current_widthB, height);
    dclReducedDueToLowCellVoltage_.setText("DCL Reduced Due To Low Cell Voltage");
    dclReducedDueToLowCellVoltage_.setStyleSheet(limitStyleSheet);
    dclReducedDueToLowCellVoltage_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&dclReducedDueToLowCellVoltage_);
    dclReducedDueToLowCellVoltage_.hide();

    dclReducedDueToLowPackVoltage_.resize(current_widthB, height);
    dclReducedDueToLowPackVoltage_.setText("DCL Reduced Due To Low Pack Voltage");
    dclReducedDueToLowPackVoltage_.setStyleSheet(limitStyleSheet);
    dclReducedDueToLowPackVoltage_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&dclReducedDueToLowPackVoltage_);
    dclReducedDueToLowPackVoltage_.hide();

    dclReducedDueToLowSoc_.resize(current_widthB, height);
    dclReducedDueToLowSoc_.setText("DCL Reduced Due To Low SOC");
    dclReducedDueToLowSoc_.setStyleSheet(limitStyleSheet);
    dclReducedDueToLowSoc_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&dclReducedDueToLowSoc_);
    dclReducedDueToLowSoc_.hide();

    dclReducedDueToTemperature_.resize(current_widthB, height);
    dclReducedDueToTemperature_.setText("DCL Reduced Due To Temperature");
    dclReducedDueToTemperature_.setStyleSheet(limitStyleSheet);
    dclReducedDueToTemperature_.setFixedSize(current_widthB, height);
    layoutB->addWidget(&dclReducedDueToTemperature_);
    dclReducedDueToTemperature_.hide();

    ui_.motor0ContentsWidget().setLayout(layout0);
    ui_.motor1ContentsWidget().setLayout(layout1);
    ui_.batteryContentsWidget().setLayout(layoutB);

    connectMotorFaults(motorFaultsPresenter_);
    connectBatteryFaults(batteryFaultsPresenter_);
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

    if (motorZeroErrorFlags.badMotorPositionHallSequence())
    {
        if (!badMotorPositionHallSequenceOn)
        {
            label0Count_++;
            badMotorPositionHallSequenceOn = true;

            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            badMotorPositionHallSequence0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.badMotorPositionHallSequence())
    {
        if (badMotorPositionHallSequenceOn)
        {

            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            configReadErrorOn = true;
            configReadError0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.configReadError())
    {
        if (configReadErrorOn)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            dcBusOverVoltageOn = true;
            dcBusOverVoltage0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.dcBusOverVoltage())
    {
        if (dcBusOverVoltageOn)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            desaturationFaultOn = true;
            desaturationFault0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.desaturationFault())
    {
        if (desaturationFaultOn)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            motorOverSpeedOn = true;
            motorOverSpeed0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.motorOverSpeed())
    {
        if (motorOverSpeedOn)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            railUnderVoltageLockOutOn = true;
            railUnderVoltageLockOut0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.railUnderVoltageLockOut())
    {
        if (railUnderVoltageLockOutOn)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            watchdogCausedLastReset = true;
            watchdogCausedLastReset0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.watchdogCausedLastReset())
    {
        if (watchdogCausedLastReset)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            softwareOverCurrent = true;
            softwareOverCurrent0Fault_.show();
        }
    }
    else if (!motorZeroErrorFlags.softwareOverCurrent())
    {
        if (softwareOverCurrent)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            busCurrentLimit = true;
            busCurrentLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.busCurrentLimit())
    {
        if (busCurrentLimit)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            busVoltageLowerLimit = true;
            busVoltageLowerLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.busVoltageLowerLimit())
    {
        if (busVoltageLowerLimit)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            busVoltageUpperLimit = true;
            busVoltageUpperLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.busVoltageUpperLimit())
    {
        if (busVoltageUpperLimit)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            ipmOrMotorTelemetryLimit = true;
            ipmOrMotorTelemetryLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.ipmOrMotorTelemetryLimit())
    {
        if (ipmOrMotorTelemetryLimit)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            motorCurrentLimit = true;
            motorCurrentLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.motorCurrentLimit())
    {
        if (motorCurrentLimit)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            outputVoltagePwmLimit = true;
            outputVoltagePwmLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.outputVoltagePwmLimit())
    {
        if (outputVoltagePwmLimit)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

            velocityLimit = true;
            velocityLimit0Fault_.show();
        }
    }
    else if (!motorZeroLimitFlags.velocityLimit())
    {
        if (velocityLimit)
        {
            if (label0Count_ >= labelResizeLimit)
            {
                ui_.motor0ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor0ContentsWidget().size().height();
            }

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

    if (motorOneErrorFlags.badMotorPositionHallSequence())
    {
        if (!badMotorPositionHallSequenceOn)
        {
            label1Count_++;
            badMotorPositionHallSequenceOn = true;

            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            badMotorPositionHallSequence1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.badMotorPositionHallSequence())
    {
        if (badMotorPositionHallSequenceOn)
        {

            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            configReadErrorOn = true;
            configReadError1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.configReadError())
    {
        if (configReadErrorOn)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            dcBusOverVoltageOn = true;
            dcBusOverVoltage1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.dcBusOverVoltage())
    {
        if (dcBusOverVoltageOn)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            desaturationFaultOn = true;
            desaturationFault1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.desaturationFault())
    {
        if (desaturationFaultOn)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            motorOverSpeedOn = true;
            motorOverSpeed1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.motorOverSpeed())
    {
        if (motorOverSpeedOn)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            railUnderVoltageLockOutOn = true;
            railUnderVoltageLockOut1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.railUnderVoltageLockOut())
    {
        if (railUnderVoltageLockOutOn)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            watchdogCausedLastReset = true;
            watchdogCausedLastReset1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.watchdogCausedLastReset())
    {
        if (watchdogCausedLastReset)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            softwareOverCurrent = true;
            softwareOverCurrent1Fault_.show();
        }
    }
    else if (!motorOneErrorFlags.softwareOverCurrent())
    {
        if (softwareOverCurrent)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            busCurrentLimit = true;
            busCurrentLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.busCurrentLimit())
    {
        if (busCurrentLimit)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            busVoltageLowerLimit = true;
            busVoltageLowerLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.busVoltageLowerLimit())
    {
        if (busVoltageLowerLimit)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            busVoltageUpperLimit = true;
            busVoltageUpperLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.busVoltageUpperLimit())
    {
        if (busVoltageUpperLimit)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            ipmOrMotorTelemetryLimit = true;
            ipmOrMotorTelemetryLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.ipmOrMotorTelemetryLimit())
    {
        if (ipmOrMotorTelemetryLimit)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            motorCurrentLimit = true;
            motorCurrentLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.motorCurrentLimit())
    {
        if (motorCurrentLimit)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            outputVoltagePwmLimit = true;
            outputVoltagePwmLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.outputVoltagePwmLimit())
    {
        if (outputVoltagePwmLimit)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

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
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            velocityLimit = true;
            velocityLimit1Fault_.show();
        }
    }
    else if (!motorOneLimitFlags.velocityLimit())
    {
        if (velocityLimit)
        {
            if (label1Count_ >= labelResizeLimit)
            {
                ui_.motor1ContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.motor1ContentsWidget().size().height();
            }

            label1Count_--;
            velocityLimit = false;
            velocityLimit1Fault_.hide();
        }
    }
}

void MotorFaultView::errorFlagsReceived(BatteryErrorFlags batteryErrorFlags)
{
    static bool alwaysOnSupplyFault = false;
    static bool canbusCommunicationsFault = false;
    static bool chargeLimitEnforcementFault = false;
    static bool chargerSafetyRelayFault = false;
    static bool currentSensorFault = false;
    static bool dischargeLimitEnforcementFault = false;
    static bool fanMonitorFault = false;
    static bool highVoltageIsolationFault = false;
    static bool internalCommununicationFault = false;
    static bool internalConversionFault = false;
    static bool internalLogicFault = false;
    static bool internalMemoryFault = false;
    static bool internalThermistorFault = false;
    static bool lowCellVoltageFault = false;
    static bool openWiringFault = false;
    static bool packVoltageSensorFault = false;
    static bool powerSupplyFault12V = false;
    static bool thermistorFault = false;
    static bool voltageRedundancyFault = false;
    static bool weakCellFault = false;
    static bool weakPackFault = false;

    int current_width = ui_.batteryContentsWidget().size().width();
    int current_height = ui_.batteryContentsWidget().size().height();

    if (batteryErrorFlags.alwaysOnSupplyFault())
    {
        if (!alwaysOnSupplyFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            alwaysOnSupplyFault = true;
            alwaysOnSupplyFault_.show();
        }
    }
    else if (!batteryErrorFlags.alwaysOnSupplyFault())
    {
        if (alwaysOnSupplyFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            alwaysOnSupplyFault = false;
            alwaysOnSupplyFault_.hide();
        }
    }

    if (batteryErrorFlags.canbusCommunicationsFault())
    {
        if (!canbusCommunicationsFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            canbusCommunicationsFault = true;
            canbusCommunicationsFault_.show();
        }
    }
    else if (!batteryErrorFlags.canbusCommunicationsFault())
    {
        if (canbusCommunicationsFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            canbusCommunicationsFault = false;
            canbusCommunicationsFault_.hide();
        }
    }

    if (batteryErrorFlags.chargeLimitEnforcementFault())
    {
        if (!chargeLimitEnforcementFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            chargeLimitEnforcementFault = true;
            chargeLimitEnforcementFault_.show();
        }
    }
    else if (!batteryErrorFlags.chargeLimitEnforcementFault())
    {
        if (chargeLimitEnforcementFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            chargeLimitEnforcementFault = false;
            chargeLimitEnforcementFault_.hide();
        }
    }

    if (batteryErrorFlags.chargerSafetyRelayFault())
    {
        if (!chargerSafetyRelayFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            chargerSafetyRelayFault = true;
            chargerSafetyRelayFault_.show();
        }
    }
    else if (!batteryErrorFlags.chargerSafetyRelayFault())
    {
        if (chargerSafetyRelayFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            chargerSafetyRelayFault = false;
            chargerSafetyRelayFault_.hide();
        }
    }

    if (batteryErrorFlags.currentSensorFault())
    {
        if (!currentSensorFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            currentSensorFault = true;
            currentSensorFault_.show();
        }
    }
    else if (!batteryErrorFlags.currentSensorFault())
    {
        if (currentSensorFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            currentSensorFault = false;
            currentSensorFault_.hide();
        }
    }

    if (batteryErrorFlags.dischargeLimitEnforcementFault())
    {
        if (!dischargeLimitEnforcementFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            dischargeLimitEnforcementFault = true;
            dischargeLimitEnforcementFault_.show();
        }
    }
    else if (!batteryErrorFlags.dischargeLimitEnforcementFault())
    {
        if (dischargeLimitEnforcementFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            dischargeLimitEnforcementFault = false;
            dischargeLimitEnforcementFault_.hide();
        }
    }

    if (batteryErrorFlags.fanMonitorFault())
    {
        if (!fanMonitorFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            fanMonitorFault = true;
            fanMonitorFault_.show();
        }
    }
    else if (!batteryErrorFlags.fanMonitorFault())
    {
        if (fanMonitorFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            fanMonitorFault = false;
            fanMonitorFault_.hide();
        }
    }

    if (batteryErrorFlags.highVoltageIsolationFault())
    {
        if (!highVoltageIsolationFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            highVoltageIsolationFault = true;
            highVoltageIsolationFault_.show();
        }
    }
    else if (!batteryErrorFlags.highVoltageIsolationFault())
    {
        if (highVoltageIsolationFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            highVoltageIsolationFault = false;
            highVoltageIsolationFault_.hide();
        }
    }

    if (batteryErrorFlags.internalCommununicationFault())
    {
        if (!internalCommununicationFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            internalCommununicationFault = true;
            internalCommununicationFault_.show();
        }
    }
    else if (!batteryErrorFlags.internalCommununicationFault())
    {
        if (internalCommununicationFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            internalCommununicationFault = false;
            internalCommununicationFault_.hide();
        }
    }

    if (batteryErrorFlags.internalConversionFault())
    {
        if (!internalConversionFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            internalConversionFault = true;
            internalConversionFault_.show();
        }
    }
    else if (!batteryErrorFlags.internalConversionFault())
    {
        if (internalConversionFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            internalConversionFault = false;
            internalConversionFault_.hide();
        }
    }

    if (batteryErrorFlags.internalLogicFault())
    {
        if (!internalLogicFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            internalLogicFault = true;
            internalLogicFault_.show();
        }
    }
    else if (!batteryErrorFlags.internalLogicFault())
    {
        if (internalLogicFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            internalLogicFault = false;
            internalLogicFault_.hide();
        }
    }

    if (batteryErrorFlags.internalMemoryFault())
    {
        if (!internalMemoryFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            internalMemoryFault = true;
            internalMemoryFault_.show();
        }
    }
    else if (!batteryErrorFlags.internalMemoryFault())
    {
        if (internalMemoryFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            internalMemoryFault = false;
            internalMemoryFault_.hide();
        }
    }

    if (batteryErrorFlags.internalThermistorFault())
    {
        if (!internalThermistorFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            internalThermistorFault = true;
            internalThermistorFault_.show();
        }
    }
    else if (!batteryErrorFlags.internalThermistorFault())
    {
        if (internalThermistorFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            internalThermistorFault = false;
            internalThermistorFault_.hide();
        }
    }

    if (batteryErrorFlags.lowCellVoltageFault())
    {
        if (!lowCellVoltageFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            lowCellVoltageFault = true;
            lowCellVoltageFault_.show();
        }
    }
    else if (!batteryErrorFlags.lowCellVoltageFault())
    {
        if (lowCellVoltageFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            lowCellVoltageFault = false;
            lowCellVoltageFault_.hide();
        }
    }

    if (batteryErrorFlags.openWiringFault())
    {
        if (!openWiringFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            openWiringFault = true;
            openWiringFault_.show();
        }
    }
    else if (!batteryErrorFlags.openWiringFault())
    {
        if (openWiringFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            openWiringFault = false;
            openWiringFault_.hide();
        }
    }

    if (batteryErrorFlags.packVoltageSensorFault())
    {
        if (!packVoltageSensorFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            packVoltageSensorFault = true;
            packVoltageSensorFault_.show();
        }
    }
    else if (!batteryErrorFlags.packVoltageSensorFault())
    {
        if (packVoltageSensorFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            packVoltageSensorFault = false;
            packVoltageSensorFault_.hide();
        }
    }

    if (batteryErrorFlags.powerSupplyFault12V())
    {
        if (!powerSupplyFault12V)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            powerSupplyFault12V = true;
            powerSupplyFault12V_.show();
        }
    }
    else if (!batteryErrorFlags.powerSupplyFault12V())
    {
        if (powerSupplyFault12V)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            powerSupplyFault12V = false;
            powerSupplyFault12V_.hide();
        }
    }

    if (batteryErrorFlags.thermistorFault())
    {
        if (!thermistorFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            thermistorFault = true;
            thermistorFault_.show();
        }
    }
    else if (!batteryErrorFlags.thermistorFault())
    {
        if (thermistorFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            thermistorFault = false;
            thermistorFault_.hide();
        }
    }

    if (batteryErrorFlags.voltageRedundancyFault())
    {
        if (!voltageRedundancyFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            voltageRedundancyFault = true;
            voltageRedundancyFault_.show();
        }
    }
    else if (!batteryErrorFlags.voltageRedundancyFault())
    {
        if (voltageRedundancyFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            voltageRedundancyFault = false;
            voltageRedundancyFault_.hide();
        }
    }

    if (batteryErrorFlags.weakCellFault())
    {
        if (!weakCellFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            weakCellFault = true;
            weakCellFault_.show();
        }
    }
    else if (!batteryErrorFlags.weakCellFault())
    {
        if (weakCellFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            weakCellFault = false;
            weakCellFault_.hide();
        }
    }

    if (batteryErrorFlags.weakPackFault())
    {
        if (!weakPackFault)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            weakPackFault = true;
            weakPackFault_.show();
        }
    }
    else if (!batteryErrorFlags.weakPackFault())
    {
        if (weakPackFault)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            weakPackFault = false;
            weakPackFault_.hide();
        }
    }
}

void MotorFaultView::limitFlagsReceived(BatteryLimitFlags batteryLimitFlags)
{
    static bool cclReducedDueToAlternateCurrentLimit = false;
    static bool cclReducedDueToChargerLatch = false;
    static bool cclReducedDueToHighCellResistance = false;
    static bool cclReducedDueToHighCellVoltage = false;
    static bool cclReducedDueToHighPackVoltage = false;
    static bool cclReducedDueToHighSoc = false;
    static bool cclReducedDueToTemperature = false;
    static bool dclandCclReducedDueToCommunicationFailsafe = false;
    static bool dclandCclReducedDueToVoltageFailsafe = false;
    static bool dclReducedDueToHighCellResistance = false;
    static bool dclReducedDueToLowCellVoltage = false;
    static bool dclReducedDueToLowPackVoltage = false;
    static bool dclReducedDueToLowSoc = false;
    static bool dclReducedDueToTemperature = false;

    int current_width = ui_.batteryContentsWidget().size().width();
    int current_height = ui_.batteryContentsWidget().size().height();

    if (batteryLimitFlags.cclReducedDueToAlternateCurrentLimit())
    {
        if (!cclReducedDueToAlternateCurrentLimit)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            cclReducedDueToAlternateCurrentLimit = true;
            cclReducedDueToAlternateCurrentLimit_.show();
        }
    }
    else if (!batteryLimitFlags.cclReducedDueToAlternateCurrentLimit())
    {
        if (cclReducedDueToAlternateCurrentLimit)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            cclReducedDueToAlternateCurrentLimit = false;
            cclReducedDueToAlternateCurrentLimit_.hide();
        }
    }

    if (batteryLimitFlags.cclReducedDueToChargerLatch())
    {
        if (!cclReducedDueToChargerLatch)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            cclReducedDueToChargerLatch = true;
            cclReducedDueToChargerLatch_.show();
        }
    }
    else if (!batteryLimitFlags.cclReducedDueToChargerLatch())
    {
        if (cclReducedDueToChargerLatch)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            cclReducedDueToChargerLatch = false;
            cclReducedDueToChargerLatch_.hide();
        }
    }

    if (batteryLimitFlags.cclReducedDueToHighCellResistance())
    {
        if (!cclReducedDueToHighCellResistance)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            cclReducedDueToHighCellResistance = true;
            cclReducedDueToHighCellResistance_.show();
        }
    }
    else if (!batteryLimitFlags.cclReducedDueToHighCellResistance())
    {
        if (cclReducedDueToHighCellResistance)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            cclReducedDueToHighCellResistance = false;
            cclReducedDueToHighCellResistance_.hide();
        }
    }

    if (batteryLimitFlags.cclReducedDueToHighCellVoltage())
    {
        if (!cclReducedDueToHighCellVoltage)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            cclReducedDueToHighCellVoltage = true;
            cclReducedDueToHighCellVoltage_.show();
        }
    }
    else if (!batteryLimitFlags.cclReducedDueToHighCellVoltage())
    {
        if (cclReducedDueToHighCellVoltage)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            cclReducedDueToHighCellVoltage = false;
            cclReducedDueToHighCellVoltage_.hide();
        }
    }

    if (batteryLimitFlags.cclReducedDueToHighPackVoltage())
    {
        if (!cclReducedDueToHighPackVoltage)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            cclReducedDueToHighPackVoltage = true;
            cclReducedDueToHighPackVoltage_.show();
        }
    }
    else if (!batteryLimitFlags.cclReducedDueToHighPackVoltage())
    {
        if (cclReducedDueToHighPackVoltage)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            cclReducedDueToHighPackVoltage = false;
            cclReducedDueToHighPackVoltage_.hide();
        }
    }

    if (batteryLimitFlags.cclReducedDueToHighSoc())
    {
        if (!cclReducedDueToHighSoc)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            cclReducedDueToHighSoc = true;
            cclReducedDueToHighSoc_.show();
        }
    }
    else if (!batteryLimitFlags.cclReducedDueToHighSoc())
    {
        if (cclReducedDueToHighSoc)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            cclReducedDueToHighSoc = false;
            cclReducedDueToHighSoc_.hide();
        }
    }

    if (batteryLimitFlags.cclReducedDueToTemperature())
    {
        if (!cclReducedDueToTemperature)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            cclReducedDueToTemperature = true;
            cclReducedDueToTemperature_.show();
        }
    }
    else if (!batteryLimitFlags.cclReducedDueToTemperature())
    {
        if (cclReducedDueToTemperature)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            cclReducedDueToTemperature = false;
            cclReducedDueToTemperature_.hide();
        }
    }

    if (batteryLimitFlags.dclandCclReducedDueToCommunicationFailsafe())
    {
        if (!dclandCclReducedDueToCommunicationFailsafe)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            dclandCclReducedDueToCommunicationFailsafe = true;
            dclandCclReducedDueToCommunicationFailsafe_.show();
        }
    }
    else if (!batteryLimitFlags.dclandCclReducedDueToCommunicationFailsafe())
    {
        if (dclandCclReducedDueToCommunicationFailsafe)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            dclandCclReducedDueToCommunicationFailsafe = false;
            dclandCclReducedDueToCommunicationFailsafe_.hide();
        }
    }

    if (batteryLimitFlags.dclandCclReducedDueToVoltageFailsafe())
    {
        if (!dclandCclReducedDueToVoltageFailsafe)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            dclandCclReducedDueToVoltageFailsafe = true;
            dclandCclReducedDueToVoltageFailsafe_.show();
        }
    }
    else if (!batteryLimitFlags.dclandCclReducedDueToVoltageFailsafe())
    {
        if (dclandCclReducedDueToVoltageFailsafe)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            dclandCclReducedDueToVoltageFailsafe = false;
            dclandCclReducedDueToVoltageFailsafe_.hide();
        }
    }

    if (batteryLimitFlags.dclReducedDueToHighCellResistance())
    {
        if (!dclReducedDueToHighCellResistance)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            dclReducedDueToHighCellResistance = true;
            dclReducedDueToHighCellResistance_.show();
        }
    }
    else if (!batteryLimitFlags.dclReducedDueToHighCellResistance())
    {
        if (dclReducedDueToHighCellResistance)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            dclReducedDueToHighCellResistance = false;
            dclReducedDueToHighCellResistance_.hide();
        }
    }

    if (batteryLimitFlags.dclReducedDueToLowCellVoltage())
    {
        if (!dclReducedDueToLowCellVoltage)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            dclReducedDueToLowCellVoltage = true;
            dclReducedDueToLowCellVoltage_.show();
        }
    }
    else if (!batteryLimitFlags.dclReducedDueToLowCellVoltage())
    {
        if (dclReducedDueToLowCellVoltage)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            dclReducedDueToLowCellVoltage = false;
            dclReducedDueToLowCellVoltage_.hide();
        }
    }

    if (batteryLimitFlags.dclReducedDueToLowPackVoltage())
    {
        if (!dclReducedDueToLowPackVoltage)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            dclReducedDueToLowPackVoltage = true;
            dclReducedDueToLowPackVoltage_.show();
        }
    }
    else if (!batteryLimitFlags.dclReducedDueToLowPackVoltage())
    {
        if (dclReducedDueToLowPackVoltage)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            dclReducedDueToLowPackVoltage = false;
            dclReducedDueToLowPackVoltage_.hide();
        }
    }

    if (batteryLimitFlags.dclReducedDueToLowSoc())
    {
        if (!dclReducedDueToLowSoc)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            dclReducedDueToLowSoc = true;
            dclReducedDueToLowSoc_.show();
        }
    }
    else if (!batteryLimitFlags.dclReducedDueToLowSoc())
    {
        if (dclReducedDueToLowSoc)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            dclReducedDueToLowSoc = false;
            dclReducedDueToLowSoc_.hide();
        }
    }

    if (batteryLimitFlags.dclReducedDueToTemperature())
    {
        if (!dclReducedDueToTemperature)
        {
            labelBcount_++;

            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height + height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            dclReducedDueToTemperature = true;
            dclReducedDueToTemperature_.show();
        }
    }
    else if (!batteryLimitFlags.dclReducedDueToTemperature())
    {
        if (dclReducedDueToTemperature)
        {
            if (labelBcount_ >= labelResizeLimit)
            {
                ui_.batteryContentsWidget().setFixedSize(current_width, current_height - height);
                current_height = ui_.batteryContentsWidget().size().height();
            }

            labelBcount_--;
            dclReducedDueToTemperature = false;
            dclReducedDueToTemperature_.hide();
        }
    }
}
