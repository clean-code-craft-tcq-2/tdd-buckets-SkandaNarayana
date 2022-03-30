#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "chargingSession.h"
#include <cassert>
#include "test/catch.hpp"

TEST_CASE("test_detectRanges_emptyInput")
{
    std::map<std::string, int> expectedMap = {};
    std::vector<int> ranges = {};
    assert(detectRanges(ranges) == expectedMap);
}

TEST_CASE("test_detectRanges_singleRange")
{
    std::map<std::string, int> expectedMap = { {"4-5", 3} };
    std::vector<int> ranges = {4,5,5};
    assert(detectRanges(ranges) == expectedMap);
}

TEST_CASE("test_detectRanges_moreThanOneRange")
{
    std::map<std::string, int> expectedMap = { {"4-5", 2},
                                               {"7-9", 3}};
    std::vector<int> ranges = {5,7,8,4,9,11};
    assert(detectRanges(ranges) == expectedMap);
}

TEST_CASE("test_getRangesMap_unsorted"){
    std::map<std::string, int> expectedMapForUnsortedInput = { {"4-5", 2},
                                               {"7-9", 3}};
    std::vector<int> ranges = {5,7,8,4,9,11};
    assert(getRangesMap(ranges) != expectedMapForUnsortedInput);
}

TEST_CASE("test_getRangesMap_sorted"){
    std::map<std::string, int> expectedMapForSortedInput = { {"4-5", 2},
                                               {"7-9", 3}};
    std::vector<int> ranges = {4,5,7,8,9,11};
    assert(getRangesMap(ranges) == expectedMapForSortedInput);
}

TEST_CASE("test_detectRanges_with12BitNumbers" )
{
    std::map<std::string, int> expectedMapForSortedInput = { {"0-1", 5}};

    std::vector<int> ranges = {0, 454, 556, 3444, 55, 342};
    assert(detectRanges(ranges) == expectedMapForSortedInput);
}

TEST_CASE("test_convert12BitInputToAmps")
{
    std::vector<int> ranges = {0, 454, 556, 3444, 55, 342};
    std::vector<int> expectedOutput = {0, 1, 1, 8, 0, 0};
    assert(convert12BitInputToAmps(ranges) == expectedOutput);
}