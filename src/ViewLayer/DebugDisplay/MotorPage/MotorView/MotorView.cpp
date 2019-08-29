#include "MotorView.h"

namespace
{
const QString MOTOR_ALIVE = "background-color:rgb(93, 234, 140); \
                          border-radius:8px; \
                          border: 1px solid white;";
const QString MOTOR_DEAD = "background-color:rgb(147, 147, 147); \
                         border-radius:8px; \
                         border: 1px solid white;";
}

MotorView::MotorView(KeyMotorPresenter& keyMotorPresenter, MotorDetailsPresenter& motorDetailsPresenter,
                     I_MotorUi& ui)
    : keyMotorPresenter_(keyMotorPresenter)
    , motorDetailsPresenter_(motorDetailsPresenter)
    , ui_(ui)
{
    connectMotor(keyMotorPresenter_, motorDetailsPresenter_ );
}

MotorView::~MotorView()
{

}
void MotorView::connectMotor(KeyMotorPresenter& keyMotorPresenter, MotorDetailsPresenter& motorDetailsPresenter)
{
    connect(&keyMotorPresenter, SIGNAL(motorZeroReceived(KeyMotor)),
            this, SLOT(motorZeroReceived(KeyMotor)));
    connect(&keyMotorPresenter, SIGNAL(motorOneReceived(KeyMotor)),
            this, SLOT(motorOneReceived(KeyMotor)));
    connect(&keyMotorPresenter, SIGNAL(motorSetCurrentReceived(double)),
            this, SLOT(motorSetCurrentReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorActualSpeedReceived(double)),
            this, SLOT(motorActualSpeedReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorBusVoltageReceived(double)),
            this, SLOT(motorBusVoltageReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorBusCurrentReceived(double)),
            this, SLOT(motorBusCurrentReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorZeroAlive(bool)),
            this, SLOT(leftAliveRecieved(bool)));
    connect(&keyMotorPresenter, SIGNAL(motorOneAlive(bool)),
            this, SLOT(rightAliveRecieved(bool)));

    connect(&motorDetailsPresenter, SIGNAL(motorZeroDetailsReceived(MotorDetails)),
            this, SLOT(motorZeroDetailsReceived(MotorDetails)));
    connect(&motorDetailsPresenter, SIGNAL(motorOneDetailsReceived(MotorDetails)),
            this, SLOT(motorOneDetailsReceived(MotorDetails)));
}

void MotorView::leftAliveRecieved(bool alive){
    if(alive)
    {
        ui_.leftAliveWidget().setStyleSheet(MOTOR_ALIVE);
    }
    else
    {
         ui_.leftAliveWidget().setStyleSheet(MOTOR_DEAD);
    }
}

void MotorView::rightAliveRecieved(bool alive){
    if(alive)
    {
        ui_.rightAliveWidget().setStyleSheet(MOTOR_ALIVE);
    }
    else
    {
         ui_.rightAliveWidget().setStyleSheet(MOTOR_DEAD);
    }
}

void MotorView::motorZeroReceived(KeyMotor motorZero)
{

    ui_.setCurrentLeftLabel().setNum(motorZero.setCurrent());
    ui_.setVelocityLeftLabel().setNum(motorZero.setVelocity());
    setVelocityLeft_ = motorZero.setVelocity();
    ui_.busCurrentLeftLabel().setNum(motorZero.busCurrent());
    ui_.busVoltageLeftLabel().setNum(motorZero.busVoltage());
    ui_.vehicleVelocityLeftLabel().setNum(motorZero.vehicleVelocity());

    ui_.setVelocityAvgLabel().setNum((motorZero.setVelocity() +
                                      setVelocityRight_) / 2);
}

void MotorView::motorOneReceived(KeyMotor motorOne)
{
    ui_.setCurrentRightLabel().setNum(motorOne.setCurrent());
    ui_.setVelocityRightLabel().setNum(motorOne.setVelocity());
    setVelocityRight_ = motorOne.setVelocity();
    ui_.busCurrentRightLabel().setNum(motorOne.busCurrent());
    ui_.busVoltageRightLabel().setNum(motorOne.busVoltage());
    ui_.vehicleVelocityRightLabel().setNum(motorOne.vehicleVelocity());

    ui_.setVelocityAvgLabel().setNum((motorOne.setVelocity() +
                                      setVelocityLeft_) / 2);
}

void MotorView::motorSetCurrentReceived(double setCurrent)
{
    ui_.setCurrentAvgLabel().setNum(setCurrent);
}

