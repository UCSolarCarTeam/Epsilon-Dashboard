#pragma once
#include <QObject>
#include <QLabel>

#include "../../../../DataLayer/DriverControlsData/DriverControlsData.h"
#include "../../../../PresenterLayer/DriverControlsPresenter/DriverControlsPresenter.h"
#include "../../ControlPage/ControlUi/I_ControlUi.h"

class DriverControlsPresenter;

class ControlView : public QObject
{
    Q_OBJECT
public:
    ControlView(DriverControlsPresenter& driverControlsPresenter,
                I_ControlUi& ui);
    ~ControlView();

private:
    void connectDriverControls(DriverControlsPresenter&);

    DriverControlsPresenter& driverControlsPresenter_;

    I_ControlUi& ui_;

private slots:
    void aliveReceived(bool);

    void lowHeadlightsReceived(bool);
    void highHeadlightsReceived(bool);

    void leftSignalReceived(bool);
    void rightSignalReceived(bool);
    void hazardReceived(bool);

    void interiorReceived(bool);
    void pushToTalkReceived(bool);
    void hornReceived(bool);


    void prevSongReceived(bool);
    void nextSongReceived(bool);
    void playPauseReceived(bool);
    void volumeUpReceived(bool);
    void volumeDownReceived(bool);

    void brakesReceived(bool);
    void forwardReceived(bool);
    void reverseReceived(bool);
    void auxReceived(bool);

    void resetReceived(bool);

    void accelerationReceived(double);
    void regenBrakingReceived(double);
};
