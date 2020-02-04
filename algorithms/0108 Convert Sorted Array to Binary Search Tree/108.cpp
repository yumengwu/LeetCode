#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
    
    TreeNode * helper(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return NULL;
        }
        if (right == left + 1) {
            TreeNode * node = new TreeNode(nums[left]);
            return node;
        }
        int mid = left + (right - left) / 2;
        TreeNode * node = new TreeNode(nums[mid]);
        node->left = helper(nums, left, mid);
        node->right = helper(nums, mid + 1, right);
        return node;
    }
};