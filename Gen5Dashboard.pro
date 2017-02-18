#
#  For further contact, email <software@calgarysolarcar.ca>
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = ../release/Gen5Dashboard
TEMPLATE = app
CONFIG += static

QMAKE_CXXFLAGS +=
RCC_DIR= ../release
DESTDIR = ../release
OBJECTS_DIR = ../release/.obj
MOC_DIR = ../release/.moc
RCC_DIR = ../release/.rcc
UI_DIR = ../release/.ui

SOURCES += \
    BusinessLayer/BusinessContainer.cpp \
    BusinessLayer/CommunicationsMonitoringService/CommunicationsMonitoringService.cpp \
    BusinessLayer/DataPopulators/BatteryPopulator.cpp \
    BusinessLayer/DataPopulators/BatteryFaultsPopulator.cpp \
    BusinessLayer/DataPopulators/CMUPopulator.cpp \
    BusinessLayer/DataPopulators/DriverControlsPopulator.cpp \
    BusinessLayer/DataPopulators/KeyMotorPopulator.cpp \
    BusinessLayer/DataPopulators/LightsPopulator.cpp \
    BusinessLayer/DataPopulators/MPPTPopulator.cpp \
    BusinessLayer/DataPopulators/MotorDetailsPopulator.cpp \
    BusinessLayer/DataPopulators/MotorFaultsPopulator.cpp \
    CommunicationLayer/CommDeviceControl/CommDeviceManager.cpp \
    CommunicationLayer/CommDeviceControl/ConnectionController.cpp \
    CommunicationLayer/CommDeviceControl/UdpConnectionService.cpp \
    CommunicationLayer/CommunicationContainer.cpp \
    CommunicationLayer/JsonReceiver/JsonReceiver.cpp \
    DataLayer/BatteryData/BatteryData.cpp \
    DataLayer/BatteryFaultsData/BatteryFaultsData.cpp \
    DataLayer/BatteryFaultsData/BatteryFaults.cpp \
    DataLayer/CMUData/CMUData.cpp \
    DataLayer/CMUData/CMU.cpp \
    DataLayer/DriverControlsData/DriverControlsData.cpp \
    DataLayer/KeyMotorData/KeyMotorData.cpp \
    DataLayer/KeyMotorData/KeyMotor.cpp \
    DataLayer/LightsData/LightsData.cpp \
    DataLayer/MPPTData/MPPTData.cpp \
    DataLayer/MPPTData/MPPT.cpp \
    DataLayer/MotorDetailsData/MotorDetailsData.cpp \
    DataLayer/MotorDetailsData/MotorDetails.cpp \
    DataLayer/MotorFaultsData/MotorFaultsData.cpp \
    DataLayer/MotorFaultsData/ErrorFlags.cpp \
    DataLayer/MotorFaultsData/LimitFlags.cpp \
    DataLayer/DataContainer.cpp \
    PresenterLayer/BatteryPresenter/BatteryPresenter.cpp \
    PresenterLayer/BatteryFaultsPresenter/BatteryFaultsPresenter.cpp \
    PresenterLayer/CMUPresenter/CMUPresenter.cpp \
    PresenterLayer/DriverControlsPresenter/DriverControlsPresenter.cpp \
    PresenterLayer/KeyMotorPresenter/KeyMotorPresenter.cpp \
    PresenterLayer/LightsPresenter/LightsPresenter.cpp \
    PresenterLayer/MPPTPresenter/MPPTPresenter.cpp \
    PresenterLayer/MotorDetailsPresenter/MotorDetailsPresenter.cpp \
    PresenterLayer/MotorFaultsPresenter/MotorFaultsPresenter.cpp \
    PresenterLayer/PresenterContainer.cpp \
    Gen5Dashboard/main.cpp \
    Gen5Dashboard/Gen5Dashboard.cpp \
    ViewLayer/ViewContainer.cpp \
    ViewLayer/DisplayDashboardUI/DisplayDashboardUI.cpp \
    ViewLayer/DisplayDashboardView/DisplayDashboardView.cpp \
    ViewLayer/DisplayDashboardUI/RaceModeDashboardUI.cpp

