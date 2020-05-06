#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return !root || helper(root->left, root->right);
    }
    
    bool helper(TreeNode * p, TreeNode * q) {
        if (!p && !q) {
            return true;
        }
        else if (p == NULL && q || p && q == NULL) {
            return false;
        }
        return p->val == q->val && helper(p->left, q->right) && helper(p->right, q->left);
    }
};