#include <vector>
#include <map>
#include <functional>
#include <queue>

using namespace std;

void printQuueue(priority_queue<pair<int, int>> nums) {
    while (!nums.empty()) {
        auto num = nums.top();
        printf("%d:%d, ", num.first, num.second);
        nums.pop();
    }
    printf("\n");
}

void printVec(vector<int> vec) {
    for (auto &x:vec) {
        printf("%d, ", x);
    }
    printf("\n");
}


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() < k) return res;
        int length = nums.size();
        if (k == 1) return nums;


        deque<int> maxIndexs;
        
        for (int i = 0;i < k;i++) {
            while (!maxIndexs.empty() && nums[i] >= nums[maxIndexs.back()]) {
                maxIndexs.pop_back();
            }
            maxIndexs.push_back(i);
        }

        res.push_back(nums[maxIndexs.front()]);

        for (int i = 0;i < length - k;i++) {
            while (!maxIndexs.empty() && nums[i + k] >= nums[maxIndexs.back()]) {
                maxIndexs.pop_back();
            }
            maxIndexs.push_back(i + k);

            while (maxIndexs.front() <= i) {
                maxIndexs.pop_front();
            }
            
            res.push_back(nums[maxIndexs.front()]);
        }
        return res;
    }
};


int main() {
    vector<int> nums = {7,2,4};
    int k = 2;
    Solution sol;
    for (auto &x:sol.maxSlidingWindow(nums, k)) {
        printf("%d ", x);
    }
    printf("\n");
}