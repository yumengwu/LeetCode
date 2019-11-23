#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct temp {
        TreeNode * node;
        int level;
    };
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<temp> q;
        temp t;
        t.node = root;
        t.level = 0;
        q.push(t);
        while (q.size() > 0) {
            t = q.front();
            q.pop();
            if (t.level >= res.size()) {
                vector<int> v;
                res.push_back(v);
            }
            res[t.level].push_back(t.node->val);
            if (t.node->left) {
                temp t2;
                t2.level = t.level + 1;
                t2.node = t.node->left;
                q.push(t2);
            }
            if (t.node->right) {
                temp t2;
                t2.level = t.level + 1;
                t2.node = t.node->right;
                q.push(t2);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};