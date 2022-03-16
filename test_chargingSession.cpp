#include "chargingSession.h"
#include <cassert>

void test_detectRanges_emptyInput(){
    std::map<std::string, int> expectedMap = {};
    std::vector<int> ranges = {};
    assert(detectRanges(ranges) == expectedMap);
}

void test_detectRanges_singleRange(){
    std::map<std::string, int> expectedMap = { {"4-5", 3} };
    std::vector<int> ranges = {4,5,5};
    assert(detectRanges(ranges) == expectedMap);
}

void test_detectRanges_moreThanOneRange(){
    std::map<std::string, int> expectedMap = { {"4-5", 2},
                                               {"7-9", 3}};
    std::vector<int> ranges = {5,7,8,4,9,11};
    assert(detectRanges(ranges) == expectedMap);
}

void test_getRangesMap_unsorted(){
    std::map<std::string, int> expectedMap = { {"4-5", 2},
                                               {"7-9", 3}};
    std::vector<int> ranges = {5,7,8,4,9,11};
    assert(getRangesMap(ranges) != expectedMap);
}

void test_getRangesMap_sorted(){
    std::map<std::string, int> expectedMap = { {"4-5", 2},
                                               {"7-9", 3}};
    std::vector<int> ranges = {4,5,7,8,9,11};
    assert(getRangesMap(ranges) == expectedMap);
}

int main(){
    test_detectRanges_emptyInput();
    test_detectRanges_singleRange();
    test_detectRanges_moreThanOneRange();
    test_getRangesMap_sorted();
    test_getRangesMap_unsorted();
}