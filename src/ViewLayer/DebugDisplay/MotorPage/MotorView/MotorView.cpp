#include "MotorView.h"

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

    connect(&motorDetailsPresenter, SIGNAL(motorZeroDetailsReceived(MotorDetails)),
            this, SLOT(motorZeroDetailsReceived(MotorDetails)));
    connect(&motorDetailsPresenter, SIGNAL(motorOneDetailsReceived(MotorDetails)),
            this, SLOT(motorOneDetailsReceived(MotorDetails)));
}


void MotorView::motorZeroReceived(KeyMotor motorZero)
{

    ui_.setCurrentLeftLabel().setNum(motorZero.setCurrent());
    ui_.setVelocityLeftLabel().setNum(motorZero.setVelocity());
    ui_.busCurrentLeftLabel().setNum(motorZero.busCurrent());
    ui_.busVoltageLeftLabel().setNum(motorZero.busVoltage());
    ui_.vehicleVelocityLeftLabel().setNum(motorZero.vehicleVelocity());

    ui_.setVelocityAvgLabel().setNum((motorZero.setVelocity() +
                                      ui_.setVelocityRightLabel().text().toInt()) / 2);
}

void MotorView::motorOneReceived(KeyMotor motorOne)
{
    ui_.setCurrentRightLabel().setNum(motorOne.setCurrent());
    ui_.setVelocityRightLabel().setNum(motorOne.setVelocity());
    ui_.busCurrentRightLabel().setNum(motorOne.busCurrent());
    ui_.busVoltageRightLabel().setNum(motorOne.busVoltage());
    ui_.vehicleVelocityRightLabel().setNum(motorOne.vehicleVelocity());

    ui_.setVelocityAvgLabel().setNum((motorOne.setVelocity() +
                                      ui_.setVelocityLeftLabel().text().toInt()) / 2);
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

    ui_.phaseCCurrentAvgLabel().setNum((motorZeroDetails.phaseCCurrent() +
                                        ui_.phaseCCurrentRightLabel().text().toInt()) / 2);

    ui_.phaseBCurrentAvgLabel().setNum((motorZeroDetails.phaseBCurrent() +
                                        ui_.phaseBCurrentRightLabel().text().toInt()) / 2);

    ui_.motorVoltageRealAvgLabel().setNum((motorZeroDetails.motorVoltageReal() +
                                           ui_.motorVoltageRealRightLabel().text().toInt()) / 2);

    ui_.motorVoltageImaginaryAvgLabel().setNum((motorZeroDetails.motorVoltageImaginary() +
            ui_.motorVoltageImaginaryRightLabel().text().toInt()) / 2);

    ui_.motorCurrentRealAvgLabel().setNum((motorZeroDetails.motorCurrentReal() +
                                           ui_.motorCurrentRealRightLabel().text().toInt()) / 2);

    ui_.motorCurrentImaginaryAvgLabel().setNum((motorZeroDetails.motorCurrentImaginary() +
            ui_.motorCurrentImaginaryRightLabel().text().toInt()) / 2);

    ui_.backEmfAvgLabel().setNum((motorZeroDetails.backEmf() +
                                  ui_.backEmfRightLabel().text().toInt()) / 2);

    ui_.voltageRail3VSupplyAvgLabel().setNum((motorZeroDetails.voltageRail3VSupply() +
            ui_.voltageRail3VSupplyRightLabel().text().toInt()) / 2);

    ui_.voltageRail1VSupplyAvgLabel().setNum((motorZeroDetails.voltageRail1VSupply() +
            ui_.voltageRail1VSupplyRightLabel().text().toInt()) / 2);

    ui_.voltageRail15VSupplyAvgLabel().setNum((motorZeroDetails.voltageRail15VSupply() +
            ui_.voltageRail15VSupplyRightLabel().text().toInt()) / 2);

    ui_.heatSinkTempAvgLabel().setNum((motorZeroDetails.heatSinkTemp() +
                                       ui_.heatSinkTempRightLabel().text().toInt()) / 2 );

    ui_.motorTempAvgLabel().setNum((motorZeroDetails.motorTemp() +
                                    ui_.motorTempRightLabel().text().toInt()) / 2);

    ui_.dspBoardTempAvgLabel().setNum((motorZeroDetails.dspBoardTemp() +
                                       ui_.dspBoardTempRightLabel().text().toInt()) / 2);

    ui_.dcBusAmpHoursAvgLabel().setNum((motorZeroDetails.dcBusAmpHours() +
                                        ui_.dcBusAmpHoursRightLabel().text().toInt()) / 2);

    ui_.odometerAvgLabel().setNum((motorZeroDetails.odometer() +
                                   ui_.odometerRightLabel().text().toInt()) / 2);

    ui_.slipSpeedAvgLabel().setNum((motorZeroDetails.slipSpeed() +
                                    ui_.slipSpeedRightLabel().text().toInt()) / 2);


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

    ui_.phaseCCurrentAvgLabel().setNum((motorOneDetails.phaseCCurrent() +
                                        ui_.phaseCCurrentLeftLabel().text().toInt()) / 2);

    ui_.phaseBCurrentAvgLabel().setNum((motorOneDetails.phaseBCurrent() +
                                        ui_.phaseBCurrentLeftLabel().text().toInt()) / 2);

    ui_.motorVoltageRealAvgLabel().setNum((motorOneDetails.motorVoltageReal() +
                                           ui_.motorVoltageRealLeftLabel().text().toInt()) / 2);

    ui_.motorVoltageImaginaryAvgLabel().setNum((motorOneDetails.motorVoltageImaginary() +
            ui_.motorVoltageImaginaryLeftLabel().text().toInt()) / 2);

    ui_.motorCurrentRealAvgLabel().setNum((motorOneDetails.motorCurrentReal() +
                                           ui_.motorCurrentRealLeftLabel().text().toInt()) / 2);

    ui_.motorCurrentImaginaryAvgLabel().setNum((motorOneDetails.motorCurrentImaginary() +
            ui_.motorCurrentImaginaryLeftLabel().text().toInt()) / 2);

    ui_.backEmfAvgLabel().setNum((motorOneDetails.backEmf() +
                                  ui_.backEmfLeftLabel().text().toInt()) / 2);

    ui_.voltageRail3VSupplyAvgLabel().setNum((motorOneDetails.voltageRail3VSupply() +
            ui_.voltageRail3VSupplyLeftLabel().text().toInt()) / 2);

    ui_.voltageRail1VSupplyAvgLabel().setNum((motorOneDetails.voltageRail1VSupply() +
            ui_.voltageRail1VSupplyLeftLabel().text().toInt()) / 2);

    ui_.voltageRail15VSupplyAvgLabel().setNum((motorOneDetails.voltageRail15VSupply() +
            ui_.voltageRail15VSupplyLeftLabel().text().toInt()) / 2);

    ui_.heatSinkTempAvgLabel().setNum((motorOneDetails.heatSinkTemp() +
                                       ui_.heatSinkTempLeftLabel().text().toInt()) / 2 );

    ui_.motorTempAvgLabel().setNum((motorOneDetails.motorTemp() +
                                    ui_.motorTempLeftLabel().text().toInt()) / 2);

    ui_.dspBoardTempAvgLabel().setNum((motorOneDetails.dspBoardTemp() +
                                       ui_.dspBoardTempLeftLabel().text().toInt()) / 2);

    ui_.dcBusAmpHoursAvgLabel().setNum((motorOneDetails.dcBusAmpHours() +
                                        ui_.dcBusAmpHoursLeftLabel().text().toInt()) / 2);

    ui_.odometerAvgLabel().setNum((motorOneDetails.odometer() +
                                   ui_.odometerLeftLabel().text().toInt()) / 2);

    ui_.slipSpeedAvgLabel().setNum((motorOneDetails.slipSpeed() +
                                    ui_.slipSpeedLeftLabel().text().toInt()) / 2);
}

