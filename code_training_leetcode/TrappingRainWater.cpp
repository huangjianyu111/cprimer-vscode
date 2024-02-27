#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>


using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int sumWater = 0;
        int maxHeight = height[0];
        for (auto& e: height) {
            maxHeight = max(maxHeight, e);
        }

        for (int i = 1;i < maxHeight;i++) {
            
        }
        return sumWater;
    }
};

int main() {
    vector<int> vec = {4,2,0,3,2,5};
    Solution sol;
    printf("water : %d\n", sol.trap(vec));
    return 0;
}