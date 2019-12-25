TEMPLATE = lib
CONFIG += staticlib

! include(../common.pri){
    error("Could not find common.pri file!")
}

DESTDIR = .lib

HEADERS += \
    DataContainer.h \
    AuxBmsData/AuxBmsData.h \
    AuxBmsData/I_AuxBmsData.h \
    BatteryData/BatteryData.h \
    BatteryData/BmsRelayStatusFlags.h \
    BatteryData/I_BatteryData.h \
    BatteryFaultsData/BatteryFaultsData.h \
    BatteryFaultsData/BatteryErrorFlags.h \
    BatteryFaultsData/BatteryLimitFlags.h \
    BatteryFaultsData/BatteryFaultsData.h \
    BatteryFaultsData/I_BatteryFaultsData.h \
    CcsData/CcsData.h \
    CcsData/I_CcsData.h \
    DriverControlsData/DriverControlsData.h \
    DriverControlsData/I_DriverControlsData.h \
    KeyMotorData/I_KeyMotorData.h \
    KeyMotorData/KeyMotor.h \
    KeyMotorData/KeyMotorData.h \
    LightsData/LightsData.h \
    LightsData/I_LightsData.h \
    MpptData/I_MpptData.h \
    MpptData/Mppt.h \
    MpptData/MpptData.h \
    MotorDetailsData/MotorDetails.h \
    MotorDetailsData/MotorDetailsData.h \
    MotorDetailsData/I_MotorDetailsData.h \
    MotorFaultsData/I_MotorFaultsData.h \
    MotorFaultsData/ErrorFlags.h \
    MotorFaultsData/LimitFlags.h \
    MotorFaultsData/MotorFaultsData.h 

SOURCES += \ 
    DataContainer.cpp \
    AuxBmsData/AuxBmsData.cpp \
    BatteryData/BmsRelayStatusFlags.cpp \
    BatteryData/BatteryData.cpp \
    BatteryFaultsData/BatteryErrorFlags.cpp \
    BatteryFaultsData/BatteryFaultsData.cpp \
    BatteryFaultsData/BatteryLimitFlags.cpp \
    CcsData/CcsData.cpp \
    DriverControlsData/DriverControlsData.cpp \
    KeyMotorData/KeyMotorData.cpp \
    KeyMotorData/KeyMotor.cpp \
    LightsData/LightsData.cpp \
    MpptData/MpptData.cpp \
    MpptData/Mppt.cpp \
    MotorDetailsData/MotorDetails.cpp \
    MotorDetailsData/MotorDetailsData.cpp \
    MotorFaultsData/ErrorFlags.cpp \
    MotorFaultsData/LimitFlags.cpp \
    MotorFaultsData/MotorFaultsData.cpp 
