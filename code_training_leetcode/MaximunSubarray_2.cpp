class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int length = nums.size();
        if (length < 1) return -1;
        
        // sum((i) = max(sum[i-1] + nums[i], nums[i])
        int pre = 0;
        int maxAns = nums[0];

        for (const auto&x:nums) {
            pre = max(pre, nums[i]);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};