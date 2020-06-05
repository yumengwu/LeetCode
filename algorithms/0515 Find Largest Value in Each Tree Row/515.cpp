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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(res, root, 0);
        return res;
    }

    void helper(vector<int>& res, TreeNode* node, int depth) {
        if (!node) {
            return;
        }
        if (depth >= res.size()) {
            res.push_back(node->val);
        }
        else if (node->val > res[depth]) {
            res[depth] = node->val;
        }
        helper(res, node->left, depth + 1);
        helper(res, node->right, depth + 1);
    }
};

