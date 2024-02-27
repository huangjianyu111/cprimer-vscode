#include <vector>
#include <deque>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;// parent
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
// 给定一个二叉树其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!mHead) {
            mHead = findRootNode(pNode);
            vinTraverse(mHead);
            
           
        }
        
        for (auto iter = mVinOrder.begin();iter != mVinOrder.end();iter++) {
            if (*iter == pNode && (iter+1) != mVinOrder.end()) {
                return *(iter+1);
            }
        }
        return nullptr;
    }

    void vinTraverse(TreeLinkNode* pNode) {
        if (pNode) {
            if (pNode->left) {
                vinTraverse(pNode->left);
            }
            mVinOrder.push_back(pNode);
            if (pNode->right) {
                vinTraverse(pNode->right);
            }
        }
    }



    TreeLinkNode* findRootNode(TreeLinkNode* pNode) {
        TreeLinkNode * temp = pNode;
        while(temp) {
            if (temp->next) {
                temp = temp->next;
            } else {
                break;
            }
        }
        return temp;
    }


private:
    TreeLinkNode* mHead = nullptr;
    std::vector<TreeLinkNode*> mVinOrder;
};

int main() {
    return 0;
}