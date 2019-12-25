#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode *> s;
        s.push(root);
        while (s.size()) {
            TreeNode * top = s.top();
            s.pop();
            res.push_back(top->val);
            if (top->right) {
                s.push(top->right);
            }
            if (top->left) {
                s.push(top->left);
            }
        }
        return res;
    }
};