HEADERS  += \
    BusinessLayer/BusinessContainer.h \
    BusinessLayer/CommunicationsMonitoringService/CommunicationsMonitoringService.h \
    BusinessLayer/CommunicationsMonitoringService/I_CommunicationsMonitoringService.h \
    BusinessLayer/DataPopulators/BatteryPopulator.h \
    BusinessLayer/DataPopulators/BatteryFaultsPopulator.h \
    BusinessLayer/DataPopulators/CMUPopulator.h \
    BusinessLayer/DataPopulators/DriverControlsPopulator.h \
    BusinessLayer/DataPopulators/KeyMotorPopulator.h \
    BusinessLayer/DataPopulators/LightsPopulator.h \
    BusinessLayer/DataPopulators/MPPTPopulator.h \
    BusinessLayer/DataPopulators/MotorDetailsPopulator.h \
    BusinessLayer/DataPopulators/MotorFaultsPopulator.h \
    BusinessLayer/DataPopulators/JsonDefines.h \
    CommunicationLayer/CommDeviceControl/CommDefines.h \
    CommunicationLayer/CommDeviceControl/CommDeviceManager.h \
    CommunicationLayer/CommDeviceControl/ConnectionController.h \
    CommunicationLayer/CommDeviceControl/I_CommDevice.h \
    CommunicationLayer/CommDeviceControl/I_ConnectionService.h \
    CommunicationLayer/CommDeviceControl/UdpConnectionService.h \
    CommunicationLayer/CommunicationContainer.h \
    CommunicationLayer/JsonReceiver/I_JsonReceiver.h \
    CommunicationLayer/JsonReceiver/JsonReceiver.h \
    DataLayer/BatteryData/BatteryData.h \
    DataLayer/BatteryData/I_BatteryData.h \
    DataLayer/BatteryFaultsData/BatteryFaultsData.h \
    DataLayer/BatteryFaultsData/BatteryFaults.h \
    DataLayer/BatteryFaultsData/I_BatteryFaultsData.h \
    DataLayer/CMUData/CMUData.h \
    DataLayer/CMUData/I_CMUData.h \
    DataLayer/DriverControlsData/DriverControlsData.h \
    DataLayer/DriverControlsData/I_DriverControlsData.h \
    DataLayer/KeyMotorData/KeyMotorData.h \
    DataLayer/KeyMotorData/I_KeyMotorData.h \
    DataLayer/LightsData/LightsData.h \
    DataLayer/LightsData/I_LightsData.h \
    DataLayer/MPPTData/MPPTData.h \
    DataLayer/MPPTData/I_MPPTData.h \
    DataLayer/MotorDetailsData/MotorDetailsData.h \
    DataLayer/MotorDetailsData/I_MotorDetailsData.h \
    DataLayer/MotorFaultsData/MotorFaultsData.h \
    DataLayer/MotorFaultsData/I_MotorFaultsData.h \
    DataLayer/DataContainer.h \
    DataLayer/CMUData/CMU.h \
    DataLayer/KeyMotorData/KeyMotor.h \
    DataLayer/MPPTData/MPPT.h \
    DataLayer/MotorDetailsData/MotorDetails.h \
    DataLayer/MotorFaultsData/ErrorFlags.h \
    DataLayer/MotorFaultsData/LimitFlags.h \
    PresenterLayer/BatteryPresenter/BatteryPresenter.h \ 
    PresenterLayer/BatteryFaultsPresenter/BatteryFaultsPresenter.h \ 
    PresenterLayer/CMUPresenter/CMUPresenter.h \ 
    PresenterLayer/DriverControlsPresenter/DriverControlsPresenter.h \ 
    PresenterLayer/KeyMotorPresenter/KeyMotorPresenter.h \ 
    PresenterLayer/LightsPresenter/LightsPresenter.h \ 
    PresenterLayer/MPPTPresenter/MPPTPresenter.h \ 
    PresenterLayer/MotorDetailsPresenter/MotorDetailsPresenter.h \ 
    PresenterLayer/MotorFaultsPresenter/MotorFaultsPresenter.h \ 
    PresenterLayer/PresenterContainer.h \
    Gen5Dashboard/Gen5Dashboard.h \
    ViewLayer/ViewContainer.h \
    ViewLayer/DisplayDashboardView/DisplayDashboardView.h \
    ViewLayer/DisplayDashboardUI/DisplayDashboardUI.h \
    ViewLayer/DisplayDashboardUI/RaceModeDashboardUI.h

FORMS    += \
    DisplayDashboardUI.ui \
    RaceModeDashboardUI.ui

RESOURCES += \
    uiresources.qrc

DISTFILES += \
    Resources/Background1.png \
    Resources/MainTitleBar.png \
    Resources/MenuButton.png \
    Resources/Solar Car Team Logo.png \
    Resources/Solar Car Team Symbol.png \
    Resources/SubTitleBar.png \
    Resources/Solar Car Team Icon.ico \
    Resources/Solar Car Team Logo.png \
    Resources/Solar Car Team Symbol.png \
    Resources/Solar Car Team Icon.ico \
    Resources/BrowseButton.png \
    Resources/HighHeadlightIndicator.png \
    Resources/LowHeadlightIndicator.png
