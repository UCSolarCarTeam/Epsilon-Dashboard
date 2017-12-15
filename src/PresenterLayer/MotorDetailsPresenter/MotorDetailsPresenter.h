#pragma once
#include "../DataLayer/MotorDetailsData/I_MotorDetailsData.h"
#include <QObject>
class I_MotorDetailsData;

class MotorDetailsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MotorDetailsPresenter(const I_MotorDetailsData& motorDetailsData);

private:
    void relayMotorDetailsData();

    const I_MotorDetailsData& motorDetailsData_;

signals:
    void motorZeroDetailsReceived(MotorDetails);
    void motorOneDetailsReceived(MotorDetails);
};
