#pragma once
#include <QObject>
#include <QLabel>

#include "../../../../DataLayer/KeyMotorData/KeyMotorData.h"
#include "../../../../DataLayer/MotorDetailsData/MotorDetailsData.h"
#include "../../../../PresenterLayer/KeyMotorPresenter/KeyMotorPresenter.h"
#include "../../../../PresenterLayer/MotorDetailsPresenter/MotorDetailsPresenter.h"
#include "../../MotorPage/MotorUi/I_MotorUi.h"

class I_MotorUi;
class KeyMotorPresenter;
class MotorDetailsPresenter;

class MotorView : public QObject
{
    Q_OBJECT
public:
    MotorView(KeyMotorPresenter& keyMotorPresenter, MotorDetailsPresenter& motorDetailsPresenter,
              I_MotorUi& ui);
    ~MotorView();

private:
    void connectMotor(KeyMotorPresenter&, MotorDetailsPresenter&);
    //void connectMotorDetails(MotorDetailsPresenter&);

    KeyMotorPresenter& keyMotorPresenter_;
    MotorDetailsPresenter& motorDetailsPresenter_;
    I_MotorUi& ui_;

private slots:
    void setCurrentLeftReceived(double);
    void setCurrentAvg(double, double);
    void setCurrentRightReceived(double);

    void setVelocityLeftReceived(double);
    void setVelocityAvg(double, double);
    void setVelocityRightReceived(double);

    void busCurrentLeftReceived(double);
    void busCurrentAvg(double, double);
    void busCurrentRightReceived(double);

    void busVoltageLeftReceived(double);
    void busVoltageAvg(double, double);
    void busVoltageRightReceived(double);

    void vehicleVelocityLeftReceived(double);
    void vehicleVelocityAvg(double, double);
    void vehicleVelocityRightReceived(double);

    void phaseCCurrentLeftReceived(double);
    void phaseCCurrentAvg(double, double);
    void phaseCCurrentRightReceived(double);

    void phaseBCurrentLeftReceived(double);
    void phaseBCurrentAvg(double, double);
    void phaseBCurrentRightReceived(double);

    void motorVoltageRealLeftReceived(double);
    void motorVoltageRealAvg(double, double);
    void motorVoltageRealRightReceived(double);

    void motorVoltageImaginaryLeftReceived(double);
    void motorVoltageImaginaryAvg(double, double);
    void motorVoltageImaginaryRightReceived(double);

    void motorCurrentRealLeftReceived(double);
    void motorCurrentRealAvg(double, double);
    void motorCurrentRealRightReceived(double);

    void motorCurrentImaginaryLeftReceived(double);
    void motorCurrentImaginaryAvg(double, double);
    void motorCurrentImaginaryRightReceived(double);

    void backEmfRealLeftReceived(double);
    void backEmfRealAvg(double, double);
    void backEmfRealRightReceived(double);

    void voltageRail15VSupplyLeftReceived(double);
    void voltageRail15VSupplyAvg(double, double);
    void voltageRail15VSupplyRightReceived(double);

    void voltageRail3VSupplyLeftReceived(double);
    void voltageRail3VSupplyAvg(double, double);
    void voltageRail3VSupplyRightReceived(double);

    void voltageRail1VSupplyLeftReceived(double);
    void voltageRail1VSupplyAvg(double, double);
    void voltageRail1VSupplyRightReceived(double);

    void heatSinkTempLeftReceived(double);
    void heatSinkTempAvg(double, double);
    void heatSinkTempRightReceived(double);

    void motorTempLeftReceived(double);
    void motorTempAvg(double, double);
    void motorTempRightReceived(double);

    void dspBoardTempLeftReceived(double);
    void dspBoardTempAvg(double, double);
    void dspBoardTempRightReceived(double);

    void dcBusAmpHoursLeftReceived(double);
    void dcBusAmpHoursAvg(double, double);
    void dcBusAmpHoursRightReceived(double);

    void odometerLeftReceived(double);
    void odometerAvg(double, double);
    void odometerRightReceived(double);

    void slipSpeedLeftReceived(double);
    void slipSpeedAvg(double, double);
    void slipSpeedRightReceived(double);
};
