#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode *> s;
        s.push(root);
        TreeNode * top, * temp;
        while (s.size() > 0) {
            top = s.top();
            s.pop();
            if (top->left) {
                temp = top->left;
                top->left = NULL;
                s.push(top);
                s.push(temp);
            }
            else {
                res.push_back(top->val);
                if (top->right) {
                    s.push(top->right);
                }
            }
        }
        return res;
    }
};