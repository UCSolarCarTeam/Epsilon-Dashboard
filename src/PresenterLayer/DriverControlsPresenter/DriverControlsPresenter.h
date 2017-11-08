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
    void aliveReceived(bool alive);
    void headlightsOffReceived(bool headlightsOff);
    void headlightsLowReceived(bool headlightsLow);
    void headlightsHighReceived(bool headlightsHigh);
    void signalRightReceived(bool signalRight);
    void signalLeftReceived(bool signalLeft);
    void hazardReceived(bool hazard);
    void interiorReceived(bool interior);
    void auxReceived(bool aux);
    void volumeUpReceived(bool volumeUp);
    void volumeDownReceived(bool volumeDown);
    void nextSongReceived(bool nextSong);
    void prevSongReceived(bool prevSong);
    void accelerationReceived(double acceleration);
    void regenBrakingReceived(double regenBraking);
    void brakesReceived(bool brakes);
    void forwardReceived(bool forward);
    void reverseReceived(bool reverse);
    void pushToTalkReceived(bool pushToTalk);
    void hornReceived(bool horn);
    void resetReceived(bool reset);
};
