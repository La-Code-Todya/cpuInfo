#ifndef CPUINFORMATION_H
#define CPUINFORMATION_H
#include <memory>
#include <cpuinfo.h>

class CpuInformation final {
    public:
    CpuInformation();
    CpuInformation(const CpuInformation&) = delete;
    CpuInformation& operator = (const CpuInformation&) = delete;
    CpuInformation(CpuInformation&&) = delete;
    CpuInformation& operator = (const CpuInformation&&) = delete;
    ~CpuInformation();
    
    static std::unique_ptr<CpuInformation>& create();
    int displayInfo();

    std::string getModel(cpuinfo_vendor vendor);
    uint32_t getCoreCount();
    uint64_t getCoreFrequency(const cpuinfo_core* infoCore);
};

#endif