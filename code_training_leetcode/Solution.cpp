#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int low = 0;
        int high = matrix[0].size() - 1;
        int index;
        while (low <= high) {
            index = (low + high) / 2;
            if (matrix[0][index] == target) {
                return true;
            } else if (matrix[0][index] > target) {
                high = index - 1;
            } else {
                low = index + 1;
            }
        }


        if (low >= matrix[0].size()) low;

        int j = low - 1;
        low = 1;
        high = matrix.size() - 1;
        while (low <= high) {
            index = (low + high) / 2;
            if (matrix[index ][j] == target) {
                return true;
            } else if (matrix[index ][j] > target) {
                high = index - 1;
            } else {
                low = index + 1;
            }
        }
        return false;
    }

    
};

int main() {
    vector<vector<int>> matrix = {{1,4,7, 11}, {6,9,10, 12}, {13,15,17, 19}};
    
    Solution sol;
    printf("%d \n", sol.searchMatrix(matrix, 3));

    return 0;
}