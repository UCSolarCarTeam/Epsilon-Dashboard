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
    void lowBeamsReceived(bool);
    void highBeamsReceived(bool);
    void brakesReceived(bool);
    void leftSignalReceived(bool);
    void rightSignalReceived(bool);
    void bmsStrobeLightReceived(bool);
    void lightAliveReceived(bool);
};
