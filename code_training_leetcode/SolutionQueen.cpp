#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> results;
        if (king.size() != 2 || queens.size() < 1) {
            return results;
        }
        int &x = king[0];
        int &y = king[1];

        int dp[8][8];
        for (auto& row:dp) {
            for (auto& ele:row) {
                ele = 0;
            }
        }

        for (int i = 0;i < queens.size();i++) {
            dp[queens[i][0]][queens[i][1]] = 1;
        }

        // row left
        find(dp, x, y, -1, 0, results);

        // row right
        find(dp, x, y, 1, 0, results);

        // col top
        find(dp, x, y, 0, -1, results);

        // col down
        find(dp, x, y, 0, 1, results);
        
        // left top
        find(dp, x, y, -1, -1, results);

        // left down
        find(dp, x, y, -1, 1, results);

        // right top
        find(dp, x, y, 1, -1, results);

        // right down
        find(dp, x, y, 1, 1, results);

        return results;

    }

    void find(int dp[8][8], int row, int col, int rowChange, int colChange, vector<vector<int>>& results) {
        row += rowChange;
        col += colChange;
        while ((row >=0) && (row < 8) && (col >=0) && (col < 8) ) {
            if (dp[row][col] == 1) {
                results.push_back({row,col});
                break;
            }
        }
        row += rowChange;
        col += colChange;
    }
};

int main() {

    return 0;
}