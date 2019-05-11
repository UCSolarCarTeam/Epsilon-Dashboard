#include "AuxBmsData/AuxBmsData.h"
#include "BatteryData/BatteryData.h"
#include "BatteryFaultsData/BatteryFaultsData.h"
#include "CcsData/CcsData.h"
#include "DriverControlsData/DriverControlsData.h"
#include "KeyMotorData/KeyMotorData.h"
#include "LightsData/LightsData.h"
#include "MpptData/MpptData.h"
#include "MotorDetailsData/MotorDetailsData.h"
#include "MotorFaultsData/MotorFaultsData.h"
#include "DataContainer.h"

DataContainer::DataContainer()
    : auxBmsData_(new AuxBmsData())
    , batteryData_(new BatteryData())
    , batteryFaultsData_(new BatteryFaultsData())
    , ccsData_(new CcsData())
    , driverControlsData_(new DriverControlsData())
    , keyMotorData_(new KeyMotorData())
    , lightsData_(new LightsData())
    , mpptData_(new MpptData())
    , motorDetailsData_(new MotorDetailsData())
    , motorFaultsData_(new MotorFaultsData())
{
}

DataContainer::~DataContainer()
{
}

I_AuxBmsData& DataContainer::auxBmsData()
{
    return *auxBmsData_;
}

I_BatteryData& DataContainer::batteryData()
{
    return *batteryData_;
}

I_BatteryFaultsData& DataContainer::batteryFaultsData()
{
    return *batteryFaultsData_;
}

I_CcsData& DataContainer::ccsData()
{
    return *ccsData_;
}

I_DriverControlsData& DataContainer::driverControlsData()
{
    return *driverControlsData_;
}

I_KeyMotorData& DataContainer::keyMotorData()
{
    return *keyMotorData_;
}

I_LightsData& DataContainer::lightsData()
{
    return *lightsData_;
}

I_MpptData& DataContainer::mpptData()
{
    return *mpptData_;
}

I_MotorDetailsData& DataContainer::motorDetailsData()
{
    return *motorDetailsData_;
}

I_MotorFaultsData& DataContainer::motorFaultsData()
{
    return *motorFaultsData_;
}
