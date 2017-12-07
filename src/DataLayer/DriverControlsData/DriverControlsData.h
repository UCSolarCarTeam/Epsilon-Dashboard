#pragma once

#include "I_DriverControlsData.h"

class DriverControlsData : public I_DriverControlsData
{
public:
    DriverControlsData();
    virtual ~DriverControlsData();

    bool alive() const;
    bool headlightsOff() const;
    bool headlightsLow() const;
    bool headlightsHigh() const;
    bool signalRight() const;
    bool signalLeft() const;
    bool hazard() const;
    bool interior() const;
    bool aux() const;
    bool volumeUp() const;
    bool volumeDown() const;
    bool nextSong() const;
    bool prevSong() const;
    double acceleration() const;
    double regenBraking() const;
    bool brakes() const;
    bool forward() const;
    bool reverse() const;
    bool pushToTalk() const;
    bool horn() const;
    bool reset() const;

    void setAlive(bool alive);
    void setHeadlightsOff(bool headlightsOff);
    void setHeadlightsLow(bool headlightsLow);
    void setHeadlightsHigh(bool headlightsHigh);
    void setSignalRight(bool signalRight);
    void setSignalLeft(bool signalLeft);
    void setHazard(bool hazard);
    void setInterior(bool interior);
    void setAux(bool aux);
    void setVolumeUp(bool volumeUp);
    void setVolumeDown(bool volumeDown);
    void setNextSong(bool nextSong);
    void setPrevSong(bool prevSong);
    void setAcceleration(double acceleration);
    void setRegenBraking(double regenBraking);
    void setBrakes(bool brakes);
    void setForward(bool forward);
    void setReverse(bool reverse);
    void setPushToTalk(bool pushToTalk);
    void setHorn(bool horn);
    void setReset(bool reset);

private:
    bool alive_;
    bool headlightsOff_;
    bool headlightsLow_;
    bool headlightsHigh_;
    bool signalRight_;
    bool signalLeft_;
    bool hazard_;
    bool interior_;
    bool aux_;
    bool volumeUp_;
    bool volumeDown_;
    bool nextSong_;
    bool prevSong_;
    double acceleration_;
    double regenBraking_;
    bool brakes_;
    bool forward_;
    bool reverse_;
    bool pushToTalk_;
    bool horn_;
    bool reset_;
};