void MotorView::motorActualSpeedReceived(double vehicleVelocity)
{
    ui_.vehicleVelocityAvgLabel().setNum(vehicleVelocity);
}

void MotorView::motorBusVoltageReceived(double busVoltage)
{
    ui_.busVoltageAvgLabel().setNum(busVoltage);
}

void MotorView::motorBusCurrentReceived(double busCurrent)
{
    ui_.busCurrentAvgLabel().setNum(busCurrent);
}


void MotorView::motorZeroDetailsReceived(MotorDetails motorZeroDetails)
{

    ui_.phaseCCurrentLeftLabel().setNum(motorZeroDetails.phaseCCurrent());
    ui_.phaseBCurrentLeftLabel().setNum(motorZeroDetails.phaseBCurrent());

    ui_.motorVoltageRealLeftLabel().setNum(motorZeroDetails.motorVoltageReal());
    ui_.motorVoltageImaginaryLeftLabel().setNum(motorZeroDetails.motorVoltageImaginary());

    ui_.motorCurrentRealLeftLabel().setNum(motorZeroDetails.motorCurrentReal());
    ui_.motorCurrentImaginaryLeftLabel().setNum(motorZeroDetails.motorCurrentImaginary());

    ui_.backEmfLeftLabel().setNum((motorZeroDetails.backEmf()));

    ui_.voltageRail3VSupplyLeftLabel().setNum(motorZeroDetails.voltageRail3VSupply());
    ui_.voltageRail1VSupplyLeftLabel().setNum(motorZeroDetails.voltageRail1VSupply());
    ui_.voltageRail15VSupplyLeftLabel().setNum(motorZeroDetails.voltageRail15VSupply());

    ui_.heatSinkTempLeftLabel().setNum(motorZeroDetails.heatSinkTemp());
    ui_.motorTempLeftLabel().setNum(motorZeroDetails.motorTemp());
    ui_.dspBoardTempLeftLabel().setNum(motorZeroDetails.dspBoardTemp());

    ui_.dcBusAmpHoursLeftLabel().setNum(motorZeroDetails.dcBusAmpHours());
    ui_.odometerLeftLabel().setNum(motorZeroDetails.odometer());
    ui_.slipSpeedLeftLabel().setNum(motorZeroDetails.slipSpeed());

    phaseCCurrentLeft_ = motorZeroDetails.phaseCCurrent();
    phaseBCurrentLeft_ = motorZeroDetails.phaseBCurrent();
    motorVoltageRealLeft_ = motorZeroDetails.motorVoltageReal();
    motorVoltageImaginaryLeft_ = motorZeroDetails.motorVoltageImaginary();
    motorCurrentRealLeft_ = motorZeroDetails.motorCurrentReal();
    motorCurrentImaginaryLeft_ = motorZeroDetails.motorCurrentImaginary();
    backEmfLeft_ = motorZeroDetails.backEmf();
    voltageRail3VSupplyLeft_ = motorZeroDetails.voltageRail3VSupply();
    voltageRail1VSupplyLeft_ = motorZeroDetails.voltageRail1VSupply();
    voltageRail15VSupplyLeft_ = motorZeroDetails.voltageRail15VSupply();
    heatSinkTempLeft_ = motorZeroDetails.heatSinkTemp();
    motorTempLeft_ = motorZeroDetails.motorTemp();
    dspBoardTempLeft_ = motorZeroDetails.dspBoardTemp();
    dcBusAmpHoursLeft_ = motorZeroDetails.dcBusAmpHours();
    odometerLeft_ = motorZeroDetails.odometer();
    slipSpeedLeft_ = motorZeroDetails.slipSpeed();

    setMotorDetailsAverageLabels();

}

