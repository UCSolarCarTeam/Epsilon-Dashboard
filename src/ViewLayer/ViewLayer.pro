TEMPLATE = lib
CONFIG += staticlib

! include(../common.pri){
    error("Could not find common.pri file!")
}

DESTDIR = ../../build/.lib

HEADERS += \
    DebugDisplay/BatteryPage/BatteryUi/BatteryUi.h \
    DebugDisplay/BatteryPage/BatteryUi/I_BatteryUi.h \
    DebugDisplay/ControlPage/ControlUi/ControlUi.h \
    DebugDisplay/ControlPage/ControlUi/I_ControlUi.h \
    DebugDisplay/ControlPage/ControlView/ControlView.h \
    DebugDisplay/HomePage/HomePageUi/HomePageUi.h \
    DebugDisplay/HomePage/HomePageUi/I_HomePageUi.h \
    DebugDisplay/MotorFaultPage/MotorFaultView/MotorFaultView.h \
    DebugDisplay/MotorFaultPage/MotorFaultUi/MotorFaultUi.h \
    DebugDisplay/MotorFaultPage/MotorFaultUi/I_MotorFaultUi.h \
    DebugDisplay/MotorPage/MotorUi/MotorUi.h \
    DebugDisplay/MotorPage/MotorUi/I_MotorUi.h \
    DebugDisplay/MPPTPage/MPPTUi/MpptUi.h \
    DebugDisplay/MPPTPage/MPPTUi/I_MpptUi.h \
    DebugDisplay/MotorPage/MotorUi/I_MotorUi.h \
    DebugDisplay/MotorPage/MotorUi/MotorUi.h \
    DebugDisplay/MotorPage/MotorUi/MotorView.h \
    DebugDisplay/MotorPage/MotorUi/MotorView.h \
    DebugDisplay/MPPTPage/MPPTView/MpptView.h \
    DebugDisplay/MotorPage/MotorUi/MotorView.h \
    DebugDisplay/ControlPage/ControlView/ControlView.h \
    DebugDisplay/MPPTPage/MPPTView/MpptView.h \
    DebugDisplay/OverlordWidget/OverlordWidget.h \
    DebugDisplay/Tab/TabUi/TabUi.h \
    DebugDisplay/Tab/TabUi/I_TabUi.h \
    DisplayDashboard/DisplayDashboardUI/DisplayDashboardUI.h \
    DisplayDashboard/DisplayDashboardUI/I_DisplayDashboardUI.h \
    DisplayDashboard/DisplayDashboardUI/I_RaceModeDashboardUI.h \
    DisplayDashboard/DisplayDashboardUI/RaceModeDashboardUI.h \
    DisplayDashboard/DisplayDashboardView/DisplayDashboardView.h \
    ViewContainer.h

SOURCES += \ 
    DebugDisplay/BatteryPage/BatteryUi/BatteryUi.cpp \
    DebugDisplay/ControlPage/ControlUi/ControlUi.cpp \
    DebugDisplay/ControlPage/ControlView/ControlView.cpp \
    DebugDisplay/HomePage/HomePageUi/HomePageUi.cpp\ 
    DebugDisplay/MotorFaultPage/MotorFaultUi/MotorFaultUi.cpp \
    DebugDisplay/MotorFaultPage/MotorFaultView/MotorFaultView.cpp \
    DebugDisplay/MotorPage/MotorUi/MotorUi.cpp \
    DebugDisplay/MPPTPage/MPPTUi/MpptUi.cpp \
    DebugDisplay/MotorPage/MotorView/MotorView.cpp \
    DebugDisplay/MotorPage/MotorUi/MotorUi.cpp \
    DebugDisplay/MotorPage/MotorUi/MotorView.cpp \
    DebugDisplay/MotorPage/MotorUi/MotorView.cpp \
    DebugDisplay/MotorPage/MotorUi/MotorView.cpp \
    DebugDisplay/MPPTPage/MPPTView/MpptView.cpp \
    DebugDisplay/MotorPage/MotorUi/MotorView.cpp \
    DebugDisplay/ControlPage/ControlView/ControlView.cpp \
    DebugDisplay/MPPTPage/MPPTView/MpptView.cpp \
    DebugDisplay/OverlordWidget/OverlordWidget.cpp \
    DebugDisplay/Tab/TabUi/TabUi.cpp \
    DisplayDashboard/DisplayDashboardUI/DisplayDashboardUI.cpp \
    DisplayDashboard/DisplayDashboardView/DisplayDashboardView.cpp \
    DisplayDashboard/DisplayDashboardUI/RaceModeDashboardUI.cpp \
    ViewContainer.cpp

FORMS += \   
    DebugDisplay/BatteryPage/BatteryUi/BatteryUi.ui \
    DebugDisplay/ControlPage/ControlUi/ControlUi.ui \
    DebugDisplay/HomePage/HomePageUi/HomePageUi.ui \
    DebugDisplay/MotorFaultPage/MotorFaultUi/MotorFaultUi.ui \
    DebugDisplay/MotorPage/MotorUi/MotorUi.ui \
    DebugDisplay/MPPTPage/MPPTUi/MpptUi.ui \
    DebugDisplay/Tab/TabUi/TabUi.ui \
    DisplayDashboard/DisplayDashboardUI.ui \
    DisplayDashboard/RaceModeDashboardUI.ui
