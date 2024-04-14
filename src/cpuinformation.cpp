#include <iostream>
#include <cpuinformation.h>

CpuInformation::CpuInformation() {
    cpuinfo_initialize();
}

std::unique_ptr<CpuInformation>& CpuInformation::create() {
    static std::unique_ptr<CpuInformation> object = std::make_unique<CpuInformation>(); 
    return object;
}

int CpuInformation::displayInfo() {
    std::cout << "Model : " << getModel(cpuinfo_get_core(0)->vendor) << std::endl;
    std::cout << "Number of Cores : " << getCoreCount() << std::endl;
    std::cout << "Processor Frequency : " << getCoreFrequency(cpuinfo_get_core(0))  << " Hz" << std::endl;
    return 0;
}

std::string CpuInformation::getModel(cpuinfo_vendor vendor) {
    std::string vendorName;
    switch (vendor) {
    case cpuinfo_vendor_intel:
        vendorName = "Intel";
        break;
    case cpuinfo_vendor_amd:
        vendorName = "AMD";
        break;
    case cpuinfo_vendor_arm:
        vendorName = "ARM";
        break;
    case cpuinfo_vendor_qualcomm:
        vendorName = "Qualcom";
        break;
    case cpuinfo_vendor_apple:
        vendorName = "Apple";
        break;
    case cpuinfo_vendor_samsung:
        vendorName = "Samsung";
        break;
    case cpuinfo_vendor_nvidia:
        vendorName = "NVIDIA";
        break;
    default:
        vendorName = "Unknown";
        break;
    }
    return vendorName;
}

uint32_t CpuInformation::getCoreCount() {
    return cpuinfo_get_cores_count();
}

uint64_t CpuInformation::getCoreFrequency(const cpuinfo_core* infoCore) {
    return infoCore->frequency;
}

CpuInformation::~CpuInformation() {
    cpuinfo_deinitialize();
}

