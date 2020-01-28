#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) {
            return res;
        }
        vector<int> temp;
        temp.push_back(root->val);
        helper(res, temp, root);
        return res;
    }
    
    void helper(vector<string> & res, vector<int> & temp, TreeNode* node) {
        if (node->left == NULL && node->right == NULL) {
            string str = to_string(temp[0]);
            for (int i = 1; i < temp.size(); ++i) {
                str += "->";
                str += to_string(temp[i]);
            }
            res.push_back(str);
            return;
        }
        if (node->left) {
            temp.push_back(node->left->val);
            helper(res, temp, node->left);
            temp.pop_back();
        }
        if (node->right) {
            temp.push_back(node->right->val);
            helper(res, temp, node->right);
            temp.pop_back();
        }
    }
};