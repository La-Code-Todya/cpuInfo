#include <iostream>
#include <cpuinformation.h>

int main() {
    std::unique_ptr<CpuInformation>& cpuInfo = CpuInformation::create();
    return cpuInfo->displayInfo();
}
