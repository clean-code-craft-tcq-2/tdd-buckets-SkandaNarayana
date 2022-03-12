#include "chargingSession.h"

std::map<std::string, int> detectRanges(std::vector<int> chargingRange){
    std::map<std::string, int> rangesCountMap = {};
    if(chargingRange.size() == 0 || chargingRange.size() == 1)
        return rangesCountMap;
    int startOfRange = chargingRange[0];
    int endOfRange = chargingRange[0];
    int rangeCount = 1;
    std::string rangeOutput;
    for(int index = 1; index < chargingRange.size(); index++){
        if(chargingRange[index] - chargingRange[index - 1] == 1){
            endOfRange = chargingRange[index];
            rangeCount++;
        }
        else{
            rangeOutput = std::to_string(startOfRange) + "-" + std::to_string(endOfRange);
            rangesCountMap.insert({rangeOutput, rangeCount} );
            rangeCount = 1;
            startOfRange = chargingRange[index];
            endOfRange = chargingRange[index];
        }
    }
    rangeOutput = std::to_string(startOfRange) + "-" + std::to_string(endOfRange);
    rangesCountMap.insert({rangeOutput, rangeCount} );
    return rangesCountMap;
}