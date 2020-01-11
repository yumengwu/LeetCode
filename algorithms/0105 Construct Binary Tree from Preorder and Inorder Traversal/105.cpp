#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode * helper(vector<int> & pre, int pl, int pr, vector<int> & inorder, int il, int ir) {
        if (pl > pr || il > ir) {
            return NULL;
        }
        int i = 0;
        for (i = il; i <= ir; ++i) {
            if (pre[pl] == inorder[i]) {
                break;
            }
        }
        TreeNode * cur = new TreeNode(pre[pl]);
        cur->left = helper(pre, pl + 1, pl + i - il, inorder, il, i - 1);
        cur->right = helper(pre, pl + i - il + 1, pr, inorder, i + 1, ir);
        return cur;
    }
};

int main()
{
    return 0;
}