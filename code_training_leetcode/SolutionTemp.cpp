#include <list>
#include <math.h>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            // sort
            sort(nums.begin(), nums.end());

            for (int i = 0;i < nums.size() - 2;i++) {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                if (nums[i] > 0) continue;
                int low = i + 1;
                int high = nums.size() - 1;

                while (low < high) {
                    int result = nums[i] + nums[low] + nums[high];
                    if (result == 0) {
                        res.push_back({nums[i], nums[low], nums[high]});

                        while (low < high && nums[high - 1] == nums[high]) high--;
                        high--;

                        while (low < high && nums[low + 1] == nums[low]) low++;
                        low++;
                        
                    } else if (result > 0) {
                        while (low < high && nums[high - 1] == nums[high]) high--;
                        high--;
                    } else {
                        while (low < high && nums[low + 1] == nums[low]) low++;
                        low++;
                    }
                }
            }

            return res;
    }
};


int main() {
    Solution sol;
    
    return 0;
}