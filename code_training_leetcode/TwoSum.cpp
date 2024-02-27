#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;


bool com(const vector<int> v1, const vector<int> v2) {
    return v1.at(0) < v2.at(0);
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.size() < 2) return result;

        std::unordered_map<int, int> numsMap;
        for (int i = 0;i < nums.size();i++) {
            auto iter = numsMap.find(target - nums[i]);
            if (iter != numsMap.end()) {
                result.push_back(iter->second);
                result.push_back(i);
                return result;
            }
            numsMap.emplace(std::make_pair(nums[i], i));
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> res = sol.twoSum(nums, target);
    if (res.size() == 2)
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    return 0;
}