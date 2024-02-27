#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
/*
描述
请设计一个函数，用来判断在一个n乘m的矩阵中是否存在一条包含某长度为len的字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 
[矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
数据范围：
 
1≤len≤25 
示例1
输入：
[[a,b,c,e],[s,f,c,s],[a,d,e,e]],"abcced"
复制
返回值：
true
复制
示例2
输入：
[[a,b,c,e],[s,f,c,s],[a,d,e,e]],"abcb"
复制
返回值：
false
*/
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> >& matrix, string word) {
        // write code here
        if (matrix.empty() || word.empty()) {
            return false;
        }

        // find
        for(int i = 0;i < matrix.size();i++) {
            for (int j = 0;j < matrix[0].size();j++) {
                if(find(matrix, word, i, j)) {
                    return true;
                }
            }
        }
        return false;

    }

    bool find(vector<vector<char> >& matrix, string &word, int i, int j) {
        if (mRecords.size() == word.size()) {
            return true;
        }

        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
            return false;
        }

        vector<int> target = {i, j};
        if (std::find(mRecords.begin(), mRecords.end(), target) != mRecords.end()) {
            return false;
        }
        
        
        if (matrix[i][j] == word[mRecords.size()]) {
            mRecords.push_back({i, j});
            // top
            int rowChange = -1;
            int colChange = 0;
            bool res;
            res = find(matrix, word, i + rowChange, j + colChange);
            if (mRecords.size() == word.size()) return true;


            // down
            rowChange = 1;
            colChange = 0;
            res = find(matrix, word, i + rowChange, j + colChange);
            if (mRecords.size() == word.size()) return true;

            // left
            rowChange = 0;
            colChange = -1;
            res = find(matrix, word, i + rowChange, j + colChange);
            if (mRecords.size() == word.size()) return true;

            // down
            rowChange = 0;
            colChange = 1;
            res = find(matrix, word, i + rowChange, j + colChange);
            if (mRecords.size() == word.size()) return true;

            mRecords.pop_back();
        }
        return false;
    }

private:
    // record path
    vector<vector<int>> mRecords;
};


int main() {
    // [[a,b],[c,d]],"abcd"
    vector<vector<char> >matrix = {{'a', 'b'}, {'c' ,'d'}};
    string word = "abcd";

    Solution sol;
    cout << sol.hasPath(matrix, word) << endl;
}