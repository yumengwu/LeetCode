#include "../header.h"
#include <ios>

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
} ();

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
    int findBottomLeftValue(TreeNode* root) {
        int res;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size()) {
            res = q.front()->val;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return res;
    }
};

