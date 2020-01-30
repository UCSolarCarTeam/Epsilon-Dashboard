TEMPLATE = lib
CONFIG += staticlib conan_basic_setup

! include(../common.pri){
    error("Could not find common.pri file!")
}

! include(../../build/conanbuildinfo.pri) {
    error("Could not find conanbuildinfo.pri file!")
}

DESTDIR = .lib

HEADERS += \
    CommDeviceControl/CommDefines.h \
    CommDeviceControl/CommDeviceManager.h \
    CommDeviceControl/ConnectionController.h \
    CommDeviceControl/I_CommDevice.h \
    CommDeviceControl/I_ConnectionService.h \
    CommunicationContainer.h \
    JsonReceiver/I_JsonReceiver.h \
    JsonReceiver/JsonReceiver.h \
    CommDeviceControl/InternetConnectionService.h \
    CommDeviceControl/InternetCommDevice.h \
    Logging/Logging.h

SOURCES += \ 
    CommDeviceControl/CommDeviceManager.cpp \
    CommDeviceControl/ConnectionController.cpp \
    CommunicationContainer.cpp \
    JsonReceiver/JsonReceiver.cpp \
    CommDeviceControl/InternetConnectionService.cpp \
    CommDeviceControl/InternetCommDevice.cpp \
    Logging/Logging.cpp
