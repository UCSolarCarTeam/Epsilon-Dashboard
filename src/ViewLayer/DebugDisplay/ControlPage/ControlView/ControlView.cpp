
#include "ControlView.h"

namespace
{
    const QString ON = "color: orange;";

    const QString OFF = "color: grey;";

    const QString LOW_BEAMS_ON = "image: url(:Resources/LowHeadlightIndicator.png);";

    const QString LOW_BEAMS_OFF = "image: url(:Resources/LowHeadlightOff.png);";

    const QString LEFT_ON = "image: url(:Resources/TurnSignalLeft.png);";

    const QString LEFT_OFF = "image: url(:Resources/TurnSignalLeftOff.png);";

    const QString RIGHT_ON = "image: url(:Resources/TurnSignalRight.png);";

    const QString RIGHT_OFF = "image: url(:Resources/TurnSignalRightOff.png);";

    const QString BRAKE_ON = "background-color: rgb(234,0,0);"
                             "border-radius: 10px;"
                             "border: 1px solid white;";

    const QString BRAKE_OFF = "background-color: rgb(75,75,75);"
                              "border-radius: 10px;"
                              "border: 1px solid white;";
}

ControlView::ControlView(CcsPresenter& ccsPresenter,
                         DriverControlsPresenter& driverControlsPresenter,
                         LightsPresenter& lightsPresenter,
                         I_ControlUi& ui)
    : ccsPresenter_(ccsPresenter)
    , driverControlsPresenter_(driverControlsPresenter)
    , lightsPresenter_(lightsPresenter)
    , ui_(ui)
{
    connectCcs(ccsPresenter_);
    connectDriverControls(driverControlsPresenter_);
    connectLights(lightsPresenter_);
}

ControlView::~ControlView()
{
}

void ControlView::connectCcs(CcsPresenter& ccsPresenter)
{
    connect(&ccsPresenter, SIGNAL(ccsAliveReceived(bool)),
            this, SLOT(ccsAliveReceived(bool)));
}

void ControlView::connectDriverControls(DriverControlsPresenter& driverControlsPresenter)
{
    connect(&driverControlsPresenter, SIGNAL(aliveReceived(bool)),
            this, SLOT(aliveReceived(bool)));

    connect(&driverControlsPresenter, SIGNAL(headlightsOffReceived(bool)),
            this, SLOT(headlightsOffReceived(bool)));

    connect(&driverControlsPresenter, SIGNAL(headlightsLowReceived(bool)),
            this, SLOT(lowHeadlightsReceived(bool)));

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

void ControlView::connectLights(LightsPresenter& lightsPresenter)
{
    connect(&lightsPresenter, SIGNAL(lightAliveReceived(bool)),
            this, SLOT(aliveLights(bool)));

    connect(&lightsPresenter, SIGNAL(lowBeamsReceived(bool)),
            this, SLOT(lowBeamsReceived(bool)));
    connect(&lightsPresenter, SIGNAL(leftSignalReceived(bool)),
            this, SLOT(leftLightReceived(bool)));
    connect(&lightsPresenter, SIGNAL(rightSignalReceived(bool)),
            this, SLOT(rightLightReceived(bool)));
    connect(&lightsPresenter, SIGNAL(brakesReceived(bool)),
            this, SLOT(brakesLightReceived(bool)));
    connect(&lightsPresenter, SIGNAL(bmsStrobeLightReceived(bool)),
            this, SLOT(bmsStrobeLightReceived(bool)));
}

void ControlView::aliveReceived(bool alive)
{
    if (alive)
    {
        ui_.aliveIndicator().setStyleSheet(ON);
    }
    else
    {
        ui_.aliveIndicator().setStyleSheet(OFF);
    }
}

void ControlView::aliveLights(bool lights)
{
    if (lights)
    {
        ui_.lightsIndicator().setStyleSheet(ON);
    }
    else
    {
        ui_.lightsIndicator().setStyleSheet(OFF);
    }
}

void ControlView::ccsAliveReceived(bool ccs)
{
    if (ccs)
    {
        ui_.ccsAlive().setStyleSheet(ON);
    }
    else
    {
        ui_.ccsAlive().setStyleSheet(OFF);
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

void ControlView::lowBeamsReceived(bool lights)
{
    if (lights)
    {
        ui_.lowBeamLabel().setStyleSheet(LOW_BEAMS_ON);
    }
    else
    {
        ui_.lowBeamLabel().setStyleSheet(LOW_BEAMS_OFF);
    }
}

void ControlView::headlightsOffReceived(bool lights)
{
    if (lights)
    {
        ui_.headlightsOff().setStyleSheet(ON);
    }
    else
    {
        ui_.headlightsOff().setStyleSheet(OFF);
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

void ControlView::leftLightReceived(bool light)
{
    if (light)
    {
        ui_.leftSignalActiveLabel().setStyleSheet(LEFT_ON);
    }
    else
    {
        ui_.leftSignalActiveLabel().setStyleSheet(LEFT_OFF);
    }
}

void ControlView::rightLightReceived(bool light)
{
    if (light)
    {
        ui_.rightSignalActiveLabel().setStyleSheet(RIGHT_ON);
    }
    else
    {
        ui_.rightSignalActiveLabel().setStyleSheet(RIGHT_OFF);
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

void ControlView::bmsStrobeLightReceived(bool strobeLight)
{
    if (strobeLight)
    {
        ui_.strobeLightOnLabel().setStyleSheet(ON);
    }
    else
    {
        ui_.strobeLightOnLabel().setStyleSheet(OFF);
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

void ControlView::brakesLightReceived(bool light)
{
    if (light)
    {
        ui_.brakesOnActiveLabel().setStyleSheet(BRAKE_ON);
    }
    else
    {
        ui_.brakesOnActiveLabel().setStyleSheet(BRAKE_OFF);
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
    int accelerationPercentage = (int)acceleration;
    ui_.accelerationProgressBar().setValue(accelerationPercentage);
}

void ControlView::regenBrakingReceived(double regenBraking)
{
    int regenBrakingPercentage = (int)regenBraking;
    ui_.regenBrakingProgressBar().setValue(regenBrakingPercentage);
}
