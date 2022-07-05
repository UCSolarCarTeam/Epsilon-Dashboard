#include "FaultDisplayData.h"

namespace
{
    const int KEEP_ALIVE_TIME = 120000;
}

FaultDisplayData::FaultDisplayData()
    : name_("")
    , color_(FaultPriorities::DEFAULT_COLOR)
    , priority_(FaultPriorities::INVALID_PRIORITY)
    , isActive_(false)
    , keepAliveTimer_(QElapsedTimer())
{
}

FaultDisplayData::FaultDisplayData(QString name, FaultPriorities::PRIORITY priority, bool isActive)
    : name_(name)
    , color_(priorityToColor(priority))
    , priority_(priority)
    , isActive_(isActive)
    , keepAliveTimer_(QElapsedTimer())
{
}

FaultDisplayData::FaultDisplayData(const FaultDisplayData& faultLabel)
    : name_(faultLabel.name())
    , color_(faultLabel.color())
    , priority_(faultLabel.priority())
    , isActive_(faultLabel.isActive())
    , keepAliveTimer_(QElapsedTimer())
{
}

FaultDisplayData& FaultDisplayData::operator=(const FaultDisplayData& other)
{
    // Guard self assignment
    if (this == &other)
    {
        return *this;
    }
    else
    {
        name_ = other.name();
        color_ = other.color();
        priority_ = other.priority();
        isActive_ = other.isActive();
    }
    return *this;
}

FaultDisplayData::~FaultDisplayData()
{
}

QString FaultDisplayData::name() const
{
    return name_;
}

QColor FaultDisplayData::color() const
{
    return color_;
}

FaultPriorities::PRIORITY FaultDisplayData::priority() const
{
    return priority_;
}

bool FaultDisplayData::isActive() const
{
    return isActive_;
}

void FaultDisplayData::setActive(bool value)
{
    //When fault is active and the incoming fault is not
    if(isActive_ && isActive_ != value)
    {
        //Check if there is a valid timer
        if(!keepAliveTimer_.isValid())
        {
            keepAliveTimer_.start();
        }
        else
        {
            //If the time has elapsed
            if(keepAliveTimer_.elapsed() >= KEEP_ALIVE_TIME)
            {
                //Invalidate the timer
                keepAliveTimer_.invalidate();
                isActive_ = value;
            }
        }

    }
    else
    {
        keepAliveTimer_.invalidate();
        isActive_ = value;
    }
}

QColor FaultDisplayData::priorityToColor(FaultPriorities::PRIORITY priority)
{
    switch (priority)
    {
        case FaultPriorities::INVALID_PRIORITY:
            return FaultPriorities::DEFAULT_COLOR;

        case FaultPriorities::HIGH_PRIORITY:
            return FaultPriorities::HIGH_PRIORITY_COLOR;

        case FaultPriorities::MEDIUM_PRIORITY:
            return FaultPriorities::MEDIUM_PRIORITY_COLOR;

        case FaultPriorities::LOW_PRIORITY:
            return FaultPriorities::LOW_PRIORITY_COLOR;
    }

    return FaultPriorities::DEFAULT_COLOR;
}
