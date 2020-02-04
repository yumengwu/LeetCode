#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// inorder
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        vector<int> v;
        inorder(root, v);
        int i;
        for (i = 0; i < v.size(); ++i) {
            if (v[i] > target) {
                break;
            }
        }
        return i > 0 && i < v.size() ? (abs(v[i] - target) > abs(v[i - 1] - target) ? v[i - 1] : v[i]) : (i == 0 ? v[i] : v[i - 1]);
    }
    
    void inorder(TreeNode * node, vector<int>& v) {
        if (node == NULL) {
            return;
        }
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
};