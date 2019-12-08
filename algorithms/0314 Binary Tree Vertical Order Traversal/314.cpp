#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct point {
        TreeNode * node;
        int index;
    };
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        int left = calLeftWidth(root->left);
        int right = calRightWidth(root->right);
        cout<<left<<' '<<right<<endl;
        // int n = left + right + 1;
        // res.resize(n);
        // queue<point> q;
        // point p;
        // p.node = root;
        // p.index = left;
        // q.push(p);
        // while (q.size()) {
        //     point pp = q.front();
        //     q.pop();
        //     res[pp.index].push_back(pp.node->val);
        //     if (pp.node->left) {
        //         point ppp;
        //         ppp.node = pp.node->left;
        //         ppp.index = pp.index - 1;
        //         q.push(ppp);
        //     }
        //     if (pp.node->right) {
        //         point ppp;
        //         ppp.node = pp.node->right;
        //         ppp.index = pp.index + 1;
        //         q.push(ppp);
        //     }
        // }
        return res;
    }
    int calLeftWidth(TreeNode * root) {
        if (root == NULL) {
            return 0;
        }
        return max(calLeftWidth(root->left) + 1, max(0, calLeftWidth(root->right) - 1));
    }
    int calRightWidth(TreeNode * root) {
        if (root == NULL) {
            return 0;
        }
        return max(calRightWidth(root->right) + 1, max(0, calRightWidth(root->left) - 1));
    }
};

int main()
{
    Solution s;
    return 0;
}