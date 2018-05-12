#include "LightsData.h"
#include <QDebug>

LightsData::LightsData()
{
}

LightsData::~LightsData()
{
}

bool LightsData::lowBeams() const
{
    return lowBeams_;
}
bool LightsData::highBeams() const
{
    return highBeams_;
}
bool LightsData::brakes() const
{
    return brakes_;
}
bool LightsData::leftSignal() const
{
    return leftSignal_;
}
bool LightsData::rightSignal() const
{
    return rightSignal_;
}
bool LightsData::bmsStrobeLight() const
{
    return bmsStrobeLight_;
}
bool LightsData::alive() const
{
    return alive_;
}

void LightsData::setlowBeams(bool lowBeams)
{
    lowBeams_ = lowBeams;
    emit lowBeamsReceived(lowBeams_);
}
void LightsData::sethighBeams(bool highBeams)
{
    highBeams_ = highBeams;
    emit highBeamsReceived(highBeams_);
}
void LightsData::setbrakes(bool brakes)
{
    brakes_ = brakes;
    emit brakesReceived(brakes_);
}
void LightsData::setleftSignal(bool leftSignal)
{
    leftSignal_ = leftSignal;
    emit leftSignalReceived(leftSignal_);
}
void LightsData::setrightSignal(bool rightSignal)
{
    rightSignal_ = rightSignal;
    emit rightSignalReceived(rightSignal_);
}
void LightsData::setBmsStrobeLight(bool bmsStrobeLight)
{
    bmsStrobeLight_ = bmsStrobeLight;
    emit bmsStrobeLightReceived(bmsStrobeLight_);
}

void LightsData::setAlive(bool alive)
{
    alive_ = alive;
    emit aliveReceived(alive_);
}
