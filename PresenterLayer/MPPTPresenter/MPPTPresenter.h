#pragma once
#include "../../DataLayer/MpptData/I_MpptData.h"

#include <QObject>
class I_MpptData;

class MpptPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MpptPresenter(const I_MpptData& mpptData);

private:
    void relayMpptData();

    const I_MpptData& mpptData_;

signals:
    void mpptZeroReceived(Mppt mpptZero);
    void mpptOneReceived(Mppt mpptOne);
    void mpptTwoReceived(Mppt mpptTwo);
    void mpptPowerReceived(double mpptPower);
};
