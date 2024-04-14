#include <thread>
#include "gtest/gtest.h"
#include "../inc/cpuinformation.h"

class CpuInformationTest : public testing::Test {
    protected:
    CpuInformationTest():cpuInfo(CpuInformation::create()) {}
    std::unique_ptr<CpuInformation>& cpuInfo;
};

TEST_F(CpuInformationTest, ModelInfo) {
    EXPECT_STREQ(cpuInfo->getModel(cpuinfo_vendor::cpuinfo_vendor_apple).c_str(), "Apple");
    EXPECT_STREQ(cpuInfo->getModel(cpuinfo_vendor::cpuinfo_vendor_nvidia).c_str(), "NVIDIA");
    EXPECT_STREQ(cpuInfo->getModel(cpuinfo_vendor::cpuinfo_vendor_intel).c_str(), "Intel");
    EXPECT_STREQ(cpuInfo->getModel(cpuinfo_vendor::cpuinfo_vendor_amd).c_str(), "AMD");
}

TEST_F(CpuInformationTest, CoreCount) {
    EXPECT_EQ(cpuInfo->getCoreCount(), std::thread::hardware_concurrency());
}

TEST_F(CpuInformationTest, CoreFrequency) {
    cpuinfo_core infoCore;
    infoCore.frequency = 220000;
    EXPECT_EQ(cpuInfo->getCoreFrequency(&infoCore), 220000);
}
