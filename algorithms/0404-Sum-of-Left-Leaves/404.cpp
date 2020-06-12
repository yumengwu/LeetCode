#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        helper(root, 'r', res);
        return res;
    }

    void helper(TreeNode* node, char c, int& res) {
        if (!node) {
            return;
        }
        if (c == 'l' && !(node->left || node->right)) {
            res += node->val;
        }
        else {
            helper(node->left, 'l', res);
            helper(node->right, 'r', res);
        }
    }
};


