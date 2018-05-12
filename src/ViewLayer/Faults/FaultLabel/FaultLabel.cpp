#include "FaultLabel.h"

FaultLabel::FaultLabel()
    : QLabel("")
    , color_("")
    , priority_(-1)
    , isActive_(false)
{
}

FaultLabel::FaultLabel(QString name, QColor color, int priority, bool isActive)
    : QLabel(name)
    , color_(color)
    , priority_(priority)
    , isActive_(isActive)
{
}

FaultLabel::FaultLabel(const FaultLabel& faultLabel)
    : QLabel(faultLabel.name())
    , color_(faultLabel.color())
    , priority_(faultLabel.priority())
    , isActive_(faultLabel.isActive())
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

int FaultLabel::priority() const
{
    return priority_;
}

bool FaultLabel::isActive() const
{
    return isActive_;
}

void FaultLabel::setActive(bool value)
{
    isActive_ = value;
}
