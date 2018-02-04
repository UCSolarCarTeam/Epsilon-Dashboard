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

    void motorZeroReceived(KeyMotor);
    void motorOneReceived(KeyMotor);
    void motorSetCurrentReceived(double);
    void motorActualSpeedReceived(double);
    void motorBusVoltageReceived(double);
    void motorBusCurrentReceived(double);
    void setCurrentLeftReceived(double);
    void setCurrentAvg(double, double);
    void setCurrentRightReceived(double);

    void motorZeroDetailsReceived(MotorDetails);
    void motorOneDetailsReceived(MotorDetails);
};
