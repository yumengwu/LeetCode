#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return t == NULL;
        }
        if (isSameTree(s, t)) {
            return true;
        }
        if (isSubtree(s->left, t)) {
            return true;
        }
        return isSubtree(s->right, t);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL && q != NULL || p != NULL && q == NULL) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        bool temp = isSameTree(p->left, q->left);
        if (!temp) {
            return false;
        }
        temp = isSameTree(p->right, q->right);
        return temp;
    }
};