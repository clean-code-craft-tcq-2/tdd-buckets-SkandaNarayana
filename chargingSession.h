#ifndef TDD_BUCKETS_SKANDANARAYANA_CHARGINGSESSION_H
#define TDD_BUCKETS_SKANDANARAYANA_CHARGINGSESSION_H

#include <iostream>
#include<map>
#include <vector>
#include <string>
#include <algorithm>


typedef enum{
    SENSOR_10_BIT,
    SENSOR_12_BIT
}SensorType;

std::vector<int> convert12BitInputToAmps(const std::vector<int>& chargingRange);
std::map<std::string, int> detectRanges(std::vector<int> chargingRange);
std::map<std::string, int> getRangesMap(const std::vector<int> &chargingRange);

#endif //TDD_BUCKETS_SKANDANARAYANA_CHARGINGSESSION_H
