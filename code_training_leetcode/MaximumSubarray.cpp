#include <stdio.h>
#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int length = nums.size();
        if (length < 1) return -1;
        int minNum = nums[0];
        int maxNum = nums[0];
        int dp[length];
        dp[0] = nums[0];
        for (int i = 1;i < length;i++) {
            minNum = min(minNum, nums[i]);
            maxNum = max(maxNum, nums[i]);
            dp[i] = dp[i-1] + nums[i];
        }

        if(maxNum <= 0 || length == 1) return maxNum;

        // left [0, n-1]
        int sum = 0;
        int right;
        int temp;
        for(int left = 0;left < length;left++) {
            if (nums[left] <= 0) continue;
            sum = max(sum, nums[left]);
            right = left+1;
            while (right < length) {
                
                if (nums[right] > 0) {
                    temp = dp[right] - dp[left];

                        if(temp + nums[left] > sum) {
                            //printf("left:%d, right:%d, prev sum: %d \n", left, right, sum);
                            sum = temp + nums[left];
                        } 
                    
                }
                right++;
            }
        }
        return sum;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    printf("%d \n", sol.maxSubArray(nums));
    return 0;
}