void MotorView::motorOneDetailsReceived(MotorDetails motorOneDetails)
{

    ui_.phaseCCurrentRightLabel().setNum(motorOneDetails.phaseCCurrent());
    ui_.phaseBCurrentRightLabel().setNum(motorOneDetails.phaseBCurrent());

    ui_.motorVoltageRealRightLabel().setNum(motorOneDetails.motorVoltageReal());
    ui_.motorVoltageImaginaryRightLabel().setNum(motorOneDetails.motorVoltageImaginary());

    ui_.motorCurrentRealRightLabel().setNum(motorOneDetails.motorCurrentReal());
    ui_.motorCurrentImaginaryRightLabel().setNum(motorOneDetails.motorCurrentImaginary());

    ui_.backEmfRightLabel().setNum((motorOneDetails.backEmf()));

    ui_.voltageRail15VSupplyRightLabel().setNum(motorOneDetails.voltageRail15VSupply());
    ui_.voltageRail3VSupplyRightLabel().setNum(motorOneDetails.voltageRail3VSupply());
    ui_.voltageRail1VSupplyRightLabel().setNum(motorOneDetails.voltageRail1VSupply());

    ui_.heatSinkTempRightLabel().setNum(motorOneDetails.heatSinkTemp());
    ui_.motorTempRightLabel().setNum(motorOneDetails.motorTemp());
    ui_.dspBoardTempRightLabel().setNum(motorOneDetails.dspBoardTemp());

    ui_.dcBusAmpHoursRightLabel().setNum(motorOneDetails.dcBusAmpHours());
    ui_.odometerRightLabel().setNum(motorOneDetails.odometer());
    ui_.slipSpeedRightLabel().setNum(motorOneDetails.slipSpeed());

    phaseCCurrentRight_ = motorOneDetails.phaseCCurrent();
    phaseBCurrentRight_ = motorOneDetails.phaseBCurrent();
    motorVoltageRealRight_ = motorOneDetails.motorVoltageReal();
    motorVoltageImaginaryRight_ = motorOneDetails.motorVoltageImaginary();
    motorCurrentRealRight_ = motorOneDetails.motorCurrentReal();
    motorCurrentImaginaryRight_ = motorOneDetails.motorCurrentImaginary();
    backEmfRight_ = motorOneDetails.backEmf();
    voltageRail3VSupplyRight_ = motorOneDetails.voltageRail3VSupply();
    voltageRail1VSupplyRight_ = motorOneDetails.voltageRail1VSupply();
    voltageRail15VSupplyRight_ = motorOneDetails.voltageRail15VSupply();
    heatSinkTempRight_ = motorOneDetails.heatSinkTemp();
    motorTempRight_ = motorOneDetails.motorTemp();
    dspBoardTempRight_ = motorOneDetails.dspBoardTemp();
    dcBusAmpHoursRight_ = motorOneDetails.dcBusAmpHours();
    odometerRight_ = motorOneDetails.odometer();
    slipSpeedRight_ = motorOneDetails.slipSpeed();


    setMotorDetailsAverageLabels();

}

void MotorView::setMotorDetailsAverageLabels()
{
    ui_.phaseCCurrentAvgLabel().setNum((phaseCCurrentLeft_ + phaseCCurrentRight_) / 2);

    ui_.phaseBCurrentAvgLabel().setNum((phaseBCurrentLeft_ + phaseBCurrentRight_) / 2);

    ui_.motorVoltageRealAvgLabel().setNum((motorVoltageRealLeft_ + motorVoltageRealRight_) / 2);

    ui_.motorVoltageImaginaryAvgLabel().setNum((motorVoltageImaginaryLeft_ + motorVoltageImaginaryRight_) / 2);

    ui_.motorCurrentRealAvgLabel().setNum((motorCurrentRealLeft_ + motorCurrentRealRight_) / 2);

    ui_.motorCurrentImaginaryAvgLabel().setNum((motorCurrentImaginaryLeft_ + motorCurrentImaginaryRight_) / 2);

    ui_.backEmfAvgLabel().setNum((backEmfLeft_ + backEmfRight_) / 2);

    ui_.voltageRail3VSupplyAvgLabel().setNum((voltageRail3VSupplyLeft_ + voltageRail3VSupplyRight_) / 2);

    ui_.voltageRail1VSupplyAvgLabel().setNum((voltageRail1VSupplyLeft_ + voltageRail1VSupplyRight_) / 2);

    ui_.voltageRail15VSupplyAvgLabel().setNum((voltageRail15VSupplyLeft_ + voltageRail15VSupplyRight_) / 2);

    ui_.heatSinkTempAvgLabel().setNum((heatSinkTempLeft_ + heatSinkTempRight_) / 2 );

    ui_.motorTempAvgLabel().setNum((motorTempLeft_ + motorTempRight_) / 2);

    ui_.dspBoardTempAvgLabel().setNum((dspBoardTempLeft_ + dspBoardTempRight_) / 2);

    ui_.dcBusAmpHoursAvgLabel().setNum((dcBusAmpHoursLeft_ + dcBusAmpHoursRight_) / 2);

    ui_.odometerAvgLabel().setNum((odometerLeft_ + odometerRight_) / 2);

    ui_.slipSpeedAvgLabel().setNum((slipSpeedLeft_ + slipSpeedRight_) / 2);
}
