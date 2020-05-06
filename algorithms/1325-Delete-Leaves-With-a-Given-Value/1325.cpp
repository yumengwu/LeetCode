#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* nn = new TreeNode(target + 1);
        nn->left = root;
        helper(root, nn, target, 'l');
        return nn->left;
    }
    
    void helper(TreeNode* node, TreeNode* parent, int tar, char c) {
        if (!node) {
            return;
        }
        helper(node->left, node, tar, 'l');
        helper(node->right, node, tar, 'r');
        if (node->val == tar && !(node->left || node->right)) {
            if (c == 'l') {
                parent->left = 0;
                // delete node;
            }
            else {
                parent->right = 0;
                // delete node;
            }
        }
    }
};