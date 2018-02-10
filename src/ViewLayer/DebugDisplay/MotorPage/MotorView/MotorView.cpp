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


void MotorView::motorZeroReceived(KeyMotor)
{
    KeyMotor keyMotorLeft = KeyMotor();

    ui_.setCurrentLeftLabel().setNum(keyMotorLeft.setCurrent());
    ui_.setVelocityLeftLabel().setNum(keyMotorLeft.setVelocity());
    ui_.busCurrentLeftLabel().setNum(keyMotorLeft.busCurrent());
    ui_.busVoltageLeftLabel().setNum(keyMotorLeft.busVoltage());
    ui_.vehicleVelocityLeftLabel().setNum(keyMotorLeft.vehicleVelocity());

    ui_.setVelocityAvgLabel().setNum((keyMotorLeft.setVelocity() +
                                      ui_.setVelocityRightLabel().text().toInt()) / 2);
}

void MotorView::motorOneReceived(KeyMotor)
{
    KeyMotor keyMotorRight = KeyMotor();

    ui_.setCurrentRightLabel().setNum(keyMotorRight.setCurrent());
    ui_.setVelocityRightLabel().setNum(keyMotorRight.setVelocity());
    ui_.busCurrentRightLabel().setNum(keyMotorRight.busCurrent());
    ui_.busVoltageRightLabel().setNum(keyMotorRight.busVoltage());
    ui_.vehicleVelocityRightLabel().setNum(keyMotorRight.vehicleVelocity());

    ui_.setVelocityAvgLabel().setNum((keyMotorRight.setVelocity() +
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


void MotorView::motorZeroDetailsReceived(MotorDetails)
{
    MotorDetails motorDetailsLeft = MotorDetails();

    ui_.phaseCCurrentLeftLabel().setNum(motorDetailsLeft.phaseCCurrent());
    ui_.phaseBCurrentLeftLabel().setNum(motorDetailsLeft.phaseBCurrent());

    ui_.motorVoltageRealLeftLabel().setNum(motorDetailsLeft.motorVoltageReal());
    ui_.motorVoltageImaginaryLeftLabel().setNum(motorDetailsLeft.motorVoltageImaginary());

    ui_.motorCurrentRealLeftLabel().setNum(motorDetailsLeft.motorCurrentReal());
    ui_.motorCurrentImaginaryLeftLabel().setNum(motorDetailsLeft.motorCurrentImaginary());

    ui_.backEmfLeftLabel().setNum((motorDetailsLeft.backEmf()));


    ui_.voltageRail3VSupplyLeftLabel().setNum(motorDetailsLeft.voltageRail3VSupply());
    ui_.voltageRail1VSupplyLeftLabel().setNum(motorDetailsLeft.voltageRail1VSupply());
    ui_.voltageRail15VSupplyLeftLabel().setNum(motorDetailsLeft.voltageRail15VSupply());

    ui_.heatSinkTempLeftLabel().setNum(motorDetailsLeft.heatSinkTemp());
    ui_.motorTempLeftLabel().setNum(motorDetailsLeft.motorTemp());
    ui_.dspBoardTempLeftLabel().setNum(motorDetailsLeft.dspBoardTemp());

    ui_.dcBusAmpHoursLeftLabel().setNum(motorDetailsLeft.dcBusAmpHours());
    ui_.odometerLeftLabel().setNum(motorDetailsLeft.odometer());
    ui_.slipSpeedLeftLabel().setNum(motorDetailsLeft.slipSpeed());

    ui_.phaseCCurrentAvgLabel().setNum((motorDetailsLeft.phaseCCurrent() +
                                        ui_.phaseCCurrentRightLabel().text().toInt()) / 2);

    ui_.phaseBCurrentAvgLabel().setNum((motorDetailsLeft.phaseBCurrent() +
                                        ui_.phaseBCurrentRightLabel().text().toInt()) / 2);

    ui_.motorVoltageRealAvgLabel().setNum((motorDetailsLeft.motorVoltageReal() +
                                           ui_.motorVoltageRealRightLabel().text().toInt()) / 2);

    ui_.motorVoltageImaginaryAvgLabel().setNum((motorDetailsLeft.motorVoltageImaginary() +
            ui_.motorVoltageImaginaryRightLabel().text().toInt()) / 2);

    ui_.motorCurrentRealAvgLabel().setNum((motorDetailsLeft.motorCurrentReal() +
                                           ui_.motorCurrentRealRightLabel().text().toInt()) / 2);

    ui_.motorCurrentImaginaryAvgLabel().setNum((motorDetailsLeft.motorCurrentImaginary() +
            ui_.motorCurrentImaginaryRightLabel().text().toInt()) / 2);

    ui_.backEmfAvgLabel().setNum((motorDetailsLeft.backEmf() +
                                  ui_.backEmfRightLabel().text().toInt()) / 2);

    ui_.voltageRail3VSupplyAvgLabel().setNum((motorDetailsLeft.voltageRail3VSupply() +
            ui_.voltageRail3VSupplyRightLabel().text().toInt()) / 2);

    ui_.voltageRail1VSupplyAvgLabel().setNum((motorDetailsLeft.voltageRail1VSupply() +
            ui_.voltageRail1VSupplyRightLabel().text().toInt()) / 2);

    ui_.voltageRail15VSupplyAvgLabel().setNum((motorDetailsLeft.voltageRail15VSupply() +
            ui_.voltageRail15VSupplyRightLabel().text().toInt()) / 2);

    ui_.heatSinkTempAvgLabel().setNum((motorDetailsLeft.heatSinkTemp() +
                                       ui_.heatSinkTempRightLabel().text().toInt()) / 2 );

    ui_.motorTempAvgLabel().setNum((motorDetailsLeft.motorTemp() +
                                    ui_.motorTempRightLabel().text().toInt()) / 2);

    ui_.dspBoardTempAvgLabel().setNum((motorDetailsLeft.dspBoardTemp() +
                                       ui_.dspBoardTempRightLabel().text().toInt()) / 2);

    ui_.dcBusAmpHoursAvgLabel().setNum((motorDetailsLeft.dcBusAmpHours() +
                                        ui_.dcBusAmpHoursRightLabel().text().toInt()) / 2);

    ui_.odometerAvgLabel().setNum((motorDetailsLeft.odometer() +
                                   ui_.odometerRightLabel().text().toInt()) / 2);

    ui_.slipSpeedAvgLabel().setNum((motorDetailsLeft.slipSpeed() +
                                    ui_.slipSpeedRightLabel().text().toInt()) / 2);


}

MotorDetails motorDetailsRight = MotorDetails();

void MotorView::motorOneDetailsReceived(MotorDetails)
{

    ui_.phaseCCurrentRightLabel().setNum(motorDetailsRight.phaseCCurrent());
    ui_.phaseBCurrentRightLabel().setNum(motorDetailsRight.phaseBCurrent());

    ui_.motorVoltageRealRightLabel().setNum(motorDetailsRight.motorVoltageReal());
    ui_.motorVoltageImaginaryRightLabel().setNum(motorDetailsRight.motorVoltageImaginary());

    ui_.motorCurrentRealRightLabel().setNum(motorDetailsRight.motorCurrentReal());
    ui_.motorCurrentImaginaryRightLabel().setNum(motorDetailsRight.motorCurrentImaginary());

    ui_.backEmfRightLabel().setNum((motorDetailsRight.backEmf()));

    ui_.voltageRail15VSupplyRightLabel().setNum(motorDetailsRight.voltageRail15VSupply());
    ui_.voltageRail3VSupplyRightLabel().setNum(motorDetailsRight.voltageRail3VSupply());
    ui_.voltageRail1VSupplyRightLabel().setNum(motorDetailsRight.voltageRail1VSupply());

    ui_.heatSinkTempRightLabel().setNum(motorDetailsRight.heatSinkTemp());
    ui_.motorTempRightLabel().setNum(motorDetailsRight.motorTemp());
    ui_.dspBoardTempRightLabel().setNum(motorDetailsRight.dspBoardTemp());

    ui_.dcBusAmpHoursRightLabel().setNum(motorDetailsRight.dcBusAmpHours());
    ui_.odometerRightLabel().setNum(motorDetailsRight.odometer());
    ui_.slipSpeedRightLabel().setNum(motorDetailsRight.slipSpeed());

    ui_.phaseCCurrentAvgLabel().setNum((motorDetailsRight.phaseCCurrent() +
                                        ui_.phaseCCurrentLeftLabel().text().toInt()) / 2);

    ui_.phaseBCurrentAvgLabel().setNum((motorDetailsRight.phaseBCurrent() +
                                        ui_.phaseBCurrentLeftLabel().text().toInt()) / 2);

    ui_.motorVoltageRealAvgLabel().setNum((motorDetailsRight.motorVoltageReal() +
                                           ui_.motorVoltageRealLeftLabel().text().toInt()) / 2);

    ui_.motorVoltageImaginaryAvgLabel().setNum((motorDetailsRight.motorVoltageImaginary() +
            ui_.motorVoltageImaginaryLeftLabel().text().toInt()) / 2);

    ui_.motorCurrentRealAvgLabel().setNum((motorDetailsRight.motorCurrentReal() +
                                           ui_.motorCurrentRealLeftLabel().text().toInt()) / 2);

    ui_.motorCurrentImaginaryAvgLabel().setNum((motorDetailsRight.motorCurrentImaginary() +
            ui_.motorCurrentImaginaryLeftLabel().text().toInt()) / 2);

    ui_.backEmfAvgLabel().setNum((motorDetailsRight.backEmf() +
                                  ui_.backEmfLeftLabel().text().toInt()) / 2);

    ui_.voltageRail3VSupplyAvgLabel().setNum((motorDetailsRight.voltageRail3VSupply() +
            ui_.voltageRail3VSupplyLeftLabel().text().toInt()) / 2);

    ui_.voltageRail1VSupplyAvgLabel().setNum((motorDetailsRight.voltageRail1VSupply() +
            ui_.voltageRail1VSupplyLeftLabel().text().toInt()) / 2);

    ui_.voltageRail15VSupplyAvgLabel().setNum((motorDetailsRight.voltageRail15VSupply() +
            ui_.voltageRail15VSupplyLeftLabel().text().toInt()) / 2);

    ui_.heatSinkTempAvgLabel().setNum((motorDetailsRight.heatSinkTemp() +
                                       ui_.heatSinkTempLeftLabel().text().toInt()) / 2 );

    ui_.motorTempAvgLabel().setNum((motorDetailsRight.motorTemp() +
                                    ui_.motorTempLeftLabel().text().toInt()) / 2);

    ui_.dspBoardTempAvgLabel().setNum((motorDetailsRight.dspBoardTemp() +
                                       ui_.dspBoardTempLeftLabel().text().toInt()) / 2);

    ui_.dcBusAmpHoursAvgLabel().setNum((motorDetailsRight.dcBusAmpHours() +
                                        ui_.dcBusAmpHoursLeftLabel().text().toInt()) / 2);

    ui_.odometerAvgLabel().setNum((motorDetailsRight.odometer() +
                                   ui_.odometerLeftLabel().text().toInt()) / 2);

    ui_.slipSpeedAvgLabel().setNum((motorDetailsRight.slipSpeed() +
                                    ui_.slipSpeedLeftLabel().text().toInt()) / 2);
}

