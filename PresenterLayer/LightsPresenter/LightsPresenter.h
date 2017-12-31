#pragma once

#include <QObject>
class I_LightsData;

class LightsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit LightsPresenter(const I_LightsData& lightsData);

private:
    void relayLightsData();

    const I_LightsData& lightsData_;

signals:
    void lowBeamsReceived(bool lowBeams);
    void highBeamsReceived(bool highBeams);
    void brakesReceived(bool brakes);
    void leftSignalReceived(bool leftSignal);
    void rightSignalReceived(bool rightSignal);
    void bmsStrobeLightReceived(bool bmsStrobeLight);
    void lightAliveReceived(bool);
};
