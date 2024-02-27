#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int temp;
        for (int i=0;i < nums.size() - count;i++) {
            if (nums[i] == 0) {
                temp = nums[i];
                for (int j = i + 1;j < nums.size() - count;j++) {
                    
                    nums[j-1] = nums[j];
                }
                nums[nums.size()-count-1] = temp;
                count++;
                i--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,1,3,10,2,0, 1};
    sol.moveZeroes(nums);
    for (const auto& ele : nums) {
        std::cout << "ele : " << ele << endl;
    }
    return 0;
}