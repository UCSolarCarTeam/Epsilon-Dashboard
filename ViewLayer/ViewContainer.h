#pragma once

#include <QScopedPointer>

class I_DisplayDashboardUI;
class DisplayDashboardView;
class PresenterContainer;
class RaceModeDashboardUI;

class ViewContainer
{
public:
    explicit ViewContainer(PresenterContainer& presenterContainer, char mode);
    ~ViewContainer();

private:
    I_DisplayDashboardUI* DisplayDashboardUI_;
    RaceModeDashboardUI* RaceModeDashboardUI_;
    QScopedPointer<DisplayDashboardView> DisplayDashboardView_;
};
