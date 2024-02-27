#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        if (k >= length)  {
            int y = k % length;
            k = y;
        }

        vector<int> newNums(length, 0);
        for (int i = 0;i < length;i++) {
            newNums[(i+k)%length] = nums[i];
        }
        nums.assign(newNums.begin(), newNums.end());
    }
};


int main() {
    Solution sol;
    vector<int> vec = {1,2,3,4,5,6,7};
    int k = 3;
    sol.rotate(vec, k);
    printf("rotated nums:\n");
    for (const auto e:vec) {
        printf("%d,", e);
    }
    return 0;

}