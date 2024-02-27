#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.size() < 1) return ans;
        // sort
        
        sort(intervals.begin(), intervals.end(), [](vector<int>&x1, vector<int>&x2){return x1.front() < x2.front();});
        int length = intervals.size();

        int i = 1;
        ans.push_back(intervals[0]);
        
        while(i < intervals.size()) {
            if (ans[ans.size() - 1][1] >= intervals[i][0]) {
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
            i++;
        }
        return ans;
    }
};

void printDemo(const vector<vector<int>> &ans) {
    for(const auto &vec:ans) {
        printf("[%d,%d], ", vec[0], vec[1]);
    }
    printf("\n");
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution sol;
    printDemo(sol.merge(intervals));
    return 0;
}