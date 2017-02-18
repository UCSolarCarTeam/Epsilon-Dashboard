#pragma once

#include <QScopedPointer>

class DisplayDashboardUI;
class RaceModeDashboardUI;
class DisplayDashboardView;
class PresenterContainer;

class ViewContainer
{
public:
    explicit ViewContainer(PresenterContainer& presenterContainer, int mode);
    ~ViewContainer();

private:
    DisplayDashboardUI* DisplayDashboardUI_;
    RaceModeDashboardUI* RaceModeDashboardUI_;
    QScopedPointer<DisplayDashboardView> DisplayDashboardView_;
};
