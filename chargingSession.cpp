#include "chargingSession.h"

std::map<std::string, int>
getRangesMap(const std::vector<int> &chargingRange) {
    std::map<std::string, int> rangesCountMap = {};
    int startOfRange = chargingRange[0];
    int endOfRange = chargingRange[0];
    int rangeCount = 1;
    std::string rangeOutput;
    for(int index = 1; index < chargingRange.size(); index++){

        while(chargingRange[index] - chargingRange[index - 1] == 1 && index < chargingRange.size()){
            endOfRange = chargingRange[index];
            rangeCount++;
            index++;
        }
        if( startOfRange != endOfRange){
            rangeOutput = std::to_string(startOfRange) + "-" + std::to_string(endOfRange);
            rangesCountMap.insert({rangeOutput, rangeCount} );
            rangeCount = 1;
            startOfRange = chargingRange[index];
            endOfRange = chargingRange[index];
        }
    }
    return rangesCountMap;
}


std::map<std::string, int> detectRanges(std::vector<int> chargingRange){
    if(chargingRange.size() == 0 || chargingRange.size() == 1)
        return {};

    std::sort(chargingRange.begin(), chargingRange.end());

    return getRangesMap(chargingRange);
}