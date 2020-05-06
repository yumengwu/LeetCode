#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) {
            return NULL;
        }
        vector<TreeNode *> v;
        helper(v, root);
        int i;
        for (i = 0; i < v.size(); ++i) {
            if (v[i] == p) {
                break;
            }
        }
        if (i < v.size() - 1) {
            return v[i + 1];
        }
        else {
            return NULL;
        }
    }
    
    void helper(vector<TreeNode *>& v, TreeNode* node) {
        if (!node) {
            return;
        }
        helper(v, node->left);
        v.push_back(node);
        helper(v, node->right);
    }
};