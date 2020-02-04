#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// inorder
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> v;
//         inorder(root, v);
//         return (v[k - 1]);
//     }
    
//     void inorder(TreeNode * root, vector<int>& v) {
//         if (root == NULL) {
//             return;
//         }
//         inorder(root->left, v);
//         v.push_back(root->val);
//         inorder(root->right, v);
//     }
// };

// recursion
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int len = cnt(root->left);
        if (len + 1 == k) {
            return root->val;
        }
        else if (len + 1 > k) {
            return kthSmallest(root->left, k);
        }
        else {
            return kthSmallest(root->right, k - len - 1);
        }
    }
    
    int cnt(TreeNode * node) {
        return node == NULL ? 0 : cnt(node->left) + cnt(node->right) + 1;
    }
};