#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> node;
        vector<int> v;
        inorder(root, node, v);
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i) {
            node[i]->val = v[i];
        }
    }
    
    void inorder(TreeNode * root, vector<TreeNode *> & node, vector<int> & v) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, node, v);
        node.push_back(root);
        v.push_back(root->val);
        inorder(root->right, node, v);
    }
};