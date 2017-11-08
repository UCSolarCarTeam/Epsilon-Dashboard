#pragma once

#include "I_LightsData.h"

class LightsData : public I_LightsData
{
public:
    LightsData();
    virtual ~LightsData();

    bool lowBeams() const;
    bool highBeams() const;
    bool brakes() const;
    bool leftSignal() const;
    bool rightSignal() const;
    bool bmsStrobeLight() const;
    bool alive() const;

    void setlowBeams(bool lowBeams);
    void sethighBeams(bool highBeams);
    void setbrakes(bool brakes);
    void setleftSignal(bool leftSignal);
    void setrightSignal(bool rightSignal);
    void setBmsStrobeLight(bool bmsStrobeLight);
    void setAlive(bool alive);

private:
    bool lowBeams_;
    bool highBeams_;
    bool brakes_;
    bool leftSignal_;
    bool rightSignal_;
    bool bmsStrobeLight_;
    bool alive_;
};

