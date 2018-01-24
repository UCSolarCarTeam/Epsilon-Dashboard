
#include "ControlView.h"

namespace
{
    const QString DRIVER_CONTROL_ALIVE = "background-color:rgb(93, 234, 140); \
                              border-radius:8px; \
                              border: 1px solid white;";
    const QString DRIVER_CONTROL_DEAD = "background-color:rgb(147, 147, 147); \
                             border-radius:8px; \
                             border: 1px solid white;";
    const QString ON = "color: orange;";

    const QString OFF = "color: grey;";
}

ControlView::ControlView(DriverControlsPresenter& driverControlsPresenter,
                         I_ControlUi& ui)
    : driverControlsPresenter_(driverControlsPresenter)
    , ui_(ui)
{
    connectDriverControls(driverControlsPresenter_);
}

ControlView::~ControlView()
{
}

void ControlView::connectDriverControls(DriverControlsPresenter& driverControlsPresenter)
{
    connect(&driverControlsPresenter, SIGNAL(aliveReceived(bool)),
            this, SLOT(aliveReceived(bool)));

    connect(&driverControlsPresenter, SIGNAL(headlightsLowReceived(bool)),
            this, SLOT(lowHeadlightsReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(headlightsHighReceived(bool)),
            this, SLOT(highHeadlightsReceived(bool)));

    connect(&driverControlsPresenter, SIGNAL(signalLeftReceived(bool)),
            this, SLOT(leftSignalReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(signalRightReceived(bool)),
            this, SLOT(rightSignalReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(hazardReceived(bool)),
            this, SLOT(hazardReceived(bool)));

    connect(&driverControlsPresenter, SIGNAL(interiorReceived(bool)),
            this, SLOT(interiorReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(pushToTalkReceived(bool)),
            this, SLOT(pushToTalkReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(hornReceived(bool)),
            this, SLOT(hornReceived(bool)));

    connect(&driverControlsPresenter, SIGNAL(auxReceived(bool)),
            this, SLOT(auxReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(prevSongReceived(bool)),
            this, SLOT(prevSongReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(nextSongReceived(bool)),
            this, SLOT(nextSongReceived(bool)));
    //connect(&driverControlsPresenter, SIGNAL(playPauseReceived(bool)),//
    //      this, SLOT(playPauseReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(volumeUpReceived(bool)),
            this, SLOT(volumeUpReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(volumeDownReceived(bool)),
            this, SLOT(volumeDownReceived(bool)));

    connect(&driverControlsPresenter, SIGNAL(brakesReceived(bool)),
            this, SLOT(brakesReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(forwardReceived(bool)),
            this, SLOT(forwardReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(reverseReceived(bool)),
            this, SLOT(reverseReceived(bool)));

    connect(&driverControlsPresenter, SIGNAL(resetReceived(bool)),
            this, SLOT(resetReceived(bool)));

    connect(&driverControlsPresenter, SIGNAL(accelerationReceived(double)),
            this, SLOT(accelerationReceived(double)));
    connect(&driverControlsPresenter, SIGNAL(regenBrakingReceived(double)),
            this, SLOT(regenBrakingReceived(double)));
}

void ControlView::aliveReceived(bool alive)
{
    if (alive)
    {
        ui_.aliveIndicator().setStyleSheet(DRIVER_CONTROL_ALIVE);
    }
    else
    {
        ui_.aliveIndicator().setStyleSheet(DRIVER_CONTROL_DEAD);
    }
}

void ControlView::lowHeadlightsReceived(bool lowBeams)
{
    if (lowBeams)
    {
        ui_.lowHeadlightsLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.lowHeadlightsLabel().setStyleSheet(OFF);
    }
}

void ControlView::highHeadlightsReceived(bool highBeams)
{
    if (highBeams)
    {
        ui_.highHeadlightsLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.highHeadlightsLabel().setStyleSheet(OFF);
    }
}

void ControlView::leftSignalReceived(bool leftSignal)
{
    if (leftSignal)
    {
        ui_.leftSignalLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.leftSignalLabel().setStyleSheet(OFF);
    }
}

void ControlView::rightSignalReceived(bool rightSignal)
{
    if (rightSignal)
    {
        ui_.rightSignalLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.rightSignalLabel().setStyleSheet(OFF);
    }
}

void ControlView::hazardReceived(bool hazard)
{
    if (hazard)
    {
        ui_.hazardOnLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.hazardOnLabel().setStyleSheet(OFF);
    }
}

void ControlView::interiorReceived(bool interior)
{
    if (interior)
    {
        ui_.interiorOnLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.interiorOnLabel().setStyleSheet(OFF);
    }
}

void ControlView::pushToTalkReceived(bool pushToTalk)
{
    if (pushToTalk)
    {
        ui_.pushToTalkOnLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.pushToTalkOnLabel().setStyleSheet(OFF);
    }
}

void ControlView::hornReceived(bool horn)
{
    if (horn)
    {
        ui_.hornOnLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.hornOnLabel().setStyleSheet(OFF);
    }
}

void ControlView::auxReceived(bool aux)
{
    if (aux)
    {
        ui_.auxOnLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.auxOnLabel().setStyleSheet(OFF);
    }
}

void ControlView::prevSongReceived(bool prevSong)
{
    if (prevSong)
    {
        ui_.prevSongLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.prevSongLabel().setStyleSheet(OFF);
    }
}

void ControlView::nextSongReceived(bool nextSong)
{
    if (nextSong)
    {
        ui_.nextSongLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.nextSongLabel().setStyleSheet(OFF);
    }
}

/*void ControlView::playPauseReceived(bool playPause)
{
    if (playPause)
    {
        ui_.playPauseLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.playPauseLabel().setStyleSheet(OFF);
    }
}*/

void ControlView::volumeUpReceived(bool volumeUp)
{
    if (volumeUp)
    {
        ui_.volumeUpLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.volumeUpLabel().setStyleSheet(OFF);
    }
}

void ControlView::volumeDownReceived(bool volumeDown)
{
    if (volumeDown)
    {
        ui_.volumeDownLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.volumeDownLabel().setStyleSheet(OFF);
    }
}

void ControlView::brakesReceived(bool brakes)
{
    if (brakes)
    {
        ui_.brakesOnLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.brakesOnLabel().setStyleSheet(OFF);
    }
}

void ControlView::forwardReceived(bool forward)
{
    if (forward)
    {
        ui_.forwardOnLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.forwardOnLabel().setStyleSheet(OFF);
    }
}

void ControlView::reverseReceived(bool reverse)
{
    if (reverse)
    {
        ui_.reverseOnLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.reverseOnLabel().setStyleSheet(OFF);
    }
}

void ControlView::resetReceived(bool reset)
{
    if (reset)
    {
        ui_.resetOnLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.resetOnLabel().setStyleSheet(OFF);
    }
}

void ControlView::accelerationReceived(double acceleration)
{
    int accelerationPercentage = acceleration * 100;
    ui_.accelerationProgressBar().setValue(accelerationPercentage);
}

void ControlView::regenBrakingReceived(double regenBraking)
{
    int regenBrakingPercentage = regenBraking * 100;
    ui_.regenBrakingProgressBar().setValue(regenBrakingPercentage);
}