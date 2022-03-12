#include "chargingSession.h"
#include <cassert>

void test_detectRanges_emptyInput(){
    std::map<std::string, int> expectedMap = {};
    std::vector<int> ranges = {};
    assert(detectRanges(ranges) == expectedMap);
}

void test_detectRanges_singleRange(){
    std::map<std::string, int> expectedMap = { {"4-5", 2} };
    std::vector<int> ranges = {4,5};
    assert(detectRanges(ranges) == expectedMap);
}
void test_detectRanges_moreThanOneRange(){
    std::map<std::string, int> expectedMap = { {"4-5", 2},
                                               {"7-9", 3}};
    std::vector<int> ranges = {4,5,7,8,9,11};
    assert(detectRanges(ranges) == expectedMap);
}

int main(){
    test_detectRanges_emptyInput();
    test_detectRanges_singleRange();
    test_detectRanges_moreThanOneRange();
}