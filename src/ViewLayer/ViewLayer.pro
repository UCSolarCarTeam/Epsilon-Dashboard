TEMPLATE = lib
CONFIG += staticlib

! include(../common.pri){
    error("Could not find common.pri file!")
}

DESTDIR = .lib
INCLUDEPATH += DebugDisplay/

HEADERS += \
    DebugDisplay/AuxBmsPage/AuxBmsUi/AuxBmsUi.h \
    DebugDisplay/AuxBmsPage/AuxBmsUi/I_AuxBmsUi.h \
    DebugDisplay/AuxBmsPage/AuxBmsView/AuxBmsView.h \
    DebugDisplay/BatteryPage/BatteryUi/BatteryUi.h \
    DebugDisplay/BatteryPage/BatteryUi/I_BatteryUi.h \
    DebugDisplay/BatteryPage/BatteryView/BatteryView.h \
    DebugDisplay/BatteryPage/ProgressBar.h \
    DebugDisplay/ControlPage/ControlUi/ControlUi.h \
    DebugDisplay/ControlPage/ControlUi/I_ControlUi.h \
    DebugDisplay/ControlPage/ControlView/ControlView.h \
    DebugDisplay/HomePage/HomePageUi/HomePageUi.h \
    DebugDisplay/HomePage/HomePageUi/I_HomePageUi.h \
    DebugDisplay/FaultPage/FaultView/FaultView.h \
    DebugDisplay/FaultPage/FaultUi/FaultUi.h \
    DebugDisplay/FaultPage/FaultUi/I_FaultUi.h \
    DebugDisplay/MotorPage/MotorUi/MotorUi.h \
    DebugDisplay/MotorPage/MotorUi/I_MotorUi.h \
    DebugDisplay/MPPTPage/MPPTUi/MpptUi.h \
    DebugDisplay/MPPTPage/MPPTUi/I_MpptUi.h \
    DebugDisplay/MPPTPage/MPPTView/MpptView.h \
    DebugDisplay/MotorPage/MotorView/MotorView.h \
    DebugDisplay/OverlordWidget/OverlordWidget.h \
    DebugDisplay/Tab/TabUi/TabUi.h \
    DebugDisplay/Tab/TabUi/I_TabUi.h \
    DisplayDashboard/DisplayDashboardUI/DisplayDashboardUI.h \
    DisplayDashboard/DisplayDashboardUI/I_DisplayDashboardUI.h \
    DisplayDashboard/DisplayDashboardView/DisplayDashboardView.h \
    Faults/BatteryFaults/BatteryFaultPopulator.h \
    Faults/BatteryFaults/BatteryFaultsResources.h \
    Faults/BatteryFaults/BatteryFaultsUpdater.h \
    Faults/BatteryFaults/I_BatteryFaultList.h \
    Faults/FaultLabel/FaultDisplayData.h \
    Faults/FaultPopulator.h \
    Faults/MotorFaults/I_MotorFaultList.h \
    Faults/MotorFaults/MotorFaultPopulator.h \
    Faults/MotorFaults/MotorFaultsResources.h \
    Faults/MotorFaults/MotorFaultsUpdater.h \
    RaceModeDisplay/RaceModeDisplayUI/I_RaceModeDashboardUI.h \
    RaceModeDisplay/RaceModeDisplayUI/RaceModeDashboardUI.h \
    ViewContainer.h \
    DebugDisplay/HomePage/HomePageView/HomePageView.h \
    RaceModeDisplay/RaceModeDashboardView.h \
    Faults/MotorFaults/MotorFaultList.h \
    Faults/BatteryFaults/BatteryFaultList.h \
    Faults/FaultPriorities/FaultPriorities.h \
    FontLoader/FontLoader.h

SOURCES += \
    DebugDisplay/AuxBmsPage/AuxBmsUi/AuxBmsUi.cpp \
    DebugDisplay/AuxBmsPage/AuxBmsView/AuxBmsView.cpp \
    DebugDisplay/BatteryPage/BatteryUi/BatteryUi.cpp \
    DebugDisplay/BatteryPage/BatteryView/BatteryView.cpp \
    DebugDisplay/BatteryPage/ProgressBar.cpp \
    DebugDisplay/ControlPage/ControlUi/ControlUi.cpp \
    DebugDisplay/ControlPage/ControlView/ControlView.cpp \
    DebugDisplay/HomePage/HomePageUi/HomePageUi.cpp\
    Faults/BatteryFaults/BatteryFaultPopulator.cpp \
    Faults/BatteryFaults/BatteryFaultsUpdater.cpp \
    Faults/FaultLabel/FaultDisplayData.cpp \
    Faults/MotorFaults/MotorFaultPopulator.cpp \
    Faults/MotorFaults/MotorFaultsUpdater.cpp \
    DebugDisplay/FaultPage/FaultUi/FaultUi.cpp \
    DebugDisplay/MotorPage/MotorUi/MotorUi.cpp \
    DebugDisplay/FaultPage/FaultView/FaultView.cpp \
    DebugDisplay/MPPTPage/MPPTUi/MpptUi.cpp \
    DebugDisplay/MotorPage/MotorView/MotorView.cpp \
    DebugDisplay/MPPTPage/MPPTView/MpptView.cpp \
    DebugDisplay/OverlordWidget/OverlordWidget.cpp \
    DebugDisplay/Tab/TabUi/TabUi.cpp \
    DisplayDashboard/DisplayDashboardUI/DisplayDashboardUI.cpp \
    DisplayDashboard/DisplayDashboardView/DisplayDashboardView.cpp \
    RaceModeDisplay/RaceModeDashboardView.cpp \
    RaceModeDisplay/RaceModeDisplayUI/RaceModeDashboardUI.cpp \
    ViewContainer.cpp \
    DebugDisplay/HomePage/HomePageView/HomePageView.cpp \
    Faults/MotorFaults/MotorFaultList.cpp \
    Faults/BatteryFaults/BatteryFaultList.cpp \
    FontLoader/FontLoader.cpp

FORMS += \
    DebugDisplay/AuxBmsPage/AuxBmsUi/AuxBmsUi.ui \
    DebugDisplay/BatteryPage/BatteryUi/BatteryUi.ui \
    DebugDisplay/ControlPage/ControlUi/ControlUi.ui \
    DebugDisplay/HomePage/HomePageUi/HomePageUi.ui \
    DebugDisplay/FaultPage/FaultUi/FaultUi.ui \
    DebugDisplay/MotorPage/MotorUi/MotorUi.ui \
    DebugDisplay/MPPTPage/MPPTUi/MpptUi.ui \
    DebugDisplay/Tab/TabUi/TabUi.ui \
    DisplayDashboard/DisplayDashboardUI.ui \
    RaceModeDisplay/RaceModeDashboardUI.ui

RESOURCES += \
    fontresources.qrc
