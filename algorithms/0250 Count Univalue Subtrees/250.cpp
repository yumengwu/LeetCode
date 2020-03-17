#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int res = 0;
        helper(root, res);
        return res;
    }
    
    bool helper(TreeNode* node, int & res) {
        if (!node) {
            return true;
        }
        bool b1 = helper(node->left, res), b2 = helper(node->right, res);
        if (b1 && b2) {
            if (node->left && node->val != node->left->val || node->right && node->val != node->right->val) {
                return false;
            }
            else {
                ++res;
                return true;
            }
        }
        return false;
    }
};