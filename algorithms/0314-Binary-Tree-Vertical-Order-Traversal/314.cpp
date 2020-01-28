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
        int idx;
        node(TreeNode * tn, int i) {
            n = tn;
            idx = i;
        }
    };
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<node> q;
        int minidx = 0;
        int maxidx = 0;
        map<int, vector<int>> m;
        node n(root, 0);
        q.push(n);
        while (q.size()) {
            node nn = q.front();
            q.pop();
            if (nn.idx < minidx) {
                minidx = nn.idx;
            }
            else if (nn.idx > maxidx) {
                maxidx = nn.idx;
            }
            m[nn.idx].push_back(nn.n->val);
            if (nn.n->left) {
                node nnn(nn.n->left, nn.idx - 1);
                q.push(nnn);
            }
            if (nn.n->right) {
                node nnn(nn.n->right, nn.idx + 1);
                q.push(nnn);
            }
        }
        for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};

int main()
{
    Solution s;
    return 0;
}