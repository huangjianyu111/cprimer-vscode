#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * 
     * @param preOrder int整型vector 
     * @param vinOrder int整型vector 
     * @return TreeNode类
     */
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
        // write code here
        TreeNode *head = nullptr;

        if (preOrder.size() < 1) {
            return head;
        } else {
            head = new TreeNode(preOrder.at(0));

            // mid index, size
            int index = find(vinOrder, preOrder[0]);
            cout << "index : " << index << endl;

            // pre
            vector<int> lefPre(preOrder.begin() + 1, preOrder.begin() + index + 1);
            vector<int> rightPre(preOrder.begin() + 1 + index, preOrder.end());

            // vin
            vector<int> leftVin(vinOrder.begin(), vinOrder.begin() + index);
            vector<int> rightVin(vinOrder.begin() + index + 1, vinOrder.end());

            head->left = reConstructBinaryTree(lefPre, leftVin);
            head->right = reConstructBinaryTree(rightPre, rightVin);
        }

        return head;
    }


    int find(const vector<int>& numbers, const int& val) {
        for (int i = 0;i < numbers.size();i++) {
            if (numbers.at(i) == val) {
                return i;
            }
        }
        return -1;
    }

};



int main() {
    Solution sol;
    vector<int> preOrder = {1,2,4,7,3,5,6,8};
    vector<int> vinOrder = {4,7,2,1,5,3,8,6};
    sol.reConstructBinaryTree(preOrder, vinOrder);
    return 0;
}