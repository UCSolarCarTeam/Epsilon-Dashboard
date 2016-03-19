
#-------------------------------------------------
#
#  Project created by QtCreator 2014-10-13T12:01:32
#
#  Schulich Delta Host Telemetry
#  Copyright (C) 2015 University of Calgary Solar Car Team
#
#  This file is part of the Schulich Delta Host Telemetry
#
#  The Schulich Delta Host Telemetry is free software: 
#  you can redistribute it and/or modify it under the terms 
#  of the GNU Affero General Public License as published by 
#  the Free Software Foundation, either version 3 of the
#  License, or (at your option) any later version.
#
#  The Schulich Delta Host Telemetry is distributed 
#  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
#  without even the implied warranty of MERCHANTABILITY or 
#  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
#  General Public License for more details.
#
#  You should have received a copy of the GNU Affero General 
#  Public License along with the Schulich Delta Host Telemetry.
#  If not, see <http://www.gnu.org/licenses/>.
#
#  For further contact, email <software@calgarysolarcar.ca>
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = ../release/Gen5QuikDash
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
    BusinessLayer/LoggerService/LoggerService.cpp \
    BusinessLayer/CommunicationsMonitoringService/CommunicationsMonitoringService.cpp \
    CommunicationLayer/CommDeviceControl/RadioCommDevice.cpp \
    CommunicationLayer/CommDeviceControl/UdpMessageForwarder.cpp \
    CommunicationLayer/CommunicationContainer.cpp \
    CommunicationLayer/DataPopulators/BatteryPopulator.cpp \
    CommunicationLayer/DataPopulators/CmuPopulator.cpp \
    CommunicationLayer/DataPopulators/DriverDetailsPopulator.cpp \
    CommunicationLayer/DataPopulators/FaultsPopulator.cpp \
    CommunicationLayer/DataPopulators/KeyDriverControlPopulator.cpp \
    CommunicationLayer/DataPopulators/MpptPopulator.cpp \
    CommunicationLayer/MessagingFramework/BatteryDataMessage.cpp \
    CommunicationLayer/MessagingFramework/BatteryFaults.cpp \
    CommunicationLayer/MessagingFramework/CmuDataMessage.cpp \
    CommunicationLayer/MessagingFramework/DriverControlDetails.cpp \
    CommunicationLayer/MessagingFramework/FaultsMessage.cpp \
    CommunicationLayer/MessagingFramework/KeyDriverControlTelemetry.cpp \
    CommunicationLayer/MessagingFramework/LimitFlags.cpp \
    CommunicationLayer/MessagingFramework/MessageDecodingHelpers.cpp \
    CommunicationLayer/MessagingFramework/MessageDefines.cpp \
    CommunicationLayer/MessagingFramework/MotorFaults.cpp \
    CommunicationLayer/MessagingFramework/MpptDataMessage.cpp \
    CommunicationLayer/MessagingFramework/MpptDefines.cpp \
    CommunicationLayer/PacketChecksumChecker/PacketChecksumChecker.cpp \
    CommunicationLayer/PacketDecoder/PacketDecoder.cpp \
    CommunicationLayer/PacketSynchronizer/PacketSynchronizer.cpp \
    CommunicationLayer/PacketUnstuffer/PacketUnstuffer.cpp \
    DataLayer/BatteryData/BatteryData.cpp \
    DataLayer/DataContainer.cpp \
    DataLayer/FaultsData/FaultsData.cpp \
    DataLayer/MpptData/MpptData.cpp \
    DataLayer/PowerData/PowerData.cpp \
    DataLayer/VehicleData/VehicleData.cpp \
    PresenterLayer/BatteryPresenter/BatteryPresenter.cpp \
    PresenterLayer/CommunicationPresenter/CommunicationPresenter.cpp \
    PresenterLayer/FaultsPresenter/FaultsPresenter.cpp \
    PresenterLayer/MpptPresenter/MpptPresenter.cpp \
    PresenterLayer/PowerPresenter/PowerPresenter.cpp \
    PresenterLayer/PresenterContainer.cpp \
    PresenterLayer/VehiclePresenter/VehiclePresenter.cpp \
    Gen5QuikDash/main.cpp \
    Gen5QuikDash/Gen5QuikDash.cpp \
    ViewLayer/ViewContainer.cpp \
    ViewLayer/DashboardUI/DashboardUI.cpp \
    ViewLayer/DashboardView/DashboardView.cpp

