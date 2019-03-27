TEMPLATE = app
QT += testlib
CONFIG += testcase c++11

LIBS += -L../../build/.lib -lBusinessLayer -lgmock -lViewLayer -lCommunicationLayer -lInfrastructureLayer -lDataLayer -lPresenterLayer

SOURCES += \
    CommunicationLayer/JsonReceiver/JsonReceiverTest.cpp \
    testmain.cpp


!win32 {
    QMAKE_CXXFLAGS +=
}

DESTDIR = ../../build/tests/

copyfiles.commands = cp testconfig.ini $${DESTDIR}

QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles

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

