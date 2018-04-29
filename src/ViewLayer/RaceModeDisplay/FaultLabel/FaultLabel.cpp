#include "FaultLabel.h"

FaultLabel::FaultLabel(QString &name, QString &color, int &priority, bool isActive)
    : color_(color)
    , priority_(priority)
    , isActive_(isActive)
{
    QLabel(name, QWidget* parent=0);
}

FaultLabel::~FaultLabel()
{
}

QString FaultLabel::name() const
{
    return this->text();
}

QString FaultLabel::color() const
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

void FaultLabel::setIsActive(bool value)
{
    isActive_ = value;
}