HEADERS  += \
    BusinessLayer/BusinessContainer.h \
    BusinessLayer/LoggerService/LoggerService.h \
    BusinessLayer/CommunicationsMonitoringService/CommunicationsMonitoringService.h \
    BusinessLayer/CommunicationsMonitoringService/I_CommunicationsMonitoringService.h \
    CommunicationLayer/CommDeviceControl/I_CommDevice.h \
    CommunicationLayer/CommDeviceControl/RadioCommDevice.h \
    CommunicationLayer/CommDeviceControl/UdpMessageForwarder.h \
    CommunicationLayer/CommunicationContainer.h \
    CommunicationLayer/DataPopulators/BatteryPopulator.h \
    CommunicationLayer/DataPopulators/CmuPopulator.h \
    CommunicationLayer/DataPopulators/DriverDetailsPopulator.h \
    CommunicationLayer/DataPopulators/FaultsPopulator.h \
    CommunicationLayer/DataPopulators/KeyDriverControlPopulator.h \
    CommunicationLayer/DataPopulators/MpptPopulator.h \
    CommunicationLayer/MessagingFramework/BatteryDataMessage.h \
    CommunicationLayer/MessagingFramework/BatteryFaults.h \
    CommunicationLayer/MessagingFramework/CmuDataMessage.h \
    CommunicationLayer/MessagingFramework/DriverControlDetails.h \
    CommunicationLayer/MessagingFramework/FaultsMessage.h \
    CommunicationLayer/MessagingFramework/KeyDriverControlTelemetry.h \
    CommunicationLayer/MessagingFramework/LimitFlags.h \
    CommunicationLayer/MessagingFramework/MessageDecodingHelpers.h \
    CommunicationLayer/MessagingFramework/MessageDefines.h \
    CommunicationLayer/MessagingFramework/MotorFaults.h \
    CommunicationLayer/MessagingFramework/MpptDataMessage.h \
    CommunicationLayer/MessagingFramework/MpptDefines.h \
    CommunicationLayer/PacketChecksumChecker/I_PacketChecksumChecker.h \
    CommunicationLayer/PacketChecksumChecker/PacketChecksumChecker.h \
    CommunicationLayer/PacketDecoder/I_PacketDecoder.h \
    CommunicationLayer/PacketDecoder/PacketDecoder.h \
    CommunicationLayer/PacketSynchronizer/I_PacketSynchronizer.h \
    CommunicationLayer/PacketSynchronizer/PacketSynchronizer.h \
    CommunicationLayer/PacketUnstuffer/I_DataInjectionService.h \
    CommunicationLayer/PacketUnstuffer/I_PacketUnstuffer.h \
    CommunicationLayer/PacketUnstuffer/PacketUnstuffer.h \
    DataLayer/BatteryData/BatteryData.h \
    DataLayer/BatteryData/I_BatteryData.h \
    DataLayer/DataContainer.h \
    DataLayer/FaultsData/FaultsData.h \
    DataLayer/FaultsData/I_FaultsData.h \
    DataLayer/MpptData/I_MpptData.h \
    DataLayer/MpptData/MpptData.h \
    DataLayer/PowerData/I_PowerData.h \
    DataLayer/PowerData/PowerData.h \
    DataLayer/VehicleData/I_VehicleData.h \
    DataLayer/VehicleData/VehicleData.h \
    PresenterLayer/BatteryPresenter/BatteryPresenter.h \
    PresenterLayer/CommunicationPresenter/CommunicationPresenter.h \
    PresenterLayer/FaultsPresenter/FaultsPresenter.h \
    PresenterLayer/MpptPresenter/MpptPresenter.h \
    PresenterLayer/PowerPresenter/PowerPresenter.h \
    PresenterLayer/PresenterContainer.h \
    PresenterLayer/VehiclePresenter/VehiclePresenter.h \
    Gen5QuikDash/Gen5QuikDash.h \
    ViewLayer/I_SolarCarWindow/I_SolarCarWindow.h \
    ViewLayer/DashboardUI/DashboardUI.h \
    ViewLayer/DashboardView/DashboardView.h \
    ViewLayer/DashboardUI/I_DashboardUI.h \
    ViewLayer/ViewContainer.h \

FORMS    += \
    DashboardUI

RESOURCES += \
    uiresources.qrc

DISTFILES += \
    Resources/Solar Car Team Icon.ico \
