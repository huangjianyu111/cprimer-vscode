#include <vector>
#include <algorithm>

/**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param target int整型 
     * @param array int整型vector<vector<>> 
     * @return bool布尔型
     */
    bool Find(int target, vector<vector<int> >& array) {
        // write code here
        for (auto &row:array) {
            if (std::binary_search(row.begin(), row.end, target)) {
                return true;
            }
        }
        return false;
    }

int main() {
    return 0;
}