#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        vector<char> vc;
        vector<int> vi;
        helper(root, vc, vi);
        int res = 0;
        for (int i = 0; i < vi.size(); ++i) {
            res += vi[i];
        }
        return res;
    }
    void helper(TreeNode * node, vector<char> & vc, vector<int> & vi) {
        if (node == NULL) {
            return;
        }
        vc.push_back(node->val + '0');
        if (!(node->left || node->right)) {
            char * str = new char[vc.size() + 1];
            for (int i = 0; i < vc.size(); ++i) {
                str[i] = vc[i];
            }
            vi.push_back(atoi(str));
            delete [] str;
            vc.pop_back();
        }
        else {
            if (node->left) {
                helper(node->left, vc, vi);
            }
            if (node->right) {
                helper(node->right, vc, vi);
            }
            vc.pop_back();
        }
    }
};