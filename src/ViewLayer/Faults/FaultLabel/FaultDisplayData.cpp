#include "FaultDisplayData.h"

FaultDisplayData::FaultDisplayData()
    : name_("")
    , color_(FaultPriorities::DEFAULT_COLOR)
    , priority_(FaultPriorities::INVALID_PRIORITY)
    , isActive_(false)
{
}

FaultDisplayData::FaultDisplayData(QString name, FaultPriorities::PRIORITY priority, bool isActive)
    : name_(name)
    , color_(priorityToColor(priority))
    , priority_(priority)
    , isActive_(isActive)
{
}

FaultDisplayData::FaultDisplayData(const FaultDisplayData& faultLabel)
    : name_(faultLabel.name())
    , color_(faultLabel.color())
    , priority_(faultLabel.priority())
    , isActive_(faultLabel.isActive())
{
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
    isActive_ = value;
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
