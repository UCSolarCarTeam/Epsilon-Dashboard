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
    DataPopulators/BatteryPopulator.h \
    DataPopulators/BatteryFaultsPopulator.h \
    DataPopulators/DriverControlsPopulator.h \
    DataPopulators/KeyMotorPopulator.h \
    DataPopulators/LightsPopulator.h \
    DataPopulators/MpptPopulator.h \
    DataPopulators/MotorDetailsPopulator.h \
    DataPopulators/MotorFaultsPopulator.h \
    DataPopulators/JsonDefines.h

SOURCES += \ 
    BusinessContainer.cpp \
    CommunicationsMonitoringService/CommunicationsMonitoringService.cpp \
    DataPopulators/BatteryPopulator.cpp \
    DataPopulators/BatteryFaultsPopulator.cpp \
    DataPopulators/DriverControlsPopulator.cpp \
    DataPopulators/KeyMotorPopulator.cpp \
    DataPopulators/LightsPopulator.cpp \
    DataPopulators/MpptPopulator.cpp \
    DataPopulators/MotorDetailsPopulator.cpp \
    DataPopulators/MotorFaultsPopulator.cpp
