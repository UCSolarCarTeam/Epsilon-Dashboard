TEMPLATE = lib
CONFIG += staticlib

! include(../common.pri){
    error("Could not find common.pri file!")
}

DESTDIR = ../../build/.lib

HEADERS += \
    BatteryPresenter/BatteryPresenter.h \ 
    BatteryFaultsPresenter/BatteryFaultsPresenter.h \ 
    DriverControlsPresenter/DriverControlsPresenter.h \ 
    KeyMotorPresenter/KeyMotorPresenter.h \ 
    LightsPresenter/LightsPresenter.h \ 
    MpptPresenter/MpptPresenter.h \
    MotorDetailsPresenter/MotorDetailsPresenter.h \ 
    MotorFaultsPresenter/MotorFaultsPresenter.h \ 
    PresenterContainer.h \  
    AuxBmsPresenter/AuxBmsPresenter.h

SOURCES += \ 
    BatteryPresenter/BatteryPresenter.cpp \
    BatteryFaultsPresenter/BatteryFaultsPresenter.cpp \
    DriverControlsPresenter/DriverControlsPresenter.cpp \
    KeyMotorPresenter/KeyMotorPresenter.cpp \
    LightsPresenter/LightsPresenter.cpp \
    MpptPresenter/MpptPresenter.cpp \
    MotorDetailsPresenter/MotorDetailsPresenter.cpp \
    MotorFaultsPresenter/MotorFaultsPresenter.cpp \
    PresenterContainer.cpp \  
    AuxBmsPresenter/AuxBmsPresenter.cpp


