#include "FaultLabel.h"

FaultLabel::FaultLabel()
    : QLabel("")
    , color_(FaultPriorities::DEFAULT_COLOR)
    , priority_(FaultPriorities::INVALID_PRIORITY)
    , isActive_(false)
    , isRaceRequired_(false)
{
}

FaultLabel::FaultLabel(QString name, FaultPriorities::PRIORITY priority, bool isActive, bool isRaceRequired)
    : QLabel(name)
    , color_(priorityToColor(priority))
    , priority_(priority)
    , isActive_(isActive)
    , isRaceRequired_(isRaceRequired)
{
}

FaultLabel::FaultLabel(const FaultLabel& faultLabel)
    : QLabel(faultLabel.name())
    , color_(faultLabel.color())
    , priority_(faultLabel.priority())
    , isActive_(faultLabel.isActive())
    , isRaceRequired_(faultLabel.isRaceRequired())
{
}

FaultLabel::~FaultLabel()
{
}

QString FaultLabel::name() const
{
    return this->text();
}

QColor FaultLabel::color() const
{
    return color_;
}

FaultPriorities::PRIORITY FaultLabel::priority() const
{
    return priority_;
}

bool FaultLabel::isActive() const
{
    return isActive_;
}

bool FaultLabel::isRaceRequired() const
{
    return isRaceRequired_;
}

void FaultLabel::setActive(bool value)
{
    isActive_ = value;
}

QColor FaultLabel::priorityToColor(FaultPriorities::PRIORITY priority)
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
