#include "DriverControlsData.h"
#include <QDebug>

DriverControlsData::DriverControlsData()
{
}

DriverControlsData::~DriverControlsData()
{
}

bool DriverControlsData::alive() const
{
    return alive_;
}
bool DriverControlsData::headlightsOff() const
{
    return headlightsOff_;
}
bool DriverControlsData::headlightsLow() const
{
    return headlightsLow_;
}
bool DriverControlsData::headlightsHigh() const
{
    return headlightsHigh_;
}
bool DriverControlsData::signalRight() const
{
    return signalRight_;
}
bool DriverControlsData::signalLeft() const
{
    return signalLeft_;
}
bool DriverControlsData::hazard() const
{
    return hazard_;
}
bool DriverControlsData::interior() const
{
    return interior_;
}
bool DriverControlsData::volumeUp() const
{
    return volumeUp_;
}
bool DriverControlsData::volumeDown() const
{
    return volumeDown_;
}
bool DriverControlsData::nextSong() const
{
    return nextSong_;
}
bool DriverControlsData::prevSong() const
{
    return prevSong_;
}
double DriverControlsData::acceleration() const
{
    return acceleration_;
}
double DriverControlsData::regenBraking() const
{
    return regenBraking_;
}
bool DriverControlsData::brakes() const
{
    return brakes_;
}
bool DriverControlsData::forward() const
{
    return forward_;
}
bool DriverControlsData::reverse() const
{
    return reverse_;
}
bool DriverControlsData::pushToTalk() const
{
    return pushToTalk_;
}
bool DriverControlsData::horn() const
{
    return horn_;
}
bool DriverControlsData::reset() const
{
    return reset_;
}
bool DriverControlsData::aux() const
{
    return aux_;
}

void DriverControlsData::setAlive(bool alive)
{
    alive_ = alive;
    emit aliveReceived(alive_);
}
void DriverControlsData::setHeadlightsOff(bool headlightsOff)
{
    headlightsOff_ = headlightsOff;
    emit headlightsOffReceived(headlightsOff_);
}
void DriverControlsData::setHeadlightsLow(bool headlightsLow)
{
    headlightsLow_ = headlightsLow;
    emit headlightsLowReceived(headlightsLow_);
}
void DriverControlsData::setHeadlightsHigh(bool headlightsHigh)
{
    headlightsHigh_ = headlightsHigh;
    emit headlightsHighReceived(headlightsHigh_);
}
void DriverControlsData::setSignalRight(bool signalRight)
{
    signalRight_ = signalRight;
    emit signalRightReceived(signalRight_);
}
void DriverControlsData::setSignalLeft(bool signalLeft)
{
    signalLeft_ = signalLeft;
    emit signalLeftReceived(signalLeft_);
}
void DriverControlsData::setHazard(bool hazard)
{
    hazard_ = hazard;
    emit hazardReceived(hazard_);
}
void DriverControlsData::setInterior(bool interior)
{
    interior_ = interior;
    emit interiorReceived(interior_);
}
void DriverControlsData::setVolumeUp(bool volumeUp)
{
    volumeUp_ = volumeUp;
    emit volumeUpReceived(volumeUp_);
}
void DriverControlsData::setVolumeDown(bool volumeDown)
{
    volumeDown_ = volumeDown;
    emit volumeDownReceived(volumeDown_);
}
void DriverControlsData::setNextSong(bool nextSong)
{
    nextSong_ = nextSong;
    emit nextSongReceived(nextSong_);
}
void DriverControlsData::setPrevSong(bool prevSong)
{
    prevSong_ = prevSong;
    emit prevSongReceived(prevSong_);
}
void DriverControlsData::setAcceleration(double acceleration)
{
    acceleration_ = acceleration;
    emit accelerationReceived(acceleration_);
}
void DriverControlsData::setRegenBraking(double regenBraking)
{
    regenBraking_ = regenBraking;
    emit regenBrakingReceived(regenBraking_);
}
void DriverControlsData::setBrakes(bool brakes)
{
    brakes_ = brakes;
    emit brakesReceived(brakes_);
}
void DriverControlsData::setForward(bool forward)
{
    forward_ = forward;
    emit forwardReceived(forward_);
}
void DriverControlsData::setReverse(bool reverse)
{
    reverse_ = reverse;
    emit reverseReceived(reverse_);
}
void DriverControlsData::setPushToTalk(bool pushToTalk)
{
    pushToTalk_ = pushToTalk;
    emit pushToTalkReceived(pushToTalk_);
}
void DriverControlsData::setHorn(bool horn)
{
    horn_ = horn;
    emit hornReceived(horn_);
}
void DriverControlsData::setReset(bool reset)
{
    reset_ = reset;
    emit resetReceived(reset_);
}
void DriverControlsData::setAux(bool aux)
{
    aux_ = aux;
    emit auxReceived(aux_);
}
