#pragma once

#include <QObject>
class I_DriverControlsData;

class DriverControlsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit DriverControlsPresenter(const I_DriverControlsData& driverControlsData);

private:
    void relayDriverControlsData();

    const I_DriverControlsData& driverControlsData_;

signals:
    void aliveReceived(bool);
    void ccsAliveReceived(bool);
    void headlightsOffReceived(bool);
    void headlightsLowReceived(bool);
    void headlightsHighReceived(bool);
    void signalRightReceived(bool);
    void signalLeftReceived(bool);
    void hazardReceived(bool);
    void interiorReceived(bool);
    void volumeUpReceived(bool);
    void volumeDownReceived(bool);
    void nextSongReceived(bool);
    void prevSongReceived(bool);
    void accelerationReceived(double);
    void regenBrakingReceived(double);
    void brakesReceived(bool);
    void forwardReceived(bool);
    void reverseReceived(bool);
    void pushToTalkReceived(bool);
    void hornReceived(bool);
    void resetReceived(bool);
    void auxReceived(bool);
    void lapReceived(bool);
};
