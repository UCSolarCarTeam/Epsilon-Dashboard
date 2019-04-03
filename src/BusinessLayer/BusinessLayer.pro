TEMPLATE = lib
CONFIG += staticlib

! include(../common.pri){
    error("Could not find common.pri file!")
}

DESTDIR = ../../build/.lib

HEADERS += \
    BusinessContainer.h \
    CommunicationsMonitoringService/CommunicationsMonitoringService.h \
    CommunicationsMonitoringService/I_CommunicationsMonitoringService.h \
    DataPopulators/AuxBmsPopulator/AuxBmsPopulator.h \
    DataPopulators/BatteryFaultsPopulator/BatteryFaultsPopulator.h \
    DataPopulators/BatteryPopulator/BatteryPopulator.h \
    DataPopulators/DriverControlsPopulator/DriverControlsPopulator.h \
    DataPopulators/JsonDefines.h \
    DataPopulators/KeyMotorPopulator/KeyMotorPopulator.h \
    DataPopulators/LightsPopulator/LightsPopulator.h \
    DataPopulators/MotorDetailsPopulator/MotorDetailsPopulator.h \
    DataPopulators/MotorFaultsPopulator/MotorFaultsPopulator.h \
    DataPopulators/MpptPopulator/MpptPopulator.h \
    DataPopulators/MotorDetailsPopulator/I_MotorDetailsPopulator.h \
    DataPopulators/MotorFaultsPopulator/I_MotorFaultsPopulator.h \
    DataPopulators/MpptPopulator/I_MpptPopulator.h \
    DataPopulators/LightsPopulator/I_LightsPopulator.h \
    DataPopulators/KeyMotorPopulator/I_KeyMotorPopulator.h \
    DataPopulators/DriverControlsPopulator/I_DriverControlsPopulator.h \
    DataPopulators/BatteryPopulator/I_BatteryPopulator.h \
    DataPopulators/BatteryFaultsPopulator/I_BatteryFaultsPopulator.h \
    DataPopulators/AuxBmsPopulator/I_AuxBmsPopulator.h \
    DataPopulators/CcsPopulator.h

SOURCES += \ 
    BusinessContainer.cpp \
    CommunicationsMonitoringService/CommunicationsMonitoringService.cpp \
    DataPopulators/AuxBmsPopulator/AuxBmsPopulator.cpp \
    DataPopulators/BatteryFaultsPopulator/BatteryFaultsPopulator.cpp \
    DataPopulators/BatteryPopulator/BatteryPopulator.cpp \
    DataPopulators/DriverControlsPopulator/DriverControlsPopulator.cpp \
    DataPopulators/KeyMotorPopulator/KeyMotorPopulator.cpp \
    DataPopulators/LightsPopulator/LightsPopulator.cpp \
    DataPopulators/MotorDetailsPopulator/MotorDetailsPopulator.cpp \
    DataPopulators/MotorFaultsPopulator/MotorFaultsPopulator.cpp \
    DataPopulators/MpptPopulator/MpptPopulator.cpp \
    DataPopulators/CcsPopulator.cpp
