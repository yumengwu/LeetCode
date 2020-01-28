#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct node {
        TreeNode * n;
        int d;
        node(TreeNode * nn, int dd) {
            n = nn;
            d = dd;
        }
    };
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        map<int, int> m;
        queue<node> q;
        node n(root, 0);
        q.push(n);
        while (q.size()) {
            node top = q.front();
            q.pop();
            m[top.d] = top.n->val;
            if (top.n->left) {
                node nn(top.n->left, top.d + 1);
                q.push(nn);
            }
            if (top.n->right) {
                node nn(top.n->right, top.d + 1);
                q.push(nn);
            }
        }
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};