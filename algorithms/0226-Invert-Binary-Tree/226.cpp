#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         helper(root);
//         return root;
//     }
    
//     void helper(TreeNode * root) {
//         if (root) {
//             TreeNode * temp = root->left;
//             root->left = root->right;
//             root->right = temp;
//             helper(root->left);
//             helper(root->right);
//         }
//     }
// };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        if (!root->left && !root->right) {
            return root;
        }
        TreeNode * temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};