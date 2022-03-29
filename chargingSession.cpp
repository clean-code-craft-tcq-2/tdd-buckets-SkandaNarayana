#include "chargingSession.h"
#include <cmath>
std::map<std::string, int>
getRangesMap(const std::vector<int> &chargingRange) {
    std::map<std::string, int> rangesCountMap = {};
    int startOfRange = chargingRange[0];
    int endOfRange = chargingRange[0];
    int rangeCount = 1;
    std::string rangeOutput;
    for(int index = 0; index < chargingRange.size() - 1; index++){
        while(chargingRange[index + 1] - chargingRange[index] < 2 && index < chargingRange.size()-1){
            endOfRange = chargingRange[index + 1];
            rangeCount++;
            index++;
        }
        if(rangeCount > 1) {
            rangeOutput = std::to_string(startOfRange) + "-" + std::to_string(endOfRange);
            rangesCountMap.insert({rangeOutput, rangeCount});
            rangeCount = 1;
            startOfRange = chargingRange[index + 1];
            endOfRange = chargingRange[index + 1];
        }
    }
    return rangesCountMap;
}

std::vector<int> convert12BitInputToAmps(const std::vector<int>& chargingRange){
    std::vector<int> chargingRangeInAmps = {};
    int convertedAmpReading = 0;
    for(auto reading: chargingRange){
        if(reading > 4094) continue;
        convertedAmpReading = std::round((reading * 10) / 4094);
        chargingRangeInAmps.push_back(convertedAmpReading);
    }
    return chargingRangeInAmps;
}

std::map<std::string, int> detectRanges(std::vector<int> chargingRange){
    if(chargingRange.size() == 0 || chargingRange.size() == 1)
        return {};
    std::vector<int> chargingRangeInAmps = convert12BitInputToAmps(chargingRange);
    std::sort(chargingRangeInAmps.begin(), chargingRangeInAmps.end());

    return getRangesMap(chargingRangeInAmps);
}