TEMPLATE = lib
CONFIG += staticlib

! include(../common.pri){
    error("Could not find common.pri file!")
}

DESTDIR = ../../build/.lib

HEADERS += \
    BatteryData/BatteryData.h \
    BatteryData/I_BatteryData.h \
    BatteryFaultsData/BatteryFaultsData.h \
    BatteryFaultsData/I_BatteryFaultsData.h \
    DriverControlsData/DriverControlsData.h \
    DriverControlsData/I_DriverControlsData.h \
    KeyMotorData/KeyMotorData.h \
    KeyMotorData/I_KeyMotorData.h \
    LightsData/LightsData.h \
    LightsData/I_LightsData.h \
    MpptData/MpptData.h \
    MpptData/I_MpptData.h \
    MotorDetailsData/MotorDetailsData.h \
    MotorDetailsData/I_MotorDetailsData.h \
    MotorFaultsData/MotorFaultsData.h \
    MotorFaultsData/I_MotorFaultsData.h \
    DataContainer.h \
    KeyMotorData/KeyMotor.h \
    MpptData/Mppt.h \
    MotorDetailsData/MotorDetails.h \
    MotorFaultsData/ErrorFlags.h \
    MotorFaultsData/LimitFlags.h \
    BatteryData/BmsRelayStatusFlags.h \
    BatteryFaultsData/BatteryErrorFlags.h \
    BatteryFaultsData/BatteryLimitFlags.h \
    AuxBmsData/AuxBmsData.h \
    AuxBmsData/I_AuxBmsData.h \
    AuxBmsData/AuxBmsData.h \
    AuxBmsData/I_AuxBmsData.h \
    BatteryData/BatteryData.h \
    BatteryData/BmsRelayStatusFlags.h \
    BatteryData/I_BatteryData.h \
    BatteryFaultsData/BatteryErrorFlags.h \
    BatteryFaultsData/BatteryFaultsData.h \
    BatteryFaultsData/BatteryLimitFlags.h \
    BatteryFaultsData/I_BatteryFaultsData.h \
    DriverControlsData/DriverControlsData.h \
    DriverControlsData/I_DriverControlsData.h \
    KeyMotorData/I_KeyMotorData.h \
    KeyMotorData/KeyMotor.h \
    KeyMotorData/KeyMotorData.h \
    LightsData/I_LightsData.h \
    LightsData/LightsData.h \
    MotorDetailsData/I_MotorDetailsData.h \
    MotorDetailsData/MotorDetails.h \
    MotorDetailsData/MotorDetailsData.h \
    MotorFaultsData/ErrorFlags.h \
    MotorFaultsData/I_MotorFaultsData.h \
    MotorFaultsData/LimitFlags.h \
    MotorFaultsData/MotorFaultsData.h \
    MpptData/I_MpptData.h \
    MpptData/Mppt.h \
    MpptData/MpptData.h \
    DataContainer.h \
    CcsData/CcsData.h \
    CcsData/I_CcsData.h

SOURCES += \ 
    BatteryData/BatteryData.cpp \
    BatteryFaultsData/BatteryFaultsData.cpp \
    DriverControlsData/DriverControlsData.cpp \
    KeyMotorData/KeyMotorData.cpp \
    KeyMotorData/KeyMotor.cpp \
    LightsData/LightsData.cpp \
    MpptData/MpptData.cpp \
    MpptData/Mppt.cpp \
    MotorDetailsData/MotorDetailsData.cpp \
    MotorDetailsData/MotorDetails.cpp \
    MotorFaultsData/MotorFaultsData.cpp \
    MotorFaultsData/ErrorFlags.cpp \
    MotorFaultsData/LimitFlags.cpp \
    DataContainer.cpp \
    BatteryData/BmsRelayStatusFlags.cpp \
    BatteryFaultsData/BatteryErrorFlags.cpp \
    BatteryFaultsData/BatteryLimitFlags.cpp \
    AuxBmsData/AuxBmsData.cpp \
    AuxBmsData/AuxBmsData.cpp \
    BatteryData/BatteryData.cpp \
    BatteryData/BmsRelayStatusFlags.cpp \
    BatteryFaultsData/BatteryErrorFlags.cpp \
    BatteryFaultsData/BatteryFaultsData.cpp \
    BatteryFaultsData/BatteryLimitFlags.cpp \
    DriverControlsData/DriverControlsData.cpp \
    KeyMotorData/KeyMotor.cpp \
    KeyMotorData/KeyMotorData.cpp \
    LightsData/LightsData.cpp \
    MotorDetailsData/MotorDetails.cpp \
    MotorDetailsData/MotorDetailsData.cpp \
    MotorFaultsData/ErrorFlags.cpp \
    MotorFaultsData/LimitFlags.cpp \
    MotorFaultsData/MotorFaultsData.cpp \
    MpptData/Mppt.cpp \
    MpptData/MpptData.cpp \
    DataContainer.cpp \
    CcsData/CcsData.cpp
