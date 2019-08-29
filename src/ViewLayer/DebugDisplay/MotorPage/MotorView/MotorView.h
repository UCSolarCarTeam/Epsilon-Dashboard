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

    KeyMotorPresenter& keyMotorPresenter_;
    MotorDetailsPresenter& motorDetailsPresenter_;
    I_MotorUi& ui_;

    double setVelocityLeft_;
    double setVelocityRight_;
    double phaseCCurrentLeft_;
    double phaseCCurrentRight_;
    double phaseBCurrentLeft_;
    double phaseBCurrentRight_;
    double motorVoltageRealLeft_;
    double motorVoltageRealRight_;
    double motorVoltageImaginaryLeft_;
    double motorVoltageImaginaryRight_;
    double motorCurrentRealLeft_;
    double motorCurrentRealRight_;
    double motorCurrentImaginaryLeft_;
    double motorCurrentImaginaryRight_;
    double backEmfLeft_;
    double backEmfRight_;
    double voltageRail15VSupplyLeft_;
    double voltageRail15VSupplyRight_;
    double voltageRail3VSupplyLeft_;
    double voltageRail3VSupplyRight_;
    double voltageRail1VSupplyLeft_;
    double voltageRail1VSupplyRight_;
    double heatSinkTempLeft_;
    double heatSinkTempRight_;
    double motorTempLeft_;
    double motorTempRight_;
    double dspBoardTempLeft_;
    double dspBoardTempRight_;
    double dcBusAmpHoursLeft_;
    double dcBusAmpHoursRight_;
    double odometerLeft_;
    double odometerRight_;
    double slipSpeedLeft_;
    double slipSpeedRight_;

private slots:

    void motorZeroReceived(KeyMotor);
    void motorOneReceived(KeyMotor);
    void leftAliveRecieved(bool);
    void rightAliveRecieved(bool);
    void motorSetCurrentReceived(double);
    void motorActualSpeedReceived(double);
    void motorBusVoltageReceived(double);
    void motorBusCurrentReceived(double);

    void motorZeroDetailsReceived(MotorDetails);
    void motorOneDetailsReceived(MotorDetails);
    void setMotorDetailsAverageLabels();

};
