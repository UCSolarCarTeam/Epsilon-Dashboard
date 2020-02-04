TEMPLATE = app
QT += testlib
CONFIG += testcase c++11 conan_basic_setup
! include($$OUT_PWD/../conanbuildinfo.pri) {
    error("Could not find conanbuildinfo.pri file!")
}

LIBS += \
    -L../ViewLayer/.lib -lViewLayer \
    -L../CommunicationLayer/.lib -lCommunicationLayer \
    -L../BusinessLayer/.lib -lBusinessLayer \
    -L../DataLayer/.lib -lDataLayer \
    -L../PresenterLayer/.lib -lPresenterLayer \
    -L../InfrastructureLayer/.lib -lInfrastructureLayer

SOURCES += \
    CommunicationLayer/JsonReceiver/JsonReceiverTest.cpp \
    testmain.cpp


!win32 {
    QMAKE_CXXFLAGS +=
}

DESTDIR = ../bin/tests/

copytestconfig.commands = cp $$PWD/testconfig.ini $${DESTDIR}

QMAKE_EXTRA_TARGETS += copytestconfig
POST_TARGETDEPS += copytestconfig

HEADERS += \
    CommunicationLayer/mockcommdevicemanager.h \
    BusinessLayer/CommunicationsMonitoringService/MockCommunicationMonitoringService.h \
    BusinessLayer/DataPopulators/MockAuxBmsPopulator.h \
    BusinessLayer/DataPopulators/MockBatteryFaultsPopulator.h \
    BusinessLayer/DataPopulators/MockBatteryPopulator.h \
    BusinessLayer/DataPopulators/MockDriverControlsPopulator.h \
    BusinessLayer/DataPopulators/MockKeyMotorPopulator.h \
    BusinessLayer/DataPopulators/MockLightsPopulator.h \
    BusinessLayer/DataPopulators/MockMotorDetailsPopulator.h \
    BusinessLayer/DataPopulators/MockMotorFaultsPopulator.h \
    BusinessLayer/DataPopulators/MockMpptPopulator.h

