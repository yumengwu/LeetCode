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
    bool isCousins(TreeNode* root, int x, int y) {
        int xd = -1, xp, yd = -1, yp;
        dfs(root, 0, 0, x, y, xd, xp, yd, yp);
        return xd >= 0 && yd >= 0 && xd == yd && xp != yp;
    }
    
    void dfs(TreeNode* node, int parent, int depth, int x, int y, int& xd, int& xp, int& yd, int& yp) {
        if (!node || (xd >= 0 && yd >= 0)) {
            return;
        }
        if (node->val == x) {
            xd = depth;
            xp = parent;
        }
        if (node->val == y) {
            yd = depth;
            yp = parent;
        }
        dfs(node->left, node->val, depth + 1, x, y, xd, xp, yd, yp);
        if (xd >= 0 && yd >= 0) {
            return;
        }
        dfs(node->right, node->val, depth + 1, x, y, xd, xp, yd, yp);
    }
};

