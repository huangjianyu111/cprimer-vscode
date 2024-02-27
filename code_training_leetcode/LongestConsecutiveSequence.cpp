#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return 1;
    int maxLength = 1;
    
    unordered_map<int, bool> numsMap;
    for (int &num:nums) {
        numsMap[num] = true;
    }

    for (int &num:nums) {
        int length = 1;
        if (numsMap.find(num-1) != numsMap.end()) continue;
        while(numsMap.find(++num) != numsMap.end()) {
            length++;
        }
        maxLength = max(length, maxLength);
    }

    return maxLength;
}

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    printf("longestConsecutive : %d \n", longestConsecutive(nums));
    return 0;
}