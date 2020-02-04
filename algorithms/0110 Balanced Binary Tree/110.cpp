#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return helper(root) != INT_MAX;
    }
    
    int helper(TreeNode * root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int l = helper(root->left), r = helper(root->right);
        if (l == INT_MAX || r == INT_MAX || abs(l - r) > 1) {
            return INT_MAX;
        }
        return max(l, r) + 1;
    }
};